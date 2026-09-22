#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Casamento dois numeros A, B:
| A e B tem mesmo numero de digitos - adicionando zeros a esquerda se necessário.
| Cada digito de A é comparado com digito de B.
-> O digito de menor valor é eliminado do numero em que pertence. (se os digitos são iguais nenhum é eliminado).
| Resultado casamento é o par formado pelos numeros remanecestes de A e B.
Se não houver digito remanescente para um dos números, o resultado é -1 para esse numero.

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    /* - Dado dois numeros A e B, fale o valor do casamento dos dois */
    string A,B; cin >> A >> B;

    int tam_max = max(A.size(), B.size());

    /* Vetor do valor a, aonde o v_int_a = o digito na casa tam_max-i. e o valor do numero é sum(v_int_a * pow(10,tam_max-i)) tam_max-i */
    vector<int> v_int_a(tam_max,0);
    vector<int> v_int_b(tam_max,0);
    int tam_a = A.size();
    int tam_b = B.size();

    for (int i = 0; i < tam_a; i++) {
        v_int_a[tam_max - 1 - i] = A[tam_a - 1 - i] - '0';
    }
    
    for (int i = 0; i < tam_b; i++) {
        v_int_b[tam_max - 1 - i] = B[tam_b - 1 - i] - '0';
    }
    //cout << endl;

    /*
    Teste verificar se vetores estão corretos
    */
    //for(int i=tam_max-1;i >=0; i--) {cout << v_int_a[i];} cout << endl;

    //for(int i=tam_max-1;i >=0; i--) {cout << v_int_b[i];} cout << endl;

    vector<int> n_vet_a;
    vector<int> n_vet_b;
    // Ordem do n_vet_a vai ser oposta ao do v_int_a; o item 0 é igual ao tam_max-i; Para cortarmos as casas
    for(int i=0; i<tam_max; i++){
        // comparativo dos dois numeros
        if(v_int_a[i] == v_int_b[i]){
            n_vet_a.push_back(v_int_a[i]);
            n_vet_b.push_back(v_int_b[i]);
        }
        else if(v_int_a[i] > v_int_b[i]){
            n_vet_a.push_back(v_int_a[i]);
        }
        else{
            n_vet_b.push_back(v_int_b[i]);
        }
    }
    
    int n_tam_a = n_vet_a.size(); int n_tam_b = n_vet_b.size();

    int n_int_a, n_int_b;
    bool n_int_a_existe  = false, n_int_b_existe = false;

    for(int i=0; i<n_tam_a; i++){
        n_int_a+=n_vet_a[i]*pow(10,n_tam_a-i-1);
        if(!n_int_a_existe) n_int_a_existe = true;
    }
    for(int i=0; i<n_tam_b; i++){
        n_int_b+=n_vet_b[i]*pow(10,n_tam_b-i-1);
        if(!n_int_b_existe) n_int_b_existe = true;
        
    }
    /*
    - Fazendo isso para contar o caso aonde o novo_int_a e o novo_int_b pode ser igual a 0;
    */
    n_int_a = (n_int_a_existe) ? n_int_a : -1;
    n_int_b = (n_int_b_existe) ? n_int_b : -1;
    if(n_int_a > n_int_b)
    cout << n_int_b  << " " << n_int_a << endl;
    if(n_int_a <= n_int_b)
    cout <<  n_int_a <<  " "  << n_int_b  << endl;
}

/* - Demorei uma hora nessa questão por bugs bestas. 
Irei relevar pois tive quase menos de 6h sono, mas ainda assim complicado

Não deu para submeter por algum erro do servidor - 100% nos exemplos.
*/