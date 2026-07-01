#include "Event.h"
#include <iostream>
using namespace std;

Event::Event(string title, Settlement* settlement, string month, double targetAmount)
    : title(title), settlement(settlement), month(month),
      targetAmount(targetAmount), currentAmount(0.0), points(0),
      status(EventStatus::Voting) {}

string Event::getTitle() const { return title; }
Settlement* Event::getSettlement() const { return settlement; }
string Event::getMonth() const { return month; }
double Event::getTargetAmount() const { return targetAmount; }
double Event::getCurrentAmount() const { return currentAmount; }
int Event::getPoints() const { return points; }
EventStatus Event::getStatus() const { return status; }

void Event::addPoints(int amount) {
    if (status != EventStatus::Voting) {
        cout << "   (voting for \"" << title << "\" is closed)\n";
        return;
    }
    points += amount;
}

void Event::addFunds(double amount) {
    if (status != EventStatus::Fundraising) {
        cout << "   (\"" << title << "\" is not accepting donations yet)\n";
        return;
    }

    currentAmount += amount;

    if (currentAmount >= targetAmount) {
        status = EventStatus::Completed;
    }
}

void Event::markAsFunded() {
    if (status == EventStatus::Voting) {
        status = EventStatus::Fundraising;
    }
}

void Event::printInfo() const {
    string statusText;
    switch (status) {
        case EventStatus::Voting:      statusText = "voting";      break;
        case EventStatus::Fundraising: statusText = "fundraising"; break;
        case EventStatus::Completed:   statusText = "FUNDED";      break;
    }

    cout << "\"" << title << "\" (" << settlement->getName() << ", " << month << ")\n"
              << "   points: " << points
              << " | status: " << statusText
              << " | funds: " << currentAmount << " / " << targetAmount << " lv.\n";
}
