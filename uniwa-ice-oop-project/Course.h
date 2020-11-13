#ifndef PROJECT_COURSE_H
#define PROJECT_COURSE_H

#include <iostream>
#include <cstring>
using namespace std;
class Course {
    char* oldId= nullptr;
    char* newId= nullptr;
    char* oldName= nullptr;
    char* newName= nullptr;
public:
    Course(char*,char*);
    Course(char*,char*,char*,char*);
    Course(const Course &);
    char* getOldId();
    char* getNewId();
    static bool strcmp(const char *, const char *, short);
    virtual ~Course();
    friend ostream &operator<<(ostream &os, const Course &course);
};


#endif //PROJECT_COURSE_H
