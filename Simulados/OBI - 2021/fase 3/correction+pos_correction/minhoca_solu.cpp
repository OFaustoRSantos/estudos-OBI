#include <bits/stdc++.h>
using namespace std;

/*
Após review fazendo do zero
*/

pair<int, vector<int>> bfs(int inicio, vector<vector<int>>& adj){
    int n = adj.size(); // numero de vertices na adjacente

    vector<int> dist(n, -1); 

    queue<int> q;
    q.push(inicio);
    dist[inicio] = 0;

    int mais_longe = inicio;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(dist[v] != -1) continue;

            // nn vimos v ainda
            dist[v] = dist[u] + 1;
            q.push(v);

            if(dist[v] > dist[mais_longe]){
                mais_longe = v;
            }
        }
    }

    return {mais_longe, dist};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> adj(N);

    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;

        --a;
        --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1ª BFS: descobrir uma extremidade do diâmetro
    auto [u, dist1] = bfs(0, adj);

    // 2ª BFS: a partir da extremidade
    auto [v, dist2] = bfs(u, adj);

    int D = dist2[v];

    int maneiras = 0;

    for(int x : dist2){
        if(x == D){
            maneiras++;
        }
    }

    cout << D + 1 << '\n';
    cout << maneiras << '\n';
}
