#include "../include/UniformTraffic.h"

#include <fstream>

UniformTraffic::UniformTraffic(double interval, int packetSize) : interval(interval), packetSize(packetSize) {}

void UniformTraffic::generate(double simulationTime, const std::string& outputFile) {
    std::ofstream file(outputFile);

    file << "time,size\n";

    double currentTime = 0.0;

    while (currentTime <= simulationTime) {
        file << currentTime << "," << packetSize << "\n";
        currentTime += interval;
    }

    file.close();
}