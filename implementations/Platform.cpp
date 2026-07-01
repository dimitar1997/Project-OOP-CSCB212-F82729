#include "Platform.h"
#include "Village.h"
#include "Town.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Platform::Platform() : settlements(nullptr), settlementsCount(0), settlementsCapacity(0),
                       events(nullptr), eventsCount(0), eventsCapacity(0),
                       history(nullptr), historyCount(0), historyCapacity(0) {}

Platform::~Platform()
{

    for (int i = 0; i < settlementsCount; i++)
        delete settlements[i];
    delete[] settlements;

    for (int i = 0; i < eventsCount; i++)
        delete events[i];
    delete[] events;

    for (int i = 0; i < historyCount; i++)
        delete history[i];
    delete[] history;
}

void Platform::loadSettlements(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: cannot open " << filename << "\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        istringstream ss(line);
        string type, name, popStr, community;

        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, popStr, ',');
        getline(ss, community, ',');

        bool isCommunity = (community == "1");
        int population = stoi(popStr);

        Settlement *s = nullptr;
        if (type == VILLAGE)
        {
            s = new Village(name, population);
        }
        else if (type == TOWN)
        {
            s = new Town(name, population, isCommunity);
        }
        else
        {
            continue;
        }

        if (settlementsCount == settlementsCapacity)
        {
            int newCapacity = (settlementsCapacity == 0) ? 4 : settlementsCapacity * 2;
            Settlement **newArr = new Settlement *[newCapacity];
            for (int i = 0; i < settlementsCount; i++)
                newArr[i] = settlements[i];
            delete[] settlements;
            settlements = newArr;
            settlementsCapacity = newCapacity;
        }

        settlements[settlementsCount++] = s;
    }

    file.close();
    cout << "Loaded " << settlementsCount << " settlements from " << filename << "\n";
}

Settlement *Platform::findSettlement(const string &name) const
{
    for (int i = 0; i < settlementsCount; i++)
    {
        if (settlements[i]->getName() == name)
            return settlements[i];
    }
    return nullptr;
}

void Platform::addEvent(Event *event)
{
    if (eventsCount == eventsCapacity)
    {
        int newCapacity = (eventsCapacity == 0) ? 4 : eventsCapacity * 2;
        Event **newArr = new Event *[newCapacity];
        for (int i = 0; i < eventsCount; i++)
            newArr[i] = events[i];
        delete[] events;
        events = newArr;
        eventsCapacity = newCapacity;
    }

    events[eventsCount++] = event;
}

void Platform::submit(Contribution *contribution, Event *event)
{

    contribution->applyTo(*event);

    if (historyCount == historyCapacity)
    {
        int newCapacity = (historyCapacity == 0) ? 4 : historyCapacity * 2;
        Contribution **newArr = new Contribution *[newCapacity];
        for (int i = 0; i < historyCount; i++)
            newArr[i] = history[i];
        delete[] history;
        history = newArr;
        historyCapacity = newCapacity;
    }

    history[historyCount++] = contribution;
}

Event *Platform::selectMonthlyWinner(const string &month)
{
    Event *winner = nullptr;

    for (int i = 0; i < eventsCount; i++)
    {
        Event *e = events[i];
        if (e->getMonth() != month)
            continue;
        if (e->getStatus() != EventStatus::Voting)
            continue;

        if (winner == nullptr || e->getPoints() > winner->getPoints())
        {
            winner = e;
        }
    }

    if (winner != nullptr)
    {
        winner->markAsFunded();

        ofstream file("winners.txt", ios::app);

        if (file.is_open())
        {
            file << month << ","
                 << winner->getTitle() << ","
                 << winner->getSettlement()->getName() << ","
                 << winner->getPoints() << ","
                 << winner->getTargetAmount() << "\n";
            file.close();
            cout << "(saved to winners.txt)\n";
        }
    }

    return winner;
}

void Platform::printSettlements() const
{
    for (int i = 0; i < settlementsCount; i++)
    {
        settlements[i]->printInfo();
    }
}

void Platform::printAllEvents() const
{
    for (int i = 0; i < eventsCount; i++)
    {
        events[i]->printInfo();
    }
}

void Platform::printHistory() const
{
    for (int i = 0; i < historyCount; i++)
    {
        cout << "   - " << history[i]->description() << "\n";
    }
}
