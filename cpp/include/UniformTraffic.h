#pragma once

#include "TrafficModel.h"

using namespace std;

class UniformTraffic : public TrafficModel {
private:
    double interval;
    int packetSize;

public:
    UniformTraffic(double interval, int packetSize);

    void generate(double simulationTime, const string& outputFile) override;
};