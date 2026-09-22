#include <bits/stdc++.h>
using namespace std;

/*
Após review fazendo do zero
*/

//pair<int, vector<int>> bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){
// int bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){
pair<int,int> bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){

    queue<int> fila;

    // {vertice, dist}
    pair<int,int> max_dist = {0,0};
    fila.push(root);
    dist[root] = 0;

    while(!fila.empty()){
        auto vert_at = fila.front(); fila.pop();

        for(int x : mat_adj[vert_at]){
            if (dist[x] != -1) continue;  // caso  da volta

            dist[x] = dist[vert_at] + 1;
            fila.push(x);

            if (dist[x] + 1 > max_dist.second){
                max_dist = {x,dist[x] + 1};
            }
        }
    }
    // nn vejo necessidade em enviar o dist também, então enviarei só o vertice
    // return {max_dist.first, dist};
    //return max_dist.first;
    // Na real vou enviar o max_dist
    return max_dist;
}

/* 
Era possivel entregar o parentes, ou seja pai imediatament superior do abençoado, mas nn vejo sentido para isso nessa questão
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<vector<int>> mat_adj (N, vector<int>());
    vector<int> dist1 (N, -1);    
    

    // construido o grafo 
    for(int i=0; i<N-1;i++){
        int a, b; cin >> a >> b;

        --a; --b;

        mat_adj[a].push_back(b);
        mat_adj[b].push_back(a);
    }

    // rodando primeiro BFS
    auto [vertice,distancia] = bfs(mat_adj, 0, dist1);

    int ciclos = 0;
    
    /* for(int i =0; i<N; i++){
        if(dist1[i] + 1 == distancia){
            ciclos++;
        }
    }
    cout << "---------" << endl;
    cout << distancia << endl << ciclos << endl;
    cout << "---------" << endl; */

    vector<int> dist2 (N, -1);
    
    auto [vertice_,distancia_] = bfs(mat_adj, vertice, dist2);

    int D = dist2[vertice_];

    for(int i =0; i<N; i++){
        if(dist2[i] == D){
            ciclos++;
        }
    }
    cout << distancia_ << endl << ciclos << endl;
}   

// Consegui achar o diametro, mas não estou conseguindo achar os pontos aonde distancia igual 5 
