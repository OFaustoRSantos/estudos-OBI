/*
Algoritmos essenciais nesse docs
*/

/*
1. Simulação / matemática modular
2. DFS
3. BFS
4. Dijkstra
5. Componentes conexos
6. DSU
7. Ordenação + Sweep Line
8. Binary Search
9. Prefix Sum
10. Two Pointers / Sliding Window
11. Monotonic Stack
12. DP básica
*/

// Dijkstra:

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Aresta {
    int destino;
    ll custo;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Aresta>> grafo(N);

    for (int i = 0; i < M; i++) {

        int A, B;
        ll C;

        cin >> A >> B >> C;

        A--;
        B--;

        grafo[A].push_back({B, C});
        grafo[B].push_back({A, C});
    }

    const ll INF = 4e18;

    vector<ll> dist(N, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    dist[0] = 0;

    pq.push({0, 0});

    while (!pq.empty()) {

        auto [distAtual, u] = pq.top();
        pq.pop();

        // Essa entrada ficou velha
        if (distAtual != dist[u])
            continue;

        for (auto aresta : grafo[u]) {

            int v = aresta.destino;
            ll peso = aresta.custo;

            if (dist[u] + peso < dist[v]) {

                dist[v] = dist[u] + peso;

                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[N - 1] << '\n';

    return 0;
}