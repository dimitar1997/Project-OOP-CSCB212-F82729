#ifndef _H_EVENT
#define _H_EVENT
#include <string>
#include "Settlement.h"
using namespace std;

enum class EventStatus
{
    Voting,
    Fundraising,
    Completed
};

class Event
{
private:
    string title;
    Settlement *settlement;
    string month;
    double targetAmount;
    double currentAmount;
    int points;
    EventStatus status;

public:
    Event(string title, Settlement *settlement, string month, double targetAmount);

    string getTitle() const;
    Settlement *getSettlement() const;
    string getMonth() const;
    double getTargetAmount() const;
    double getCurrentAmount() const;
    int getPoints() const;
    EventStatus getStatus() const;

    void addPoints(int amount);
    void addFunds(double amount);

    void markAsFunded();

    void printInfo() const;
};

#endif
