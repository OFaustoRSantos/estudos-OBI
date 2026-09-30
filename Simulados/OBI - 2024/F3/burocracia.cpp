#include <bits/stdc++.h>
using namespace std;

/*
- arvore
root id =1

> relatório a superior K niveis acima.
exemplo se k =3 -> p[p[p[i]]];

> escolher nobre v, e todos subordinados a v (direto ou indiretamente serão subordianados diretos de v)
: BFS simples mudando par de todos

Nem preciso disso talvez
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Numero nobres
    int N; cin >> N;

    vector<int> par(N,0);
    vector<vector<int>> mat_adj (N,vector<int>());
    

    for(int i=1; i<N;i++){
        cin >> par[i];
        par[i]-=1;
        mat_adj[i].push_back(par[i]);
        mat_adj[par[i]].push_back(i);
    }
    int Q; cin >> Q;
    for(int op =0; op<Q; op++){
        int a;
        cin >> a;
        if(a == 1){
            int b, c; cin >> b >> c;
            b--;
            while(c>0){
                b=par[b];
                c--;
            }
            cout << b+1 << endl;
        } else if (a==2){
            int b; cin >> b;
            b--;
            //cout << "| Comecando BFS " << endl;
            vector<int> vis(N,0);

            queue<int> fila;
            
            vis[b]=1;

            for(int w : mat_adj[b]){
                if(w == par[b]) continue;

                //cout << "> mudando vizinho" << w << endl;

                vis[w] = 1;
                for(int u : mat_adj[w]){
                    if(vis[u] == 1) continue;
                    //cout << "-> add vizinho " << u << " de w como parente e na fila " << endl;
                    par[u] = b;
                    fila.push(u);
                }

                // mudar_mat_adj, ela some e só adiciona b 
                mat_adj[w].clear(); 
                mat_adj[w].push_back(b);
            }


            while(!fila.empty()){
                auto n_at = fila.front(); fila.pop();

                if(vis[n_at] == 1) continue;
                //cout << "- Bfs em " << n_at << endl;

                vis[n_at] = 1;

                for(int w : mat_adj[n_at]){
                    if(vis[w] == 1) continue;
                    par[w] = b;
                    fila.push(w);
                }

                // mudar_mat_adj, ela some e só adiciona b 
                mat_adj[n_at].clear(); 
                mat_adj[n_at].push_back(b);
                mat_adj[b].push_back(n_at);
            }
        }
    }

}

/*
44 minutos - 100% exemplos

*/