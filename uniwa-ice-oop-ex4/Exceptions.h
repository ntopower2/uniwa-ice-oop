#ifndef PROJECT_EXCEPTIONS_H
#define PROJECT_EXCEPTIONS_H


class WrongLineForm {
public:
    const char* line;
    explicit WrongLineForm(const char* line): line(line) {}
};

class OutOfRangeException {
public:
    short stars;
    explicit OutOfRangeException(short stars) : stars(stars) {}
};

class NonExistentDev {
public:
    char* code;
    explicit NonExistentDev(char *code) : code(code) {}
};

class NonExistentApp {
public:
    char* app;
    explicit NonExistentApp(char *app) : app(app) {}
};

class NegativePrice {
public:
    float price;
    explicit NegativePrice(float price) : price(price) {}
};

#endif //PROJECT_EXCEPTIONS_H
