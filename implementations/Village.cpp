#include "Village.h"
using namespace std;

Village::Village(string name, int population)
    : Settlement(name, population) {}

string Village::getType() const {
    return "Village";
}

void Village::printInfo() const {
    Settlement::printInfo();
}
