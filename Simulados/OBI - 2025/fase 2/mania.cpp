#include <bits/stdc++.h>
using namespace std;

/*
- Quantidades impares

- N linhas e M colunas bandeja
- N e M impares
- cada linha i e coluna j possui G_i,j gotas
*/

vector<vector<int>> gotas;
vector<vector<int>> matrix;
/*
- Para todo par adjacente de cookies, a soma das gostas é impar.
- adjacente - embaixo, emcima ou dos lados

> Economizar, add minimo de gotas possiveis
*/

int gotas_add = 0;

vector<int> dir_x = {1,0};
vector<int> dir_y = {0,-1}; // não preciso fazer voltando

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    gotas.assign(N,vector<int>(M,0));
    /* Criar tabela */
    for(int i =0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> gotas[i][j];
        }
    }
    //cout << "montada matrix gotas, iniciando matrix paridade" << endl;
    matrix.assign(N,vector<int>(M,0));
    /* Fazer calculo aonde está par na tabela, e estudar casos */
    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            for(int x = 0; x<2; x++){
                int n_i = i+dir_x[x];
                int n_j = j+dir_y[x];

                if(n_i > matrix.size() -1 || n_j > matrix[0].size() -1 || n_i < 0 || n_j < 0) continue;

                if((gotas[i][j] + gotas[n_i][n_j])%2 == 1){
                    // se matrizes não forem definidas, colocar como impar
                    if(matrix[i][j] == 0){
                        matrix[i][j] = 1; // é impar
                    }
                    if(matrix[n_i][n_j] == 0){
                        matrix[n_i][n_j] = 1;
                    }
                    // se já foi definido como par ignorar;
                } else { 
                    if(matrix[n_i][n_j] == 0) {matrix[n_i][n_j] = 2;} else{matrix[n_i][n_j]++;}
                    if(matrix[i][j] == 0){matrix[i][j] = 2;} else{matrix[i][j]++;}
                    
                }
            }
            
        }
    }
    //cout << "terminada matrix paridade" << endl;

    // fazer verificação formatos de cruz; 
    //cout << "começando adicionar gotas" << endl;
    for(int teste=0; teste<3; teste++) {
    for(int i =0; i< N; i++){
        for(int j =0; j<M; j++){
            if(matrix[i][j] == 1){
                continue;
            }
            // extremidades:
            if(i==0){
                if((j==0)) {
                    if(matrix[i+1][j] >= 2 && matrix[i][j+1] >= 2){
                    matrix[i][j]--; 
                    matrix[i+1][j]--; 
                    matrix[i][j+1]--;
                    gotas_add++;
                    gotas[i][j]++;
                    }
                }
                else if (j==M-1) {
                    if(matrix[i+1][j] >= 2 && matrix[i][j-1] >= 2){
                        matrix[i][j]--; matrix[i+1][j]--; matrix[i][j-1]--;
                        gotas_add++;
                        gotas[i][j]++;
                    }
                } else {
                    // Ou seja está na parte superior somente
                    if(matrix[i+1][j] >= 2 && matrix[i][j-1] >= 2 && matrix[i][j+1] >= 2){
                        matrix[i][j]--; matrix[i+1][j] --; matrix[i][j-1]--;  matrix[i][j+1]--;
                        gotas_add++;
                        gotas[i][j]++;
                    }
                }
            }
            
            else if(i==N-1){
                if (j==0) {
                    if(matrix[i-1][j] >= 2 && matrix[i][j+1] >= 2){
                        matrix[i][j]--; matrix[i-1][j] --; matrix[i][j+1]--;
                        gotas_add++;
                        gotas[i][j]++;
                    }
                }
             
                else if (j==M-1){
                    if(matrix[i-1][j] >= 2 && matrix[i][j-1] >= 2){
                        matrix[i][j]--; matrix[i-1][j]--; matrix[i][j-1]--;
                        gotas_add++;
                        gotas[i][j]++;
                    }
                }
                else {
                    // Ou seja está na parte superior somente
                    if(matrix[i-1][j] >= 2 && matrix[i][j-1] >= 2 && matrix[i][j+1] >= 2){
                        matrix[i][j] = 1; matrix[i-1][j] = 1; matrix[i][j-1] = 1;  matrix[i][j+1] = 1;
                        gotas_add++;
                        gotas[i][j]++;
                    }
                }
            }
            // bordas:
            else if(j==0){
                if(matrix[i-1][j] == 2 && matrix[i+1][j] == 2 && matrix[i][j+1] == 2){
                    matrix[i][j]--; matrix[i-1][j]--; matrix[i+1][j]--;  matrix[i][j+1]--;
                    gotas_add++;
                    gotas[i][j]++;
                }
            }
            else if(j==M-1){
                if(matrix[i-1][j] >= 2 && matrix[i+1][j] >= 2 && matrix[i][j-1] >= 2){
                    matrix[i][j]--; matrix[i-1][j]--; matrix[i+1][j]--;  matrix[i][j-1]--;
                    gotas_add++;
                    gotas[i][j]++;
                }
            }
            else{
                // Caso geral dentro do quadrado
                if(matrix[i-1][j] >= 2 && matrix[i+1][j] >= 2 && matrix[i][j+1] >= 2 && matrix[i][j-1] >= 2){
                    matrix[i][j]--; matrix[i-1][j]--; matrix[i+1][j]--;  matrix[i][j-1]--;matrix[i][j+1]--;
                    gotas_add++;
                    gotas[i][j]++;
                }
            }


        }
    }
    }
    
    /* Printa n° de gotas adicionadas. */

    cout << gotas_add << endl;
    /* Printar a tabela */
    for(int i=0; i<N; i++){ for(int j=0; j<M; j++){
        if(j==M-1){
            cout << gotas[i][j] << endl;
            continue;
        }
        cout << gotas[i][j] << " ";
    }}
}

// 83 minutos para esse problema e para o da feira
// Deu 100% nos exemplos demorei 50 minutos para finalizar;
// fiz uma certa gambiarra, usando um loop 3x na matrix;
// 100% nos exemplos, mas acredito que ganharia uns 50-80 nos testes, aprender solução certa depois