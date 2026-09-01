#include <bits/stdc++.h>
using namespace std;

/*
Qntd bolinhas mesa. Caixa vazia joão;

Mover bolinha da mesa para caixa.
- Se ao final da rodada caixa ter L ou + bolinhas, acaba partida
- Cada rodada, João pode mover no min A e no max B bolinhas
- Rodada inicia com João escolhendo X para mover.
-> OBS: João não pode escolher o mesmo x em cada rodada.
- Se joão não tiver um x valido a partida termina
*/

vector<int> rodadas_int;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    

    int partidas; cin >> partidas;
    for(int i=0; i<partidas;i++){
        int L, A, B; cin >> L >> A >> B;
        int rodadas=0;
        int b_at=0; // bolas atuais
        int menor_n = A;
        // Simples while t_b < L; insert menor x possivel entre A e B que nao tenha sido usado
        while(b_at<L){
            if(menor_n > B) break;
            b_at+= menor_n;
            rodadas++;
            menor_n++;
        }
        // Saida: qntd de rodadas igual qntd de chocolates
        // Saida: max de rodadas
        rodadas_int.push_back(rodadas);
    }
    
    for(int i=0; i< partidas;i++){
        cout << rodadas_int[i] << endl;
    }
}

// + ou - 20 min para ler tudo, + ou - 10 min para resolver esse

// 1° - Distindo - feito - 100% com os exemplos
// 2° - feira - feito - 100%;
// 3° - Placar - 100% com os exemplos
// 4° - mania - 100% com os exemplos