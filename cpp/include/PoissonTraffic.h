#pragma once

#include "TrafficModel.h"
#include <random>

class PoissonTraffic : public TrafficModel {
private:
    double lambdaDelay;
    double lambdaSize;

    std::mt19937 generator;

public:
    PoissonTraffic(double lambdaDelay, double lambdaSize);

    void generate(double simulationTime, const std::string& outputFile);
};