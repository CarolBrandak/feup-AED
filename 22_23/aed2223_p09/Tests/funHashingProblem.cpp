#include "funHashingProblem.h"
#include <unordered_set>

FunHashingProblem::FunHashingProblem() {}

// -------------------------------------

// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    std::unordered_set<int> seen;
    std::vector<int> duplicates;
    for (int i = 0; i < values.size(); i++) {
        if (i > k) {
            seen.erase(values[i - k - 1]);
        }
        if (seen.count(values[i]) > 0) {
            duplicates.push_back(values[i]);
        }
        seen.insert(values[i]);
    }
    return duplicates;
}