
/* Apanhei */

/*
Ideal:
-> Supermercado -> AC
-> Matrix -> AC
*/

/* - Observações:
-> DP no Detetive, mas o estado ficou errado

Maior problema:
reconhecimento → modelagem → escolha do algoritmo → implementação rápida.

*/

// só mexo no topo da pilha do mercado_at


// Diagnóstico problemas:
/*

1 - Supermercado - razão/custo por grama - Muito fácil - 1°
2 - Matriz super-legal	- Monge + maior retângulo	- Média/alta - 2º
3 - Detetive - DAG + DP / interseção de causas - Alta - 3º

*/

// Ideia -> Consigo transformar o enunciado em uma solução simples em ~5 minutos?

/* A estratégia que você deveria ter usado

| Para essa prova especificamente:

0–10 min — leitura

| Ler os três problemas procurando:
- entrada;
- saída;
- restrições;
- palavras-chave;
- ideia provável.

Você fez aproximadamente 16 minutos, o que não é absurdo.

O problema veio depois.

| 10–25 min — Supermercado

Resolver e submeter.

Esse problema praticamente grita:

- “Compare preço por grama.”

A solução é extremamente curta.

> Tirar ultimo e colocar novo para atualizar

| 25–70 min — Matriz

Aqui você investe tempo.

Você provavelmente precisaria descobrir:

- a condição pode ser reduzida a quadrados 2×2;
- isso vira uma matriz de válido/inválido;
- precisamos do maior retângulo sem células inválidas;

isso é Largest Rectangle in Histogram.

Esse problema é muito mais valioso para seu treinamento porque junta vários conceitos.

| 70–115 min — Detetive

Agora você tem ~45 minutos.

É suficiente para pensar com calma no DAG.

| 115–120 min — submissão/check

Sempre deixe alguns minutos.

*/

// Algebrizar coisas de matrix;

/*
- Cada quadrado:
A[i][j]       A[i][j+1]
A[i+1][j]     A[i+1][j+1]

-> Caso condição seja = true, todos os quadrados = true
*/
/*
Matriz original
        ↓
matriz de quadrados válidos
        ↓
maior retângulo formado somente por 1
*/

/*
A solução mental da Matriz

Quando você vir novamente algo como:

“A propriedade precisa valer para todas as submatrizes”

faça esta pergunta:

1. Posso verificar apenas estruturas mínimas?

Aqui:

2×2
2. Essas estruturas viram uma matriz binária?

Sim:

válido / inválido
3. Quero o maior bloco contínuo válido?

Sim.

4. Qual problema clássico é esse?

Largest Rectangle in Histogram.

Essa sequência mental é MUITO importante.
*/

// Problemas do DP / Detetitve

// Se a solução está começando a precisar de 4 flags para explicar o estado, provavelmente você ainda não encontrou a abstração correta.

// Abstração:
/*
certeza[v] -> Set eventos verdadeiros caso v aconteça

certain[v] = {v, x, z}
*/
// logo definimos certeza como:
// Certain[v] = {V} U certain[A] /\ certain[B] /\ certain[C]


// 3 casos:
// 1- Caso sem causas:
// A aconteceu

//Solução detetive

#include <bits/stdc++.h>
using namespace std;

const int MAXE = 1005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, I, V;
    cin >> E >> I >> V;

    vector<vector<int>> adj(E + 1);
    vector<int> indeg(E + 1);

    for (int i = 0; i < I; i++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        indeg[B]++;
        // Numero de casos relacionados a B
    }

    // Topological sort
    queue<int> q;

    for (int i = 1; i <= E; i++) {
        if (indeg[i] == 0)
            q.push(i);

        // Relação de elementos Root. ou seja que não fora acessados.
    }

    vector<int> topo;

    // Dessa forma ele acessa todos os elementos, criando uma ordem de camadas:
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;

            if (indeg[v] == 0)
                q.push(v);
        }
    }

    // Para cada evento, conjunto de eventos
    // que são necessariamente verdadeiros
    // se esse evento for verdadeiro.
    vector<bitset<MAXE>> certain(E + 1);
    // bitset = fixed-seize sequence of bits. highly space-optimized so that each element occupies exactly one bit of memory

    vector<vector<int>> pred(E + 1);

    // Precisamos dos predecessores
    for (int u = 1; u <= E; u++) {
        for (int v : adj[u]) {
            pred[v].push_back(u);
        }
    }

    for (int v : topo) {

        // O próprio evento aconteceu
        certain[v][v] = 1;

        if (pred[v].empty()) {
            continue;
        }

        // Começa com o conjunto da primeira causa
        certain[v] = certain[pred[v][0]];

        // Interseção das outras causas
        for (int i = 1; i < pred[v].size(); i++) {
            certain[v] &= certain[pred[v][i]];
        }

        // O próprio evento também é certamente verdadeiro
        certain[v][v] = 1;
    }

    // Eventos inicialmente conhecidos como verdadeiros
    vector<bool> trueEvent(E + 1, false);

    for (int i = 0; i < V; i++) {
        int x;
        cin >> x;

        trueEvent[x] = true;
    }

    // Tudo que é garantido pelos eventos conhecidos
    for (int x = 1; x <= E; x++) {
        if (trueEvent[x]) {
            for (int v = 1; v <= E; v++) {
                if (certain[x][v])
                    trueEvent[v] = true;
            }
        }
    }

    // Fechamento para frente das implicações
    queue<int> bfs;

    for (int i = 1; i <= E; i++) {
        if (trueEvent[i])
            bfs.push(i);
    }

    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for (int v : adj[u]) {
            if (!trueEvent[v]) {
                trueEvent[v] = true;
                bfs.push(v);
            }
        }
    }

    for (int i = 1; i <= E; i++) {
        if (trueEvent[i])
            cout << i << ' ';
    }

    cout << '\n';

    return 0;
}