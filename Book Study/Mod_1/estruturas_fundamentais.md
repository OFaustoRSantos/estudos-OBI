
# Pilhas

## Ideia

Ao adicionarmos algo, o primeiro que sai sempre será o de cima, logo o ultimo adicionado

Por isso, a ideia do LIFO - Last In, First Out

## Exemplo

Verificar se todos os parenteses tem seus respectivos fechamento/abertura ( e )

Solução com pilha:
Empilhar "(" e ao ver um ")" desimpilhar
Ou seja:

Em vez de procurar, a pilha já "guarda" o candidato mais recente pendente, que
é sempre o certo a fechar primeiro.

## Funções da stack

push(x) → coloca x no topo
pop() → remove o elemento do topo (não retorna valor na STL)
top() → olha o elemento do topo sem remover
empty() → true se vazia

## Implementação manual (com vetor)

const int MAXN = 100005;

int stk[MAXN];

int topo = -1; // pilha vazia

void push(int x) { stk[++topo] = x; }

void pop() { topo--; }

int top() { return stk[topo]; }

bool empty() { return topo == -1;}

## Implementação STL

 #include <stack>
 using namespace std;

stack<int> st;
st.push(10);
st.push(20);

cout << st.top(); // 20
st.pop();
cout << st.top(); // 10

cout << st.empty(); // 0 (false)

### OBS

Todas as operações citadas acima na pilha tem complexidade O(1)

## Additional

### Erros clássicos

- Chamar top() ou pop() numa pilha vazia (comportamento indefinido — sempre
confira empty() antes)
- Achar que pop() retorna o valor removido — na STL, não retorna. Se precisa do valor,
salve com top() antes de dar pop().
- Usar pilha quando na verdade a ordem que importa é FIFO (aí é fila, não pilha)

### Problemas clássicos (ordem crescente)


1. Validar parênteses balanceados (fácil)
(Feito dia 13/7)
(Score: _/100)
2. Simplificar caminho de diretório tipo /a/./b/../../c/ (médio)
(desafio pelo gemini)
(Feito dia 13/7)
(Score: _/100)
3. Maior retângulo em histograma — usa monotonic stack (difícil)
(Feito dia 13/7)
(Score: _/100)

#### Desafop do problema 2. feito pelo gemini

O Problema: Simplificação de Caminho Absoluto
Você recebeu uma string path que representa um caminho absoluto para um arquivo ou diretório em um sistema de arquivos no estilo Unix. Seu objetivo é convertê-lo para o caminho canônico simplificado.

Em um sistema de arquivos Unix, aplicam-se as seguintes regras:

Um único ponto (.) refere-se ao diretório atual (não faz nada).

Dois pontos consecutivos (..) referem-se ao diretório pai (move um nível para cima).

Qualquer sequência de múltiplas barras consecutivas (como //) é tratada como uma única barra /.

Qualquer outra sequência de caracteres é considerada um nome de diretório ou arquivo válido.

Regras para o formato do Caminho Canônico de saída:

Deve começar com uma única barra /.

Dois diretórios devem ser separados por exatamente uma barra /.

O caminho não deve terminar com uma barra /, a não ser que o caminho seja apenas a raiz (/).

O caminho não deve conter referências ao diretório atual (.) ou ao diretório pai (..). Se o comando .. tentar subir além do diretório raiz, o caminho deve permanecer na raiz.

Exemplos
Exemplo 1:

Entrada: path = "/home/"
Saída: "/home"
Explicação: Note que a barra no final é removida.

Exemplo 2:

Entrada: path = "/../"
Saída: "/"
Explicação: Subir um nível a partir do diretório raiz simplesmente mantém você na raiz.

Exemplo 3:

Entrada: path = "/home//foo/"
Saída: "/home/foo"
Explicação: Múltiplas barras seguidas são combinadas em uma única barra.

Exemplo 4:

Entrada: path = "/a/./b/../../c/"
Saída: "/c"
Explicação:

Entra em a

O . mantém no mesmo lugar

Entra em b

O primeiro .. volta para a

O segundo .. volta para a raiz /

Entra em c

Restrições
O comprimento da string path será entre 1 e 3000.

path consiste em letras (maiúsculas e minúsculas), números, pontos ., barras / ou sublinhados _.

path sempre começa com uma barra /.

### Padrões

"Próximo maior/menor elemento à
direita/esquerda" -> Monotonic Stack

DFS sem recursão Pilha

### Onde não usar

- Quando você precisa processar elementos na ordem de chegada (isso é fila)
- Quando precisa de acesso aleatório a qualquer posição (use vetor)

### Outros problemas

- CSES: "Stack Sequences" (categoria Introductory)
- LeetCode: "Valid Parentheses" (fácil), "Daily Temperatures" (monotonic stack, médio)

## STL - Monotonic Stack

Ideia: manter a pilha sempre crescente (ou decrescente).

// Exemplo: para cada elemento, achar o próximo maior à direita

vector<int> a = {2, 1, 2, 4, 3};

vector<int> resposta(a.size(), -1);
// Caso default, nenhum dos a tem um numero maior -> Exemplo tudo igual.

stack<int> st; // guarda ÍNDICES

for (int i = 0; i < (int)a.size(); i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
        resposta[st.top()] = a[i];
        st.pop();
    }
    // Vamos testar na fila até encontrar um maior que o elemento na lista
    st.push(i);
}
// resposta = [4, 2, 4, -1, -1]

/*
// i = 0:
    st vazio logo st tem posição - pushed
// i = 1:
    st não vazio, mas 1 menor que 2 logo foge do loop - pushed
// i = 2:
    st não vazio, e 2 é maior que 1, ou seja, loop inicia:
    - tira o 1 da lista e adiciona na posição do 1 nas respostas o numero 2
    - Como 2 é igual a dois loop não acontece de novo
    - adiciona o 2 na fila.
// i == 3
    st não vazio e como 4 é maior que dois inicia loop:
    - tira o 2 da pilha e adiciona na posição do 2 nas respostas o numero 4
    - Testa loop com nova elemento da pilha
    - adiciona o 4 na fila.
*/

## Desafios

1. Valide se uma string de parênteses (){}[] está balanceada.
2. Dado um vetor, ache para cada elemento o próximo elemento à esquerda que é menor.
3. Simplifique um caminho de arquivo estilo Unix.
4. Ache o maior retângulo possível num histograma.
5. Avalie uma expressão em notação pós-fixa (RPN)

# Filas