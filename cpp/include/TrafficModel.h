#pragma once

#include <string>

class TrafficModel {
public:
     virtual void generate(double simulationTime, const std::string& outputFile) = 0;
};