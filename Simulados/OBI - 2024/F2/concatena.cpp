#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
N digitos: 1 <= N <= 9 -> sem zero
numeros

OBS: se o numero tem X frequencia na lista ela só pode coloca-lo no maximo x vezes

size() - posição + 1 = potencia de 10
*/

vector<int> lista_num; // lista dos numeros

vector<int> respostas;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    // input

    int N; cin >> N; // Numero de digitos na lista

    int Q; cin >> Q; // Qntd de perguntas

    for(int i=0; i<N;i++){
        int digito; cin >> digito;
        lista_num.push_back(digito);
    }

    // Potencial:
        // N! possiveis posições;
        // cada numero aparece N-1 vezes em cada posição
        // logo (SUM (n-1) * x para cada x em N) * 11

    // Potencial contiguo é considerando somente alguns elementos da lista
    /* - logica antiga
    for(int i=0; i<Q; i++){
        int A, B; cin >> A >> B;
        // recebendo inicio e fim da lista
        // se so tivermos um numero nn da para concatenar então ignorar
        // Aqui definimos a quantidade de digitos available
        if(A-B == 0){
            respostas.push_back(0);
            continue;
        }
        vector<int> digitos_available(9,0); // qnt de digito disponível

        // for( lista inicio -> lista fim), digito_avalialable[list[i]-1]++;
        // definindo digitos available

        int sum = 0;
        int n_combinacoes = 1; // total de combinações
        for(int j=A-1;j<B;j++){
            digitos_available[lista_num[j]-1]++;
            n_combinacoes = n_combinacoes * (B-j);
        }

        //cout << "n_combinacoes para essa sublista é" << n_combinacoes << endl;

        int n_de_vezes_digito_aparece_ = n_combinacoes/(B-A+1);
        //cout << "n_de_vezes_digito_aparece_ para essa sublista é" << n_de_vezes_digito_aparece_ << endl;

        for(int j=0; j<9;j++){
            //cout << "sum antes de somar: " << sum << endl;
            //cout << "digitos_available para numero " << j+1 << " = " << digitos_available[j] << endl;
            // se um aparece 2 vezes então os numeros:
            // 12, 13,19, aparecem duas vezes


            sum += (j+1)*digitos_available[j] * n_de_vezes_digito_aparece_;
            //cout << "sum depois de somar: " << sum << endl;
            
        }


        int potencial = sum * 11;
        respostas.push_back(potencial);
        
    }
    */

    // Nova lógica:
    for(int i=0; i<Q; i++){
        int A, B; cin >> A >> B;
        // recebendo inicio e fim da lista
        // se so tivermos um numero nn da para concatenar então ignorar
        // Aqui definimos a quantidade de digitos available
        if(A-B == 0){
            respostas.push_back(0);
            continue;
        }
        vector<int> digitos_available(9,0); // qnt de digito disponível

        // for( lista inicio -> lista fim), digito_avalialable[list[i]-1]++;
        // definindo digitos available

        int sum = 0;
        int n_combinacoes = 1; // total de combinações
        for(int j=A-1;j<B;j++){
            digitos_available[lista_num[j]-1]++;
            n_combinacoes = n_combinacoes * (B-j);
        }

        //cout << "n_combinacoes para essa sublista é" << n_combinacoes << endl;

        int n_de_vezes_digito_aparece_ = n_combinacoes/(B-A+1);
        //cout << "n_de_vezes_digito_aparece_ para essa sublista é" << n_de_vezes_digito_aparece_ << endl;

        for(int j=0; j<9;j++){
            // se j aparece x vezes, todas as combinações de numero vão aparecer x;

            if(digitos_available[j]>1){
                // adicionando o par jj
                
                int repeticoes_de_j = digitos_available[j] * (digitos_available[j]-1);
                // sum de jj = n_de repetições * valor de j * 11
                sum += repeticoes_de_j * (j+1) * 11;
            }
            // adicionando outros pares:
            // se j == 2, então 2, 3 e 4 vai aparecer 2 vezes,
            
            // soma dos outros valores * numero de j
            
            for(int x=j+1; x<9;x++){
                // logo ele vai concatenar com todos maiores que ele
                // cada numero vai aparecer n_x *n_j vezes
                int repeticoes_xj = digitos_available[x] * digitos_available[j];
                sum += repeticoes_xj * (x+1+j+1) * 11;
            }
            //cout << "sum depois de somar: " << sum << endl;
            
        }

        respostas.push_back(sum);
        
    }


    // Output

    for(int i=0; i<respostas.size();i++){
        cout << respostas[i] << endl;
    }   

}

// Não deu 100 % nos testes, não sei porque

// descobri, algoritimo está errado; refarei ele

// 100% nos testes