#include "../include/PoissonTraffic.h"

#include <fstream>
#include <cmath>

using namespace std;

PoissonTraffic::PoissonTraffic(double lambdaDelay, double lambdaSize)
    : lambdaDelay(lambdaDelay), lambdaSize(lambdaSize), generator(random_device{}()) {}

void PoissonTraffic::generate(double simulationTime, const string& outputFile) {

    ofstream file(outputFile);

    file << "time,size\n";

    exponential_distribution<double> delayDist(lambdaDelay);
    exponential_distribution<double> sizeDist(lambdaSize);

    double currentTime = 0.0;

    while (currentTime <= simulationTime) {

        int packetSize = static_cast<int>(round(sizeDist(generator)));

        if (packetSize <= 0)
            packetSize = 1;

        file << currentTime << "," << packetSize << "\n";

        currentTime += delayDist(generator);
    }

    file.close();
}