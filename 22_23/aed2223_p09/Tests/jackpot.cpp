#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}

// -----------------------------------------------------------
// TODO
void Jackpot::addBet(const Bet& b) {
    bets.insert(b);
}

// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
    for (auto i = bets.begin(); i != bets.end(); ++i) {
        for (int j = 0; j < i->getNumbers().size(); ++j) {
            if(num==i->getNumbers()[j])
                count++;
        }
    }
	return count;
}

// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
    unsigned count;
    for (auto i = bets.begin(); i != bets.end(); ++i) {
        count = 0;
        for (int j = 0; j < i->getNumbers().size(); ++j) {
            for (auto it = draw.begin(); it != draw.end(); ++it) {
                if (*it == i->getNumbers()[j])
                    count++;
            }
        }
        if (count >= 3) {
            res.push_back(i->getPlayer());
        }
    }
	return res;
}
