#include <bits/stdc++.h>
using namespace std;

/*
Ladrilhos de 20x20cm
duas cores: brancos (centro), uma fileira de ladrilhos azuils em cada lateral;

dada quantidade de ladrilhos determinar proporção dimensões sala
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // A = ladrilhos azuis, B = ladrilhos brancos
    int A,B; cin >> A >> B;

    // azuis => dimensão branco + 2 cada - total ladrilhos brancos

    // Numero total de ladrilhos = A + B
    
    // 1° - achar dois numeros que multiplicados dão o numero B de ladrilhos

    // pares possíveis

    // Uma ideia que quero testar é um binary_search com um guloso.

    // se eu tenho B ladrilhos brancos, então calculamos numero de pares que dão B: se não houver pulamos;

    vector<int> pares;

    // a ideia de raiz de B vezes raiz de B = B, 
    int par_minimo = sqrt(B);
    // exemplo com B = 12; raiz de 12 ~ 3
    
    cout << par_minimo << endl; // ver se arredonda para o maior


    // saida
    // cout << menor_dimensão << maior_dimensão << endl;

}

/* - Não parece dificil, mas não to com uma ideia clara vou pular 13 minutos aqui

*/