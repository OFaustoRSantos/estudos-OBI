#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    N, n° de numeros menores ou = a N que são primos
    Para testar usará uma lista de numeros K
*/

// ta certo, mas os exemplos tão errados, não faz sentido

int n_primos = 0;

bool N_at_primo = true;

bool testar_divisibilidade(int N_teste, int K_divisor){
    if(N_teste < K_divisor){
        return false;
    }
    else if (N_teste == K_divisor){
        return false;
    }
    else if(N_teste%K_divisor == 0){
        return true;
    } else{
        return false;
    }
}

int main(){
    int N, K;
    vector<int> primos;
    cin >> N >> K;
    for(int i =0; i < K; i++){
        int primo_at;
        cin >> primo_at;
        primos.push_back(primo_at);
    }

    for(int N_at=N; N_at>0;N_at--){
        N_at_primo = true;
        cout << N_at << endl;
        for(int K_at : primos){
            if(testar_divisibilidade(N_at,K_at)){
                N_at_primo = false;
                break;
            }
        }
        if(N_at_primo){
            cout << "é primo" << endl;
            n_primos++;    
        }
    }
    cout << n_primos << endl;
}

