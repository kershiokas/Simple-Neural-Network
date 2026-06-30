cmake_minimum_required(VERSION 4.0)
project(neu_network)

set(CMAKE_CXX_STANDARD 20)

add_executable(neu_network main.cpp
        matrix.h
        Layer.h
        Network.h
        Activations.h)
