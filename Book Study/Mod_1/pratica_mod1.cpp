#include <vector>
#include <iostream>
#include <stack>
using namespace std;

void maior_ret_histo();

int main(){

}

void maior_ret_histo(){
    int N;
    cin >> N;
    long long areaMax;
    // quando eu andar uma posição, eu tenho que atualizar a área, e talvez a área max
    // largura = index 1° maior - index 1° menor

    vector<int> alturas;
    for(int i =0; i<N; i++){
        int altura_at;
        cin >> altura_at;
        alturas.push_back(altura_at);
    }

    stack<int> pilha;
    for(int i=0;i<N;i++){
        
        // Verificando se as ultimas alturas eram menores que a altura atual,
        // Quando a altura atual é menor que a ultima altura, precisamos calcular a area que conseguimos com a altura atual
        while (!pilha.empty() && alturas[pilha.top()] > alturas[i]) {
                int indice = pilha.top();
                pilha.pop();

                long long altura = alturas[indice];

                int direita = i; // ou seja indice maximo que podemos alcançar com essa altura (dps retira-se 1)

                int esquerda;

                if (pilha.empty())
                    esquerda = -1;
                else
                    esquerda = pilha.top(); // Novo ultimo menor - pois tiramos o que estamos vendo agr


                int largura = direita - esquerda - 1;

                long long area = altura * largura;

                areaMax = max(areaMax, area);
            }


            pilha.push(i);
        
    }

    // caso aonde chegamos no final da lista e não havia um menor;
    // Exemplo tem o numero 1 na lista, ou 2 etc
    while (!pilha.empty()) {
        int indice = pilha.top();
        pilha.pop();

        long long altura = alturas[indice];

        int direita = N;

        int esquerda;

        if (pilha.empty())
            esquerda = -1;
        else
            esquerda = pilha.top();

        int largura = direita - esquerda - 1;

        long long area = altura * largura;

        areaMax = max(areaMax, area);
    }

    cout << areaMax << endl;
    
}

/* Pseudocodigo sozinho para resolver o problema:
    Calculo do retangulo :
    diferença indice do ultimo menor e atual menor * altura

    sistema da fila:
    Se o numero atual for maior que o primeiro na pilha - não preciso calcular a area agora, logo só faço um push
    caso ele seja menor, terei que calcular a area do topo da pilha e tirar ele
    caso ele seja menor que o atual topo terei que fazer o mesmo logo um while
    
    para cada N (indice){
    while(!fila.empty() && alturas[fila.top()] > altura[i]){
        Calculo largura
        calculo área
        max()
    }
    
    incluir na pilha

    }

    Caso limite, onde o topo não encontra numero menor:
    Fazer recursividade para ir calculando esses casos

    exemplo menor numero é o 4 e ele aparece no indice 3, largura é absurdamente grande
    while(!fila.empty){
    }

*/