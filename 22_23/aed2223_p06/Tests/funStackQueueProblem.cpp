#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

// TODO
vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    vector<string> res={};
    //queue< string> q;
    //q.push("1");

    for (int i = 1; i <=n ; i++) {
        int t=0;
        t=i%2;
        i=i/2;
        //q.push(to_string(i));
        //string s1 = q.front();
        res.push_back(to_string(t));
    }
    return res;
}

//TODO
vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices)
{
    vector<int> res;

    return res;
}


//TODO
int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}






