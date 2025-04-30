#include "Stronghold.h"

int main() {
    Population pop;
    Army army;
    Leadership lead;
    Economy eco;
    Bank bank;
    Resource res;
    Event event;

    load_game(pop, army, lead, eco, bank, res);

    int choice;
    do {
        cout << endl;
        cout << "=== Stronghold Kingdom Management ===" << endl;
        cout << "1. Manage Population" << endl;
        cout << "2. Train Army" << endl;
        cout << "3. Change Leadership" << endl;
        cout << "4. Manage Economy" << endl;
        cout << "5. Use Bank" << endl;
        cout << "6. Collect Resources" << endl;
        cout << "7. Handle Random Event" << endl;
        cout << "8. Show Kingdom Status" << endl;
        cout << "0. Exit Game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            pop.grow();
            pop.check_revolt();
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 2:
            army.recruit(pop);
            army.feed();
            army.pay();
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 3:
            lead.change_leader();
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 4:
            eco.collect_tax(pop);
            eco.adjust_inflation();
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 5:
            cout << "1. Take Loan  2. Repay Loan: ";
            int bank_choice;
            cin >> bank_choice;
            if (bank_choice == 1) bank.take_loan(eco);
            else bank.repay_loan(eco);
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 6:
            res.gather();
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 7:
            event.random_disaster(pop, army, res, eco);
            save_game(pop, army, lead, eco, bank, res);
            break;
        case 8:
            cout << "Leader: " << lead.leader_name << " (Popularity: " << lead.popularity << ")" << endl;
            cout << "Population: " << pop.total << " (Happiness: " << pop.happiness << ")" << endl;
            cout << "Army: " << army.soldiers << " soldiers (Morale: " << army.morale << ")" << endl;
            cout << "Treasury: " << eco.treasury << " gold (Tax Rate: " << eco.tax_rate << "%)" << endl;
            cout << "Loan Amount: " << bank.loan_amount << " gold (Interest Rate: " << bank.interest_rate << "%)" << endl;
            cout << "Resources - Food: " << res.food << ", Wood: " << res.wood << ", Stone: " << res.stone << ", Iron: " << res.iron << endl;
            break;
        case 0:
            cout << "Exiting game. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
