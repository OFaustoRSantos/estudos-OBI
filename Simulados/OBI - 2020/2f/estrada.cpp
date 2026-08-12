#include <bits/stdc++.h>
using namespace std;

/*

Saida:

menor vizinhança

1- sort(), ordena distancias
2- criar tamanho vizinhança
3- sort, ordena tamanho vizinhanca,
. .  .

*/

// cruzou o pais, estrada unica linha reta


/* 
A vizinhança da estrada de uma cidade A é definida como todos os
pontos da estrada que são mais próximos do centro da cidade A do que do centro de qualquer outra
cidade
*/


vector<double> dist_oeste_cidade;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tamanho_estrada; cin >> tamanho_estrada;
    int cidades_passar; cin >> cidades_passar;

    for(int i=0; i<cidades_passar;i++){
        int cidade_at;
        cin >> cidade_at;

        dist_oeste_cidade.push_back(cidade_at);
    }

    //1- sort(), ordena distancias
    sort(dist_oeste_cidade.begin(), dist_oeste_cidade.end());
     
    //2- criar tamanho vizinhança
    vector<double> tam_viz;
    for(int i=0; i<cidades_passar; i++){
        // tirando casos limites
        if(i == 0){
            tam_viz.push_back(dist_oeste_cidade[0] + (dist_oeste_cidade[1] - dist_oeste_cidade[0])*10/20.00);
            continue;
        } if (i == cidades_passar-1){
            tam_viz.push_back(
                (tamanho_estrada - dist_oeste_cidade[i]) + (dist_oeste_cidade[i] - dist_oeste_cidade[i-1])*10/20.00);
            continue;
        }
        tam_viz.push_back(
            (dist_oeste_cidade[i+1] - dist_oeste_cidade[i])*10/20.00 + (dist_oeste_cidade[i] - dist_oeste_cidade[i-1])*10/20.00
        );
    }

    //3- sort, ordena tamanho vizinhanca,

    sort(tam_viz.begin(), tam_viz.end());

    cout << fixed << setprecision(2) << tam_viz[0]*10/10.00 << endl;

}

// fiz muito rapido também, porém submeti de novo no submite errado
// ta dando 20/100, não estou conseguindo achar onde estaria o erro
// achei o erro.
// 100/100

// 20 min para o problema quebra.cpp