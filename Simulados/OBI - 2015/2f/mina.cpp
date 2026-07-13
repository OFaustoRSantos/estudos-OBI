#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// dijkstra - não consegui fazer ...
struct position{int x;int y;};
int N;
void search(int dis_at, position position_at, vector<vector<int>>& matrix, vector<vector<int>>& matrix_dist);

int main(){
    // dimensão matrix quadrada
    cin >> N;
    vector<vector<int>> matrix;
    
    vector<vector<int>> matrix_dist;
    for(int i=0; i<N; i++){
        vector<int> new_row;
        vector<int> new_row_dist;
        for(int j=0; j<N;j++){
            int N_new;
            cin >> N_new;
            new_row.push_back(N_new);
            new_row_dist.push_back(9999999);
        }
        matrix.push_back(new_row);
        matrix_dist.push_back(new_row_dist);
    }

    //dijkstra - sria o ideal
    position pos_at;
    pos_at.x = 0; pos_at.y = 0;
    position pos_end;
    pos_end.x = N -1; pos_end.y = N-1;

    cout << matrix_dist[N-1][N-1];
    return 0;
}

void search(int dis_at, position position_at, vector<vector<int>>& matrix, vector<vector<int>>& matrix_dist){
    if(dis_at + matrix[position_at.x][position_at.y] < matrix_dist[position_at.x][position_at.y]){
        matrix_dist[position_at.x][position_at.y] = dis_at + matrix[position_at.x][position_at.y];
        dis_at += matrix[position_at.x][position_at.y];
        if(position_at.x+1 < N-1){
            position_at.x++;
            search(dis_at, position_at, matrix, matrix_dist);
        }
        if(position_at.x-1 > 0){
            position_at.x--;
            search(dis_at, position_at, matrix, matrix_dist);
        }
        if(position_at.y+1 < N -1){
            position_at.y++;
            search(dis_at, position_at, matrix, matrix_dist);
        }
        if(position_at.y-1 > 0){
            position_at.y--;
            search(dis_at, position_at, matrix, matrix_dist);
        }
    // Se já tiver uma distancia menor, não precisa recalcular
    } else{
    
    }
    
}


/* 
===========================================
 Correção + Comentários: dia 9/7 - ChatGPT
===========================================
Matrix Quadrada (NxN)
Objetivo: 0,0 até o N-1, N-1

Possiveis formas: BFS, 0-1 BFS, Dijkstra

Quando você vê um problema de caminho mínimo, pergunte sempre:

| As arestas têm peso?
- Não → normalmente BFS.
| Os pesos são apenas 0 e 1?
- Sim → 0-1 BFS (ou Dijkstra, se você ainda não conhece 0-1 BFS).
| Os pesos são quaisquer valores não negativos?
- Sim → Dijkstra.
| Existem pesos negativos?
-  Sim → Dijkstra não serve; aí entram algoritmos como Bellman-Ford ou Floyd-Warshall, dependendo do problema.

===========================
É um problema de caminho?

        │
        ▼
Todos os movimentos têm custo igual?

        │
   Sim ─────► BFS

        │
       Não
        │
        ▼

Os custos são apenas 0 e 1?

        │
   Sim ─────► 0-1 BFS

        │
       Não
        │
        ▼

Todos os pesos são ≥ 0 ?

        │
   Sim ─────► Dijkstra

        │
       Não
        │
        ▼

Bellman-Ford


Para encontrar mais informações, e a estrutura de cada algoritimo olhar -> Algor/graphs/search_on_graphs.cpp

*/