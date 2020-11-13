cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Developer.cpp
        Developer.h
        Ex4.cpp
        Rating.cpp
        Rating.h
        App.cpp
        App.h
        Game.cpp
        Game.h
        Office.cpp
        Office.h
        AppSystem.cpp
        AppSystem.h)
