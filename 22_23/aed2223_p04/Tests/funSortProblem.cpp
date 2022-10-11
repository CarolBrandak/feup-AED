#include "funSortProblem.h"
#include <algorithm>
#include <limits.h>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if(products.size()>k) {
        for (int i = 0; i < products.size(); i++) {
            int min = i;
            for (int j = i + 1; j < products.size(); j++) {
                if (products[j] < products[min]) {
                    min = j;
                }
                swap(products[i], products[min]);
            }
        }
        products.erase(products.begin() + k, products.end());
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size()<nc) return -1;
    else{
        vector<unsigned> v=values;

        for (int i = 0; i < v.size(); i++) {
            int min = i;
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] < v[min]) {
                    min = j;
                }

            }
            swap(v[i], v[min]);
        }

        int minDiff= INT_MAX, currentDiff;
        for(int i=0; i<v.size()-nc+1; i++){
            currentDiff= v[i+nc-1]-v[i];
            if(currentDiff < minDiff){
                minDiff=currentDiff;
            }
        }
        return minDiff;
    }
}

// TODO

bool key(pair<float,char> &p1, pair<float,char> &p2){
    return p1.first<p2.first;
}

bool exist(vector<char> l){
    for(auto i: l){
        if (i!='V')
            return true;
    }
    return false;
}

void generateTrain(vector<char> &l){
    char che='A';
    for(auto & h:l){
        if(h==che){
            h='V';
            if(che=='A')
                che='D';
            else
                che='A';
        }
    }
}
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    char che='A';
    char par='D';
    int p=0;
    vector<pair<float,char>> order={};
    if(arrival.size()!=0 || departure.size()!=0){
        for(auto time:arrival){
            order.push_back(pair<float,char>(time,che));
        }
        for(auto time:departure){
            order.push_back(pair<float,char>(time,par));
        }
        sort(order.begin(),order.end(),key);

        vector<char> l={};
        for(auto i:order){
            l.push_back(i.second);
        }
        while(exist(l)){
            generateTrain(l);
            p++;
        }
    }

    return p;
}

//TODO
template <class Comparable>
void insertionSortCnt(vector<Comparable> &v, unsigned & cnt) {
    for (unsigned p = 1; p < v.size(); p++) {
        Comparable tmp = v[p];
        unsigned j;
        for (j = p; j > 0 && tmp < v[j-1]; j--) {
            v[j] = v[j - 1];
            cnt++;
        }
        v[j] = tmp;
    }
}

unsigned FunSortProblem::numInversions(vector <int> v) {
    unsigned a = 0;
    insertionSortCnt(v, a);
    return a;
}

// TODO
bool NBKey (const Piece &p1, const Piece &p2) {
    return p1.getDiameter() < p2.getDiameter();
}

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    sort(nuts.begin(), nuts.end(), NBKey);
    sort(bolts.begin(), bolts.end(), NBKey);
}

