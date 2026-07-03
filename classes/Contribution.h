#ifndef _H_CONTRIBUTION
#define _H_CONTRIBUTION
#include "Event.h"
#include <string>
using namespace std;


class Contribution
{
protected:
    string personName;

public:
    explicit Contribution(string personName);
    virtual ~Contribution();

    virtual void applyTo(Event &event) const = 0;

    virtual string description() const = 0;

    string getPersonName() const;
};

#endif
