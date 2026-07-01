#include <iostream>
#include "Platform.h"
#include "Vote.h"
#include "Donation.h"
using namespace std;

int main()
{
    Platform platform;

    platform.loadSettlements("settlements.txt");

    cout << "\nSettlements:\n";
    platform.printSettlements();

    const string MONTH = "2026-06";

    Settlement *skalsko = platform.findSettlement("Skalsko");
    Settlement *treklyano = platform.findSettlement("Treklyano");
    Settlement *zaya = platform.findSettlement("Zaya");

    cout << *zaya << " Get Zaya village with << ";

    Event *e1 = new Event("Remont na chitalishte", skalsko, MONTH, 5000.0);
    Event *e2 = new Event("Nova detska ploshtadka", treklyano, MONTH, 3000.0);
    Event *e3 = new Event("Cheshma v centura", zaya, MONTH, 800.0);

    platform.addEvent(e1);
    platform.addEvent(e2);
    platform.addEvent(e3);

    cout << "\n===== Voting for " << MONTH << " =====\n\n";

    platform.submit(new Vote("Ivan"), e1);
    platform.submit(new Vote("Maria"), e1);
    platform.submit(new Vote("Georgi"), e1);
    platform.submit(new Vote("Petya"), e2);
    platform.submit(new Vote("Stefan"), e3);
    platform.submit(new Vote("Elena"), e3);
    platform.submit(new Vote("Dimo"), e3);
    platform.submit(new Vote("Anna"), e3);

    platform.printAllEvents();

    cout << "\n===== Selecting winner =====\n\n";
    Event *winner = platform.selectMonthlyWinner(MONTH);

    if (winner)
    {
        cout << "Winner: \"" << winner->getTitle()
             << "\" with " << winner->getPoints() << " points\n\n";
    }

    cout << "===== Fundraising =====\n\n";

    platform.submit(new Donation("Ivan", 300.0), winner);
    platform.submit(new Donation("Stefan", 200.0), winner);
    platform.submit(new Donation("Anna", 300.0), winner);

    cout << "\n===== Final status =====\n\n";
    platform.printAllEvents();

    cout << "\n===== History =====\n\n";
    platform.printHistory();

    return 0;
}
