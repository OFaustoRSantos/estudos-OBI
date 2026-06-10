#include <iostream>
using namespace std;

// 3 prédios: Escola -> Mercado -> Lojinha
// Distancia = delta posição

int main (){
    // Posições
    int E,S,L;
    cin >> E >> S >> L;
    int distancia;
    // 3 casos: 
    // 1 - escola no meio
    if(E > S && E < L){
        distancia = (E-S) * 2 + (L-E) * 2;
        
    }else if(E < S && E > L){
        distancia = (E-L) * 2 + (S-E) * 2;
    }
    // 2 - Escola > S e L - working
    else if (E > S && E > L){
        if(S > L){
            distancia = 2*(E-L);
        } else{
            distancia = 2*(E-S);
        }
    }
    // 3 - Escola < S e L - Working
    else if (E < S && E < L){
        if(S > L){
            distancia = 2*(S-E);
        } else{
            distancia = 2*(L-E);
        }
    }
    cout << distancia;
    return 0;
}

// como usar modulo em c++ - importante
// 100% com os exemplos