#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include <memory>
#include "logic.h"


class Facade {
private:
     WorkWithFile file_worker; // памагииииииитее нужно хранить имя файла только тута не в главном окне точка аш
//    Json_checker json_cheker;
public:
    Facade(WorkWithFile file):file_worker(file){};
    ~Facade(){};
    std::string fp;
    std::string read_operation();
    void check_operation(const std::string& ft);
};

#endif // FACADE_H
