#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Matrix: N x M

Cada monstro tem um poder; -> Inicio define poder heroi

> Pode visistar a mesma célula.
- Quando visita celula Heroi won se poder heroi > poder monstro; se não acaba o jogo
- Quando monstro perde poder heroi aumenta em P_i,j; e valor da célula = 0


-> Priority queue com menor valor de poder do monstro;

*/

struct grid_monstro{int poder; int i; int j; 
    bool operator<(const grid_monstro&  other) const {return poder < other.poder;};
    bool operator>(const grid_monstro&  other) const {return poder > other.poder;};
};

bool comp(grid_monstro a, grid_monstro b){return a.poder < b.poder;};



// tenho que criar uma memória por ponto, pois quando um usuário com x > poder no local, entrar naquele ponto, ele já somar - Não dá, tentarei na força bruta como estou fazendo agora; da ss
// matrix visited; path, quando entrar num ponto já visitado adicionar todos os pontos do path que não tem no path atual e aumentar o poder total quando adicionar; mesmo que seja só o próprio ponto.
// só criarei uma matrix a path, em vez de visited;

// vector<vector<vector<pair<int,int>>>> path; 
// gigante: path[i][j][indice no caminho] first = i, second = j

// esquece olhando agora, eu teria que interar no path, ou seja, daria a mesma complexidade

// se valor max daquele ponto é maior que o meu valor atual, então aquele ponto com certeza passou por mim, por isso posso parar e assumir o valor total dele!

vector<vector<int>> valor_max_ponto; 

vector<vector<int>> matrix; 
vector<vector<int>> matrix_vis;

vector<int> dir_x = {1,-1, 0,0};
vector<int> dir_y = {0,0, -1, 1};

int max_ponto_iniciando_nesse_ponto(int i, int j){
    //cout << "iniciando max_ponto de " << i << j << endl;
    if (valor_max_ponto[i][j] != matrix[i][j]){
        //cout << " max_ponto de " << i << j << " já foi calculado" << endl;
        //cout << " valor de max ponto = " << valor_max_ponto[i][j] << endl;
        return valor_max_ponto[i][j];
        // elemento já foi explorado;
    }

    // se não:
    priority_queue<grid_monstro, vector<grid_monstro>, greater<grid_monstro>> pq;

    // int valor_ponto_at = matrix[i][j];
    grid_monstro grid_monstro_at; grid_monstro_at.i = i; grid_monstro_at.j = j; grid_monstro_at.poder = matrix[i][j];

    // fazer teste para verificar se o ponto max dos ao redores já foi visto
    //cout << "textando vizinhos max_ponto de " << i << j << endl;
    for(int w=0; w<4; w++){
        int n_i = i + dir_x[w];
        int n_j = j + dir_y[w];

        if(n_i < 0 || n_j < 0 || n_i > matrix.size() -1 || n_j > matrix[0].size() -1) continue;
        
        // se valor ao lado for menor que o valor atual, e o valor máximo for maior que o valor atual, então esse quadrado já foi percorrido

        if(matrix[n_i][n_j] <= matrix[i][j] && valor_max_ponto[n_i][n_j] > matrix[i][j]){
            valor_max_ponto[i][j] = valor_max_ponto[n_i][n_j];
            //cout << " vizinhos max_ponto encontrado " << i << j << " valor = " << valor_max_ponto[n_i][n_j] << endl;
            return valor_max_ponto[n_i][n_j];
            // ele não foi explorado mas o da vizinhança foi
        }
    }

    // Nenhum ao lado computado, começando processo novo vertice

    //cout << "nenhum vizinho calculado, iniciando busca nova " << endl;

    matrix_vis.assign(matrix.size(), vector<int>(matrix[0].size(), 0));

    pq.push(grid_monstro_at);
    matrix_vis[i][j] = 1;
    while(!pq.empty()){
        // se o valor max do ponto for maior que o valor ponto at, substituir valor e dar um break
        // explorar
        auto temp = pq.top(); pq.pop();

        // adicionando vizinhos
        for(int w=0; w<4; w++){
            int n_i = temp.i + dir_x[w];
            int n_j = temp.j + dir_y[w];

            if(n_i < 0 || n_j < 0 || n_i > matrix.size() -1 || n_j > matrix[0].size() -1 || matrix_vis[n_i][n_j] == 1) continue;
        
        // se valor ao lado for menor que o valor atual, e o valor máximo for maior que o valor atual, então esse quadrado já foi percorrido

            if(matrix[n_i][n_j] <= valor_max_ponto[i][j]){
                valor_max_ponto[i][j] += matrix[n_i][n_j];
                grid_monstro n_grid_monstro; n_grid_monstro.i = n_i; n_grid_monstro.j = n_j; n_grid_monstro.poder = matrix[i][j];
                matrix_vis[n_i][n_j] = 1;
                pq.push(n_grid_monstro);
            }
        }
    }
    //cout << valor_max_ponto[i][j] << " = valor max ponto do não calculado " << i << j << endl;
    return valor_max_ponto[i][j];

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N, M; cin >> N >> M;

    matrix.assign(N, vector<int>(M, 0));
    

    valor_max_ponto.assign(N, vector<int>(M, 0));

    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            int dig_at; cin >> dig_at; matrix[i][j] = dig_at;
            valor_max_ponto[i][j] = matrix[i][j];
        }
    }

    /*for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            cout << matrix[i][j] << " v_max ";
            cout << valor_max_ponto[i][j] << " ";
        }
        cout << endl;
    } */

    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            if(j!= M-1) cout << max_ponto_iniciando_nesse_ponto(i,j) << " "; else cout << max_ponto_iniciando_nesse_ponto(i,j) << endl; 
        }
    }
}

// mais dificil do ano, mas nn achei dificil
