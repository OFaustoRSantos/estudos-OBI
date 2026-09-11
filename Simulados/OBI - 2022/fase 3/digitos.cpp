#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Problema: 
dois ints: A, B - usar long long
A <= B

Colocando um espaço após cada digito, não dando para ver quando um numero começa ou termina

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> digitos(N,0);
    long long valor_junto = 0;
    for(int i =0;i<N;i++){
        cin >> digitos[i];
        valor_junto += digitos[i] * pow(10,N-i-1);
        // cout << valor_junto << endl; - valor junto certo
    }
    // Caso dois valores de A: Produzir A com o menor valor possível

    // lógica, escrever todos os inteiros entre A e B.
    // Tem como pegar os 23 pontos sem fazer.

    // ideia inicial:
    // chutar tamanho de A, e ir efetuando soma.

    for(ll i=0; i < N/2 + 1; i++){
        // Assumindo A
        ll A = 0;

        // uma forma legal de pegar A
        A = valor_junto/pow(10,N-i-1);

        //cout << "fazendo teste A = " << A << ". comencando repeticoes " << endl;
        // tenho um valor de A, testar os próximos numeros até não ser

        bool vai_ate_fim = true;
        // até j ser igual a N;
        int j = i+1;
        int n_digitos_n_numero=i+1;
        int w =1;
        while(j<N){
            // pegar numero de casas de i mais um
            ll n_numero = A+w;
            ll numero_a_tira = valor_junto/pow(10,N-j);  
            //cout << "repeticao: " << w << ". n_esperado= " << A+w << endl;
            //cout << "valor a tirar: " << numero_a_tira<< endl;
            // Atualizando tamanho digitos proximo numero
            if(n_numero/pow(10,n_digitos_n_numero) == 1) n_digitos_n_numero++;
            cout << n_digitos_n_numero << endl;

            // pegando proximo numero
            ll next_numero_lista = 0;
            //for(ll w=1; w<=n_digitos_n_numero;w++){
            //    next_numero_lista += digitos[i] * pow(10,n_digitos_n_numero-w);
            //}
            // forma mais inteligente de pegar o valor
            next_numero_lista = (valor_junto-numero_a_tira*pow(10,N-j))/pow(10,N-j-n_digitos_n_numero);

            //cout << ". proximo numero= " << next_numero_lista<< endl;
            
            if(next_numero_lista != n_numero){
                vai_ate_fim = false;
                break;
            }
            

            j+=n_digitos_n_numero;
            if(j>N){
                vai_ate_fim = false;
                break;
            }
            w++;
            
        }

        if(!vai_ate_fim){
            continue;
        }
        cout << A << endl;
        return 0;
    }


}

/* - Começando 152 minutos
terminado: 

São 113 min agora, vou passar para o próximo.
minto, vou dar mais 20 min só

terminei em 55 minutos
1 hora para esse problema.

100% nos exemplos.

- bem mais dificil

*/