#include <cstring>
#include <new>
#include <iostream>
#include <iomanip>

using namespace std;

class Foititis {
    char* AM;
    string name;
    unsigned int semester;
    unsigned int passed;
    float* passed_array;

public:
    // overloaded contructors
    Foititis(char*, string );
    Foititis(char* , string , unsigned int );
    Foititis(char* , string , unsigned int , unsigned int , float* );
    Foititis(Foititis *);

    // destructor
    ~Foititis();

    // setters
    void setAM(char*);
    void setName(string);
    void setSemester(unsigned int );
    void setPassed(unsigned int , float* );

    // getters
    char* getAM();
    string getName();
    unsigned int getSemester();
    unsigned int getPassed();
    float* getPassedArray();

    // additional functions
    void insertPassed(float );
    void print(ostream &);
    void printGrades(ostream &);
    friend ostream& operator<<(ostream&, const Foititis& );
};

// constructors' declarations
Foititis::Foititis(char* mitroo, string onoma) {
    int len = strlen(mitroo);
    if (len) {
        AM = new char[len+1];
        for (int i=0;i<len;i++) {
            AM[i] = mitroo[i];
        }
        AM[len]='\0';
    }
    name = onoma;
    semester = 1;
    passed = 0;
    passed_array = {};
}

Foititis::Foititis(char* mitroo, string onoma, unsigned int eksamino) {
    int len = strlen(mitroo);
    if (len) {
        AM = new char[len+1];
        for (int i=0;i<len;i++) {
            AM[i] = mitroo[i];
        }
        AM[len]='\0';
    }
    name = onoma;
    semester = eksamino;
    passed = 0;
    passed_array = {};
}

Foititis::Foititis(char* mitroo, string onoma, unsigned int eksamino, unsigned int perasmena, float* perasmena_array) {
    int len = strlen(mitroo);
    if (len) {
        AM = new char[len+1];
        for (int i=0;i<len;i++) {
            AM[i] = mitroo[i];
        }
        AM[len]='\0';
    }
    name = onoma;
    semester = eksamino;
    passed = perasmena;
    if (perasmena) {
        passed_array = new float[perasmena];
        for (int i=0;i<perasmena;i++) {
            passed_array[i] = perasmena_array[i];
        }
    }
}

Foititis::Foititis(Foititis *a) {
    AM = new char[strlen(a->AM)+1];
    strcpy(AM,a->AM);
    name = a->name;
    semester = a->semester;
    passed = a->passed;
    passed_array = a->passed_array;
}

// destructor definition
Foititis::~Foititis() {
    cout << "destroyed student with AM " << AM << endl;
    delete AM;
    delete[] passed_array;
}

// setters' declarations
void Foititis::setAM(char* mitroo) {
    int len = strlen(mitroo);
    if (len) {
        delete AM;
        AM = new char[len+1];
        for (int i=0;i<len;i++) {
            AM[i] = mitroo[i];
        }
        AM[len]='\0';
    }
}

void Foititis::setName(string onoma) {
    name = onoma;
}

void Foititis::setSemester(unsigned int eksamino) {
    semester = eksamino;
}

void Foititis::setPassed(unsigned int perasmena, float* perasmena_array) {
    passed = perasmena;
    if (perasmena) {
        passed_array = new float[perasmena];
        for (int i=0;i<perasmena;i++) {
            passed_array[i] = perasmena_array[i];
        }
    }
}

// getters' declarations
char* Foititis::getAM() {
    return AM;
}

string Foititis::getName() {
    return name;
}

unsigned int Foititis::getSemester() {
    return semester;
}

unsigned int Foititis::getPassed() {
    return passed;
}

float* Foititis::getPassedArray() {
    return passed_array;
}

// additional functions' declarations
void Foititis::insertPassed(float grade) {
    passed++;
    float *arr = new float[passed];
    for (int i=0;i<passed-1;i++) arr[i] = passed_array[i];
    arr[passed-1] = grade;
    setPassed(passed,arr);
    delete[] arr;
}

void Foititis::print(ostream &cha) {
    cha << left;
    cha << "AM: " << AM;
    cha << " | Name: " << name;
    cha << " | Semester: " << semester << endl;
    cha << '\n';
}

void Foititis::printGrades(ostream &cha) {
    float mean = 0.0;
    for (int j=0;j<passed;j++) {
        float course = passed_array[j];
        mean += course;
        cha << setw( 0) << "Course " << j+1 << ": " << course << endl;
    }
    mean /= passed;
    cha << setw(10) << "GPA : " << mean << endl;
    cha << '\n';
}

ostream& operator<<(ostream &cha, const Foititis & a) {
    float mean = 0.0;
    for (int j=0;j<a.passed;j++) {
        float course = a.passed_array[j];
        mean += course;
        cha << setw( 0) << "Course " << j+1 << ": " << course << endl;
    }
    mean /= a.passed;
    cha << setw(10) << "GPA : " << mean << endl;
    cha << '\n';
    return cha;
}

int main() {
    Foititis f1 = new Foititis((char *)"1111","Dokimidis1");
    Foititis f2 = new Foititis((char *)"1112","Dokimidis2",2);
    float arr[] = {4.2,3.3,7.8}, arr2[] = {7.9,9.2};
    Foititis f3 = new Foititis((char *)"1113","Dokimidis3",3,3,arr);
    Foititis f4 = new Foititis(f3);
    f4.setName("Dokimidis4");
    f4.setSemester(1);
    f4.setAM((char *)"1114");
    f2.setPassed(2,arr2);
    Foititis f5 = new Foititis(f4.getAM(),f4.getName());
    f5.setPassed(f3.getPassed(),f3.getPassedArray());
    f5.insertPassed(4.3);
    f2.insertPassed(8.9);
    f4.insertPassed(6.3);
    char* s1 = f4.getAM(); string s2 = f4.getName();
    float* grades = f3.getPassedArray();
    f4.print(cout);
    cout << f2; // same output as f4.printGrades(cout);
    return 0;
}