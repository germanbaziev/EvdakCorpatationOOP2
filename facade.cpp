#include "facade.h"
#include "logic.h"

std::string Facade::read_operation() {
    return fileWorker->getTextFile();
}

int Facade::check_operation() { // не создавать каждый раз новый объект
    return jsonCheker->fullChecker();

}

