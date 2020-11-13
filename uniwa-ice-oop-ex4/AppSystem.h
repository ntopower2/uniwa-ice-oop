#ifndef EX4_APPSYSTEM_H
#define EX4_APPSYSTEM_H

#include <vector>
#include <cstring>
#include <fstream>
#include <App.h>
#include <Rating.h>
#include <Developer.h>
#include <Game.h>
#include <Office.h>
#include <map>
#include <memory>

struct strcmp2 {
    bool operator()(char const *a, char const *b) const {
        return strcmp(a, b) < 0;
    }
};

using namespace std;
class AppSystem {
    vector<shared_ptr<App>> apps;
    vector<Developer*> developers;
    map<const char*,Developer*,strcmp2> code2Dev;
    map<const char*,shared_ptr<App>,strcmp2> code2App;

public:
    void AddApp(const shared_ptr<App>&);
    void AddDev(const char*,const char*,const char*);
    void AddRating(const shared_ptr<App>&,Rating*);
    void SetPrice(const shared_ptr<App>&,float);
    void SetPrice(char *app, float P);
    void SetAppName(const shared_ptr<App> &app, char *N);
    void SetAppName(char *app, char *N);
    void SetDevName(Developer &dev, char *N);
    void SetDevName(char *dev, char *N);
    Developer* getDevFromCode(char*);
    shared_ptr<App> getAppFromCode(char*);
    void loadFrom(char*);
    void RemoveMalicious(Developer*);
    vector<shared_ptr<Game>> GetGoodGames();
    vector<shared_ptr<Office>> GetGoodOffice();
    virtual ~AppSystem();
    void print(ostream&);

    void SetDevEmail(char *dev, char *E);

    void SetDevEmail(Developer &dev, char *E);
};


#endif //EX4_APPSYSTEM_H
