#include <bits/stdc++.h>
using namespace std;

/*

6 cubos -> Mesmo tamanho peso diferente

empilhar os 6 em piramide 3 andares
Se o peso total de cada andar possuir o mesmo valor = Balanceada

S -> possível formar pirâmide balanceada com os seis cubos


*/
bool comp(int a, int b){
    return a > b;
    // sort decrescente
}

vector<int> pesos(6,0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1° faz um sort:

    // Mais pesada vai para o topo, e por isso; naturalmente ela define o valor por andar

    int sum_pesos =0; // add early_stop
    for(int i=0; i<6;i++){
        cin >> pesos[i];
        sum_pesos+= pesos[i];
    }

    sort(pesos.begin(), pesos.end(), comp);

    int peso_p_andar = pesos[0];
    // casos padrão:
    if(sum_pesos - peso_p_andar < 2* peso_p_andar || pesos[1] == pesos[0]){
        cout << 'N' << endl;
        return 0;
    }
    if(pesos[1]+pesos[5] > peso_p_andar){
        cout << 'N' << endl;
        return 0;
    }

    bool seg_andar = false;
    // 2° andar:
    for(int i=1; i<3;i++){
        // testar os 2 primeiros:
        int peso_andar_at = 0;
        peso_andar_at += pesos[i];

        for(int j=5; j>1;j--){
            if(j == i) continue;     
            if(peso_andar_at + pesos[j] == peso_p_andar) {
                // zerar os pesos:
                pesos[i] = 0; pesos[j] = 0;
                seg_andar=true;
                break; break;
            }
        }
    }

    if(seg_andar == false) {
        cout << 'N' << endl;
        return 0;
    }

    sort(pesos.begin(), pesos.end(), comp); 
    // não é 100% necessário
    if(pesos[1]+pesos[2]+pesos[3] != peso_p_andar){
        cout << 'N' << endl;
        return 0;
    }

    cout << 'S' << endl;
    return 0;
}


/*
100% nos exemplos; 20 minutos.
*/