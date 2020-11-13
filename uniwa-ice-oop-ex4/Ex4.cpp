#include <iostream>
#include <AppSystem.h>

using namespace std;


int main() {
    AppSystem MadRobot;
    MadRobot.loadFrom((char*)"../uniwa-ice-oop-ex4/input_file");
    //MadRobot.RemoveMalicious(MadRobot.getDevFromCode((char*)"foo2"));
    auto goodg = MadRobot.GetGoodGames();
    auto goodo = MadRobot.GetGoodOffice();
    //for (auto godo:goodg) godo->print(cout);
    MadRobot.print(cout);
}
