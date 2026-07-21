
# Estruturas Fundamentais: Pilhas, Filas, Vetores + Algoritimos STL

## Pilhas

### Ideia

Ao adicionarmos algo, o primeiro que sai sempre será o de cima, logo o ultimo adicionado

Por isso, a ideia do LIFO - Last In, First Out

### Exemplo

Verificar se todos os parenteses tem seus respectivos fechamento/abertura ( e )

Solução com pilha:
Empilhar "(" e ao ver um ")" desimpilhar
Ou seja:

Em vez de procurar, a pilha já "guarda" o candidato mais recente pendente, que
é sempre o certo a fechar primeiro.

### Funções da stack

push(x) → coloca x no topo
pop() → remove o elemento do topo (não retorna valor na STL)
top() → olha o elemento do topo sem remover
empty() → true se vazia

### Implementação manual (com vetor)

const int MAXN = 100005;

int stk[MAXN];

int topo = -1; // pilha vazia

void push(int x) { stk[++topo] = x; }

void pop() { topo--; }

int top() { return stk[topo]; }

bool empty() { return topo == -1;}

### Implementação STL

 #include <stack>
 using namespace std;

stack<int> st;
st.push(10);
st.push(20);

cout << st.top(); // 20
st.pop();
cout << st.top(); // 10

cout << st.empty(); // 0 (false)

#### OBS

Todas as operações citadas acima na pilha tem complexidade O(1)

### Additional

#### Erros clássicos

- Chamar top() ou pop() numa pilha vazia (comportamento indefinido — sempre
confira empty() antes)
- Achar que pop() retorna o valor removido — na STL, não retorna. Se precisa do valor,
salve com top() antes de dar pop().
- Usar pilha quando na verdade a ordem que importa é FIFO (aí é fila, não pilha)

#### Problemas clássicos (ordem crescente)


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

##### Desafio do problema 2. feito pelo gemini

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

#### Padrões

"Próximo maior/menor elemento à
direita/esquerda" -> Monotonic Stack

DFS sem recursão Pilha

#### Onde não usar

- Quando você precisa processar elementos na ordem de chegada (isso é fila)
- Quando precisa de acesso aleatório a qualquer posição (use vetor)

#### Outros problemas

- CSES: "Stack Sequences" (categoria Introductory)
- LeetCode: "Valid Parentheses" (fácil), "Daily Temperatures" (monotonic stack, médio)

### STL - Monotonic Stack

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

### Desafios

1. Valide se uma string de parênteses (){}[] está balanceada.
2. Dado um vetor, ache para cada elemento o próximo elemento à esquerda que é menor.
3. Simplifique um caminho de arquivo estilo Unix.
4. Ache o maior retângulo possível num histograma.
5. Avalie uma expressão em notação pós-fixa (RPN)

## Filas

- (Queue, Deque, Priority Queue, Heap)

Fila simples -> Base BFS
Deque -> Base 0-1 BFS e Sliding Window
Priority queue/heap -> Base do Dijkstra e de gulosos

### Estruturas

Queue: FIFO -> Quem entra primeiro sai primeiro
Deque: Fila que pode se inserir ou remover dos dois lados.
Priority Queue/heap: fila de pronto-soccorro -> Mais grave = Maior prioridade

### Problema de origem

Você tem um grafo e quer visitar todos os nós "em ondas" a partir de uma origem, garantindo que a primeira vez que alcança um nó é pela distância mínima (queue → BFS).
Depois, você tem pesos diferentes nas arestas e precisa sempre processar o nó de menor custo acumulado primeiro (priority_queue → Dijkstra).

### Estrutura codigo

Queue:          push_back → [ ] → pop_front
Deque:   push_front → [ ] ← push_back
                        (pop dos dois lados também)
Priority Queue: sempre entrega o de MAIOR prioridade (por padrão, o maior valor)

### Implementação manual

const int MAXN = 100005;
int arr[MAXN];
int inicio = 0, fim = 0;

void push(int x) { arr[fim++] = x; }
void pop() { inicio++; }
int front() { return arr[inicio]; }
bool empty() { return inicio == fim; }

### Implementação STL - duas bibliotecas

#include <queue>
#include <deque>
using namespace std;

// Queue
queue<int> q;
q.push(5); q.push(3);
q.front(); // 5
q.pop();

// Deque
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.front(); // 2
dq.back();  // 1
dq.pop_front();
dq.pop_back();

// Priority Queue (max-heap por padrão)
priority_queue<int> pq;
pq.push(3); pq.push(9); pq.push(1);
pq.top(); // 9 (o maior)
pq.pop();

// Priority Queue como MIN-heap (essencial para Dijkstra)
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(3); minpq.push(9); minpq.push(1);
minpq.top(); // 1 (o menor)

### Priority queue

priority_queue<int, vector<int>, greater<int>> minpq;
// priority_queue<tipo de dado a armazenar, modelo para armazenar memoria (só use vector<int>), adicionar para mudar ordem lista, nesse caso um min-heap usa: (greater<int>)> minpq;

### Visualização

```
Queue:  [5][7][9]  push(3) →  [5][7][9][3]
         ↑ front                remove daqui

Heap (max, como árvore):
          9
        /   \
       7     8
      / \
     3   5
```


### Erros clássicos

- Confundir front() (queue, olha o início) com top() (priority_queue/stack, olha o "maior"/topo)
- Esquecer que priority_queue por padrão é max-heap — para Dijkstra você precisa do min-heap: priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>
- Chamar pop()/front() em estrutura vazia
- Em Dijkstra, esquecer que a priority_queue pode ter entradas "desatualizadas" (o mesmo nó inserido mais de uma vez com distâncias diferentes) — sempre verificar se a distância ainda é válida ao processar


### Problemas clássicos


1. Simular fila de atendimento (fácil)
2. Menor caminho em grid sem peso (BFS) — médio
3. K-ésimo maior elemento com stream de números (priority queue) — médio
4. Menor caminho com pesos (Dijkstra) — difícil

### Padrões


| Se o enunciado diz... | Pense em... |
|---|---|
| Processar na ordem de chegada | Queue |
| Precisa inserir/remover nos dois extremos | Deque |
| "Sempre pegar o maior/menor disponível até agora" | Priority Queue |
| Pesos 0 e 1 nas arestas | Deque (0-1 BFS) |
| Pesos positivos quaisquer | Priority Queue (Dijkstra) |
| Top-K elementos de um fluxo de dados | Priority Queue |

### Casos onde NÃO usar

- Priority Queue quando você precisa de ordem FIFO estrita (ela vai "furar a fila" por prioridade)
- Queue simples quando as arestas têm pesos diferentes (aí BFS simples dá resposta errada — precisa de Dijkstra)

### Problemas OBI

- Problemas de simulação com fila de atendimento/processos
- Problemas de "menor caminho" em grid (ver Módulo 2)

### Outros problemas - Fila

- CSES: "Traffic Lights" (deque/multiset), "Sliding Window Median"
- LeetCode: "Sliding Window Maximum" (deque monotônico), "Kth Largest Element in a Stream" (priority_queue)

### Cheatsheet

```cpp
queue<int> q;
q.push(x); q.pop(); q.front(); q.back(); q.empty(); q.size();

deque<int> dq;
dq.push_front(x); dq.push_back(x);
dq.pop_front(); dq.pop_back();
dq.front(); dq.back();

priority_queue<int> pq;              // max-heap
priority_queue<int, vector<int>, greater<int>> pq2; // min-heap
pq.push(x); pq.pop(); pq.top();
```

### STL — Priority Queue com pares e structs

```cpp
// min-heap de pares (usado em Dijkstra: {distância, nó})
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// com struct e comparator customizado
struct Tarefa {
    int prioridade, id;
};
struct Comparador {
    bool operator()(const Tarefa& a, const Tarefa& b) {
        return a.prioridade > b.prioridade; // menor prioridade primeiro
    }
};
priority_queue<Tarefa, vector<Tarefa>, Comparador> pq3;
```

### Template BFS

```cpp
// BFS genérico usando queue — ver Módulo 2 para o template completo
queue<int> q;
q.push(origem);
while (!q.empty()) {
    int u = q.front(); q.pop();
    // processar u
}
```

### Desafios - Fila

1. Implemente uma fila usando dois vetores (sem deslocar índices).
2. Simule uma fila de atendimento com prioridade (VIP furando fila).
3. Ache a mediana de uma sequência de números que chega em tempo real (dois heaps).
4. Implemente sliding window maximum com deque.
5. Implemente 0-1 BFS usando deque.

### Mini-projeto - Fila

Sistema de fila de hospital: pacientes chegam com uma prioridade (1 a 5); simule o atendimento sempre pegando o de maior prioridade, e em empate, quem chegou primeiro.

### Duvida

Q: É possivel fazer uma fila com um pair ou um struct? uma priority queue especificamente?
Ans: Sim, é totalmente possível criar uma priority_queue (fila de prioridade) usando um pair ou um struct. Na verdade, essa é uma prática extremamente comum em algoritmos

#### Demostranção Duvida 1

priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({30, "Tarefa Baixa"});
    pq.push({10, "Tarefa Alta"});
    pq.push({20, "Tarefa Média"});

### Checklist de maestria

**Conhecimento**

- [ ] Sei explicar quando usar queue vs deque vs priority_queue
- [ ] Sei por que BFS precisa de queue (não pilha)
- [ ] Sei por que Dijkstra precisa de priority_queue (não queue simples)

**Implementação**

- [ ] Consigo declarar min-heap e max-heap sem erro
- [ ] Consigo implementar priority_queue com comparator customizado

**Reconhecimento**

- [ ] Reconheço "pesos 0 e 1" como sinal de deque/0-1 BFS
- [ ] Reconheço "sempre o maior/menor disponível" como priority_queue

**Competição**

- [ ] Resolvi pelo menos 3 problemas com queue/BFS
- [ ] Resolvi pelo menos 1 problema com priority_queue

---

## Vetores e STL de algoritimos

Dominar ferramentas de <algorithm>
Classicos:

- sort
- lower_bound
- upper_bound
- binary_search

Além do: pair, tuple, struct.

Ordenar é, sozinho, uma das operações mais poderosas em programação competitiva: depois de ordenado, muitos problemas viram "percorra e some" ou "faça busca binária".

Procurar onde valor se encaixaria num vetor ordenado - tecnica: lower_bound/upper_bound (O(log N)).

Sort e encontrar valor X ou mais proximo.

### Estrutura dos algoritmos citados

sort(begin, end)              → ordena o intervalo
lower_bound(begin, end, x)    → primeiro elemento >= x
upper_bound(begin, end, x)    → primeiro elemento > x
binary_search(begin, end, x)  → true/false se x existe

### Implementação manual()

int lowerBoundManual(vector<int>& a, int x) {
    int lo = 0, hi = a.size(); // hi é exclusivo
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo; // índice do primeiro elemento >= x
}

### Implementação com STL

#include <algorithm>
using namespace std;

vector<int> a = {5, 1, 4, 2, 3};
sort(a.begin(), a.end());               // {1,2,3,4,5}
sort(a.begin(), a.end(), greater<int>()); // decrescente

int x = 3;
auto it = lower_bound(a.begin(), a.end(), x); // aponta para o 3
int pos = it - a.begin();                      // índice = 2

auto it2 = upper_bound(a.begin(), a.end(), x); // aponta para o 4
bool existe = binary_search(a.begin(), a.end(), x); // true

// P.S: auto em C++ não é um tipo de dado, mas uma instrução para o compilador deduzir automaticamente o tipo da variável com base na expressão usada na inicialização.

### Uso do Pair, tuple, Struct

// pair — útil para (peso, nó), (x, y), etc.
pair<int,int> p = {3, 5};
cout << p.first << " " << p.second;

vector<pair<int,int>> v = {{3,1}, {1,2}, {2,0}};
sort(v.begin(), v.end()); // ordena por .first, depois por .second

// tuple — quando precisa de 3+ campos
tuple<int,int,int> t = {1, 2, 3};
auto [a1, b1, c1] = t; // structured bindings (C++17)

// struct com comparator customizado
struct Pessoa {
    string nome;
    int idade;
};

bool comparaPorIdade(const Pessoa& a, const Pessoa& b) {
    return a.idade < b.idade; // crescente
}

vector<Pessoa> pessoas = {{"Ana", 30}, {"Beto", 20}};
sort(pessoas.begin(), pessoas.end(), comparaPorIdade);

// comparator como lambda (mais comum em prova)
sort(pessoas.begin(), pessoas.end(), [](const Pessoa& a, const Pessoa& b) {
    return a.idade < b.idade;
});

### Visualizações


Vetor ordenado: [1, 2, 3, 3, 3, 5, 8]
                        ↑lower_bound(3)   ↑upper_bound(3)
                     (primeiro 3)      (primeiro depois dos 3s, o 5)


### Erros classicos

- Usar `lower_bound`/`upper_bound`/`binary_search` num vetor **não ordenado** — resultado incorreto e silencioso (não dá erro de compilação nem crash)
- Confundir `lower_bound` (>=) com `upper_bound` (>)
- Esquecer de subtrair `a.begin()` para converter iterador em índice
- Comparator que não é uma "ordem estrita fraca" (ex: usar `<=` em vez de `<`) pode causar comportamento indefinido no `sort`

### Problema de exemplo

eu tenho 12 numeros
Eu quero encontrar os maiores que 3
os menores que 2
os que estão entre 3 e 5

vector<int> v = {1, 2, 2, 3, 4, 5, 7, 9};
a---todos os números maiores que 3 (> 3)
Use upper_bound, porque ele retorna o primeiro elemento maior que 3.
auto it = upper_bound(v.begin(), v.end(), 3);

for (; it != v.end(); it++)
    cout << *it << " ";

b---Todos os números menores que 2 (< 2)

Use lower_bound, porque ele retorna o primeiro elemento maior ou igual a 2. Tudo antes dele é menor que 2.

auto it = lower_bound(v.begin(), v.end(), 2);

for (auto i = v.begin(); i != it; i++)
    cout << *i << " ";

c--Entre 3 e 5

auto ini = lower_bound(v.begin(), v.end(), 3);
auto fim = upper_bound(v.begin(), v.end(), 5);

for (auto it = ini; it != fim; it++)
    cout << *it << " ";

## Problemas clássicos disso

1. Ordenar e imprimir (fácil)
2. Contar quantos elementos são menores que X, para várias consultas (médio)
3. Ordenar structs por múltiplos critérios com comparator customizado (médio)

## Padrões — quando pensar nisso

| Se o enunciado diz... | Pense em... |
|---|---|

| "Quantos elementos são menores/maiores que X" | Ordenar + lower_bound/upper_bound |
| "Ordene por critério A, empate por critério B" | Comparator customizado |
| "Existe algum elemento igual a X" | binary_search (com vetor ordenado) |
| Pares (x, y) que precisam ser processados juntos | pair/tuple |

### Casos onde NÃO usar_

- `lower_bound`/`upper_bound` em vetor não ordenado (sempre ordene antes)
- `sort` quando a ordem original importa e não pode ser alterada (nesse caso, ordene índices, não os valores)

### Outros problemas_

- CSES: "Distinct Numbers", "Sorting and Searching" (categoria inteira)
- LeetCode: "Search Insert Position" (lower_bound direto)

### Cheatsheet_

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
sort(v.begin(), v.end(), [](auto&a, auto&b){ return a.x < b.x; });

lower_bound(v.begin(), v.end(), x) - v.begin(); // índice do primeiro >= x
upper_bound(v.begin(), v.end(), x) - v.begin(); // índice do primeiro > x
binary_search(v.begin(), v.end(), x);           // true/false
```

## STL — funções úteis extras

```cpp
reverse(v.begin(), v.end()); // inverte ordem lista
int mn = *min_element(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());
long long soma = accumulate(v.begin(), v.end(), 0LL);
v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicatas (vetor deve estar ordenado)
```

### Template

```cpp
vector<int> v = /* ler entrada */;
sort(v.begin(), v.end());
for (int query : queries) {
    int qtd_menores = lower_bound(v.begin(), v.end(), query) - v.begin();
    // usar qtd_menores
}
```

### Desafios_

1. Ordene uma lista de alunos por nota (decrescente), empate por nome (alfabética).
2. Para cada consulta X, responda quantos elementos do vetor são exatamente iguais a X (usando upper_bound - lower_bound).
3. Implemente `lower_bound` manualmente e compare com a versão STL.
4. Remova duplicatas de um vetor mantendo ordenado.
5. Ordene pares por soma dos elementos.

### Mini-projeto_

Sistema de ranking: dada uma lista de (nome, pontuação), ordene por pontuação decrescente e, para uma pontuação nova, responda em qual posição do ranking ela entraria (usando busca binária na lista já ordenada).

### Resumo final

`sort` organiza em O(N log N). Depois de ordenado, `lower_bound`/`upper_bound`/`binary_search` respondem em O(log N). `pair`/`tuple`/`struct` + comparator customizado permitem ordenar por critérios complexos. Erro clássico: usar busca binária em vetor não ordenado.

### Checklist de maestria

**Conhecimento**

- [ ] Sei explicar a diferença entre lower_bound e upper_bound
- [ ] Sei por que preciso ordenar antes de usar busca binária da STL

**Implementação**

- [ ] Consigo escrever um comparator customizado (lambda ou função)
- [ ] Consigo usar pair/tuple com structured bindings

**Reconhecimento**

- [ ] Reconheço "ordene e depois processe" como padrão de sort + binary search

**Competição**

- [ ] Resolvi pelo menos 3 problemas usando sort + lower_bound/upper_bound