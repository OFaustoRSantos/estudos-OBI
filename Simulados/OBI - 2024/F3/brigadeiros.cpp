#include <bits/stdc++.h>
using namespace std;

struct ponto{int id=0; int brigadeiros=0; int tipo=0;};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    n - brigadeiros
    k - amigos
    t - segundos restando
    */
    int N, K, T; cin >> N >> K >> T;

    ponto ponto_default;
    vector<ponto> brigadeiros(N,ponto_default);
    vector<int> membros_grupo;
    // pos_relativa, prato mais brigadeiro, do grupo atual
    pair<int,int> m_pos;

    for(int i=0; i<N;i++) {
        brigadeiros[i].id = i;
        cin >> brigadeiros[i].brigadeiros;
    }
    for(int i=0;i<N;i++){
        int a; cin >> brigadeiros[i].tipo;

        if(a == 1){
            membros_grupo.push_back(i);
        }

    }
    // N pratos disponíveis, N alunos
    // cada prato 0 a 9 brigadeiros

    // Seu grupo = subconjunto de K membros (contigo)
    // objetivo: maximizar o numero de brigadeiros

    // Cada membro do grupo, pode trocar de lugar a um vizinho (i+1, ou i-1)
    // só pode fazer um troca por segundo, existem T trocas disponíveis

    // ideia 1: dp[T] - melhor composição após obrigatórios T turnos; tenho só que colocar um early stop.

}

/*
- Não tive ideia para fazer, pulando.
Perdi muito tempo indo no banheiro :(
*/