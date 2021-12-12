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

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

//TODO
void Dictionary::readFile(ifstream &f) {
    string word;
    string meaning;
    while(!f.eof()){
        getline(f,word);
        getline(f,meaning);
        WordMean found= words.find(WordMean(word, meaning));
        if(found==WordMean("",""))
            words.insert(WordMean(word,meaning));
    }
}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {

    return "";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}

//TODO
void Dictionary::print() const {
    BSTItrIn<WordMean> itr(words);
    while(!itr.isAtEnd()){
        cout << itr.retrieve().getWord() << endl;
        cout << itr.retrieve().getMeaning() << endl;
        itr.advance();
    }
}

bool WordMean::operator < (const WordMean& lhs) const{
    return getWord()<lhs.getWord();
}

bool WordMean::operator == (const WordMean& lhs) const{
    return getWord()==lhs.getWord();
}
