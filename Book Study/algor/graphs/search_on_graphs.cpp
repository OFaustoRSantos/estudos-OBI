#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N;
const int INF = 1e9;

struct Node{
    int row;
    int col;
};

// movimentos - MUITO INTELIGENTE
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};


vector<vector<int>> dist(
    N,
    vector<int>(N, INF)
);

int BFS(){

    int N;
    cin>>N;
    // Não precisa-se atualizar distancia
    vector<vector<int>> grid(N, vector<int>(N));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];

    // distância mínima em quantidade de passos
    vector<vector<int>> dist(
        N,
        vector<int>(N,INF)
    );

    queue<Node> q;

    dist[0][0]=0;

    q.push({0,0});

    while(!q.empty()){

        Node atual=q.front();
        q.pop();

        for(int k=0;k<4;k++){

            int nr=atual.row+dr[k];
            int nc=atual.col+dc[k];

            if(nr<0 || nr>=N || nc<0 || nc>=N)
                continue;

            if(dist[nr][nc]!=INF)
                continue;

            dist[nr][nc]=dist[atual.row][atual.col]+1;

            q.push({nr,nc});
        }
    }

}

int Dijkstra(){
    struct State{

    int cost;

    int row;

    int col;

    bool operator<(const State& other) const{

        return cost>other.cost;

    }

};
    struct State{

    int cost;

    int row;

    int col;

    bool operator<(const State& other) const{

        return cost>other.cost;

    }

};

priority_queue<State> pq;

dist[0][0]=0;

pq.push({0,0,0});

}