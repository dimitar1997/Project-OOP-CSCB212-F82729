#include "Settlement.h"
using namespace std;

Settlement::Settlement(string name, int population) : name(name), population(population) {}

Settlement::~Settlement() {}

string Settlement::getName() const { return name; }
int Settlement::getPopulation() const { return population; }

void Settlement::printInfo() const
{

    cout << getType() << ": " << name
         << " (pop: " << population << ")\n";
}

ostream &operator<<(ostream &os, const Settlement &s)
{
    os << s.getType() << " " << s.name << " (pop: " << s.population << ")";
    return os;
}
