#include <bits/stdc++.h>
using namespace std;


/* - Matriz

A_ij, elemento na i_linha, j_coluna. Da Matriz A.

- Matriz legal se:
A_1,1 + A_lin_col <= A_1,col + A_lin,col

para todo lin e col maior que 1.

- Matriz super-legal se:

cada submatriz com pelo menos duas linhas e duas colunas é legal.

Submatriz S, de M_lxC é matriz que inclui todos os elemente Mij.
onde L1 <= i <= l2; c1 <= j <= c2;
1 <= l1 <= l2 <= L e 1 <= c1 <= c2 <= C;

| Objetivo: Para matrix A, determinar + qnt, elementos de uma submatrix super-legal.

*/

vector<vector<int>> matrix;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Entrada
    int L, C; // L=Linhas, C=Colunas.
    matrix.assign(L, vector<int>(C,0));

    //matrix.assign();
    
    for(int i=0; i<L;i++){
        for(int j=0; j<C; j++){
            cin >> matrix[i][j];
        }
    }
    

}