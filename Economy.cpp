#include "Stronghold.h"

Economy::Economy() {
    treasury = 1000;
    tax_rate = 10;
}

void Economy::collect_tax(Population& pop) {
    int tax = (pop.total * tax_rate) / 100;
    treasury += tax;
    cout << "Collected " << tax << " gold from taxes." << endl;
}

void Economy::adjust_inflation() {
    int loss = rand() % 100;
    treasury -= loss;
    cout << "Inflation caused a loss of " << loss << " gold from treasury." << endl;
}
