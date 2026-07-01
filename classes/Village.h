#ifndef _H_VILLAGE
#define _H_VILLAGE
#include "Settlement.h"
using namespace std;

class Village : public Settlement
{
public:
    Village(string name, int population);
    string getType() const override;
    void printInfo() const;
};

#endif
