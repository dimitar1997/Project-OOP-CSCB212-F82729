#include "Contribution.h"
using namespace std;

Contribution::Contribution(string personName)
    : personName(personName) {}

Contribution::~Contribution() {}

string Contribution::getPersonName() const {
    return personName;
}
