#include <iostream>
#include <vector>
using namespace std;

vector<int> lista;
int main(){
    // quantos intervalos de dias existem na lista, tal que a soma das medições nesse intervalo é um certo valor
    int N, S;
    cin >> N >> S;
    int intervalos = 0;
    int N_at;
    for(int i =0; i<N; i++){
        cin >> N_at;
        lista.push_back(N_at);
    }
    
    
    // dois ponteiros
    int sum_at;
    for(int i = 0; i<N; i++){
        sum_at = 0;
        //cout << "i atual: " << i << endl;
        if(lista[i] > S){
            continue;
        } else if (lista[i] == S){
            sum_at += lista[i];
            intervalos++;
        } else{
            sum_at += lista[i];
        }

        for(int j=i+1; j<N; j++){
            if(sum_at + lista[j] == S) {
                intervalos++;
            }
            else if (sum_at + lista[j] < S){
                sum_at += lista[j];
            } else{
                break;
            }
        }
    }

    cout << intervalos;
    return 0;
}
// 100% de acerto nos exemplos