#include "Game.h"
#include <cstring>


Game::Game(bool O, char * CAT,
           char * C, char * N, float R, Developer * D, float P):
        App(C, N, R, D, P) {
    online = O;
    category = new char[strlen(CAT) + 1];
    strcpy (category, CAT);
}

Game::Game(bool O, char * CAT,
           char * C, char * N, float R, Developer * D):
        App(C, N, R, D,0) {
    online = O;
    category = new char[strlen(CAT) + 1];
    strcpy (category, CAT);
}

Game::~Game() {
    delete[] category;
}

void Game::print(ostream &cha) {
    cha << "[APP_GAME] ";
    cha << code << "|";
    cha << name << "|";
    cha << dev->getCode() << "|";
    cha << "OS >= " << required << "|online:" << online << "|";
    cha << category<< "|" << price << " $"<< endl;
    for (auto rate:ratings) cha << "[RATE] app:"<< code << "|",rate.print(cha);
    //cha << "----------------------------------------------------" << std::endl;
}
