#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// terminado 100% - ~20 min

int main(){
    // linhas N, e colunas N, N sempre par
    // dois quadrados com figurinha, em qualquer posição
    // comprou uma barra, quer dividir

    // Por ser quadrado, ele pode dividir de 2 formas,
    // faremos os testes com essas duas formas
    int N; //dimensão quadrado
    cin >> N;
    struct position{int x; int y; int quadrante;};
    vector<position> figurinhas;
    position n_figurinha;
    n_figurinha.quadrante = -1;
    cin >> n_figurinha.x >> n_figurinha.y;
    figurinhas.push_back(n_figurinha);
    cin >> n_figurinha.x >> n_figurinha.y;
    figurinhas.push_back(n_figurinha);

    // ver posição fig_1 e definir a partir dela
    // quadrante 1: x < N/2, y<N/2
    // quadrante 2: x > N/2, y<N/2
    // quadrante 3: x < N/2, y>N/2
    // quadrante 4: x > N/2, y>N/2
    for(int i =0; i<2;i++){
        if(figurinhas[i].x <= N/2){
            if(figurinhas[i].y <= N/2){
                figurinhas[i].quadrante = 1;
            }else{
                figurinhas[i].quadrante = 3;
            }
        } else{
            if(figurinhas[i].y <= N/2){
                figurinhas[i].quadrante = 2;
            }else{
                figurinhas[i].quadrante = 4;
            }   
        }
    }
    if(figurinhas[0].quadrante != figurinhas[1].quadrante){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}

/*
O que você acertou

Quando li seu código, a primeira impressão foi positiva.

Você pensou exatamente na estrutura natural do problema.

vector<int> fila;

As operações ficaram intuitivas.

Inserção

fila.insert(...)

Consulta

for(...)

Se o problema tivesse

N ≤ 500
Q ≤ 500

eu diria que sua solução estava praticamente pronta.

Ou seja, o raciocínio não estava errado.

========================
// Erros básicos que vale a pena testar:
========================

Coloquei fila.begin()+I-1
sendo que não havia necessidade do -1 pois o I já começava no zero

- Sempre inicie o valor!

Operação 1

Você fez

for(int i=I-1;i>=0;i--)

Gostei.

A ideia está certa.

Vai caminhando para frente da fila.

Depois

if(fila[i]>=fila[I-1]+X)

Também correto.

Mas apareceu um bug.

Você declarou

int pos;

E se ninguém satisfizer?

pos nunca recebe valor.

Depois

cout<<pos;

Resultado:

lixo de memória.

Sempre fazemos

int pos=-1;

*/


/*
==========================
Complexidade:
==========================

Qual a complexidade?

Vamos medir.

Inserção

vector.insert()

Quanto custa?

Imagine

1 2 3 4 5 6

Inserindo

99

na posição 2.

O vetor vira

1 2 99 3 4 5 6

Quem moveu?

3
4
5
6

Quatro elementos.

Ou seja

O(N)

e na consulta também gasto O(N)
*/

/*
Como tive esse erro na estrutura o legal é sempre pensar nesse framework:

Enunciado

↓

Quais operações existem?

↓

Inserir

Consultar

Remover

↓

Qual estrutura faz essas operações rápido?

============
Tabelinha de estruturas
Algumas estruturas famosas
Estrutura	Inserção	Busca	Remoção
vector	O(N)	O(1) índice	O(N)
deque	O(1) pontas	O(1) índice	O(1) pontas
list	O(1)	O(N)	O(1)
set	O(log N)	O(log N)	O(log N)
map	O(log N)	O(log N)	O(log N)
priority_queue	O(log N)	menor/maior O(1)	O(log N)

Preciso estudar elas
*/