#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
using std::vector;
using std::string;

#include "Utility.hpp"

class Graph final {
private:
    int m_numNodes;
    int** m_adjMatrix;

public:
    explicit Graph(std::ifstream& stream) { loadFromFile(stream); }
    ~Graph();

    Graph(const Graph& other) = delete;
    Graph(Graph&& other) = delete;
    Graph& operator=(const Graph& other) = delete;
    Graph& operator=(Graph&& other) = delete;

    bool loadFromFile(std::ifstream& stream);
    vector<int> dijkstra(int from, vector<string>& paths);
    void getAllPathsAndDistances();

    // dohvatanje iz allDistances i allPaths
    int getDistanceFromTo(int from, int to) const;
    string getPathFromTo(int from, int to) const;

    int getNumNodes() const;
    void displayAdjMatrix() const;

private:
    // [i][j] => distanca/putanja od i-tog do j-tog cvora
    vector<vector<int>> allDistances;
    vector<vector<string>> allPaths;
};

#endif