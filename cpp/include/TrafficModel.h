#pragma once

#include <string>

using namespace std;

class TrafficModel {
public:
    virtual void generate(double simulationTime, const string& outputFile) = 0;

    virtual ~TrafficModel() = default;
};