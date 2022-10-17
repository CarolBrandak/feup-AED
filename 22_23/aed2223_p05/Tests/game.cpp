#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//-----------------------------------------------------------------

// TODO
Kid Game::loseGame(string phrase) {
    int words= numberOfWords(phrase);
    int index=0;
    while(kids.size()>1) {
        index = (words - 1 + index) % kids.size();
        list<Kid>::iterator it;
        it = kids.begin();
        for (int i = 0; i < index; i++) {
            it++;
        }
        kids.remove(*it);
    }
    return kids.front();
}


// TODO
list<Kid> Game::rearrange() {
    list<Kid> queueBoys;
    list<Kid> queueGirls;
    list<Kid> final;
    list<Kid> result;
    for(auto kid:kids){
        if(kid.getSex()=='m')
            queueBoys.push_back(kid);
        else
            queueGirls.push_back(kid);
    }
    int n=queueGirls.size();
    int m=queueBoys.size();
    int d=m/n;
    int f=n/m;
    if(n<m){
        while(m>0 && n>0){
            final.push_back(queueGirls.front());
            queueGirls.pop_front();
            n--;
            for(int i=0; i<d; i++){
                final.push_back(queueBoys.front());
                queueBoys.pop_front();
                m--;
            }
        }
    }else{
        while(m>0 && n>0){
            for(int i=0; i<f; i++){
                final.push_back(queueGirls.front());
                queueGirls.pop_front();
                n--;
            }
            final.push_back(queueBoys.front());
            queueBoys.pop_front();
            m--;
        }
    }
    kids=final;
    while(queueBoys.size()>0){
        result.push_back(queueBoys.front());
        queueBoys.pop_front();
    }
    while(queueGirls.size()>0){
        result.push_back(queueGirls.front());
        queueGirls.pop_front();
    }
    return result;
}


// TODO
list<Kid> Game::shuffle() const {
    list<Kid> result = {}, k = kids;
    int index;
    while (k.size()) {
        index = rand() % k.size(); // random index in [0..k.size()]
        int i = 0;
        for (auto kid : k) {
            if (i == index) {
                result.push_back(kid);
                k.remove(kid);
                break;
            }
            i++;
        }
    }
    return result;
}
