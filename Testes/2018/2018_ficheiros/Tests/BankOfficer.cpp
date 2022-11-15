/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer() : id(0) {}

void BankOfficer::setName(string nm) {
    name = nm;
}

string BankOfficer::getName() const {
    return name;
}

vector<Account *> BankOfficer::getAccounts() const {
    return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
    myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const {
    return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar
int id_aux = 1;

BankOfficer::BankOfficer(string nm) {
    name = nm;
    id = id_aux;
    id_aux++;
    myAccounts = {};
}

bool BankOfficer::operator>(const BankOfficer &b1) {
    if (myAccounts.size() == b1.myAccounts.size()) {
        return getName() > b1.getName();
    }
    return myAccounts.size() > b1.myAccounts.size();
}



