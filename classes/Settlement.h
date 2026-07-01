#ifndef _H_SETTLEMENT
#define _H_SETTLEMENT
#include <string>
#include <iostream>
using namespace std;

class Settlement
{
protected:
    string name;
    int population;

public:
    Settlement(string name, int population);
    virtual ~Settlement();

    string getName() const;
    int getPopulation() const;

    virtual string getType() const = 0;

    virtual void printInfo() const;

    friend ostream &operator<<(ostream &os, const Settlement &s);
};

#endif
