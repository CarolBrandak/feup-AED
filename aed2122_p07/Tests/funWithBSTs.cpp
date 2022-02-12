// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2012]

#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
// TODO
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    set<int> cromos_total;
    for (auto x:collection)
        cromos_total.insert(x);
    int res=cromos_total.size();
    for (auto x: bag)
        cromos_total.insert(x);
    return cromos_total.size()-res;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
// TODO
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    priority_queue<int> deckAlice, deckBruno;
    int A, B;

    for(auto x: alice)
        deckAlice.push(x);
    for(auto x: bruno)
        deckBruno.push(x);

    while( !deckAlice.empty() && !deckBruno.empty()){
        A=deckAlice.top();
        deckAlice.pop();
        B=deckBruno.top();
        deckBruno.pop();
        if(A > B){
            A=A-B;
            deckAlice.push(A);
        }else if(A < B){
            B=B-A;
            deckBruno.push(B);
        }
    }
    return deckAlice.size()-deckBruno.size();
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
// TODO
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    set<string> films;
    for(auto x: reviews)
        films.insert(x.first);
  return films.size();
}

// ..............................
// b) O filme com mais reviews
// TODO
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> m_counter;
    m=0;
    n=0;
    for (auto x: reviews){
        if(m_counter.insert(pair<string, int>(x.first,1)).second== false)
            m_counter[x.first]++;
        if(m<m_counter[x.first])
            m=m_counter[x.first];
    }
    for (auto x : m_counter){
        if (x.second == m) n+=1;
    }
}

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;
    map<string, double> counter;
    map<string, double> total;

    for (auto x : reviews){
        if (!counter.insert(pair<string, double>(x.first, 1.0)).second)
            counter[x.first]++;
        if(!total.insert(pair<string, double>(x.first, x.second)).second)
            total[x.first] = total[x.first] + x.second;
    }

    for (auto x : counter){
        total[x.first] = total[x.first] / counter[x.first];

        if (total[x.first] >= k)
            answer.push_back(x.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
