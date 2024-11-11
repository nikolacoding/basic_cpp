#include <iostream>
#include <vector>

#include "Team.h"
#include "Match.h"
#include "Predictor.h"

int main(void){
    int numMatches = 3;
    int numPredictors = 3;
    std::vector<Match> matches;
    std::vector<Predictor> predictors;

    for (int i = 0; i < numMatches; i++){
        std::pair<Team, Team> current;

        std::printf("Unesi timove [%d]: ", i + 1);
        std::cin >> current.first.name >>
                    current.second.name;
        
        Match newMatch;
        newMatch.teams = current;
        newMatch.winner = 0;
        matches.push_back(newMatch);
    }

    std::printf("Unesi %d predvidjaca:\n", numPredictors);
    for (int i = 0; i < numPredictors; i++){
        std::string current;

        std::cout << i + 1 << ": ";
        std::cin >> current;

        Predictor newPredictor;
        newPredictor.name = current;
        predictors.push_back(newPredictor);
    }

    for (int i = 0; i < matches.size(); i++){
        Match m = matches[i];

        std::cout << "  Mec: " << m.teams.first.name << " (1) - " << 
        m.teams.second.name << " (2)" << std::endl;

        for (Predictor p : predictors){
            unsigned short pred;
            std::cout << p.name << ": ";
            std::cin >> pred;

            std::pair<Match, unsigned short> prediction;
            prediction.first = m;
            prediction.second = pred;

            p.prediction[i] = prediction;
        }
    }
}