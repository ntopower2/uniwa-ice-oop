#include "Office.h"
#include <utility>

Office::Office(vector<string> T,
               char * C, char * N, float R, Developer * D,float P):
        App(C, N, R, D, P) {
   types = move(T);
}

Office::Office(vector<string> T,
               char * C, char * N, float R, Developer * D):
        App(C, N, R, D,0) {
    types = move(T);
}

void Office::print(ostream &cha) {
    cha << "[APP_OFFICE] ";
    cha << code << "|";
    cha << name << "|";
    cha << dev->getCode() << "|";
    cha << "OS >=" << required << "|(";
    vector <string>::iterator it;
    for (it = types.begin (); it != types.end ()-1; it++) cha << (*it) <<",";
    cha << (*it) << ")|"  << price << " $"<<endl;
    for (auto rate:ratings) cha << "[RATE] app:"<< code << "|",rate.print(cha);
    //cha << "----------------------------------------------------" << endl;
}