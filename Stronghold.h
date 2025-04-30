#ifndef STRONGHOLD_H
#define STRONGHOLD_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Population {
public:
    int total;
    int happiness;

    Population();
    void grow();
    void shrink();
    void check_revolt();
};

class Army {
public:
    int soldiers;
    int morale;

    Army();
    void recruit(Population& pop);
    void feed();
    void pay();
};

class Leadership {
public:
    string leader_name;
    int popularity;

    Leadership();
    void change_leader();
};

class Economy {
public:
    int treasury;
    int tax_rate;

    Economy();
    void collect_tax(Population& pop);
    void adjust_inflation();
};

class Bank {
public:
    int loan_amount;
    int interest_rate;

    Bank();
    void take_loan(Economy& eco);
    void repay_loan(Economy& eco);
};

class Resource {
public:
    int food;
    int wood;
    int stone;
    int iron;

    Resource();
    void gather();
};

class Event {
public:
    Event();
    void random_disaster(Population& pop, Army& army, Resource& res, Economy& eco);
};

void save_game(Population& pop, Army& army, Leadership& lead, Economy& eco, Bank& bank, Resource& res);
void load_game(Population& pop, Army& army, Leadership& lead, Economy& eco, Bank& bank, Resource& res);

#endif
#pragma once
