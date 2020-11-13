#include "Course.h"
#include "Exceptions.h"


Course::Course(char *id1, char *name1) {

        if (strcmp(id1,(char*)"ICE1-",5)) {
            newId = new char[strlen(id1)+1];
            newName = new char[strlen(name1)+1];
            strcpy(newId,id1),strcpy(newName,name1);
        }
        else if (strcmp(id1,(char*)"P1-",3)) {
            oldId = new char[strlen(id1)+1];
            oldName = new char[strlen(name1)+1];
            strcpy(oldId,id1),strcpy(oldName,name1);
        }
        else throw NoCourse(id1,0);
    }

Course::Course(char *id1, char *name1, char *id2, char *name2) {
    newId = new char[strlen(id1)+1];
    newName = new char[strlen(name1)+1];
    strcpy(newId,id1),strcpy(newName,name1);
    oldId = new char[strlen(id2)+1];
    oldName = new char[strlen(name2)+1];
    strcpy(oldId,id2),strcpy(oldName,name2);
}

bool Course::strcmp(const char *a, const char *b, short len) {
    int i=0; bool same = true;
    while (i<len && same) {
        same = (a[i]==b[i]);
        i++;
    }
    return same;
}

Course::~Course() {
    delete[] oldId;
    delete[] oldName;
    delete[] newName;
    delete[] newId;
}

Course::Course(const Course &c) {
    if (c.oldId!= nullptr) {
        oldId = new char[strlen(c.oldId)+1];
        strcpy(oldId,c.oldId);
    }
    if (c.oldName!= nullptr) {
        oldName = new char[strlen(c.oldName)+1];
        strcpy(oldName,c.oldName);
    }
    if (c.newId!= nullptr) {
        newId = new char[strlen(c.newId)+1];
        strcpy(newId,c.newId);
    }
    if (c.newName!= nullptr) {
        newName = new char[strlen(c.newName)+1];
        strcpy(newName,c.newName);
    }

}

ostream &operator<<(ostream &os, const Course &course) {
    os << course.newId << ";" << course.newName << ";" << course.oldId << ";" << course.oldName;
    return os;
}

char* Course::getOldId() {
    return oldId;
}

char* Course::getNewId() {
    return newId;
}
