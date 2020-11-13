#ifndef EX4_RATING_H
#define EX4_RATING_H
#include <iostream>

using namespace std;
class Rating {
    short stars;
    string rater;
    string comments;
public:
    Rating(short,string,string);
    Rating(const Rating &);
    short getStars();
    void print(ostream &);

    void setComments(const string &comments);

    void setStars(short stars);

    virtual ~Rating();
};


#endif //EX4_RATING_H
