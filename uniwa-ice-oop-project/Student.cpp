#include "Student.h"

Student::Student() {
    AM = nullptr;
    first = nullptr;
    last = nullptr;
}

Student::Student(char * c1, char *c2, char *c3) {
    AM = new char[strlen(c1)+1];
    first = new char[strlen(c2)+1];
    last = new char[strlen(c3)+1];
    strcpy(AM,c1),strcpy(first,c2),strcpy(last,c3);
}

Student::~Student() {
    delete[] AM;
    delete[] first;
    delete[] last;

}

Student::Student(const Student & st) {
    AM = new char[strlen(st.AM)+1];
    strcpy(AM,st.AM);
    first = new char[strlen(st.first)+1];
    strcpy(first,st.first);
    last = new char[strlen(st.last)+1];
    strcpy(last,st.last);
}

void Student::addGrade(Course & c, float g, bool isold) {
    char* code = (isold)?c.getOldId():c.getNewId();
    try {
        if (g>10 || g<0) throw OutOfRangeException(AM,g);
        if (!grades.count(&c)) grades[&c] = make_pair(g,isold);
        else if (grades[&c].first != g) throw TwoGrades(code,AM);
        else if (grades[&c].second && !isold) grades[&c].second = false;
    }
    catch (OutOfRangeException& oore) {
        fprintf(stderr,"OutOfRangeGrade;%s;%s;%f\n",oore.AM,code,oore.grade);
    }
    catch (TwoGrades& tg) {
        fprintf(stderr,"TwoGrades;%s;%s;%f\n",tg.am,tg.course,g);
    }
}

char *Student::getAM() const {
    return AM;
}

ostream &operator<<(ostream &os, const Student &student) {
    for (const auto& grade:student.grades) if (grade.second.second && grade.first->getNewId())
            os << student.AM << ";" << student.first << ";" << student.last << ";"
            <<  *grade.first << ";" << grade.second.first<<endl;
    return os;
}
