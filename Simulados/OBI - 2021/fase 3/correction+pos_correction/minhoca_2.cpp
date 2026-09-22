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
    
    }
    
    // resposta
    cout << maior_dist.first << endl << maior_dist.second/2 << endl;
}

/* - força bruta não serviu
    Ideia 2 - achar o root.
    achando o root faremos a profundidade de cada ponto.
    // não vai dar tempo dessa vez  
*/

/* - tenho 20 minutos mas como comecei a prova atrasado não terminei

*/