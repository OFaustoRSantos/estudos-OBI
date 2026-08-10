#include <bits/stdc++.h>
using namespace std;

// montar uma grid

vector<vector<int>> matrix; 
vector<vector<bool>> vis; 
// matrix => 0 = ponto, 1 = H, 2 = o;

struct position {int x;int y;};
position pos_H;
position pos_inicio;

vector<int> dir_x = {1,-1,0,0};
vector<int> dir_y = {0,0,1,-1};

int L, C;

void DFS(int is, int j){
    
    bool outro_perto = false;
    for(int i=0; i<4; i++){
        int nx = is + dir_x[i];
        int ny = j + dir_y[i];

        // testando limites
        if(nx < 0 || nx >= L || ny < 0 || ny >= C){
            continue;
        }
        // fazendo DFS para ao lado
        if(vis[nx][ny] == false && matrix[nx][ny] == 1){
            outro_perto = true;
            vis[nx][ny] = true;
            DFS(nx,ny);
        }
    }

    if(outro_perto == false){
        pos_H.x = i;
        pos_H.y = j;
    }

}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    cin >> L; // ordem estava errada

    matrix.assign(L,vector<int>(C,-1));
    
    vis.assign(L,vector<bool>(C,false));


    for(int i =0; i<L; i++){
        string frase;
        cin >> frase;
        for(int j=0; j<C;j++){
            if(frase[j] == 'H')
            matrix[i][j] = 1;
            if(frase[j] == '.') matrix[i][j] = 0;
            if(frase[j] == 'o'){
                pos_inicio.x = i;
                pos_inicio.y = j;
                matrix[i][j] = 2;
            }
        }
    }
    vis[pos_inicio.x][pos_inicio.y] = true;
    DFS(pos_inicio.x, pos_inicio.y);

    cout << pos_H.x << " " << pos_H.y << endl;

}

// ficou infinito, nn entendo o pq
// aaaaaaaaaaaa

// Correção com gemini

/*
Você identificou DFS, mas implementou errado
DFS em matriz + controle de estado

*/

// Aqui você estava muito mais perto do que parece.

// Erros bobos de implementação
// Verificar linha a linha !


/*

#include <bits/stdc++.h>
using namespace std;

int L, C;

vector<string> mapa;
vector<vector<bool>> vis;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int respostaX, respostaY;

void DFS(int x, int y) {

    bool encontrouProximo = false;

    for (int k = 0; k < 4; k++) {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= L || ny < 0 || ny >= C)
            continue;

        if (vis[nx][ny])
            continue;

        if (mapa[nx][ny] != 'H')
            continue;

        encontrouProximo = true;

        vis[nx][ny] = true;

        DFS(nx, ny);
    }

    if (!encontrouProximo) {
        respostaX = x;
        respostaY = y;
    }
}

int main() {

    cin >> L >> C;

    mapa.resize(L);

    for (int i = 0; i < L; i++)
        cin >> mapa[i];

    vis.assign(L, vector<bool>(C, false));

    int inicioX, inicioY;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {

            if (mapa[i][j] == 'o') {
                inicioX = i;
                inicioY = j;
            }
        }
    }

    vis[inicioX][inicioY] = true;

    DFS(inicioX, inicioY);

    cout << respostaX + 1 << " " << respostaY + 1 << '\n';

    return 0;
}
*/