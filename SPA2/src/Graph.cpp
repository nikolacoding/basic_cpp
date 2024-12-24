#include "Graph.hpp"

#include <climits>
#include <fstream>

Graph::~Graph(){
    for (int i = 0; i < this->m_numNodes; i++)
        delete[] this->m_adjMatrix[i];
    delete[] this->m_adjMatrix;
}

// ucitavanje matrice susjednosti grafa iz datoteke ciji otvoren tok je argument
bool Graph::loadFromFile(std::ifstream& stream) {
    vector<string> allLines = Utility::getAllCSVLinesFromFile(stream);
    const int dimension = Utility::getCSVLineIntCount(allLines[0]);

    this->m_numNodes = dimension;
    this->m_adjMatrix = new int*[dimension];
    for (int i = 0; i < dimension; i++){
        this->m_adjMatrix[i] = new int[dimension];
        const vector<int> current = Utility::parseCSVLineToIntVector(allLines[i]);

        for (int j = 0; j < dimension; j++)
            this->m_adjMatrix[i][j] = current[j];
    }
    stream.close();
    return true;
}

// pomocna funkcija za Graph::dijkstra
// INT_MAX iz <climits>/<limits.h> se uzima kao beskonacnost
static int min_dist(Graph& graph, vector<int> distances, vector<int> visited){
    int min = INT_MAX;
    int min_i;

    for (int v = 0; v < graph.getNumNodes(); v++)
        if (!visited[v] && distances[v] <= min)
            min = distances[v], min_i = v;
    return min_i;
}

// osnovna C-olika implementacija Dijkstra algoritma sa O(v^2) slozenoscu (v - broj cvorova)
// potencijalna optimizacija: koristiti pq/heap varijantu za O(v + elogv) (e - broj grana)
// INT_MAX iz <climits>/<limits.h> se uzima kao beskonacnost
vector<int> Graph::dijkstra(int from, vector<string>& paths) {
    using std::to_string;

    vector<int> visited, distances;

    visited.resize(this->m_numNodes);
    distances.resize(this->m_numNodes);
    paths.resize(this->m_numNodes);
    // ^ random segfault jednom i nikad vise?

    // gruba inicijalizacija (mozda moze direktno sa nekom metodom vektora?)
    for (int i = 0; i < this->m_numNodes; i++) {
        visited[i] = 0;
        distances[i] = INT_MAX;
        paths[i] = "";
    }
    distances[from] = 0;
    paths[from] = to_string(from);

    for (int i = 0; i < this->m_numNodes; i++) {
        int u = min_dist(*this, distances, visited);
        visited[u] = 1;

        for (int v = 0; v < this->m_numNodes; v++) {
            if (!visited[v] && this->m_adjMatrix[u][v] && distances[u] != INT_MAX &&
                distances[u] + this->m_adjMatrix[u][v] < distances[v]) {
                
                distances[v] = distances[u] + this->m_adjMatrix[u][v];
                paths[v] = paths[u] + " -> " + to_string(v);
                // rekonstrukcija putanje direktnom konverzijom onoga sto bi inace bio
                // pseudo parent/prev niz
            }
        }
    }
    // uvijek vraca kompletne udaljenosti i putanje jer nema uslov prevremenog zaustavljanja
    return distances;
}

// generisanje i smjestanje u memoriju (kao atribut instance objekta) svih mogucih udaljenosti i putanja
// od svakog do svakog cvora grafa
void Graph::getAllPathsAndDistances(){
    vector<vector<int>> allDistances;
    vector<vector<string>> allPaths;
    for (int i = 0; i < this->m_numNodes; i++){
        vector<string> currentPaths;
        allDistances.push_back(this->dijkstra(i, currentPaths));
        allPaths.push_back(currentPaths);
    }

    this->allDistances = allDistances;
    this->allPaths = allPaths;
}

// koristimo vec sacuvane rezultate dobijene pozivanjem
// Graph::getAllPathsAndDistances(...)
int Graph::getDistanceFromTo(int from, int to) const {
    return this->allDistances[from][to];
}

string Graph::getPathFromTo(int from, int to) const {
    return this->allPaths[from][to];
}

int Graph::getNumNodes() const {
    return this->m_numNodes;
}

// debug
void Graph::displayAdjMatrix() const {
    const int n = this->m_numNodes;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << this->m_adjMatrix[i][j] << " ";
        std::cout << std::endl;
    }
}