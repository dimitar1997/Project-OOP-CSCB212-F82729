#include "Vote.h"
#include "Event.h"
using namespace std;

Vote::Vote(string personName)
    : Contribution(personName) {}

void Vote::applyTo(Event& event) const {
    event.addPoints(1);
}

string Vote::description() const {
    return personName + " voted";
}
