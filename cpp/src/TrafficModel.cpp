#include "../include/UniformTraffic.h"
#include "../include/PoissonTraffic.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Правильный запуск: ./traffic_model <input_file>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return 1;
    }

    double simulationTime;
    std::string line;

    std::getline(input, line);
    simulationTime = std::stod(line);

    std::getline(input, line);
    std::stringstream ss(line);
    std::string modelName;

    ss >> modelName;

    std::unique_ptr<TrafficModel> model;

    if (modelName == "uniform:") {
        double interval;
        int packetSize;

        ss >> interval >> packetSize;

        model = std::make_unique<UniformTraffic>(interval, packetSize);

        model->generate(simulationTime, "../output/output_uniform.csv");
        std::cout << "Трафик сгенерирован в output_uniform.csv\n";

    } else if (modelName == "poisson:") {
        double lambdaDelay;
        double lambdaSize;

        ss >> lambdaDelay >> lambdaSize;

        model = std::make_unique<PoissonTraffic>(lambdaDelay, lambdaSize);

        model->generate(simulationTime, "../output/output_poisson.csv");
        std::cout << "Трафик сгенерирован в output_poisson.csv\n";

    } else {
        std::cerr << "Неизвестная модель\n";
        return 1;
    }
    return 0;
}