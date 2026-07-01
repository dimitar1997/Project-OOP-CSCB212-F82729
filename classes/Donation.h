#ifndef _H_DONATION
#define _H_DONATION
#include "Contribution.h"
using namespace std;

class Donation : public Contribution
{
private:
    double amount;

public:
    Donation(string personName, double amount);

    void applyTo(Event &event) const override;
    string description() const override;

    double getAmount() const;
};

#endif
