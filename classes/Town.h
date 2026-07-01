#ifndef _H_TOWN
#define _H_TOWN
#include "Settlement.h"
using namespace std;

class Town : public Settlement
{
private:
    bool community;

public:
    Town(string name, int population, bool community);
    string getType() const override;
    void printInfo() const override;
};

#endif
