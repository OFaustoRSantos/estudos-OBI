// melancia
#include <iostream>
#include <vector>
using namespace std;

// Maior e + madura em todos
// Peso w, Pete e Billy são fãs de numero pares, logo divisão deve fazer
// cada um ter numero par de quilo
// onde w(p) pode ser != w(b)
// sendo w(p) e w(b) positivo

int main(){
    int w;
    cin >> w;
    // CASO p_b e p_p sejam inteiros é bem easy

    if(w%2 == 0){
        cout << "YES" << endl;
    }

    // mas se não necessáriamente ter que ser inteiro a resposta sempre será yes
    return 0;

}

// duas solução uma sempre printando yes, outra fazendo lógica acima, ainda usarei as duas variantes com ou sem endl somente por garantia
