

/*
Para uma matriz ser super-legal, basta que todo quadrado 2×2 adjacente satisfaça essa condição.

OK[i][j] = 1
se
A[i][j] + A[i+1][j+1]
<=
A[i][j+1] + A[i+1][j]

*/

// Muito legal pois envolve tanto a formação da matrix, mas também a ideia de Largest Rectangle in a Binary Matrix

#include <bits/stdc++.h>
using namespace std;

// Retorna a maior área de um retângulo formado por 1s em um histograma.
// Usa Monotonic Stack.
// Complexidade: O(C)

int maiorRetangulo(vector<int>& h) {

    h.push_back(0);

    stack<int> pilha;

    int melhor = 0;

    for (int i = 0; i < (int)h.size(); i++) {

        while (!pilha.empty() &&
               h[pilha.top()] > h[i]) {

            int altura = h[pilha.top()];
            pilha.pop();

            int largura;

            if (pilha.empty()) {
                largura = i;
            }
            else {
                largura = i - pilha.top() - 1;
            }

            melhor = max(melhor, altura * largura);
        }

        pilha.push(i);
    }

    h.pop_back();

    return melhor;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    cin >> L >> C;

    vector<vector<long long>> A(
        L,
        vector<long long>(C)
    );

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
        }
    }

    
    // heights[j] = quantidade de quadrados 2x2 válidos
    // consecutivos acima da posição atual.
    //
    // A matriz OK tem:
    // (L-1) linhas
    // (C-1) colunas

    vector<int> heights(C - 1, 0);

    int resposta = 0;

    for (int i = 0; i < L - 1; i++) {

        for (int j = 0; j < C - 1; j++) {

            bool ok =
                A[i][j] + A[i + 1][j + 1]
                <=
                A[i][j + 1] + A[i + 1][j];

            if (ok) {
                heights[j]++;
                // In perfect world this can even be L-1.
            }
            else {
                heights[j] = 0;
            }
        }

        // Encontramos o maior retângulo de 1s nessa linha.

        vector<int> copia = heights;

        int areaOK = maiorRetangulo(copia);

        // Se temos h x w quadrados 2x2 válidos,
        // a submatriz original possui:
        // (h+1) x (w+1) elementos.
        
        // Precisamos recuperar h e w.
        // Para isso, fazemos novamente o cálculo abaixo
        // diretamente usando a stack.

        stack<int> pilha;

        for (int j = 0; j <= C - 1; j++) {

            int atual;

            if (j == C - 1)
                atual = 0;
            else
                atual = heights[j];

            while (!pilha.empty() &&
                   heights[pilha.top()] > atual) {

                int h = heights[pilha.top()];
                pilha.pop();

                int w;

                if (pilha.empty())
                    w = j;
                else
                    w = j - pilha.top() - 1;

                int areaOriginal =
                    (h + 1) * (w + 1);

                resposta = max(resposta, areaOriginal);
            }

            if (j < C - 1)
                pilha.push(j);
        }
    }

    cout << resposta << "\n";

    return 0;
}