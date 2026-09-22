#include <bits/stdc++.h>
using namespace std;

/*
Após perceber que a solução que aprendi estava errada, chatgpt passou a ideia errada, mas aprendi coisas legais!

*/

//pair<int, vector<int>> bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){
// int bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){
pair<int,int> bfs(const vector<vector<int>>& mat_adj, const int& root, vector<int>& dist){

    queue<int> fila;

    // {ciclos, dist}
    pair<int,int> max_dist = {0,0};
    fila.push(root);
    dist[root] = 0;

    while(!fila.empty()){
        auto vert_at = fila.front(); fila.pop();

        for(int x : mat_adj[vert_at]){
            if (dist[x] != -1) continue;  // caso  da volta

            dist[x] = dist[vert_at] + 1;
            fila.push(x);

            if (dist[x] + 1 == max_dist.second){
                max_dist = {max_dist.first+1,dist[x] + 1};
            }

            if (dist[x] + 1 > max_dist.second){
                max_dist = {1,dist[x] + 1};
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

    // numero de ciclos, e numero de distancias
    pair<int, int> dist_ciclos = {0,0};
    for(int i=0; i<N; i++){
        int extremidades =0;
        vector<int> dist1 (N, -1);
        if (mat_adj[i].size()==1){
            auto [ciclos, distancia] = bfs(mat_adj, i, dist1);
            if(distancia > dist_ciclos.second){
                dist_ciclos = {ciclos, distancia};
                
            }
            if(distancia == dist_ciclos.second){
                dist_ciclos.first += ciclos - extremidades;
                
            }
            extremidades++;
        }

    }
    cout << dist_ciclos.second << endl << dist_ciclos.first << endl;
}   

// Consegui achar o diametro, mas não estou conseguindo achar os pontos aonde distancia igual 5 
