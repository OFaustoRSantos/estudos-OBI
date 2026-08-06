#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*
    Duas cabines ligadas por uma roldana.
    Ao uma subir outra desce

    Objetivo, levar todas caixas do 1° andar pro 2°

    // Só se pode colocar uma caixa por vez
    Peso cabine 1 - peso cabine 2 deve ser menor que 8
    int diff = max(P1,P2) - min (P1,P2);
*/

vector<int> caixas;
bool caixa_diff_menor_8 = false;

// acredito que seja tipo um sort, temos que 

// lógica com stack?:

/* 
    Acredito que uma solução boa seja fazer = o leetcode de daily temperatures
    encontrar o proximo na lista entre 8 maior unidades
    porém dar um sort na lista
    porém se for dar sort é mais facil fazer simplesmente por um while simples

*/


int main(){
    int N;
    cin >> N; // N de caixas

    for(int i=0; i<N;i++){
        int peso_at;
        cin >> peso_at;
        caixas.push_back(peso_at);

    }
    sort(caixas.begin(), caixas.end());
    if(caixas[0]>8){
        caixa_diff_menor_8 = true;
    }
    if(caixa_diff_menor_8)
    {
        cout << 'N' << endl;
        return 0;
    }
    for(int i=0; i<caixas.size()-1;i++){
        int diff = (caixas[i] - caixas[i+1]);
        // checando próxima caixa
        if(diff*diff > 64){
            caixa_diff_menor_8 = true;
        } else{
            continue;
        }
        if(caixa_diff_menor_8)
        {
            cout << 'N' << endl;
            return 0;
        }
    }

    cout << 'S' << endl;
    return 0;
}

/*
Resultado no Site OBI:
100/100;

*/


/* Comentarios Chat:

1. Você cria variáveis demais

Exemplo:

bool caixa_diff_menor_8 = false;

Depois:

if(...)
    caixa_diff_menor_8 = true;

if(caixa_diff_menor_8)

Você poderia fazer simplesmente

if(...)
{
    cout << "N";
    return 0;
}

Na OBI isso melhora bastante a legibilidade.

Você ainda escreve código "defensivo"

Exemplo:

else{
    continue;
}

Esse continue é desnecessário.

Você faz contas mais difíceis que o necessário

Você escreveu

if(diff*diff > 64)

Quando poderia escrever

if(caixas[i+1]-caixas[i] > 8)
// pois eu já dei sort
Muito mais simples.

Comentando demais

O principal problema

Você percebeu?

Você ficou procurando um algoritmo complicado.

Na verdade era um problema de observação matemática.

Isso acontece MUITO na OBI.

Você ainda entra muito rápido em

"isso deve usar alguma estrutura."

Muitas vezes não usa nada.
*/