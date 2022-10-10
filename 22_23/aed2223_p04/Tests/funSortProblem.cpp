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
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}

//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}

// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}

