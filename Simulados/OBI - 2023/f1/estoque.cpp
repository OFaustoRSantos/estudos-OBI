#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tipo, tamanho
// i = tipo, j = tamanho

int M_max = 500;
int N_max = 500;

int mat[M_max][N_max];
int vendas = 0;
// pensa vendida estoque atualizado
void vender_p(int[M_max][N_max] &l, int i, int j);

int main(){
    int I, J;

    cin >> M >> N;
    int n_at;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> n_at;
            mat[i][j] = n_at;
        }
    }
    int P;
    int p_i, p_j;
    cin >> P;
    for(int i =0; i < P; i++){
        cin >> p_i >> p_j;
        vender_p(mat, p_i, p_j);
    }
    // vai ter que tirar um de i e de j
    cout << vendas;
}
// não sei se coloca-se o int M_max aqui, e se coloca quando chama a função
void vender_p(int[M_max][N_max] &l, int i, int j){
    if(l[i][j] == 0){

    } else{
        vendas++;
        l[i][j]--;
    }
}

// eu podia usar so void vender_p(int &J)
// e quando chamar usamos vender_p(mat[p_i][p_j])


// mapa de soluções - com func
// - s_endl 
// 1 - atual
// 2 - vender_p com int &J
// - c_endl 
// 1 - atual
// 2 - vender_p com int &J

// - sem func
// - s_endl 
// 1 - 

// - c_endl 
// 1 - 



