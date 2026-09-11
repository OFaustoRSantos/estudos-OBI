#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Problema: 
Redistribuir para que todos tenham o mesmo peso

Dado os pesos carregados por cada camelo antes da parada.
escreva para cada camelo o peso o qual deve ser adicionado ou retirado para todos carregar o mesmo peso

Média, média - camelo[i]
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> camelos (N,0);
    int peso_total = 0;

    for(int i=0; i<N;i++){
        cin >> camelos[i];

        peso_total += camelos[i];
    }

    int pesos_por_camelo = peso_total/N;

    for(int i =0; i<N;i++){
        cout << pesos_por_camelo-camelos[i] << endl;
    }

    return 0;
}

/* - 100% com os exemplos ~8 minutos

*/