#include <bits/stdc++.h>
using namespace std;

bool testando_valor(const vector<int>& lista, const int meio, const int K){
    int N = lista.size();
    int valor_total_at=0;
    int K_adicionados=1;
    for(int i=0;i<N;i++){
        int n_at = lista[i];
        if(valor_total_at+n_at > meio){
            K_adicionados++;
            if(K_adicionados > K){
                return false;
            }
            valor_total_at = n_at;
            if(valor_total_at > meio) return false;
        } else{
            valor_total_at += n_at;
        }
    }   

    return true;
}

int main(){ 
    ios::sync_with_stdio(0); cin.tie(NULL);
    int menor_num = 1e9;
    int maior_num = -1;

    int N, K; cin >> N >> K;
    vector<int> lista(N,0);
    for(int i=0;i<N;i++){
        cin >> lista[i];
        menor_num = min(menor_num, lista[i]);
        maior_num = max(maior_num, lista[i]);
    }

    int esq = menor_num;
    int dir = maior_num*(K+2);
    while(esq < dir){
        int meio = (esq + dir)/2;

        if(testando_valor(lista, meio, K)){
            // funciona vamos tentar um numero menor
            dir = meio;
        } else{
            esq = meio + 1;
        }
    }

    cout << dir << endl; 
    // dir = menor que deu certo
}