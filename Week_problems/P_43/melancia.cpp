#include <bits/stdc++.h>
using namespace std;

/*
    escolha a maior e mais pesada
    w quilos

    P e B  só vao aceitar se duas partes = par
    Duas partes não precisam pesar igual


*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w; // peso melancia
    cin >> w;

    // w tem que ser par
    // duas partes pares = par; 
    // se w for impar, sempre terá uma parte impar e outra par

    if(w%2==0 ){    
        cout << "YES" << endl;

    } else{
        cout << "NO" << endl;
    }
}

// 4 minutos