
#include "Dashboard.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    Dashboard dash;
    auto errfp = freopen("../uniwa-ice-oop-project/error.csv","w",stderr);
    fprintf(stderr,"ERROR;DATA;ROW\n");
    dash.loadMapping((char*)"../uniwa-ice-oop-project/mapping.csv");
    dash.loadCourses((char*)"../uniwa-ice-oop-project/courses.csv");
    dash.loadStudents((char*)"../uniwa-ice-oop-project/students.csv");
    dash.loadGrades((char*)"../uniwa-ice-oop-project/grades.csv");
    ofstream outfile ("../uniwa-ice-oop-project/output.csv");
    dash.printNotTransferred(outfile);
    outfile.close();
    return 0;
}
