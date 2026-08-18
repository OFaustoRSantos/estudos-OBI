
/*
DAG
 ↓
topological sort
 ↓
DP no DAG
 ↓
interseção das causas
 ↓
eventos inicialmente verdadeiros
 ↓
propagação das implicações
*/
/* - para fazer inclusão e exclusão de conjuntos:
∣A∪B∣=∣A∣+∣B∣−∣A∩B∣
∣A∪B∪C∣=∣A∣+∣B∣+∣C∣−∣A∩B∣−∣A∩C∣−∣B∩C∣+∣A∩B∩C∣

∣A∪B∪C∣=∣A∣+∣B∣+∣C∣−∣A∩B∣−∣A∩C∣−∣B∩C∣+∣A∩B∩C∣

set<int> A = {1, 2, 3, 4};
set<int> B = {3, 4, 5, 6};

set<int> uniao = A;

// coloca em uniao tudo que está em B
for (int x : B) {
    uniao.insert(x);
}

cout << uniao.size() << endl;

*/

// Topological Sort - a linear order of nodes in a directed graph
// Works only on a DAG (Directed Acyclic Graph), meaning the graph has directed edges and zero loops or cycles.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, I, V;
    cin >> E >> I >> V;

    vector<vector<int>> grafo(E);
    vector<vector<int>> predecessores(E);

    vector<int> grauEntrada(E, 0); // literal numero de predecessores de E

    // Lendo as implicações A -> B
    for (int i = 0; i < I; i++) {
        int A, B;
        cin >> A >> B;

        A--;
        B--;

        grafo[A].push_back(B);
        predecessores[B].push_back(A);

        grauEntrada[B]++; 
    }

    
    // 1. Topological Sort

    queue<int> fila;

    // Inserindo os Roots
    for (int i = 0; i < E; i++) {
        if (grauEntrada[i] == 0) {
            fila.push(i);
        }
    }

    vector<int> ordem;

    // Iniciando camada 1, depois camada 2 ...
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        ordem.push_back(u);

        for (int v : grafo[u]) {
            grauEntrada[v]--;

            if (grauEntrada[v] == 0) {
                fila.push(v);
            }
        }
    }

    // certezas[v][x] = 1 se, sabendo que v aconteceu,
    // podemos ter certeza de que x aconteceu.

    vector<vector<char>> certezas(E, vector<char>(E, false));

    // Abordagem interessante: dividir casos

    // 1- Para eventos sem causa:
    // Se uma causa inicial aconteceu, todos os seus descendentes - necessariamente acontecem.

    for (int s : ordem) {

        // se tiver predecessor ignorar
        if (!predecessores[s].empty())
            continue;

        // DFS para descobrir todos os descendentes de s.
        stack<int> pilha;
        pilha.push(s);

        vector<bool> visitado(E, false);
        visitado[s] = true;

        while (!pilha.empty()) {
            int u = pilha.top();
            pilha.pop();

            certezas[s][u] = true;

            for (int v : grafo[u]) {
                if (!visitado[v]) {
                    visitado[v] = true;
                    pilha.push(v);
                }
            }
        }
    }

    // Agora processamos os demais eventos na ordem topológica.
    
    // Para v acontecer, pelo menos UM de seus predecessores
    // precisa ter acontecido.
    
    // Portanto, um evento x só é garantido se estiver nas
    // certezas de TODOS os predecessores.
    

    for (int v : ordem) {

        if (predecessores[v].empty())
            continue; // ja foi contado antes

        // Começamos supondo que x pode ser garantido.
        for (int x = 0; x < E; x++) {

            bool garantido = true;

            // x precisa ser garantido por TODOS os predecessores.
            // muito maneiro
            for (int p : predecessores[v]) {

                if (!certezas[p][x]) {
                    garantido = false;
                    break;
                }
            }

            if (garantido) {
                certezas[v][x] = true;
            }
        }

        // O próprio evento v obviamente aconteceu.
        certezas[v][v] = true;
    }


    // Eventos inicialmente determinados como verdadeiros.

    vector<int> resposta(E, 0);

    for (int i = 0; i < V; i++) {

        int x;
        cin >> x;
        x--;

        // Se x aconteceu, tudo em certezas[x] aconteceu.
        for (int j = 0; j < E; j++) {
            if (certezas[x][j]) {
                resposta[j] = 1;
            }
        }
    }

    // Saída em ordem crescente.
    
    bool primeiro = true;

    for (int i = 0; i < E; i++) {
        if (resposta[i]) {

            if (!primeiro)
                cout << " ";

            cout << i + 1;

            primeiro = false;
        }
    }

    cout << "\n";

    return 0;
}