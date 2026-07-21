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

/*
==========================
Biblioteca padrão questões de grafo - path
==========================


#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct Node {
    int row;
    int col;
};

*/

/*
==========================
Implementeação ideal:
==========================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Um número muito grande - para trocarmos
const int INF = 1e9;

// Movimentos possíveis:
// cima, baixo, esquerda e direita.
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// Estado que ficará dentro da Priority Queue.
struct State
{
    int cost;   
    // custo acumulado até chegar aqui
    int row;    // linha
    int col;    // coluna

    // A priority_queue do C++ é uma MAX HEAP.
    // Queremos retirar primeiro o MENOR custo.
    // Por isso invertemos a comparação.
    bool operator<(const State &other) const
    {
        return cost > other.cost;
    } 
        // muito maneiro
    // existe outra forma para trabalhar para criar um max heap
    // ideia aqui:
    // Vamos redefinir o operador < ao comparado (const State& other) o & é simplesmente para não copiar o objeto comparado só usa-lo mas como constante, ou seja não será alterado, e o const no final diz a mesma coisa com relação ao proprio objeto. 
    // ele A é menor que B, quando o custo de A é maior que de B - Ou seja só mentimos pro STL

    // ao criar o priority_queue, ele vai identificar o metodo(normalmente min heap é greater<int>) como o operador acima. Caso seja true, quer dizer que o state atual deve ficar depois do que tem menor custo

};

int main()
{
    int N;
    cin >> N;

    //--------------------------------------------------
    // Leitura da matriz
    //--------------------------------------------------

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    //--------------------------------------------------
    // dist[r][c]
    // Menor custo conhecido para chegar na célula (r,c)
    //--------------------------------------------------

    vector<vector<int>> dist(
        N,
        vector<int>(N, INF));

    //--------------------------------------------------
    // Priority Queue
    //--------------------------------------------------

    priority_queue<State> pq;

    //--------------------------------------------------
    // Começamos na posição (0,0)
    //--------------------------------------------------

    dist[0][0] = 0;

    pq.push({0, 0, 0});

    //--------------------------------------------------
    // Dijkstra
    //--------------------------------------------------

    while (!pq.empty())
    {
        //----------------------------------------------
        // Pega o vértice de menor custo
        //----------------------------------------------

        State atual = pq.top();
        pq.pop();

        //----------------------------------------------
        // Este estado pode estar "velho".
        //
        // Exemplo:
        //
        // primeiro encontramos custo = 8
        //
        // depois encontramos custo = 5
        //
        // os dois ficam na fila.
        //
        // Quando sair o custo 8,
        // ignoramos.
        //----------------------------------------------

        if (atual.cost > dist[atual.row][atual.col])
            continue;
        // Caso o custo atual esteja maior, vamos explorar outro lugar na fila

        //----------------------------------------------
        // Visita os quatro vizinhos
        //----------------------------------------------

        for (int k = 0; k < 4; k++)
        {
            int nr = atual.row + dr[k];
            int nc = atual.col + dc[k];

            // nova coluna, novo row

            // explorar se está nos limites
            //------------------------------------------
            // Fora da matriz
            //------------------------------------------

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            // se estiver pular operaçãp
            //------------------------------------------
            // Entrar nessa célula custa:
            //
            // 0 se livre
            // 1 se pedra
            //------------------------------------------

            int newCost =
                dist[atual.row][atual.col] +
                grid[nr][nc];

            //------------------------------------------
            // Relaxação
            //
            // Encontramos um caminho melhor?
            //------------------------------------------

            if (newCost < dist[nr][nc])
            {
                dist[nr][nc] = newCost;
                // atualiza caso encontramos o melhor caminho
                //--------------------------------------
                // Coloca novamente na fila
                //--------------------------------------

                pq.push(
                    {
                        newCost,
                        nr,
                        nc});
                // caso tenhamos um novo melhor caminho, recolocamos na fila, se não só ignora e testa proximo da fila
            }
        }
    }

    //----------------------------------------------
    // Resposta
    //----------------------------------------------

    cout << dist[N - 1][N - 1] << endl;

    return 0;
}

*/