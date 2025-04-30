#include "Stronghold.h"

void save_game(Population& pop, Army& army, Leadership& lead, Economy& eco, Bank& bank, Resource& res) {
    ofstream fout("game_save.txt");
    fout << pop.total << " " << pop.happiness << endl;
    fout << army.soldiers << " " << army.morale << endl;
    fout << lead.leader_name << " " << lead.popularity << endl;
    fout << eco.treasury << " " << eco.tax_rate << endl;
    fout << bank.loan_amount << " " << bank.interest_rate << endl;
    fout << res.food << " " << res.wood << " " << res.stone << " " << res.iron << endl;
    fout.close();
}

void load_game(Population& pop, Army& army, Leadership& lead, Economy& eco, Bank& bank, Resource& res) {
    ifstream fin("game_save.txt");
    if (!fin) {
        cout << "No previous save found. Starting new game." << endl;
        return;
    }
    fin >> pop.total >> pop.happiness;
    fin >> army.soldiers >> army.morale;
    fin >> lead.leader_name >> lead.popularity;
    fin >> eco.treasury >> eco.tax_rate;
    fin >> bank.loan_amount >> bank.interest_rate;
    fin >> res.food >> res.wood >> res.stone >> res.iron;
    fin.close();
}
