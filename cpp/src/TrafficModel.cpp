#include "../include/UniformTraffic.h"
#include "../include/PoissonTraffic.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Правильный запуск: ./traffic_model <input_file>\n";
        return 1;
    }

    ifstream input(argv[1]);

    if (!input.is_open()) {
        cerr << "Ошибка открытия файла\n";
        return 1;
    }

    double simulationTime;
    string modelLine;

    getline(input, modelLine);
    simulationTime = stod(modelLine);
    getline(input, modelLine);
    stringstream ss(modelLine);
    string modelName;

    ss >> modelName;

    unique_ptr<TrafficModel> model;

    if (modelName == "uniform:") {
        double interval;
        int packetSize;

        ss >> interval >> packetSize;

        model = make_unique<UniformTraffic>(interval, packetSize);

    } else if (modelName == "poisson:") {
        double lambdaDelay;
        double lambdaSize;

        ss >> lambdaDelay >> lambdaSize;

        model = make_unique<PoissonTraffic>(lambdaDelay, lambdaSize);

    } else {
        cerr << "Неизвестная модель трафика\n";
        return 1;
    }

    model->generate(simulationTime, "output.csv");
    cout << "Трафик сгенерирован в output.csv\n";

    return 0;
}