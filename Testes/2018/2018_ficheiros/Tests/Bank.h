/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>

#include "BankOfficer.h"


class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};

template <class T>
unsigned int numberDifferent (const vector<T> & v1){
    if(v1.size()==0)
        return 0;
    vector <T> temp;
    bool e;
    for (int i = 0; i < v1.size(); i++) {
        e=false;
        for (int j = 0; j < temp.size(); ++j) {
            if(v1[i]==temp[j]){
                e=true;
            }
        }
        if(!e)
            temp.push_back(v1[i]);
    }
    return temp.size();
}

class NoBankOfficerException {
    string name;
public:
    NoBankOfficerException(const string &name) {this->name = name;}
    string getName() {return name;}
};

#endif /* SRC_BANK_H_ */
