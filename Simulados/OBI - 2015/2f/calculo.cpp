#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 100% - corrigido

// representação Obi-2015
// valores positivos menores que um
// binário
int main(){
    int M, N;
    cin >> M >> N;
    // valor binário
    vector<int> M_b;
    vector<int> N_b;
    //valor numerico
    double M_10, N_10; // M,N em base 10

    for(int i=0; i < M; i++){
        int new_binary;
        cin >> new_binary;
        // salvando valor binário
        M_b.push_back(new_binary);
        //convertendo valor numerico
        M_10 += new_binary*pow(2,-(i+1));
    }
    for(int i =0; i< N; i++){
        int new_binary;
        cin >> new_binary;
        // salvando valor binário
        N_b.push_back(new_binary);
        //convertendo valor numerico
        N_10 += new_binary*pow(2,-(i+1));
    }
    // valor numerico
//    cout << N_10 + M_10 << endl;
    // Conversão valor binário

    // calculo já com no modelo binário
    vector<int> num_invertido;
    vector<int> num_certo;
    if (N > M){
        for(int i=N_b.size()-1; i >=0; i--){
            if(i < M_b.size()){
                if(N_b[i] + M_b[i] >= 2){
                    N_b[i-1]++;
                    num_invertido.push_back(N_b[i] + M_b[i]-2);
                } else{
                    num_invertido.push_back(N_b[i] + M_b[i]);
                }
            }
            else{
                num_invertido.push_back(N_b[i]);
            }
        }
    } else{
        for(int i=M_b.size()-1; i >=0; i--){
            if(i < N_b.size()){
                if(N_b[i] + M_b[i] >= 2){
                    M_b[i-1]++;
                    num_invertido.push_back(N_b[i] + M_b[i]-2);
                } else{
                    num_invertido.push_back(N_b[i] + M_b[i]);
                }
            }
            else{
                num_invertido.push_back(M_b[i]);
            }
        }
    }

    for(int i=num_invertido.size()-1; i>=0;i--){
        num_certo.push_back(num_invertido[i]);
        cout << num_invertido[i] << " ";
    }
}

/*
A forma clássica de resolver

A solução usada em competições é:

Alinhar os dois números pela direita (os bits menos significativos).
Percorrer de trás para frente.
Manter uma variável carry.
Calcular:
soma = bitA + bitB + carry
resposta = soma % 2
carry = soma / 2
No final, remover zeros à direita da representação (lembrando que a representação usa o menor número possível de bits, então o último bit deve ser 1).

Esse padrão é simples, linear (O(max(M,N))) e não sofre com problemas de precisão.
*/

/*
//Solução Chat:
int i = M.size()-1;
int j = N.size()-1;
int carry = 0;

while(i>=0 || j>=0){
    bitM =
    (i>=0)? M[i] : 0;
    bitN =
    (j>=0)? N[j] : 0;
    // o que isso quer dizer?
    soma = bitM + bitN + carry;
    reposta.push_back(soma%2);
    carry = soma/2
}
*/

/*

*/