#include "funListProblem.h"
#include <algorithm>

FunListProblem::FunListProblem() {}


//-----------------------------------------------------------------

// TODO
list<int> FunListProblem::removeHigher(list<int> &values, int x) {
    list<int> l1;
    for (auto itr = values.begin(); itr != values.end(); itr++) {
        if(*itr > x){
            l1.push_back(*itr);
            itr = values.erase(itr);
            itr--;
        }
    }
    return l1;
}

//TODO
list<pair<int,int>> FunListProblem::overlappingIntervals(list<pair<int,int>> values) {
    list<pair<int,int>> res;

    return res;
}
