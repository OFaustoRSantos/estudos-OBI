#include <bits/stdc++.h>
using namespace std;

// squencia de retangulos.

stack<int> altura;

// group

// chuta a mediana funciona? , não
// chute da moda/ menor?

int papeis = 2; // o primeiro, e o segundo pos corte

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int N;
    cin >> N;

    for(int i =0; i<N;i++){
        int int_at;
        cin >> int_at;

        if(int_at < altura.top()){
            papeis++;
        }

        altura.push(int_at);
    }

    cout << papeis << endl;
    // descobrir o cal
}