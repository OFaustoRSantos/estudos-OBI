#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Problema: 

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // Numero de salas conectadas.

    int N, K; cin >> N >> K;
    vector<vector<int>> mat_adj (N, vector<int>());

    // comprou K radares, decidir quais salas colocar um radar
    // cada radar tem um raio de alcance K.
    // todas as salas com distancia <= R a sala com radar estão protegidas

    // Pergunta: Qual menor valor de R para que seja possibel escolher K salar onde todas as N salas fiquem protegidas

    // ideias: 
    /*
    - fazer igual problema dos quartos um dentro do outro
    -
    */
    // Grafo bidirecionado

    // achar maior distancia entre dois vertices.
    // tamanho do radar = distancia dividido por K - c
}

