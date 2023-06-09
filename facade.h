#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include <memory>
#include "logic.h"


class Facade {
private:
     WorkWithFile* fileWorker; // памагииииииитее нужно хранить имя файла только тута не в главном окне точка аш
     JsonChecker* jsonCheker;
public:
    Facade(WorkWithFile* file = nullptr, JsonChecker* checker = nullptr):fileWorker(file), jsonCheker(checker){};
    ~Facade(){};
    std::string fp;
    std::string read_operation();
    AllInformationsAboutError check_operation();
};

#endif // FACADE_H
