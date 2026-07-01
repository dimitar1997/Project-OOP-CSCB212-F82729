#ifndef _H_PLATFORM
#define _H_PLATFORM
#include <string>
#include "Event.h"
#include "Contribution.h"
using namespace std;

class Platform
{
private:
    Settlement **settlements;
    int settlementsCount;
    int settlementsCapacity;

    Event **events;
    int eventsCount;
    int eventsCapacity;

    Contribution **history;
    int historyCount;
    int historyCapacity;

public:
    Platform();
    ~Platform();

    void loadSettlements(const string &filename);

    Settlement *findSettlement(const string &name) const;

    void addEvent(Event *event);

    void submit(Contribution *contribution, Event *event);

    Event *selectMonthlyWinner(const string &month);

    void printSettlements() const;
    void printAllEvents() const;
    void printHistory() const;
};

#endif
