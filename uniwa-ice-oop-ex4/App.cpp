#include "App.h"
#include <cstring>
#include <utility>

App::App(char * C, char * N, float R, Developer * D, float P=0) {
    code = new char[strlen(C) + 1];
    strcpy (code, C);
    name = new char[strlen(N) + 1];
    strcpy (name, N);
    required = R;
    dev = D;
    price = P;
}

void App::setName(char *N) {
    delete name;
    name = new char[strlen(N) + 1];
    strcpy (name, N);
}

float App::getPrice() {
    return price;
}

float App::getRateMean() {
    float mean = 0.0;
    vector <Rating>::iterator it;
    for (it = ratings.begin (); it != ratings.end (); it++)
        mean+=it->getStars();
    if (!ratings.empty()) mean /= ratings.size();
    return mean;
}

Developer* App::getDev() {
    return dev;
}

App::~App() {

    delete[] code;
    delete[] name;
}

void App::print(ostream & cha) {
    cerr << "Warning: App::print executed!" <<endl;
}

char *App::getCode() {
    return code;
}

void App::addRate(const Rating& rate) {
    ratings.push_back(rate);
}

void App::setPrice(float P) {
    price = P;
}

App::App(const App &a) {
    code = new char[strlen(a.code) + 1];
    strcpy (code, a.code);
    name = new char[strlen(a.name) + 1];
    strcpy (name, a.name);
    required = a.required;
    dev = a.dev;
    price = a.price;
    ratings = move(a.ratings);
}
