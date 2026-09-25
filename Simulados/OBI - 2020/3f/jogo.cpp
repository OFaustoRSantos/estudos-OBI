#include <bits/stdc++.h>
using namespace std;

vector<int> dir_x = {1,-1,0,0};
vector<int> dir_y = {0,0,1,-1};
int L, C;

int testando_permuta(queue<pair<int,int>>& fila, vector<vector<int>> matrix){
int n_brancas =0;
while(!fila.empty()){
    auto pos_preta = fila.front(); fila.pop();
    
    // testando vizinhos da posição
    for(int i=0; i<4; i++){
        int n_x = pos_preta.first + dir_x[i];
        int n_y = pos_preta.second + dir_y[i];
        
        // tirando casos fora da borda
        if(n_x < 0 || n_x >= L || n_y < 0 || n_y >= C) continue;

        // tirando os casos de a posição que tentamos atacar é uma preta ou uma branca
        if(matrix[n_x][n_y] == 1 || matrix[n_x][n_y] == 2) continue;
    
        // ponto na matrix está vazio
        bool possivel = true;
        for(int j=0; j<4; j++){
            int n_x_ = n_x + dir_x[j];
            int n_y_ = n_y + dir_y[j];

            // tirando casos fora da borda
            if(n_x_ < 0 || n_x_ >= L || n_y_ < 0 || n_y_ >= C) continue;
            // tirando o caso de estar voltando
            if(n_x_ == pos_preta.first && n_y_ == pos_preta.second) continue;

            if(matrix[n_x_][n_y_] == 2){
                possivel = false;
                break;
            }
        }
        // tem como adicionar
        if(possivel){
            matrix[n_x][n_y] = 2;
            n_brancas++;
        }
    }
}
    return n_brancas;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;

    // 0 = não tem, 1 = preta
    vector<vector<int>> matrix_ori(L, vector<int>(C,0));
    int P; cin >> P;

    

    vector<pair<int,int>> fila_p;
    vector<int> indices;
    for(int i=0; i<P;i++){
        int x,y; cin >> x >> y;
        --x;--y;
        matrix_ori[x][y] = 1;
        fila_p.push_back({x,y});
        indices.push_back(i);
    }

    int n_at=fila_p.size();
    int n_permutacoes =1;
    while(n_at>1){
        n_permutacoes = n_permutacoes*n_at;
    }


    
    int n_brancas_total = 0;
    for(int p=0; p<n_permutacoes;p++){
        queue<pair<int,int>> fila;
        for(int num=0; num<fila_p.size(); num++){
            fila.push({fila_p[indices[num]].first,fila_p[indices[num]].second});
        }
        next_permutation(indices.begin(), indices.end());

        int n_brancas = testando_permuta(fila, matrix_ori);

        n_brancas_total = max(n_brancas_total,n_brancas);
    }

    // talvez eu tenha que fazer uma loucura:
    // testar as 10 permutações de P, pois pode ser que adicionando uma P alé

    cout << n_brancas_total << endl;

}

/*
- complexidade N de peças pretas = 10, logo podemos fazer algo bem simples:

P*4*3 (cada peça preta verá as 4 posições ao lado, cada posição ao lado verá as 3 posições ao lado (para ver se não tem nenhuma branca))
para cada peça preta, tentaremos ver as posições 

Feito em 25 minutos:
1 teste sem a permutação: 80

2 teste com a permutação: 

não está indo com permutação está dando infinito
gastei um 10 minutos para isso
*/