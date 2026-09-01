#include <bits/stdc++.h>
using namespace std;
/*
- Cubo de lado N -> pintou -> N^3 cubos de 1cm de lado
*/


int main(){
    
    // 3 pintadas: Numero de bordas totais - extremidades -> 8
    // 2 pintadas: Numero nas bordas
    // 1 pintadas: (N-2)^2 * 6
    // 0 pintados: (n-2)^3

    int N; cin >> N; // dimensão

    // 0
    if(N-2>0) cout << pow(N-2, 3) << endl; else cout << 0 << endl;
    // 1
    if(N-2 >0) cout << pow(N-2,2) * 6 << endl; else cout << 0 << endl;
    // 2: N-2 (uma lateral) * 4 (4 laterais por face) * 3 ( repete-se isso 3 vezes, opostos e uma a mais para incluir os que estão no "meio")
    if(N-2 >0) cout << (N-2)*4*3 << endl; else cout << 0 << endl;
    // 3
    if(N>1) cout << 8 << endl; else cout << 1 << endl;
} 

// Super easy primeira questão
// finalizada em 4 minutos, fiz o caso do escolher 1, mas não faz difernça

// 100 % nos exemplos