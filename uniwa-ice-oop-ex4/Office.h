#ifndef EX4_OFFICE_H
#define EX4_OFFICE_H

#include <string>
#include "Developer.h"
#include "Rating.h"
#include "App.h"

using namespace std;
class Office: public App {
    vector<string> types;
public:
    Office(vector<string>, char*, char*, float, Developer*, float);
    Office(vector<string>, char*, char*, float, Developer*);
    void print(ostream &) override;
};


#endif //EX4_OFFICE_H
