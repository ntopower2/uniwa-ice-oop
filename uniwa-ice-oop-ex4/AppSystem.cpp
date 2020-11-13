#include "AppSystem.h"
#include "Exceptions.h"

#define CERR if (cerr_disabled) {} else std::cerr
bool cerr_disabled = false;

void AppSystem::AddApp(const shared_ptr<App>& app) {
    apps.emplace_back(app);
    code2App.insert({app->getCode(),app});
}

void AppSystem::AddDev(const char * c, const char *n, const char *e) {
    auto dev = new Developer(c,n,e);
    developers.emplace_back(dev);
    code2Dev.insert({dev->getCode(),dev});
}

void AppSystem::AddRating(const shared_ptr<App>& app, Rating * rate) {
    app->addRate(*rate);
}

void AppSystem::SetPrice(const shared_ptr<App>& app, float P) {
    app->setPrice(P);
}

void AppSystem::SetPrice(char* app, float P) {
    try {
        auto app_ptr = getAppFromCode(app);
        app_ptr->setPrice(P);
    }
    catch (NonExistentApp& nea) {
        CERR << nea.app <<" - Non existent app code!\n";
    }
}

void AppSystem::SetAppName(const shared_ptr<App>& app, char* N) {
    app->setName(N);
}

void AppSystem::SetDevName(Developer& dev, char* N) {
    dev.setName(N);
}

void AppSystem::SetDevName(char* dev, char* N) {
    try {
        auto dev_ptr = getDevFromCode(dev);
        dev_ptr->setName(N);
    }
    catch (NonExistentDev& ned) {
        CERR << ned.code <<" - Non existent dev code!\n";
    }
}

void AppSystem::SetDevEmail(char* dev, char* E) {
    try {
        auto dev_ptr = getDevFromCode(dev);
        dev_ptr->setName(E);
    }
    catch (NonExistentDev& ned) {
        CERR << ned.code <<" - Non existent dev code!\n";
    }
}

void AppSystem::SetDevEmail(Developer& dev, char* E) {
    dev.setName(E);
}

void AppSystem::SetAppName(char* app, char* N) {
    try {
        auto app_ptr = getAppFromCode(app);
        app_ptr->setName(N);
    }
    catch (NonExistentApp& nea) {
        CERR << nea.app <<" - Non existent app code!\n";
    }
}

void AppSystem::RemoveMalicious(Developer * dev) {
    auto iter = apps.begin();
    while (iter!=apps.end()) {
        auto dev_code = (*iter)->getDev()->getCode();
        if (strcmp(dev_code,dev->getCode())==0)
            iter = apps.erase(iter), code2App.erase(dev_code);
        else ++iter;
    }
}

vector<shared_ptr<Game>> AppSystem::GetGoodGames() {
    vector<shared_ptr<Game>> good_games;
    for (auto app : apps) {
        auto gamep = dynamic_pointer_cast<Game> (app);
        if (gamep && gamep->getRateMean()>4 && !gamep->getPrice())
            good_games.push_back(gamep);
    }
    return good_games;
}

vector<shared_ptr<Office>> AppSystem::GetGoodOffice() {
    vector<shared_ptr<Office>> good_office;
    for (auto app : apps) {
        auto officep = dynamic_pointer_cast<Office> (app);
        if (officep && officep->getRateMean()>4 && !officep->getPrice())
            good_office.push_back(officep);
    }
    return good_office;
}

void AppSystem::print(ostream & cha) {
    for (auto dev:developers) dev->print(cha);
    cha << "\n";
    for (auto app:apps) app->print(cha);
}

void AppSystem::loadFrom(char* filename) {
    ifstream fp(filename);
    string buff;
    if (fp) {
        while (getline(fp,buff)) {
            char type[12];
            sscanf(buff.c_str(),"[%[^]]]",type);
            try {
                if (buff[0]!='[') throw WrongLineForm(buff.c_str());
                if (strcmp(type, "DEV") == 0) {
                    char code[12], name[30], email[40];
                    sscanf(buff.c_str(), "[%[^]]] %[^|]|%[^|]|%s", type, code, name, email);
                    AddDev(code, name, email);
                }
                else if (strcmp(type, "APP_GAME") == 0) {
                    char code[12], name[30], cat[12], dev[12];
                    float required, price;
                    int online;
                    sscanf(buff.c_str(), "[%[^]]] %[^|]|%[^|]|%[^|]|OS >= %g|online:%i|%[^|]|%f $",
                           type, code, name, dev, &required, &online, cat, &price);
                    try {
                        if (price < 0) throw NegativePrice(price);
                        auto dev_code = getDevFromCode(dev);
                        auto game = new Game(online, cat, code, name, required, dev_code);
                        auto gamep = shared_ptr<Game>(game);
                        AddApp(gamep);
                        SetPrice(gamep, price);
                    }
                    catch (NonExistentDev &ned) {
                        CERR << ned.code << " - Non existent dev code!\n";
                    }
                    catch (NegativePrice &np) {
                        CERR << np.price << " - Negative price!\n";
                    }
                }
                else if (strcmp(type, "APP_OFFICE") == 0) {
                    char code[12], name[30], types_str[50], dev[12];
                    float required, price;
                    vector<string> types;
                    sscanf(buff.c_str(), "[%[^]]] %[^|]|%[^|]|%[^|]|OS >= %g|(%[^()])|%f $",
                           type, code, name, dev, &required, types_str, &price);
                    size_t pos = 0;
                    string s(types_str), delim = ",", token;
                    while ((s.find(delim) != string::npos)) {
                        pos = s.find(',');
                        types.emplace_back(s.substr(0, pos));
                        s.erase(0, pos + delim.length());
                    }
                    types.emplace_back(s);
                    try {
                        if (price<0) throw NegativePrice(price);
                        auto dev_code = getDevFromCode(dev);
                        auto office = new Office(types, code, name, required, dev_code);
                        office->setPrice(price);
                        auto offcep = shared_ptr<Office>(office);
                        AddApp(offcep);
                        SetPrice(offcep,price);
                    }
                    catch (NonExistentDev& ned) {
                        CERR << ned.code <<" - Non existent dev code!\n";
                    }
                    catch (NegativePrice& np) {
                        CERR << np.price << " - Negative price!\n";
                    }
                }
                else if (strcmp(type, "RATE") == 0) {
                    char name[30], comm[100], app[12];
                    short stars;
                    sscanf(buff.c_str(), "[%[^]]] app:%[^|]|%[^|]|%[^|]|stars:%hu", type, app, name, comm, &stars);
                    try {
                        if (stars > 5 || stars < 0) throw OutOfRangeException(stars);
                        auto app_code = getAppFromCode(app);
                        auto rate = new Rating(stars, name, comm);
                        AddRating(app_code, rate);
                        delete rate;
                    }
                    catch (OutOfRangeException &oore) {
                        CERR << oore.stars << " - Incorrect number of rating stars!\n";
                    }
                    catch (NonExistentApp& nea) {
                        CERR << nea.app <<" - Non existent app code!\n";
                    }
                }
            }
            catch (WrongLineForm& wlf) {
                CERR << wlf.line << " - Incorrect line form!\n";
            }
        }
        fp.close();
    }
    else CERR << filename << " not found!\n";
}

Developer *AppSystem::getDevFromCode(char* code) {
    if (code2Dev.count(code) == 0) throw NonExistentDev(code);
    return code2Dev[code];
}

shared_ptr<App>AppSystem::getAppFromCode(char *code) {
    if (code2App.count(code) == 0) throw NonExistentApp(code);
    return code2App[code];
}

AppSystem::~AppSystem() {
    for (auto dev:developers) delete(dev);
}