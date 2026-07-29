#include <iostream>
#include <vector>
#include <algorithm>

// Super didático, gostei.

using namespace std;

vector<vector<int>> adj;
// memo[no][ultimo_outro_paridade + 1], ou seja. Uma matrix NxN/2xN -> cada indice tem uma lista de numeros com paridade oposta.
// dessa forma é mais eficiente

// Usamos +1 no índice para acomodar o estado inicial -1 (nenhum visitado)
vector<vector<int>> memo;

// u vertice atual, last_other paridade
int DFS(int u, int last_other) {
    int idx_other = last_other + 1;
    // Pq o indice do outro tem que se somar 1?
    // simplesmente para evitar indices negativos
    /*
    O valor da variável last_other pode assumir duas situações:
    - -1: quando nenhum nó da outra paridade foi visitado ainda.
    - 0 a N - 1: o índice do último vértice visitado.
    Como na questão não tem 0, poderia ser 0 no 1° last other evitando esse problema, mas é uma boa estratégia
    */
    
    // Se já calculamos este estado antes, retorna o resultado guardado; -1 é o valor default setado no main
    if (memo[u][idx_other] != -1) {
        return memo[u][idx_other];
    }

    int maior_caminho = 1; // O próprio nó 'u' já conta como tamanho 1

    // Define os limites atuais de paridade - gosto dessa notação
    int last_par = (u % 2 == 0) ? u : last_other;
    // Se true -> u, se falso -> last_other
    int last_impar = (u % 2 != 0) ? u : last_other;

    for (int v : adj[u]) 
    {
        //Essa verificação também impede a volta do vetor.
        if (v % 2 == 0) {
            // Próximo é PAR: precisa ser estritamente maior que o último PAR
            if (v > last_par) {
                // No fim o DFS entrega o numero do maior caminho, mas se aumenta 1 para incluir ele próprio
                maior_caminho = max(maior_caminho, 1 + DFS(v, last_impar));
            
            }
        } else {
            // Próximo é ÍMPAR: precisa ser estritamente maior que o último ÍMPAR
            if (v > last_impar) {
                maior_caminho = max(maior_caminho, 1 + DFS(v, last_par));
            }
        }
    }

    return memo[u][idx_other] = maior_caminho;
}

int main() {
    // simplesmente para acelerar
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    // valor default do memo = -1, muito legal a função assign
    adj.assign(N, vector<int>());
    memo.assign(N, vector<int>(N + 1, -1));

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        
        // Se a entrada do problema for baseada em 1 (vértices de 1 a N),
        // descomente as duas linhas abaixo para ajustar para índice 0:
        // A--; B--;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    for (int i = 0; i < N; i++) {
        // -1 indica que ainda não visitamos nenhum nó da outra paridade
        cout << DFS(i, -1) << " ";
    }
    cout << "\n";

    return 0;
}