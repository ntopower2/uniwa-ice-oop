#include <cstring>
#include <new>
#include <iostream>
#include <iomanip>

using namespace std;

class Course {
    string code;
    string name;
    unsigned int semester;

public:
    // overloaded contructor
    Course();
    Course(string, string, unsigned int);
    Course(Course *);

    //getters
    string getCode();
    string getName();
    unsigned int getSemester();

    //print
    void print(ostream &);
};

class Foititis {
    char* AM;
    string name;
    unsigned int semester;
    unsigned int passed;
    float* passed_array = nullptr;
    unsigned int registered;
    Course** registered_array = nullptr;

public:
    // overloaded contructors
    Foititis(char*, string );
    Foititis(char* , string , unsigned int );
    Foititis(char* , string , unsigned int , unsigned int , float* );
    Foititis(char* , string , unsigned int , unsigned int , float*, unsigned int, Course**);
    Foititis(const Foititis &);

    // destructor
    ~Foititis();

    // setters
    void setAM(char*);
    void setName(string);
    void setSemester(unsigned int );
    void setPassed(unsigned int , float* );
    void setRegistered(unsigned int, Course**);

    // getters
    char* getAM();
    string getName();
    unsigned int getSemester();
    unsigned int getPassed();
    float* getPassedArray();
    unsigned int getRegistered();
    Course** getRegistedArray();

    // additional functions
    void insertPassed(float );
    void print(ostream &);
    void printGrades(ostream &);

    // operators' definitions
    Foititis& operator= (const Foititis &);
    void operator+= (Course *);
    int operator== (const Foititis &);
    int operator!= (const Foititis &);
    int operator< (const Foititis &);
    int operator<= (const Foititis &);
    int operator> (const Foititis &);
    int operator>= (const Foititis &);
};

Course::Course() {
    code = "";
    name = "";
    semester = 0;
}

Course::Course(string kodikos,string onoma, unsigned eksamino) {
    code = kodikos;
    name = onoma;
    semester = eksamino;
}

Course::Course(Course *c) {
    code = c->code;
    name = c->name;
    semester = c->semester;
}

string Course::getCode() {
    return code;
}

string Course::getName() {
    return name;
}

unsigned int Course::getSemester() {
    return semester;
}

void Course::print(ostream &cha) {
    cha << left;
    cha <<"Code: " << setw(4) << code;
    cha <<" | Name: " << setw(10) << name;
    cha << right;
    cha <<" | Semester: " << setw(2) << semester << endl;
    cha << '\n';
}

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
    semester = 0;
    passed = 0;
    passed_array = nullptr;
    registered = 0;
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
    passed_array =  nullptr;
    registered = 0;
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
    if (perasmena) setPassed(perasmena,perasmena_array);
    registered = 0;
}

Foititis::Foititis(char* mitroo, string onoma, unsigned int eksamino, unsigned int perasmena, float* perasmena_array,
        unsigned int dilomena, Course** dilomena_array) {
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
    if (perasmena) setPassed(perasmena,perasmena_array);
    if (dilomena) setRegistered(dilomena,dilomena_array);
}

Foititis::Foititis(const Foititis &a) {
    AM = new char[strlen(a.AM)+1];
    strcpy(AM,a.AM);
    name = a.name;
    semester = a.semester;
    setPassed(a.passed,a.passed_array);
    setRegistered(a.registered,a.registered_array);
}

// destructor definition
Foititis::~Foititis() {
    cout << "destroyed student with AM " << AM << endl;
    delete[] AM;
    delete[] passed_array;
    delete[] registered_array;
}

// setters' declarations
void Foititis::setAM(char* mitroo) {
    int len = strlen(mitroo);
    if (len) {
        delete[] AM;
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
        delete[] passed_array;
        passed_array = new float[perasmena];
        for (int i=0;i<perasmena;i++) passed_array[i] = perasmena_array[i];
    }
}

void Foititis::setRegistered(unsigned int dilomena, Course** dilomena_array) {
    delete[] registered_array;
    registered = dilomena;
    registered_array = new Course*[registered];
    for (int i=0;i<registered;i++) registered_array[i] = dilomena_array[i];
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

unsigned int Foititis::getRegistered() {
    return registered;
}

Course** Foititis::getRegistedArray() {
    return registered_array;
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
    cha << " | NAME: " << name;
    cha << " | SEMESTER: " << semester << endl;
    cha << '\n';
    cha << "REGISTERED COURSES:" << endl;
    for (int i = 0;i<registered;i++) registered_array[i]->print(cha);
}

void Foititis::printGrades(ostream &cha) {
    float mean = 0.0;
    for (int j=0;j<passed;j++) {
        float course = passed_array[j];
        mean += course;
        cha << "Course " << setw(2)<<j+1 << "  " << course << endl;
    }
    cha << "GPA :" << setw(10) << mean/passed << endl;
    cha << '\n';
}

ostream& operator<<(ostream &cha,Foititis* a) {
    cha << left;
    cha << "AM: " << a->getAM();
    cha << " | NAME: " << a->getName();
    cha << " | SEMESTER: " << a->getSemester();
    cha << "\n";
    return cha;
}

void Foititis::operator+=(Course *c) {
    registered++;
    Course** arr = new Course*[registered];
    for (int i=0;i<registered-1;i++) arr[i] = registered_array[i];
    arr[registered-1] = c;
    delete[] registered_array;
    registered_array = arr;
}

int Foititis::operator==(const Foititis & a) {
    return (semester == a.semester);
}

int Foititis::operator!=(const Foititis & a) {
    return (semester != a.semester);
}

int Foititis::operator<=(const Foititis & a) {
    return (semester <= a.semester);
}

int Foititis::operator<(const Foititis & a) {
    return (semester < a.semester);
}

int Foititis::operator>(const Foititis & a) {
    return (semester > a.semester);
}

int Foititis::operator>=(const Foititis & a) {
    return (semester >= a.semester);
}

Foititis& Foititis::operator=(const Foititis & a) {
    delete[] AM;
    AM = new char[strlen(a.AM)+1];
    strcpy(AM,a.AM);
    name = a.name;
    semester = a.semester;
    setPassed(a.passed,a.passed_array);
    setRegistered(a.registered,a.registered_array);
    return *this;
}

int main() {
    srand (static_cast <unsigned> (time(0))); cout<<setprecision(3);
    Course **cptr, **cptr2;
    cptr = new Course* [10];
    cptr2 = new Course* [2];
    float arr[10], arr2[] = {5.22,8.31,7.85};
    for (int i=0;i<10;i++)
        //loads some courses and some grades
        cptr[i] = new Course(to_string(i+150),"Course"+to_string(i+1),int(rand() % 10)+1),
        arr[i] = 5.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(10.0-5.0)));

    Foititis f1((char *)"1111","Dokimidis1",2,10,arr,10,cptr);
    Course C1("B11","Modified1",10);
    Course C2("B12","Modified2",3);
    Course C3("B13","Modified3",2);
    cptr2[0] = &C1;
    cptr2[1] = &C2;
    Foititis f2((char *)"1112","Dokimidis2",7,3,arr2,2,cptr2);
    Foititis f3 = f2; //copy constructor
    f3.setAM((char*)"1113");
    f3.setSemester(5);
    f2 = f1; //overloaded assignment operator
    f2.setAM((char*)"1112");
    f2.operator+=(&C1); //adding to registered courses
    f1+=&C3; //another way to call += operator
    f1.insertPassed(9.95);
    cptr2[1] = &C3; //an existing course is modified, change is being propagated
    f3.getRegistedArray()[1]->print(cout);
    cout << &f3; //overloaded << operator
    f2.print(cout); //print by function into cout
    f1.printGrades(cout);
    cout << "f3 is on semester " << f3.getSemester() << " and f2 is on semester "
    << f2.getSemester() << " so is f3>f2? => " << (f3>f2) << endl; //comparison between objects Foititis

    for (int i=0;i<10;i++) delete cptr[i]; //deleting temp courses
    delete[] cptr; delete[] cptr2; //deleting Course** arrays
    return 0;
}