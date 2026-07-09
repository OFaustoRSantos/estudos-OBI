#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 100%

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