#ifndef RUNTIME_H
#define RUNTIME_H

#include "Match.h"
#include "Predictor.h"
#include <algorithm>
#include <vector>

namespace Runtime{
    // Stage 1
    void addMatches(std::vector<Match>& vector, int numMatches);
    void addPredictors(std::vector<Predictor>& vector, int numPredictors);
    void setPredictions(const std::vector<Match>& matches, std::vector<Predictor>& predictors);

    // Stage 2
    void setResults(std::vector<Predictor>& predictors, std::vector<Match>& matches);
    void evaluatePredictions(std::vector<Predictor>& predictors);
}

#endif