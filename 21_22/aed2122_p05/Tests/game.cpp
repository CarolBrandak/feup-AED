#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
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

//-----------------------------------------------------------------

//TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

//TODO
list<Kid> Game::getKids() const {
    return kids;
}

//TODO
void Game::setKids(const list<Kid>& l1) {
    this -> kids = l1;
}

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
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> result= {};
    for (auto kid : kids){
        if(kid.getAge()>id){
            kids.remove(kid);
            result.push_back(kid);
        }
    }
    return result;
}

// TODO
queue<Kid> Game::rearrange() {
    queue<Kid> queueBoys;
    queue<Kid> queueGirls;
    list<Kid> final;
    queue<Kid> result;
    for(auto kid:kids){
        if(kid.getSex()=='m')
            queueBoys.push(kid);
        else
            queueGirls.push(kid);
    }
    int n=queueGirls.size();
    int m=queueBoys.size();
    int d=m/n;
    int f=n/m;
    if(n<m){
        while(m>0 && n>0){
            final.push_back(queueGirls.front());
            queueGirls.pop();
            n--;
            for(int i=0; i<d; i++){
                final.push_back(queueBoys.front());
                queueBoys.pop();
                m--;
            }
        }
    }else{
        while(m>0 && n>0){
            for(int i=0; i<f; i++){
                final.push_back(queueGirls.front());
                queueGirls.pop();
                n--;
            }
            final.push_back(queueBoys.front());
            queueBoys.pop();
            m--;
        }
    }
    kids=final;
    while(queueBoys.size()>0){
        result.push(queueBoys.front());
        queueBoys.pop();
    }
    while(queueGirls.size()>0){
        result.push(queueGirls.front());
        queueGirls.pop();
    }
    return result;
}

//TODO
bool Game::operator==(Game& g2) {
	return (this->kids==g2.kids);
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
