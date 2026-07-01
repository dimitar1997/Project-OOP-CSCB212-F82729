#ifndef _H_VOTE
#define _H_VOTE
#include "Contribution.h"
using namespace std;

class Vote : public Contribution
{
public:
    explicit Vote(string personName);

    void applyTo(Event &event) const override;
    string description() const override;
};

#endif
