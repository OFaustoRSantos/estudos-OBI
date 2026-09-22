#include <bits/stdc++.h>
using namespace std;


    /* é uma arvore */ 

    // comprimento do ciclo = numero de vertices que envolve
    // objetivo: numero de salas do maior ciclo de maior comprimento. e quantas maneiras possíveis construir esse ciclo.
    // ideia: escolher os dois pontos mais distantes um do outro
    // faremos um: dijkstra para cada vertice, tinha uma outra técnica, mas nesse caso não acho que faz diferença


int max_dist = 50010;


// os que fazem o maior ciclo são aqueles com maior distancia, sempre que descobrirmos uma distancia grande colocaremos nessa pq
//priority_queue<int,vector<int>> distancias;

// esquece ideia melhor:
/*
maior_dist,
primeiro - valor da distancia
segundo - numero de ciclos possíveis com essa distancia
*/
pair<int,int> maior_dist = {1,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N; cin >> N;

    vector<vector<int>> mat_adj(N,vector<int>());
    vector<vector<int>> dist(N,vector<int>(N,50010));
    vector<int> inicios;
    
    for(int i=0; i<N-1;i++){
        int a,b;
        cin >> a >> b;
        mat_adj[a-1].push_back(b-1);
        mat_adj[b-1].push_back(a-1);
    }
    cout << "computando inicios " << endl;

    for(int i=0;i<N;i++){
        if(mat_adj[i].size() == 1){
            // ele é uma folha
            inicios.push_back(i);
        }
    }

    for(int i=0;i<inicios.size();i++){cout << inicios[i] << endl;}

    for(int i=0;i<inicios.size();i++){

        // não pegaremos todos os vertices somente os que estão no final
        dist[inicios[i]][inicios[i]]=0; // dist vertice até ele mesmo
        // iniciando dijkstra

        /*
        queue, não tem valores nn precisa de dijkstra só BFS
        1° - distancia
        2° - vertice 
        */
        queue<pair<int,int>> fila;

        fila.push({dist[inicios[i]][inicios[i]], inicios[i]});

        cout << "comecando BFS do inicio " << inicios[i] << endl;
        while(!fila.empty()){
            auto at = fila.front(); 
            fila.pop();
            
            cout << "explorando o vertice " << at.second << endl;

            // Caso a distancia de i->atual seja diferente da no priority queue, então está desatualizado, sendo queue não precisa disso também, mas vou deixar.

            if(dist[inicios[i]][at.second] != at.first) continue;

            cout << "explorando o " << at.second << endl; 
            // explorando vizinhos
            for(int w : mat_adj[at.second]){
                // se a distancia dele for maior que a distancia que achamos
                
                if(dist[inicios[i]][w] > at.first+1){
                    cout << "| adicionando vizinho " << w << " na fila" << endl;
                    fila.push({at.first+1, w});
                    dist[inicios[i]][w] = at.first+1;

                    if(maior_dist.first == dist[inicios[i]][w] + 1){
                        maior_dist.second++;
                    }
                    else if(maior_dist.first < dist[inicios[i]][w]+1){
                        maior_dist = {dist[inicios[i]][w]+1, 1};
                    }
                }
            }
        }

    }    
    
    // resposta
    cout << maior_dist.first << endl << maior_dist.second/2 << endl;
}

/* - acabou tempo vou almoçar correndo e terminar as meia hora extra

Terminei - 1h15 minutos + ou - / 1h, não sei ao certo

100% nos exemplos 0 no teste
*/

/* - força bruta não serviu

*/