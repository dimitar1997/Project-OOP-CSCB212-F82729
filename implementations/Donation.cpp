#include "Donation.h"
#include "Event.h"
using namespace std;

Donation::Donation(string personName, double amount)
    : Contribution(personName), amount(amount) {}

void Donation::applyTo(Event& event) const {
    event.addFunds(amount);
}

string Donation::description() const {
    return personName + " donated " + to_string((int)amount) + " eu.";
}

double Donation::getAmount() const {
    return amount;
}
