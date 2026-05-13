#pragma once

#include "TrafficModel.h"

class UniformTraffic : public TrafficModel {
private:
    double interval;
    int packetSize;

public:
    UniformTraffic(double interval, int packetSize);

    void generate(double simulationTime, const std::string& outputFile) override;
};