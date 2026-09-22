#include <bits/stdc++.h>
using namespace std;

/*
    Dona Minhoca - OBI 2021

    Ideia:

    Se adicionarmos uma aresta entre A e B,
    o ciclo criado terá:

        distancia(A, B) + 1

    salas.

    Portanto, precisamos:

    1. Encontrar a maior distância entre dois vértices
       (o DIÂMETRO da árvore).

    2. Contar quantos pares de vértices possuem essa
       distância máxima.

*/


tuple<int, vector<int>, vector<int>>
bfs(int inicio, const vector<vector<int>>& adj) {

    int n = adj.size();

    vector<int> dist(n, -1);
    vector<int> pai(n, -1);

    queue<int> q;

    q.push(inicio);
    dist[inicio] = 0;

    int mais_longe = inicio;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v : adj[u]) {

            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            pai[v] = u;

            q.push(v);

            // Encontramos alguém mais distante
            if (dist[v] > dist[mais_longe]) {
                mais_longe = v;
            }
        }
    }

    return {mais_longe, dist, pai};
}

// Bem de boa o BFS entendido


// Caso que temos dois centros
long long conta_distancia(
    int inicio,
    int bloqueado, // se for D par nenhum, se impar será o outro centro
    int dist_alvo,
    const vector<vector<int>>& adj
) {

    long long quantidade = 0;

    queue<pair<int, int>> q;

    // {vertice, distancia}
    q.push({inicio, 0});

    while (!q.empty()) {

        auto [u, dist] = q.front();
        q.pop();

        // Chegamos exatamente na distância desejada
        if (dist == dist_alvo) {
            quantidade++;
            continue;
        }

        for (int v : adj[u]) {

            // Não podemos atravessar para o outro lado
            if (v == bloqueado)
                continue;

            q.push({v, dist + 1});
        }
    }

    return quantidade;
}


// quando temos um centro definido.

long long conta_ramo(
    int inicio,
    int pai,
    int dist_alvo,
    const vector<vector<int>>& adj
) {

    long long quantidade = 0;

    queue<pair<int, int>> q;

    q.push({inicio, 1});

    while (!q.empty()) {

        auto [u, dist] = q.front();
        q.pop();

        if (dist == dist_alvo) {
            quantidade++;
            continue;
        }

        for (int v : adj[u]) {

            if (v == pai)
                continue;

            q.push({v, dist + 1});

            // nn colocou aqui, mas eu colocaria um early stop se dist+1 < dist_alvo; porém acredito que o if dist < dist_alvo -> continue já serve de early stop
        }
    }

    return quantidade;
}


// duas funções uma para um centro outra para dois centros.

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> adj(N);

    for (int i = 0; i < N - 1; i++) {

        int a, b;
        cin >> a >> b;

        --a;
        --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // encontrando a primeira ponta do diametro

    auto [u, dist1, pai1] = bfs(0, adj);


    // encontramos agora : v e u pontas do diametro 

    auto [v, dist2, pai2] = bfs(u, adj);

    int D = dist2[v]; // conseguimos o diametro

    vector<int> caminho;

    int atual = v;

    while (atual != -1) {

        caminho.push_back(atual);

        if (atual == u)
            break;

        atual = pai2[atual];
    }

    reverse(caminho.begin(), caminho.end()); //criamos um caminho que define o diametro

    // Contando numeros de pares
    long long maneiras = 0;

    // diametro par: logo dois centros
    if (D % 2 == 0) {

        int centro = caminho[D / 2]; // Literalmente elemento do meio

        int metade = D / 2;

        vector<long long> qtd;


        // Cada vizinho do centro representa um ramo.
        for (int vizinho : adj[centro]) {

            long long quantidade =
                conta_ramo(
                    vizinho,
                    centro,
                    metade, // metade diametro
                    adj
                );

            qtd.push_back(quantidade);
        }

        // Fazer um chuveirinho, para pegarmos todas as combinações possíveis. No final se temos 2 ramos, o resultado será a multiplicação deles, pois as distancias não podem estar no mesmo ramo
        for (int i = 0; i < (int)qtd.size(); i++) {

            for (int j = i + 1; j < (int)qtd.size(); j++) {

                maneiras += qtd[i] * qtd[j];
            }
        }
    }

    // temos dois centros:
    else {
        int centro1 = caminho[D / 2];
        int centro2 = caminho[D / 2 + 1];

        int metade = D / 2;

        // possibilidades cada lado
        long long esquerda =
            conta_distancia(
                centro1,
                centro2,
                metade,
                adj
            );

        long long direita =
            conta_distancia(
                centro2,
                centro1,
                metade,
                adj
            );


        // Qualquer escolha da esquerda pode ser combinada com qualquer escolha da direita.
        maneiras = esquerda * direita;
    }

    cout << D + 1 << '\n';
    cout << maneiras << '\n';

    return 0;
}

