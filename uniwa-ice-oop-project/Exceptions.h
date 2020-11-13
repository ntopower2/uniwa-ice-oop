#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H

#include <stdexcept>
using std::runtime_error;

class OutOfRangeException {
public:
    char* AM;
    float grade;
    OutOfRangeException(char *am, float grade) : AM(am), grade(grade) {}
};

class NoAM {
public:
    char* AM;
    int row;
    NoAM(char *mitroo, int r) : AM(mitroo),row(r) {
    }
};


class NoCourse {
public:
    char* course;
    int row;
    NoCourse(char* c,int r) : course(c),row(r) {
    }
};

class TwoGrades {
public:
    char* course;
    char* am;
    TwoGrades(char *course, char *am) : course(course), am(am) {}
};

#endif //PROJECT_EXCEPTIONS_H
