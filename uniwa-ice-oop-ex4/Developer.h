#ifndef EX4_DEVELOPER_H
#define EX4_DEVELOPER_H
#include <iostream>

using namespace std;
class Developer {
    char* code;
    char* name;
    char* email;
public:
    Developer(const char*,const char*,const char*);
    Developer(const Developer&);
    void print(ostream &);

    char *getCode() const;

    virtual ~Developer();

    void setName(char *name);

    void setEmail(char *email);
};


#endif //EX4_DEVELOPER_H
