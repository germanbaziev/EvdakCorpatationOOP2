#include "facade.h"

std::string Facade::read_operation() {
    return file_worker.getTextFile();
}

//void Facade::check_operation(const std::string& ft) { // не создавать каждый раз новый объект
//    json_cheker.check_json(ft);
//}

