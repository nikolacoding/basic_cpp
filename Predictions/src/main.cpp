#include <iostream>
#include <vector>

#include "Team.h"
#include "Match.h"
#include "Predictor.h"
#include "Runtime.h"

int main(void){
    int numMatches = 1;
    int numPredictors = 2;
    std::vector<Match> matches;
    std::vector<Predictor> predictors;

    Runtime::addMatches(matches, numMatches);
    Runtime::addPredictors(predictors, numPredictors);
    Runtime::setPredictions(matches, predictors);
    Runtime::setResults(predictors, matches);
    Runtime::evaluatePredictions(predictors);
}