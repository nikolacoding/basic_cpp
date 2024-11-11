#include "Runtime.h"
#include <iostream>
#include <vector>

static inline bool isInvalid(const unsigned short value, const std::vector<unsigned short>&& allowed){
    return std::find(allowed.begin(), allowed.end(), value) == allowed.end();
}

void Runtime::addMatches(std::vector<Match>& vector, int numMatches){
    for (int i = 0; i < numMatches; i++){
        std::pair<Team, Team> current;

        std::printf("Unesi timove [%d]: ", i + 1);
        std::cin >> current.first.name >>
                    current.second.name;
        
        Match newMatch;
        newMatch.teams = current;
        newMatch.winner = 0;
        vector.push_back(newMatch);
    }
}

void Runtime::addPredictors(std::vector<Predictor>& vector, int numPredictors){
    std::printf("Unesi %d predvidjaca:\n", numPredictors);
    for (int i = 0; i < numPredictors; i++){
        std::string current;

        std::cout << i + 1 << ": ";
        std::cin >> current;

        Predictor newPredictor;
        newPredictor.name = current;
        vector.push_back(newPredictor);
    }
}

void Runtime::setPredictions(const std::vector<Match>& matches, std::vector<Predictor>& predictors){
        for (int i = 0; i < matches.size(); i++){
        Match m = matches[i];

        std::cout << "  Mec: " << m.teams.first.name << " (1) - " << 
        m.teams.second.name << " (2)" << std::endl;

        for (Predictor& p : predictors){
            unsigned short pred;
            do{
                std::cout << p.name << ": ";
                std::cin >> pred;
            } while (isInvalid(pred, {1, 2}));

            p.predictions.emplace_back(m, pred);
        }
    }
}

void Runtime::setResults(std::vector<Predictor>& predictors, std::vector<Match>& matches){
    for (int i = 0; i < matches.size(); i++){
        std::pair<Team, Team> current = predictors[0].predictions[i].first.teams;
        unsigned short winner;
        do{
            std::cout << current.first.name << " (1) - " << 
            current.second.name << " (2)" << " <-> unesi pobjednika: ";
            std::cin >> winner;
        } while (isInvalid(winner, {1, 2}));

        for (Predictor& p : predictors){
            p.predictions[i].first.winner = winner;
        }
    }
}

void Runtime::evaluatePredictions(std::vector<Predictor>& predictors){
    for (int i = 0; i < predictors.size(); i++){
        const Match& match = predictors[0].predictions[i].first;
        for (int j = 0; j < predictors.size(); j++){
            std::cout << match.teams.first.name << " vs " << match.teams.second.name;
            // TODO: dokusuriti
        }
    }
}