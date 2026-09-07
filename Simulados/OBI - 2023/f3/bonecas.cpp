#include <bits/stdc++.h>
using namespace std;

/*
mesmo formato tamanho diferente, vendidas semre em trio

um trio de A,B,C, sendo A<=B<=C, tem balanceamento = (A-B)^2 = pow(menor - do meio,2)

Ideal:
o balanceamento ser igual a 0;


*/

int sum_balanceamento=0;
vector<int> bonecas;

int balanceamento(int a, int b){ 
    return (a-b)*(a-b);};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // N = numero de bonecas; K = numero de trios
    int N, K; cin >> N >> K;

    for(int i=0; i<N; i++){
        int bon_at;
        cin >> bon_at;
        bonecas.push_back(bon_at);
    }

    sort(bonecas.begin(), bonecas.end());
    int ind_menor_bon= 0; 
    int ind_maior_bon= K-1;

    while(K>0){
        // ideia: pegar sempre as duas menores ou sempre as duas maiores;
        
        int balanceamento_menor = balanceamento(bonecas[ind_menor_bon], bonecas[ind_menor_bon+1]);
        int balanceamento_maior = balanceamento(bonecas[ind_maior_bon-1], bonecas[ind_maior_bon-2]);

        int balanceamento_at=min(balanceamento_maior, balanceamento_menor);
        
        if(balanceamento_maior < balanceamento_menor){
            ind_maior_bon-=3;
        } else{
            ind_menor_bon+=2;
            // escolha: pegar o ultimo, ou pegar o próximo
            if(balanceamento(bonecas[ind_menor_bon+1], bonecas[ind_menor_bon]) > balanceamento(bonecas[ind_maior_bon-1], bonecas[ind_maior_bon-2])){
                ind_menor_bon++;
            } else{
                ind_maior_bon--;
            }
        }

        // calcular balanceamento; Adicionar ao valor

        sum_balanceamento += balanceamento_at;
        K--;
    }

    cout << sum_balanceamento << endl;

}


/*
    começando em 230 min faltando

    tive de pausar em 219 min para almoçar

    11 minutos.
    - Tive que parar por um problema com as supp, terminando no dia seguinte com menos tempo.
    150 minutos
    terminando em min faltando
    Tempo no problema:
*/

// Pulei, não consegui fazer

// Lógica certa:

// Vou carregar o numero de balanceamento por X primeiras posições, para formar Y trios

// Vou ver o mínimo entre: usar esse par ou não usar

/* - Aprenda:
"escolher K coisas"
+
"há uma ordem natural"
+
"as escolhas anteriores afetam as próximas"
+
"queremos mínimo/máximo"
*/