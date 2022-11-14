#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}

// ---------------------------------------------
bool WordMean::operator == (const WordMean& wm2) const{
    return getWord()==wm2.getWord();
}

//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    return getWord()<wm2.getWord();
}


//TODO
void Dictionary::readFile(ifstream &f) {
    string word;
    string meaning;
    while(!f.eof()){
        getline(f,word);
        getline(f,meaning);
        WordMean found = *words.find(WordMean(word, meaning));
        if(found==WordMean("",""))
            words.insert(WordMean(word,meaning));
    }
}

//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    WordMean findMean(w1, "");
    auto it = words.begin();
    while (it != words.end()){
        if((*it)==findMean)
            return (*it).getMeaning();
        else {
            if(it==words.begin())
                previous = (*it);
            else
                previous=next;
            it++;
            next=(*it);
            if(findMean<next)
                break;
        }
    }
    return "word not found";
}

//TODO
bool Dictionary::update(string w1, string m1) {
    auto it=words.begin();
    while(it!=words.end()){
        if (it->getWord() == w1){
            words.erase(it);
            words.insert(WordMean(w1, m1));
            return true;
        }
        it++;
    }
    words.insert(WordMean(w1,m1));
    return false;
}

//TODO
void Dictionary::print() const {
    auto itr=words.begin();
    while(itr!=words.end()){
        cout << itr->getWord() << endl;
        cout << itr->getMeaning() << endl;
        itr++;
    }
}
