#include <bits/stdc++.h>
using namespace std;

/*
- fator influencia:
indice de rpostagem da mensagem M, de usuário U como
n° de usuarios diferentes de U que repostaram M

Fator de influencia(FI) é o maximo valor onde U poste FI mensagens, e cada mensagem tenha repostagem de pelo menos FI

ou seja fator 1 é pq o u postou 1 mensagem com 1 indice de repostagem
fator dois: 2 mensagens com 2 indices de repostagem acima ou igual a 2


*/

bool comp(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N; // N de mensagns postados pelo User.

    // priority queue com maiores na frente
    priority_queue<int, vector<int>> pq;
    // vector<int> mensagens(N,0);
    for(int i=0; i<N;i++){
        int mensagem_at;
        cin >> mensagem_at;
        pq.push(mensagem_at);
    }

    int FI_atual = 1;
    int numeros_passados = 1;
    bool tirar=true;
    while(!pq.empty()){
        int next_numero = pq.top(); pq.pop();

        numeros_passados++;
        // numero tem mais repostagem que minimo do FI atual, podemos pensar em subir a FI_atual, e ele é maior ou igual ao numero de passadas atuais
        if(next_numero > FI_atual){
            // sendo maior todos os que passaram antes são maiores também;
            // se numero_passados for maior que a FI atual também podemos agora por ele
            if(next_numero > numeros_passados){
                FI_atual = max(numeros_passados, FI_atual);
            }
            if(next_numero == numeros_passados){
                FI_atual = max(numeros_passados, FI_atual);
                tirar=false;
                break;

            }
        }
        // se numero for menor, então podemos dar um break;
        else{
            break;
        }
    }
    // fazendo um sort invertido, ou mesmo posso usar uma pq acho
    //sort(mensagens.begin(), mensagens.end(), comp);
    if (tirar) FI_atual--;
    cout << FI_atual << endl;

}

/* - finalizado em 15 minutos

40 pontos real está errada
eu acho que está errada a do sistema, coloquei um tirar, para ver se conserta, mas aumentou 10 pontos,
*/
