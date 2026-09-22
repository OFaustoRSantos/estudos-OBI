#include <bits/stdc++.h>
using namespace std;

/*
729 é ao mesmo tempo cubo de um numero e quadrado de outro.
*/

/*
- ideia mais rápida:
fazer um sistema para printar todos os numeros que são cubos e quadrados, e depois criar uma lista com eles.
*/

// não acredito que força bruta serve, de fazer um a um até 100.000.000

/* - Ideia:
Menor cubor entre A-B:
verificar todos os cubos, e dos cubos verificar se o cubro é quadrado.

exemplo:
cubo 1 = 1
cubo 2 = 8
cubo 3 = 27
logo se o A é 64 que tem cubo o 4^3
o proximo cubo é somente o 5^3 que já é 125 logo muda muito o numero de cubos a verificar

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int A,B; cin >> A >> B;

    // descobrindo menor cubo entre A, B

    /*
    Menor cubo da lista
    */  

    int m_cubo = int(pow(A,1.0/3.0));
    //cout << m_cubo << endl;
    if(pow(m_cubo,3) < A) m_cubo++;
    //cout << m_cubo << endl;
    int n_cubos_quadrados=0;
    int cubo_at=m_cubo;

    //cout << "teste: " << pow(63, 1.0/2.0) << " " << int(pow(63, 1.0/2.0)/1) <<endl;

    while(pow(cubo_at,3)<=B){
        // cout << "testando: " << pow(cubo_at,3) << " cubo de " << cubo_at << endl;
        int n_at = pow(cubo_at,3);
        double n_at_sqrt = sqrt(n_at);
        if(int(n_at_sqrt)*int(n_at_sqrt) == n_at)  n_cubos_quadrados++;

        // cout << n_at_sqrt << endl;
        // pode ser inteiro ou não, 
        cubo_at++;
    }
    cout << n_cubos_quadrados;
}

/* - demorei 40 minutos - 100% nos exemplos
| Demorei mais que esperava também.
- 100% no teste consegui enviar
*/