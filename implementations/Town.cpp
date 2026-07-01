#include "Town.h"
using namespace std;

Town::Town(string name, int population, bool community)
    : Settlement(name, population), community(community) {}

string Town::getType() const
{
    return "Town";
}

void Town::printInfo() const
{
    Settlement::printInfo();
    cout << "  Community: " << (community ? "yes" : "no") << "\n";
}
