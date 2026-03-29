cmake_minimum_required(VERSION 3.16)
project(OOP_1)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(OOP_1
        main.cpp
        my_lib.cpp
        my_lib.h
        Studentas.h)
