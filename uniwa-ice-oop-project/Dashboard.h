#ifndef PROJECT_DASHBOARD_H
#define PROJECT_DASHBOARD_H

#include "Course.h"
#include "Student.h"
#include "Exceptions.h"
#include <vector>

using namespace std;

struct strcmp2 {
    bool operator()(char const *a, char const *b) const {
        return strcmp(a, b) < 0;
    }
};

class Dashboard {
    vector<Course> courses; vector<Student> students;
    map<char*, char*,strcmp2> oldToNew;
    map<char*, char*,strcmp2> newToOld;
    map<char*, Student*,strcmp2> studMap;
    map<char*, Course*,strcmp2> courseMap;

public:
    void loadMapping(char*);
    void loadCourses(char*);
    void loadStudents(char*);
    void loadGrades(char*);
    void printNotTransferred(ostream&);
};
#endif //PROJECT_DASHBOARD_H
