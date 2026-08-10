#include <bits/stdc++.h>
using namespace std;

/*
5 opções
0 vence 1,2
1 vence 2,3
2 vence 3,4
3 vence 4,0
4 vence 0,1

Ou seja, o numero n ganha do n+1 e n+2;


*/

int pontos_X = 0;
int pontos_D = 0;



void vencedor(int dario, int xerxes){
    // descobre quem vence, true = dario, false = xerxes
    if(dario > xerxes){
        if((dario+1)%5 == xerxes || (dario+2)%5 == xerxes){
            pontos_D++;
        } else{
            pontos_X++;
        }
    }
    else{
        if((xerxes+1)%5 == dario || (xerxes+2)%5 == dario){
            pontos_X++;
        } else{
            pontos_D++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // N rodadas

    for(int i =0; i< N; i++){
        int D,X;
        cin >> D >> X;

        vencedor(D,X);
    }

    if(pontos_D > pontos_X){
        cout << "dario" << endl;
    } else{
        cout << "xerxes" << endl;
    }
    return 0;
}


// ta dando 0 de 100, mas não entendo aonde que está errado

// Correção gemini

/*
Você teve a ideia, mas errou detalhes de C++
Matemática modular + implementação
*/


/*
Burricimo, eu coloquei no final cout < xavier e não xerxes
Por isso mesmo mudando o algoritimo estava dando errado.
Ideal sempre verificar cout!

OBS 2.: Lembrar de usar parenteses

O que fiz na 1° tentativa estava certo:
bool vence(int a, int b) {
    return (b == (a + 1) % 5 || b == (a + 2) % 5);
}
*/


/*
bool vence(int a, int b) {
    return (b == (a + 1) % 5 || b == (a + 2) % 5);
}
*/