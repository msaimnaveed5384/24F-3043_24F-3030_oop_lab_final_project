#include "Stronghold.h"

Population::Population() {
    total = 100;
    happiness = 70;
}

void Population::grow() {
    int increase = rand() % 20 + 5;
    total += increase;
    happiness += 2;
    cout << "Population grew by " << increase << " people." << endl;
}

void Population::shrink() {
    int decrease = rand() % 15 + 5;
    total -= decrease;
    if (total < 0) total = 0;
    happiness -= 5;
    cout << "Population shrank by " << decrease << " people." << endl;
}

void Population::check_revolt() {
    if (happiness < 30) {
        cout << "Warning: People are unhappy and may revolt!" << endl;
    }
}
