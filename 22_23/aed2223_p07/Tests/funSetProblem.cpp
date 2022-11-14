#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//-----------------------------------------------------------------

// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    pair<int,int> res;
    res.first=0;
    res.second=0;
    for (int i = 0; i < values.size(); i++) {
        for (int j = i+1; j <= values.size(); j++) {
            if(values[i]+values[j]==sum){
                res.first=values[i];
                res.second=values[j];
                return res;
            }
        }
    }
    return res;
}
