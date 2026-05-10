cmake_minimum_required(VERSION 3.10)

project(TrafficModel)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(traffic_model
    src/TrafficModel.cpp
    src/UniformTraffic.cpp
    src/PoissonTraffic.cpp
)