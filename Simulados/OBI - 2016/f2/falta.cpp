#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
24 cartas, cada uma uma permutação de 1,2,3,4
logo temos 4! cartas, ou seja 24

Acredito que teremos que fazer um sort e encontrar aonde pula

ele coloca N de 2 até 8.
*/

// 100% e acredito ser BEM eficiente o meu meio

// Farei na força bruta - // desisti desse modo
vector<vector<int>> matrix; // y = posição, x= numero
/*
int main(){
    // sol 1, mais trabalhosa
    sol();
    /*
    int N;
    cin >> N;
    int n_cartas = 1;
    vector<int> row_reseted = {0,0,0,0,0,0,0,0};
    for(int i = N; i > 0; i--){
        n_cartas = n_cartas * i;
        matrix.push_back(row_reseted);
    }
    for(int i = 0; i < n_cartas-1; i++){
        int v_N_at;
        for(int j=0; j<N;j++){
            int N_at;
            cin >> N_at;
            v_N_at += N_at * pow(10, j);
            matrix[N_at-1][N-j-1]++;
        }
    }
    for(int i =0; i <N;i++)
    {
        for(int j=0; j<N;j++){
            if(matrix[i][j] == (n_cartas/N-1)){
                cout << j+1;
            }
        }
    }
    
    
    return 0;

}
*/
// modo dois

int main(){
    // adição de todos as permutações - adição todas as permutações enviadas

    int N;
    cin >> N;
    int soma_digitos = 0;
    int n_total_permuta = 1;
    int multiplicativo_11 = 0;
    for(int i=N; i>0;i--){
        n_total_permuta = n_total_permuta * i;
        soma_digitos += i;
        multiplicativo_11 += 1 * pow(10,i-1);
    }
    int soma_all_permuta = 0;

    //cout << multiplicativo_11 << endl;
    //cout << soma_digitos << endl;
    // Cada numero aparece N-1! vezes em cada posição, logo se eu tenho N numeros, posso fazer que a soma de N numeros * (N-1)! * (111111(1 para cada digito N)) = soma total

    soma_all_permuta = (n_total_permuta/N) * (soma_digitos) * multiplicativo_11;

    //cout << soma_all_permuta << endl;
    int soma_permuta_enviada = 0;
    for(int i = 0; i<n_total_permuta-1;i++){
        for(int j=N; j>0;j--){
            int d_at;
            cin >> d_at;
            soma_permuta_enviada += d_at * pow(10, j-1);
            // cout << soma_permuta_enviada << endl;
        }
    }
    // cout << soma_permuta_enviada << endl;
    cout << soma_all_permuta - soma_permuta_enviada << endl;


}

// 100% correto - bem obvio