/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double res;
    for (auto x:accounts) {
        if(x->getCodH()==cod1)
            res+=x->getWithdraw();
    }
	return res;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res;
    for (auto it = bankOfficers.begin(); it != bankOfficers.end(); it++) {
        if(it->getName()==name){
            res = it->getAccounts();
            bankOfficers.erase(it);
            break;
        }
    }
	return res;
}

// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();

    for (int i = 0; i < bankOfficers.size(); i++) {
        if(bankOfficers[i].getName()==name){
            bankOfficers[i].addAccount(ac);
            return bankOfficers[i];
        }

    }
    throw NoBankOfficerException(name);
}

bool comp(Account *a1, Account *a2) {
    if(a1->getBalance() == a2->getBalance())
        return a1->getCodIBAN() < a2->getCodIBAN();
    return a1->getBalance() < a2->getBalance();
}

// a alterar
void Bank::sortAccounts() {
    std::sort(accounts.begin(), accounts.end(), comp);
}

