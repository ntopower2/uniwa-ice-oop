#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <cstring>
#include <map>
#include <vector>
#include <ostream>
#include "Course.h"
#include "Exceptions.h"

using namespace std;

class Student {
    char* AM = nullptr;
    char* first = nullptr;
    char* last = nullptr;
    map<Course*,pair<float,bool>> grades;
public:
    Student();
    Student(char*, char*, char*);
    friend ostream &operator<<(ostream &os, const Student &student);
    Student(const Student &);
    char * getAM() const;
    void addGrade(Course&, float,bool);
    virtual ~Student();
};

#endif //PROJECT_STUDENT_H
