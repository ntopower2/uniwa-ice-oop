#ifndef EX4_GAME_H
#define EX4_GAME_H

#include "Rating.h"
#include "Developer.h"
#include "App.h"
#include <iostream>
#include <vector>

using namespace std;
class Game: public App {
    bool online;
    char* category;
public:
    Game(bool, char*, char*, char*, float, Developer*, float);
    Game(bool, char *, char *, char *, float , Developer *);
    void print(ostream &) override;
    virtual ~Game() override;
};


#endif //EX4_GAME_H
