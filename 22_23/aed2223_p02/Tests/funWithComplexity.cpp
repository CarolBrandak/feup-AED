// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> & v) {
    unsigned n = v.size();
    int maxSoFar = v[0]; // porque é esta uma boa escolha para a melhor soma inicial?
    for (unsigned i=0; i<n; i++) // todas as posicoes iniciais possiveis
        for (unsigned j=i; j<n; j++) { // todas as posicoes finais possiveis
            int sum = 0;
            for (unsigned k=i; k<=j; k++) // calcular soma entre posicoes i e j
                sum += v[k];

            // neste momento sum é a soma dos elementos no intervalo [i,j]
            if (sum > maxSoFar) maxSoFar = sum;
        }
    return maxSoFar;
}


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    return 0;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}