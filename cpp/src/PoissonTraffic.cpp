#include "../include/PoissonTraffic.h"

#include <fstream>
#include <cmath>

PoissonTraffic::PoissonTraffic(double lambdaDelay, double lambdaSize) : lambdaDelay(lambdaDelay), lambdaSize(lambdaSize), generator(std::random_device{}()) {}

void PoissonTraffic::generate(double simulationTime, const std::string& outputFile) {
    std::ofstream file(outputFile);

    file << "time,size\n";

    std::exponential_distribution<double> distDelay(lambdaDelay);
    std::exponential_distribution<double> distSize(lambdaSize);

    double currentTime = 0.0;

    while (currentTime <= simulationTime) {

        int packetSize = static_cast<int>(std::round(distSize(generator)));

        if (packetSize <= 0)
            packetSize = 1;

        file << currentTime << "," << packetSize << "\n";

        currentTime += distDelay(generator);
    }

    file.close();
}