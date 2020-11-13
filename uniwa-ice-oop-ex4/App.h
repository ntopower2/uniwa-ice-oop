#ifndef EX4_APP_H
#define EX4_APP_H

#include "Rating.h"
#include "Developer.h"
#include <vector>

using namespace std;
class App {
protected:
    char* code;
    char* name;
    float required;
    Developer* dev = nullptr;
    vector<Rating> ratings={};
    float price;
public:
    App(char*, char*, float, Developer*, float);
    App(const App&);
    void setPrice(float price);

    char* getCode();
    float getPrice();
    float getRateMean();
    Developer *getDev();
    void addRate(const Rating&);
    virtual void print(ostream &);
    virtual ~App();

    void setName(char *name);
};

#endif //EX4_APP_H
