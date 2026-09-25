#include <bits/stdc++.h>
using namespace std;

/* - trem da mina

ciclo igual sequencia aonde volta para vertice inicial.
s1, si+1 = ramo de trilho, para 1<= i <= n


*/

/*
- estações com acesso ao solo, se é possível que o trem entre pela estação, percorra a menor distancia, e saia na mesma, sem dar ré
*/

vector<vector<pair<int,int>>> lista_adj;

// distancia de X até Y dist[X][Y]
vector<vector<int>> dist;

// 0 - não sorted ou 1 - sorted
vector<int> distancia_root_root_sorted;

// first = distancia, second tamanho minimo trem para essa distancia
vector<vector<pair<int,int>>> distancias_root_root;
// 10^6 ta no limite da int então fé
const int INF = 1e7;

void BFS(int root){
    // definindo distancia root;
    dist[root][root] = 0;
    // fist = atual, second = origem
    queue<pair<int,int>> fila;

    fila.push({root, -1});
    while(!fila.empty()){
        auto vert_at = fila.front(); fila.pop();
        
        for(pair<int,int> u : lista_adj[vert_at.first]){

            // se eu tiver acabado de sair desse vértice
            if(u.first == vert_at.second) continue;

            // já foi acessado, logo já tem a menor dist, tenho como fazer um ciclo com esse outro vértice;
            if(dist[root][u.first] != INF) {
                // distancia de volta ao root = distancia vertice atual + distancia esse vertice que tem ciclo. comprimento minimo trem = u.second, 
                distancias_root_root[root].push_back({dist[root][u.first] + dist[root][vert_at.first], u.second + max(dist[root][u.first], dist[root][vert_at.first]) - min(dist[root][u.first], dist[root][vert_at.first])});
                continue;
            };

            dist[root][u.first] = dist[root][vert_at.first] + u.second;
            fila.push({u.first, vert_at.first});
        }
    }
    
}

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    } else{
        return a.first < b.first;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int E, R; cin >> E >> R;

    lista_adj.assign(E, vector<pair<int,int>>());
    dist.assign(E, vector<int>(E,INF));
    distancia_root_root_sorted.assign(E, 0);
    distancias_root_root.assign(E, vector<pair<int,int>>());

    for(int i=0; i<R;i++){
        int a,b,c; cin >> a >> b >> c;
        --a; --b;
        lista_adj[a].push_back({b,c});
        lista_adj[b].push_back({a,c});
    }


    // ideia 1: fazer um BFS saindo de i;
    // ideia 2: fazer um djkstra que sai de X, e volta para X, porém temos que fazer com que nenhum ciclo tenha comprimento menor que T! fazer um se

    cout << "1 - matrix feita" << endl;
    vector<int> respostas;
    // consultas
    int K; cin >> K;

    for(int t=0; t<K;t++){
        cout << "2 - comecando teste " << t << endl;
        int X,T; cin >> X >> T;
        --X;

        if(dist[X][X] != 0){
            cout << "BFS nao foi feito em " << X << endl;
            // não foi feito BFS;
            BFS(X);

        }
        cout << "3- BFS concluido ou ja tinha sido feito" << endl;
        // verificando se BFS já foi feito no vertice X, se não fazer BFS;
        // já foi feito BFS
        int distancia = -1;
        if(distancias_root_root[X].size() != 0){
            cout << "temos como fazer um ciclo " << endl;
            if(distancia_root_root_sorted[X] == 0) {
                sort(distancias_root_root[X].begin(), distancias_root_root[X].end(), comp);
                distancia_root_root_sorted[X] = 1;
            }

            for(int i=0; i< distancias_root_root[X].size(); i++){
                if(distancias_root_root[X][i].first >= T && distancias_root_root[X][i].second >= T){
                    distancia = distancias_root_root[X][i].first;
                    break;
                }
            }
        };

        respostas.push_back(distancia);
    }

    // não acho que tem porblema postar depois mas vou dar cout depois de tudo

    for(int w=0; w<K;w++){
        cout << respostas[w] << endl;
    }
}

// tenho 42 minutos para resolver esse.

// 20 minutos  terminei bfs e estrutura

/*
- Não acho que dijkstra será o mais inteligente, pensei em colocar no BFS já as distancias, até o centro, mas para isso eu teria que ver o comprimento dos ciclos o que também daria um trabalho danado.

*/

/*  - terminamos o problema em 45 minutos


No pior dos casos farei 100 BFS em 100 vertices diferentes.

isso pode ser até
100 * 10^4
ai + o djkstra


Apanhei, talvez fosse mais inteligente ter feito um DFS, até achar ciclos, e fazer distancia root_X até ciclos
dist_root_ciclo [X][C]
com Dijkstra, e cada ciclo armazenar:
tamanho do mesmo.

fazemos um sort dos ciclos, e depois fazer um dijkstra do root pedido até o ciclo com menor comprimento maior que C

distancia total = dist_root_ciclo + tamanho ciclo
*/

// depois ver se a solução usa ideia acima, ganhei 0 pontos;