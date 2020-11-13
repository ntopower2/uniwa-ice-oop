cmake_minimum_required(VERSION 3.15)
project(uniwa-ice-oop)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(uniwa-ice-oop-ex4)
include_directories(uniwa-ice-oop-project)

add_executable(Ex1 Ex1.cpp)
add_executable(Foititis Foititis.cpp)
add_executable(Foititis2 Foititis2.cpp)
add_executable(exam exam.cpp)
add_executable(ex4
        uniwa-ice-oop-ex4/Developer.cpp
        uniwa-ice-oop-ex4/Developer.h
        uniwa-ice-oop-ex4/Ex4.cpp
        uniwa-ice-oop-ex4/Rating.cpp
        uniwa-ice-oop-ex4/Rating.h
        uniwa-ice-oop-ex4/App.cpp
        uniwa-ice-oop-ex4/App.h
        uniwa-ice-oop-ex4/Game.cpp
        uniwa-ice-oop-ex4/Game.h
        uniwa-ice-oop-ex4/Office.cpp
        uniwa-ice-oop-ex4/Office.h
        uniwa-ice-oop-ex4/AppSystem.cpp
        uniwa-ice-oop-ex4/AppSystem.h)
add_executable(project
        uniwa-ice-oop-project/Course.cpp
        uniwa-ice-oop-project/Course.h
        uniwa-ice-oop-project/main.cpp
        uniwa-ice-oop-project/Student.cpp
        uniwa-ice-oop-project/Student.h
        uniwa-ice-oop-project/Dashboard.cpp
        uniwa-ice-oop-project/Dashboard.h
        uniwa-ice-oop-project/Exceptions.h)