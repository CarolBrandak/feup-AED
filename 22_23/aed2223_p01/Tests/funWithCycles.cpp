// AED 2022/2023 - Aula Pratica 01
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 18/09/2022]

#include "funWithCycles.h"

// ----------------------------------------------------------
// Exercicio 1: Palindromos
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    unsigned length = s.size();
    for (unsigned i = 0; i < length/2; i++)
        if (s[i] != s[length-i-1])
            return false;
    return true;
}

// ----------------------------------------------------------
// Exercicio 2: Frases Palindromo
// ----------------------------------------------------------
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    std::string new_s;
    for(int i=0; s[i]; i++){
        if(isalpha(s[i]))
            new_s += tolower(s[i]);
    }
    return palindrome(new_s);
}

// ----------------------------------------------------------
// Exercicio 3: Numeros Interessantes
// ----------------------------------------------------------
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n++;
    while (digitSum(n)!=sum){
        n++;
    }
    return n;
}

// Esta funcao auxiliar devera devolver a soma dos digitos de n
// TODO
int FunWithCycles::digitSum(int n) {
    int resto, resultado, soma = 0;
    resultado = n;
    while (resultado != 0)
    {
        resto = resultado % 10;
        resultado = resultado / 10;
        soma += resto;
    }
    return soma;
}

// ----------------------------------------------------------
// Exercicio 4: O Inverno esta a chegar
// ----------------------------------------------------------
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    std::vector<int> new_v;
    for (int i = 0; i < v.size()-1; i++) {
        new_v.push_back(v[i+1]-v[i]);
    }

    int cont=0, max=0;
    for (int i = 0; i < new_v.size(); i++) {
        if(new_v[i]<0){
            cont++;
            if(cont>max)
                max=cont;
        }else{
            cont=0;
        }
    }
    return max;
}


// ----------------------------------------------------------
// Exercicio 5: Brincando com vectores
// ----------------------------------------------------------

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int cnt=0;
    for (int i = 0; i < v.size(); i++) {
        if(v[i]==n)
            cnt++;
    }
    return cnt;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = i+1; j < v.size(); j++) {
            if(v[i]==v[j])
                return true;
        }
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = i+1; j < v.size(); j++) {
            if(v[i]==v[j]){
                v.erase(v.begin()+j);
                j--;
            }
        }
    }
}

// d) merge
// TODO
#include <algorithm>
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    for (int i = 0; i < v1.size(); i++) {
        ans.push_back(v1[i]);
    }
    for (int i = 0; i < v2.size(); i++) {
        ans.push_back(v2[i]);
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}

// ----------------------------------------------------------
// Exercicio 6: Brincando com numeros primos
// ----------------------------------------------------------

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    int cnt=0;
    for (int i = 2; i <= n/2; i++) {
        if(n%i==0) {
            cnt++;
        }
    }
    if(cnt==0) return true;
    return false;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    vector<int> ans;
    if(isPrime(n)) ans.push_back(n);
    else{
        for (int i = 2; i <= n/2; i++) {
            if( n%i==0 && (i%2!=0 || i==2) && isPrime(i)) {
                ans.push_back(i);

            }
        }
    }

    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}


// ----------------------------------------------------------
// Exercicio 7: Numeros interessantes (versao desafio)
// ----------------------------------------------------------
// TODO
long long FunWithCycles::fastNextInterestingNumber(long long n, int sum) {
    return 0;
}

