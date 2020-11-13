#include "Rating.h"
#include <cstring>
#include <utility>

Rating::Rating(short R,std::string N,std::string C) {
    stars = R;
    rater = std::move(N);
    comments = std::move(C);
}

short Rating::getStars() {
    return stars;
}

Rating::~Rating()  {
    //cout << "Destruction " << rater <<"\n";
}

void Rating::print(std::ostream &cha) {
    cha << rater << "|" << comments << "|stars:" << stars << std::endl;
}

Rating::Rating(const Rating &r) {
    stars = r.stars;
    rater = r.rater;
    comments = r.comments;
}

void Rating::setComments(const string &comments) {
    Rating::comments = comments;
}

void Rating::setStars(short stars) {
    Rating::stars = stars;
}

