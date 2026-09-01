# Comentário Chat_gpt prova de 2024

Seu desempenho na prova foi muito bom, mas tecnicamente você ainda não gabaritou essa prova.

- O cubo está correto. O alfabeto tem um caso escondido errado. O concatena tem a fórmula correta, mas problemas sérios de int. E o poder, apesar de passar nos exemplos, tem um erro algorítmico real.

## Overview da prova

| Problema                | Ideia principal       | Sua solução          | Ideal                | Avaliação                                |
| ----------------------- | --------------------- | -------------------- | -------------------- | ---------------------------------------- |
| **Cubo Preto**          | Matemática / contagem | Fórmulas             | Fórmulas             | 🟢 Correto                               |
| **Alfabeto Alienígena** | Frequência / array    | Arrays por categoria | `bool[128]`          | 🟡 Quase                                 |
| **Concatena Dígitos**   | Soma de prefixos      | Contagem por pares   | Prefix sum           | 🟡 Ideia correta, implementação perigosa |
| **Jogo do Poder**       | DSU + Small-to-Large  | Busca + memoização   | DSU + Small-to-Large | 🔴 Ideia inadequada                      |

A própria resolução do NOIC confirma exatamente essa progressão: somas de prefixos em Concatena e Union-Find + Small-to-Large em Jogo do Poder.

> Pensei em soma de prefixos, mas acabei não implementando aff

### Você já está muito bem em:

- matemática básica de contagem;
- implementação direta;
- arrays;
- exploração de padrões;
- prefixos, mesmo que você tenha chegado à fórmula por outro caminho;
- pensar em otimização;
- transformar observações do enunciado em código.

### Seu gargalo atual é outro:

| reconhecer a estrutura algorítmica antes de começar a programar.

## Overview por problema

### P1: Cubos

#### Avaliaçã geral

100% - perfect

#### Pequena melhoria

Você usou:

pow(N-2, 3)

Para programação competitiva, prefira:

long long x = N - 2;
cout << x*x*x << '\n';

Porque pow trabalha com double e não é necessário aqui.

### Problema 2 — Alfabeto Alienígena

O enunciado diz que existem até 68 caracteres possíveis, e precisamos verificar se todo caractere da mensagem pertence ao alfabeto alienígena.

Sua ideia foi:

"Vou separar letras maiúsculas, minúsculas, números e símbolos."

Isso funciona conceitualmente.

Você criou:

vector<int> lista_letra_maiscula(26,0);
vector<int> lista_letra_minuscula(26,0);
vector<int> lista_digitos(9,0);
vector<int> simbolos_especiais(6,0);

e depois classificou cada caractere pelo código ASCII.

Mas existe um bug.

Você fez:

else if(49 <= valor_char_at && valor_char_at <= 57)

Isso representa:

1 2 3 4 5 6 7 8 9

Mas o problema possui também o:

0

> Coisa simples nos testes eu corrigiria, de boa

#### melhoria muito maior

Você está fazendo uma classificação enorme:

if letra minúscula
else if letra maiúscula
else if número
else if +
else if -
...

Mas o problema não pede que você saiba que tipo de caractere é.

Só pergunta:

"Esse caractere está permitido?"

Era só usar o
bool permitido[128];

Eu não preciso me importar com todos os valores possíveis do ASCII. Só preciso de uma tabela grande o suficiente para comportar os caracteres que podem aparecer.

No problema, o enunciado restringe os caracteres a:

abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
0123456789
+-*/#!

Então todos eles têm códigos ASCII dentro de 0..127.

Por isso:

bool permitido[128] = {};

é suficiente.

#### Solução ideal

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;

    bool permitido[128] = {};

    for (int i = 0; i < K; i++) {
        char c;
        cin >> c;
        permitido[(int)c] = true;
    }

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;

        if (!permitido[(int)c]) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
}

### Problema 3

Da para gabaritar com o atual.
A matemática por trás dele funciona.
Mas existe uma solução muito mais bonita.

observação que você deveria guardar

Considere um intervalo com:

K=R−L+1

elementos.

Pegue um elemento qualquer:

a
i
	​


Ele pode aparecer como:

Dezena

Existem:

K−1

escolhas para a unidade.

Então ele contribui:

10a
i
	​

(K−1)
Unidade

Também existem:

K−1

escolhas.


Portanto:

Resposta=11(K−1) * sum ( i=L até R) ai

#### Sol ideal P3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> pref(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        pref[i] = pref[i - 1] + x;
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        long long soma = pref[R] - pref[L - 1];

        long long resposta =
            11LL * (R - L) * soma;

        cout << resposta << '\n';
    }
}

### Problema 4 - Poder

O enunciado possui até:

\[
N \times M \le 100000
\]

e cada poder pode chegar a:

\[
10^9
\]

Essa é claramente a questão que deveria consumir mais tempo.

E você gastou bastante tempo nela. Isso foi correto.

---

#### 9. Sua ideia no Jogo do Poder

Você percebeu corretamente:

> "Se meu poder atual é maior que o monstro, eu consigo matá-lo e aumentar meu poder."

E começou a construir uma espécie de busca com `priority_queue`.

Você também teve uma ótima percepção aqui:

if (valor_max_ponto[i][j] != matrix[i][j])

e tentou memorizar resultados para evitar refazer buscas.

Além disso, você percebeu que simplesmente fazer uma BFS para cada posição seria caro.

**Essa percepção é boa.**

O problema está em tentar transformar a busca individual em uma memoização local.

---

#### 10. Seu algoritmo realmente falha

Não é apenas uma questão de estilo.

Existe um contraexemplo muito pequeno:

```text
8 7 7
```

A resposta correta é:

```text
22 22 22
```

Porque começando em qualquer posição:

##### Começando no 7

Você pode matar o outro 7:

[
7 + 7 = 14
]

Depois consegue matar o 8:

[
14 + 8 = 22
]

#### Seu programa

Produz:

```text
22 14 14
```

Ou seja, ele perde a possibilidade de uma célula se beneficiar de uma região que foi descoberta por outra célula.

- basta mudar a condição para adicionar na priority queue - comentário próprio

Esse é exatamente o tipo de situação que sua variável:

```text
valor_max_ponto
```

não consegue representar corretamente.

---

#### 11. A grande ideia do Jogo do Poder

Aqui está a abstração que eu quero que você aprenda.

Em vez de perguntar:

> "O que acontece se eu começar em cada célula?"

pergunte:

> **"Quais células podem ser agrupadas em uma mesma componente?"**

Isso muda completamente o problema.

A solução oficial comentada pelo NOIC usa:

* Union-Find / DSU;
* processamento em ordem crescente dos poderes;
* Small-to-Large;
* uma estrutura de candidatos para cada componente.

---

#### 12. Pense primeiro em uma linha

Imagine:

```text
2 3 1 10
```

Ativamos as células em ordem de poder:

```text
1
2
3
10
```

Quando ativamos uma célula, todas as células menores ou iguais a ela já estão "disponíveis".

Uma componente mantém:

```text
soma dos poderes
```

*

```text
candidatos
```

Um **candidato** é uma posição que ainda consegue dominar toda aquela componente.

Por exemplo:

```text
[2] [3]
```

Se a soma da primeira componente é:

[
2
]

ela não consegue dominar um monstro de poder 3.

Então o candidato 2 morreu naquele momento.

Sua resposta fica definitivamente:

[
2
]

---

#### 13. A regra fundamental

Suponha que estamos ativando uma célula de poder `x`.

Existe uma componente vizinha com soma:

```text
sum
```

Se:

```text
sum < x
```

então os candidatos daquela componente **não conseguem derrotar `x`**.

Logo, suas respostas estão fechadas:

```cpp
ans[candidato] = sum;
```

Por outro lado, a nova célula `x` consegue derrotar **todos os monstros daquela componente**, porque todos eles têm poder:

[
\le x
]

Então podemos unir as componentes.

---

#### 14. O que é Small-to-Large?

Suponha:

```text
componente A:
candidatos = {1, 5, 8, 10}

componente B:
candidatos = {3, 7}
```

Ao unir:

```text
A + B
```

queremos mover o menor conjunto para o maior.

Então:

```cpp
if (cand[A].size() < cand[B].size())
    swap(A, B);
```

e:

```cpp
for (int x : cand[B])
    cand[A].push_back(x);
```

Isso garante que cada candidato não seja movido muitas vezes.

É a técnica **Small-to-Large**.

---

#### 15. Solução ideal do Jogo do Poder

Uma implementação simples e bastante didática:

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> pai;
    vector<ll> soma;
    vector<vector<int>> candidatos;

    DSU(vector<ll>& valor) {
        int n = valor.size();

        pai.resize(n);
        soma = valor;
        candidatos.resize(n);

        for (int i = 0; i < n; i++) {
            pai[i] = i;
            candidatos[i].push_back(i);
        }
    }

    int find(int x) {
        if (pai[x] == x)
            return x;

        return pai[x] = find(pai[x]);
    }

    void unir(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Small-to-Large:
        // queremos colocar o vetor menor no maior.
        if (candidatos[a].size() < candidatos[b].size())
            swap(a, b);

        pai[b] = a;

        soma[a] += soma[b];

        for (int x : candidatos[b])
            candidatos[a].push_back(x);

        candidatos[b].clear();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int V = N * M;

    vector<ll> valor(V);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> valor[i * M + j];
        }
    }

    vector<int> ordem(V);

    for (int i = 0; i < V; i++)
        ordem[i] = i;

    sort(ordem.begin(), ordem.end(), [&](int a, int b) {
        return valor[a] < valor[b];
    });

    DSU dsu(valor);

    vector<bool> ativo(V, false);
    vector<ll> resposta(V, -1);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int pos : ordem) {

        ativo[pos] = true;

        int i = pos / M;
        int j = pos % M;

        for (int d = 0; d < 4; d++) {

            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni < 0 || ni >= N ||
                nj < 0 || nj >= M)
                continue;

            int viz = ni * M + nj;

            if (!ativo[viz])
                continue;

            int a = dsu.find(pos);
            int b = dsu.find(viz);

            if (a == b)
                continue;

            /*
                Se a soma da componente vizinha
                é menor que o poder da célula atual,
                nenhum candidato daquela componente
                consegue chegar até a célula atual.
            */
            if (dsu.soma[b] < valor[pos]) {

                for (int candidato : dsu.candidatos[b]) {
                    resposta[candidato] = dsu.soma[b];
                }

                dsu.candidatos[b].clear();
            }

            dsu.unir(a, b);
        }
    }

    /*
        Os candidatos que sobreviveram até o final
        conseguem dominar a componente inteira.

        Como a matriz é conexa, essa componente
        contém todas as células.
    */
    int raiz = dsu.find(0);

    for (int candidato : dsu.candidatos[raiz]) {
        resposta[candidato] = dsu.soma[raiz];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (j)
                cout << ' ';

            cout << resposta[i * M + j];
        }

        cout << '\n';
    }
}
```

A solução do NOIC descreve exatamente essa estratégia: componentes, soma dos poderes, candidatos, ativação em ordem crescente e remoção dos candidatos quando a soma da componente não alcança o próximo poder.

---

#### 16. Sua evolução de 2024 para cá

Isso é o que mais me chama atenção.

Nas provas anteriores que corrigimos, você estava frequentemente fazendo:

> "Parece BFS."

ou:

> "Vou tentar força bruta."

Agora você já está fazendo:

> "Priority queue."

> "Preciso de memória por ponto."

> "Talvez eu consiga aproveitar um resultado já calculado."

Isso é uma evolução **real**.

O próximo salto é:

### Antes

```text
problema
    ↓
algoritmo conhecido
    ↓
código
```

#### Agora

Você precisa chegar em:

```text
problema
    ↓
qual é a estrutura matemática?
    ↓
qual propriedade permanece verdadeira?
    ↓
qual informação realmente importa?
    ↓
qual algoritmo mantém essa informação?
    ↓
código
```

Essa mudança de mentalidade é uma das coisas mais importantes para você avançar nas provas da OBI.

```
```
