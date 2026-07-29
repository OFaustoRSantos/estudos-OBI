#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    N, n° de numeros menores ou = a N que são primos
    Para testar usará uma lista de numeros K
*/

// ta certo, mas os exemplos tão errados, não faz sentido

int n_primos = 0;

bool N_at_primo = true;

bool testar_divisibilidade(int N_teste, int K_divisor){
    if(N_teste < K_divisor){
        return false;
    }
    else if (N_teste == K_divisor){
        return false;
    }
    else if(N_teste%K_divisor == 0){
        return true;
    } else{
        return false;
    }
}

int main(){
    int N, K;
    vector<int> primos;
    cin >> N >> K;
    for(int i =0; i < K; i++){
        int primo_at;
        cin >> primo_at;
        primos.push_back(primo_at);
    }

    for(int N_at=N; N_at>0;N_at--){
        N_at_primo = true;
        cout << N_at << endl;
        for(int K_at : primos){
            if(testar_divisibilidade(N_at,K_at)){
                N_at_primo = false;
                break;
            }
        }
        if(N_at_primo){
            cout << "é primo" << endl;
            n_primos++;    
        }
    }
    cout << n_primos << endl;
}

// certo - mas complexo demais

// aproximadaments 70-80% com sorte, como nessa 2° fase nn costuma ter time limit, poderia ser possível 100%


// Lógica bem mais simples é possível:
/*
Ideia da solução (Inclusão-Exclusão):

Queremos contar quantos números de 1 até N NÃO são divisíveis
por nenhum dos K primos fornecidos.

Ao invés de testar cada número (O(N)), contamos o complemento:

    resposta = N - (quantidade divisível por pelo menos um primo)

Para isso usamos o Princípio da Inclusão-Exclusão:

- Somamos os múltiplos de cada primo.
- Subtraímos os múltiplos dos produtos de cada par de primos.
- Somamos novamente os produtos de cada trio.
- E assim por diante, alternando os sinais.

Como os números da lista são primos distintos, o MMC de um subconjunto
é simplesmente o produto de seus elementos.

Apesar de existirem 2^K subconjuntos, a busca pode ser podada:
assim que o produto ultrapassar N, nenhum superconjunto contribuirá
(com N/produto = 0). Como o produto de primos cresce muito rapidamente,
o número de subconjuntos realmente explorados é pequeno, tornando a
solução viável para N <= 10^9 e K <= 40.
*/


// Prova nn queria força bruta