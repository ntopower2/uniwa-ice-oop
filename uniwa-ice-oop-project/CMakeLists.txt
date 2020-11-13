cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project
        Course.cpp
        Course.h
        main.cpp Student.cpp Student.h Dashboard.cpp Dashboard.h Exceptions.h)