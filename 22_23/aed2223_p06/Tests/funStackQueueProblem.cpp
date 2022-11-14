#include "funStackQueueProblem.h"
#include "cell.h"

FunStackQueueProblem::FunStackQueueProblem() {}


//-----------------------------------------------------------------

// TODO
vector<string> FunStackQueueProblem::binaryNumbers(int n) {
    vector<string> res={};
    int cnt;
    for (int i = 1; i <=n ; i++) {
        cnt=i;
        int bin = 0;
        int rem, j = 1;
        while (i!=0) {
            rem = i % 2;
            i /= 2;
            bin += rem * j;
            j *= 10;
        }
        i=cnt;
        res.push_back(to_string(bin));
    }
    return res;
}

//TODO
vector<int> FunStackQueueProblem::calculateSpan(vector<int> prices)
{
    vector<int> res;
    int cnt=1;
    stack<int> s;
    stack<int> copy;
    for (int i = 0; i < prices.size(); i++) {
        cnt=1;
        copy=s;
        if(s.empty()){
            res.push_back(1);
            s.push(prices[i]);
            continue;
        }
        while(prices[i] > copy.top() && !copy.empty()){
            cnt++;
            copy.pop();
        }
        res.push_back(cnt);
        s.push(prices[i]);
    }

    return res;
}


//TODO
int FunStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}






