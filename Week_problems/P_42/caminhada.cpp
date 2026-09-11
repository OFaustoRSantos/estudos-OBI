#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
2 dimensões, andar por D metros.
0,0 -> x,y.
Ele pode não conseguir andar exatamente D km.
Mas ele que andar o mais próximo possível disso

Menor diferença entre D e quantidade de km que Juan anda;
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int D; cin >> D;

    // x e y tem que ser inteiros.
    // conseguir o maior par x,y onde x^2 + y^2 <= quantidade D
    // 441 -> 20^2 = 400
    // triangulos pitagóricos: 3, 4, 5

    // binary search
    
    // caçar entre intervalo do mais pitagórico possível e o numero
    
    if(D%5 == 0) 
    {cout << 0 << endl; return 0;}

    // valor minimo de x^2 + y^2.

}

// ta errado o problema, mas seria um legal de resolver

/* vem simples com "força bruta"*/

bool possivel(ll n) {
    ll n2 = n * n;

    for (ll x = 0; x <= n; x++) {
        ll resto = n2 - x * x;

        ll y = sqrt(resto);

        if (y * y == resto) {
            return true;
        }
    }

    return false;
}

int sol_(){
    ll D;
    cin >> D;

    for (ll dist = D; ; dist--) {

        if (possivel(dist)) {
            cout << D - dist << endl;
            return 0;
        }
    }
}