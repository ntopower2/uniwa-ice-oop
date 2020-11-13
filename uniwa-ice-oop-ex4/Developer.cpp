#include "Developer.h"
#include <cstring>

Developer::Developer(const char * C,const char * N,const char * E) {
    code = new char[strlen(C) + 1];
    strcpy (code, C);
    name = new char[strlen(N) + 1];
    strcpy (name, N);
    email = new char[strlen(E) + 1];
    strcpy (email,E);
}

Developer::~Developer() {
    delete[] code;
    delete[] name;
    delete[] email;
}

void Developer::setName(char *N) {
    delete name;
    name = new char[strlen(N) + 1];
    strcpy (name, N);
}

void Developer::setEmail(char *E) {
    delete E;
    email = new char[strlen(E) + 1];
    strcpy (email,E);
}

void Developer::print(ostream & cha) {
    cha << "[DEV] " << code << "|" << name << "|" << email << endl;
}

char *Developer::getCode() const {
    return code;
}

Developer::Developer(const Developer &d) {
    code = new char[strlen(d.code) + 1];
    strcpy (code, d.code);
    name = new char[strlen(d.name) + 1];
    strcpy (name, d.name);
    email = new char[strlen(d.email) + 1];
    strcpy (email,d.email);
}

