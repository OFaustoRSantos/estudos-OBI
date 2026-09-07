#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ponto{int destino; int custo;
    bool operator<(const ponto &other) const{
        if(custo == other.custo){
            return destino < destino;
        }
        return custo < other.custo;
    }
    bool operator>(const ponto &other) const{
        if(custo == other.custo){
            return destino > destino;
        }
        return custo > other.custo;
    }
};

const int INF = 9e10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vector<vector<ponto>> mat_adj;
    mat_adj.assign(N,{});

    // montando grafo;
    for(int i=0; i<M;i++){
        ponto ponto_at;
        int a;
        cin >> a >> ponto_at.destino >> ponto_at.custo;

        mat_adj[a].push_back(ponto_at);
        int tempo = ponto_at.destino; ponto_at.destino = a; 
        mat_adj[tempo].push_back(ponto_at);
    }

    priority_queue<ponto, vector<ponto>, greater<ponto>> pq;

    ponto ponto_ini; ponto_ini.custo =0; ponto_ini.destino=0; 

    vector<int> dist(N, INF);
    dist[0] = 0;
    pq.push(ponto_ini);

    while(!pq.empty()){
        auto ponto_at = pq.top(); pq.pop();

        if(ponto_at.custo != dist[N])
            continue;

        for(auto e : mat_adj[ponto_at.destino]){
            ponto next_ponto; 
            next_ponto.custo = e.custo + ponto_at.custo; 
            if(next_ponto.custo > dist[e.destino]) continue;

            next_ponto.destino = e.destino;

            pq.push(next_ponto);
        }
        
    }
    
    if(dist[N-1] == INF) {cout << -1 << endl; return 0;}
    cout << dist[N-1] << endl;
}