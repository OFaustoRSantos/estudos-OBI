#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t; cin >> t;

    for(int testess =0; testess<t; testess++){
    
    int N; cin >> N;
    
    vector<int> docura(N,0);
    // dividir em K intervalos para comer todos de um grupo em cada dia.
    // mex = menor valor que não parece na sequencia
    
    vector<vector<int>> elemento(N+1,vector<int>());
    for(int i=0; i<N;i++){
        cin >> docura[i];
        elemento[docura[i]].push_back(i);
    }
    // objetivo fazer uma divisão onde MEX é igual
    
    // Saida: se não tem divisão: -1
    // se tiver: cout << n° de intervalo. e k linhas: cada com cout << começo intervalo << final intervalo.

    // ideia:
    // fazer um vector com cada numero tendo nele o indice onde fica o número.
    // se não temos 0, podemos ter qualquer intervalo. se só tivermos 1 - 0: cout << -1
    // se tivermos x zeros, temos que fazer agora 1<n<=x intervalos com o numero de elementos 1 (proximo elemento maior), se tivermos só 1 um, então cout << -1; assim por diante

    // 02222222011 - mex diferente, mesmo tendo dois 1. posição importa

}
}

// droga!