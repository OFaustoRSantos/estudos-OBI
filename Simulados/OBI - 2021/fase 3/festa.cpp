#include <bits/stdc++.h>
using namespace std;

/*  - Lei para calcular lista convidados.
Suditos são 1 a N.
lista ordenada de suditos, 1° pos da lista = 1;

Terão M turnos:
Cada turno, sorteará um valor T1;
deve ser removido todos que ocupam posições multiplas de T1

no final mantem a ordem relativa, mas sem as posições que sairam
*/

// if(set_j.find(x) == set_j.end())

vector<int> fila_original;

vector<int> n_lista;
set<int> tirados;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N,M; cin >> N >> M;

    for(int i=0; i<N;i++){
        fila_original.push_back(i+1);
    }
    
    /* - ideia:
        faremos sempre um sort, e teremos o numero de posições tiradas no final, com isso vamos andar um ponteiro que é aonde realmente começa a lista
    
    */
    int ponteiro = -1;
    for(int i=0; i<M;i++){
        int T; cin >> T;
        //cout << "-> comecando turno: " << T << endl;
        //temos o numero n, vamos tirar todos os numeros de posição n
        /*
        numero elementos tirados
        */
        int j = 1;
        //cout << "| tirando os multiplos de T" << endl;
        for(j; T*j+ponteiro<N; j++){
            // loop para tirar os multiplos
            //cout << "tirando posicao " << j*T << " + o ponteiro no " << ponteiro << endl;
            //cout << "numero original: " << fila_original[ponteiro+j*T] << endl;
            fila_original[ponteiro+j*T] = 0;
        }
        j--;
        //cout << j << " numeros tirados" << endl;
        //cout << j;

        //cout << "| comecando sort da fila começando no ponteiro - 1" << endl;
        if (ponteiro == -1){
            sort(fila_original.begin(), fila_original.end());
        } else{
            sort(fila_original.begin() + ponteiro, fila_original.end());
        }

        // atualizando o ponteiro com numeros de elementos tirados
        ponteiro += j;
    }
    //cout << ponteiro << endl;

    int repeticoes = min(N,10000);

    // cout << "comecando resposta " << endl;
    // cout << repeticoes << " " << ponteiro << endl;
    for(int i=ponteiro+1; i<repeticoes;i++){
        cout << fila_original[i] << endl;
    }
}

// terminei em + ou - 40-50 minutos
/* - 100 % nos exemplos, terminar do processamento não está funcionando no site da OBI
*/