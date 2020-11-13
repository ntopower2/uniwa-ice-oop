
#include "Dashboard.h"

void Dashboard::loadMapping(char * filename)  {

    FILE *fp = fopen(filename,"r");
    if (fp== nullptr) {
        fprintf(stderr,"UnknownFilename;%s\n",filename);
        return;
    }
    char buff[512]; unsigned int row = 0;
    char c1[12], c2[90], c3[12], c4[90];
    auto headerfp = fgets(buff, sizeof(buff),fp); //header
    while (fgets(buff, sizeof(buff),fp)) {
        buff[strcspn(buff,"\r\n")] = 0; row+=1;
        sscanf(buff, "%[^;];%[^;];%[^;];%[^;]",c1,c2,c3,c4);
        try {
            Course temp(c1,c2,c3,c4);
            courses.emplace_back(temp);
        }
        catch (NoCourse& nc) {
            fprintf(stderr,"UnknownCourse;%s;%d\n",nc.course,row);
        }
    }
    for (auto &p:courses)
        oldToNew[p.getOldId()] = p.getNewId(), newToOld[p.getNewId()] = p.getOldId();
    fclose(fp);
}

void Dashboard::loadCourses(char* filename) {

    FILE *fp = fopen(filename,"r");
    if (fp== nullptr) {
        fprintf(stderr,"UnknownFilename;%s\n",filename);
        return;
    }
    char buff[256], c1[12],c2[90]; unsigned int row=0;
    auto headerfp = fgets(buff, sizeof(buff),fp); //header
    while (fgets(buff, sizeof(buff),fp)) {
        buff[strcspn(buff,"\r\n")] = 0; row+=1;
        sscanf(buff, "%[^;];%[^;]",c1,c2);
        try {
            Course temp(c1,c2);
            if (!oldToNew.count(c1) && !newToOld.count(c1))
                courses.emplace_back(temp);
        }

        catch (NoCourse& nc) {
            fprintf(stderr,"UnknownCourse;%s;%d\n",nc.course,row);
        }
    }
    for (auto &p:courses)
        courseMap[(p.getNewId() == nullptr) ? p.getOldId() : p.getNewId()] = &p;
    fclose(fp);
}

void Dashboard::loadStudents(char* filename) {

    FILE *fp = fopen(filename,"r");
    if (fp== nullptr) {
        fprintf(stderr,"UnknownFilename;%s\n",filename);
        return;
    }
    char buff[256];
    char c1[20], c2[40], c3[20];
    auto headerfp = fgets(buff, sizeof(buff),fp); //header
    while (fgets(buff, sizeof(buff),fp)) {
        buff[strcspn(buff,"\r\n")] = 0;
        sscanf(buff, "%[^;];%[^;];%[^;]",c1,c2,c3);
        Student temp(c1,c2,c3);
        students.emplace_back(temp);
    }
    for (auto &p:students) studMap[p.getAM()] = &p;
}

void Dashboard::loadGrades(char * filename) {

    FILE *fp = fopen(filename,"r");
    if (fp== nullptr) {
        fprintf(stderr,"UnknownFilename;%s\n",filename);
        return;
    }
    char buff[256];
    char AM[20], COURSE[12];
    float grade=0.0; int row=0;
    auto headerfp = fgets(buff, sizeof(buff),fp); //header
    while (fgets(buff, sizeof(buff),fp)) {
        buff[strcspn(buff,"\r\n")] = 0;
        sscanf(buff, "%[^;];%[^;];%f", AM, COURSE, &grade); row++;
        try {
            auto stud = studMap[AM];
            if (stud== nullptr) throw NoAM(AM, row);
            auto pos = courseMap.find(COURSE);
            if (pos!=courseMap.end()) stud->addGrade(*pos->second,grade,false);
            else if (oldToNew.count(COURSE)) stud->addGrade(*courseMap[oldToNew[COURSE]], grade,true);
            else throw NoCourse(COURSE, row);
        }
        catch (NoCourse& nc) {
            fprintf(stderr,"UnknownCourse;%s;%d\n",nc.course,nc.row);
        }
        catch (NoAM& na) {
            fprintf(stderr,"UnknownAM;%s;%d\n",na.AM,na.row);
        }
    }
}

void Dashboard::printNotTransferred(ostream &cha) {
    cha << "ал;епымуло;омола;йыдийос мпс;омола мпс;йыдийос ппс;омола ппс;бахлос\n";
    for (auto& student:students) cha << student;
}
