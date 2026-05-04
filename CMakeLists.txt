cmake_minimum_required(VERSION 3.16)
project(OOP_1)
set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(OOP_2
        src/main.cpp
        src/my_lib.cpp
        include/my_lib.h
        include/Studentas.h
        include/Zmogus.h)

add_executable(testai
        tests/studentas_test.cpp
        src/my_lib.cpp
        include/my_lib.h
        include/Studentas.h
        include/Zmogus.h)
