#pragma once

#include "TrafficModel.h"
#include <random>

using namespace std;

class PoissonTraffic : public TrafficModel {
private:
    double lambdaDelay;
    double lambdaSize;

    mt19937 generator;

public:
    PoissonTraffic(double lambdaDelay, double lambdaSize);

    void generate(double simulationTime, const string& outputFile) override;
};