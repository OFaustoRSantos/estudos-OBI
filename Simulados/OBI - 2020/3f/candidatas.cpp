#include <bits/stdc++.h>
using namespace std;

/*
S
subsequencia de S é candidata se mdc é maior que 1;
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N = numero de elementos, M = numero de operações
    int N, M; cin >> N >> M;
    vector<int> mat_prote(N,0);
    for(int i=0; i<N;i++){
        cin >> mat_prote[i];
    }
    /*
    - Operação 1 -> Alterar valor de um elemento na sequencia
    - Operação 2 -> consultar numero de subsequencias em um trecho
    */

    for(int i=0; i<M;i++){
        int opera_at; cin >> opera_at; // T

        if(opera_at == 1){
            int i, v; cin >> i >> v;
            --i;
            mat_prote[i] = v;
        }   
        if(opera_at ==2){ 
            // cout por operações tipo 2
            int E,D; cin >> E >> D; // indice 1 do conjunto e indice 2;
            --E; --D;
            int numero_sequencias = 0;
            for(int j=E; j<D; j++){
                // começo de um numero novo

                vector<int> divisores;

                int mdc=1;
                
                divisores.push_back(mat_prote[j]);
                for(int w=j+1; w<D; w++){
                    // surgiu um numero, duas opções:
                    // Adicionar numero;

                    // Tirar numero;
                }
            }

        }

    }
}

/*
complexidade solução ideia 1:
M * (D-E) * (D-E)
não sei o quão viável ela é vamos testar se der certo é vai ter sido muito rápido desenvolver
*/


/*
To apanhando
*/