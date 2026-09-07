# OBI fase 3- 2023

Apanhei muito

## Preciso mudar abordagem

ler o enunciado → identificar a estrutura → provar a observação → implementar.

ler → pensar em uma estratégia plausível → codar → testar.

## Pirâmide

São somente 6 cubos, logo resolução mais fácil (quando são poucas possibilidade):

Logo forma mais fácil:

vector<int> v;

    for(int i = 0; i < 6; i++)
    {
        int aux; cin >> aux;
        v.push_back(aux);
    }

    //ordeno para o next_permutation checar todos os casos
    sort(v.begin(),v.end());

    //guarda se consegui achar uma posição que é válida
    bool dah = false;

    //enquanto tiver uma permutação que não foi testada, testo ela e tento gerar outra
    do
    {
        int primeira = v[5];
        int segunda = v[3] + v[4];
        int terceira = v[0] + v[1] + v[2];

        //testo se satisfaz a condição
        if(primeira == segunda && segunda == terceira) dah = true;
    }
    while(next_permutation(v.begin(),v.end()));

    //a função next_permutation gera, para uma sequência, a próxima em ordem lexicográfica
    //se tiver uma próxima, ela retorna true, se não, retorna false

    if(dah) cout << "S";
    else cout << "N";

Esse next_permutation é legal.

Preciso achar a solução mais simples o mais rápido possível

- gabaritei mas podia ter sido mais rapido

> Caso N seja pequeno basta usar força bruta

## Oficina - também gabaritado

Zero comentários, solução com duas priority_queue ficou sensacional

## Trio

- Apanhei

Abordagem errada:
pegar as menores ou pegar as maiores
( essa que usei ) (talvez o certo seria fazer um novo vetor com a diferença entro o i e o i+1)

1 - Ordenar decrescente

### Lógica usa DP

Lógica final: bem mais inteligente:

Escolher K pares adjacentes, garantindo que existam pelo menos 3K bonecas processadas.

Tanto faz o 3 que é o maior, precisamos de K pares adjacentes.

dp[posição][formar K trios]

Duas escolhas:

1- Não usar boneca atual no par:
dp[pos][k] = dp[pos-1][k]
// Se eu não usar vou simplesmente continuar com o mesmo balanceamento.

2- Usar atual e anterior
dp[pos][k] =
    dp[pos-2][k-1] // pegando o balanceamento quando já fechou os grupos, e por isso não inclui o pos-2
    + (a[pos-1] - a[pos])²

Onde pos >= 3*k

Após ordernarmos, temos que dp[pos][k] significa:
usando as primeiras X posições, qual o menor balanceamento necessário para formar k pares

Se queremos que a[pos] participe de um par, com quem ela deve ser pareada?

A observação do problema é:

Se a[pos] for o menor elemento de um par, é ótimo pareá-lo com o elemento imediatamente anterior
a[pos-1] x a[pos]

tendo essa lógica agora fica um pouco mais fácil:

- Interar para os N primeiros posições, interando para os K trios

### Solução

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> a(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    // sort decrescente
    sort(a.begin() + 1, a.end(), greater<long long>());

    const long long INF = 4e18;

    vector<vector<long long>> dp(
        N + 1,
        vector<long long>(K + 1, INF)
    );

    dp[0][0] = 0; // definindo raíz

    // Começando da pos 1 até a N
    for (int pos = 1; pos <= N; pos++) {
        // em cada posição testar o máximo de K possível
        for (int k = 0; k <= K; k++) {

            // caso impossíveis, pular
            if (pos < 3 * k)
                continue;

            // Não formar um par usando essa boneca - definindo valor de base
            dp[pos][k] = dp[pos - 1][k];

            // Usar a boneca atual e a anterior
            // Se não valor certo já definido
            if (k > 0 && pos >= 2) {

                long long dif = a[pos - 1] - a[pos];

                if (dp[pos - 2][k - 1] != INF) // se posição não for impossivel: Caso do pos = 0 e k =4
                {
                    dp[pos][k] = min(
                        dp[pos][k],
                        dp[pos - 2][k - 1] + dif * dif
                    );
                    // se o balanceamento aumentar usando esse par: não use
                }
            }
        }
    }

    cout << dp[N][K] << '\n';
}

## transporte, não lembrava dijkstra e pulei

saber qual estação estou é insuficiente

Preciso saber a estação e o tipo de transporte
estado (vertice, tipo)
-> Exemplo se for um personagem que pode trocar entre fogo e agua porém a troca tem um custo, qual o menor custo para alcançar Y partindo de X

// Quando o futuro depende de alguma informação que não está representada no vértice, essa informação provavelmente precisa virar parte do estado.

Se fosse tudo 100 conectado teriamos algo igual um DP, porém não é o caso

troca de estado:

(vertice_atua, sistema_atual) -> (novo_vertice, sistema_atual)
tenho que sair:
(novo_vertice, sistema_atual) -> aux[novo_vertice]
aux[novo_vertice] -> (novo_vertice, sistema novo escolhido);
Custo = P[novo_sistema]

Portanto, temos um grafo normal com pesos positivos.

Esse aux é isso, uma aresta auxilia

### Dijkstra normal temos

dist[u] -> Menor distancia para alcançar o vertice u

Entendi, computamos a menor distancia para chegar em u, mas não qual tipo estamos quando chegamos em u

cada aresta adicionada nesse grafo bidirecionado cria dois estados:

(u, s) e (v, s) -> sendo s o sistema da aresta

Portanto por lógica temos no máximo 2M de estados sendo M o numero de arestas

para trocar de sistema pagamos o preço do sistema 

Para reudizr as milhares arestas temos o vertice auxiliar:

### Verticie auxiliar

sair do sistema: 
aux[B] - vertice auxiliar
trocar transporte

dijkstra, duas opções:

- sair da linha -> entrar no aux[x], sem limite
- manter na linha -> se mover sem pagar, ai no caso só podemos andar por aqueles que forem da nossa linha

pelo dijakstra ser um guloso, ele sempre tenterá manter na mesma linha no começo 

estado_at = (vértice, tipo de transporte)

estando em (v,sistema S) temos duas possibilidades:

- continuar usando S
- sair para a auxiliar de v e escolher outro sistema

### Desenhando um grafo com tudo isso, bem dificil (parece)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Aresta {
    int destino;
    ll custo;
};

struct ArestaOriginal {
    int u, v, sistema;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    // Preço para entrar em cada sistema
    vector<ll> P(K + 1);

    for (int i = 1; i <= K; i++) {
        cin >> P[i];
    }

    vector<ArestaOriginal> arestas(M);

    /*
        id[(u,s)] = número do vértice que representa
                    "estou na estação u usando o sistema s"
    */
    /*
    Map = dicionário: Chave -> valor
    ou seja, digitando um par [x,y] recebemos W
    */
    map<pair<int, int>, int> id;

    int qtd_vertices = 0;

    // função lambda -> função que você cria no lugar
    // Esse [&] permite ela acessar variaveis fora das no parentese

    // Objetivo dela: se par não existe crie novo ID, se não retorne o id existente
    auto get_id = [&](int u, int sistema) {

        pair<int, int> estado = {u, sistema};

        // id.count(estado) retorna 0 se não tiver nenhum.
        if (!id.count(estado)) {
            id[estado] = qtd_vertices++;
        }

        return id[estado];
    };


    /*
        Primeiro lemos todas as arestas.

        Para cada:

            u -- sistema -- v

        precisamos dos estados:

            (u,sistema)
            (v,sistema)
    */

    for (int i = 0; i < M; i++) {

        int u, v, sistema;

        cin >> u >> v >> sistema;

        arestas[i] = {u, v, sistema};

        get_id(u, sistema);
        get_id(v, sistema);
        // temos o ID de cada aresta
    }

    /*
        Agora criamos uma auxiliar para cada estação.

        aux[u] representa:

        "estou na estação u e posso escolher
         qualquer sistema disponível aqui"
    */

    vector<int> aux(N + 1);

    for (int u = 1; u <= N; u++) {
        // estamos adicionando outros N vertices
        aux[u] = qtd_vertices++;
    }

    /*
        Agora sabemos o número total de vértices.
    */

    vector<vector<Aresta>> grafo(qtd_vertices); //matrix adj

    /*
        1) Arestas originais

        u --s-- v

        vira:

        (u,s) --0-- (v,s)
    */

    for (auto e : arestas) {
        // saida vertice a, sistema da mesma
        int a = get_id(e.u, e.sistema);
        // saida vertice b
        int b = get_id(e.v, e.sistema);

        grafo[a].push_back({b, 0});
        grafo[b].push_back({a, 0});
    }

    /*
        2) Troca de sistemas

        (u,s) -> aux[u]     custo 0
        aux[u] -> (u,s)     custo P[s]
    */

    for (auto [estado, vertice] : id) {
        // em todos os id pegaremos
        int u = estado.first; // a saida
        int sistema = estado.second; // o sistema

        // Sair do sistema atual
        grafo[vertice].push_back({
            aux[u],
            0
        });

        // Entrar nesse sistema
        grafo[aux[u]].push_back({
            vertice,
            P[sistema]
        });
    }

    /*
        Agora temos um grafo comum.

        Vamos rodar Dijkstra.
    */

    const ll INF = 4e18;

    vector<ll> dist(qtd_vertices, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    int inicio = 1;
    int destino = N;

    /*
        Começamos na estação inicial
        sem estar usando nenhum sistema.

        Por isso começamos na auxiliar.
    */

    dist[aux[inicio]] = 0;

    pq.push({
        0,
        aux[inicio]
    });

    while (!pq.empty()) {

        auto [dist_atual, u] = pq.top();
        pq.pop();

        // Entrada velha da priority_queue
        if (dist_atual != dist[u])
            continue;

        for (auto e : grafo[u]) {

            int v = e.destino;
            ll nova_dist = dist_atual + e.custo;

            if (nova_dist < dist[v]) {

                dist[v] = nova_dist;

                pq.push({
                    dist[v],
                    v
                });
            }
        }
    }

    /*
        Podemos terminar em qualquer sistema.

        Por isso usamos a auxiliar do destino.
    */

    cout << dist[aux[destino]] << '\n';
}

## Fast-Food

Aprendizado: Reconhecer a sequencia de transformações

Objetivo: dividir os restaurantes em dois sistemas, aonde a maior distancia entre dois restaurantes do sistema seja a menor possível

- minimizar o máximo X

Pergunta que deve ser automatica (não foi)

Posso testar se X é possível?

Resposta ótima
       ↓
"É possível com distância <= X?"
       ↓
      SIM/NÃO
       ↓
Busca binária

Queremos saber, se existe uma divisão dos restaurantes em dois grupos onde nenhuma distancia interna seja maior que 10.

| isso não é só força bruta então?

- Isso se torna uma restrição de 2-coloração

### Dividir em 3 conjuntos

A = restaurantes já colocados no grupo 0

V = restaurantes já colocados no grupo 1

B = restaurantes ainda não classificados

A = {1}
V = {}
B = resto

Para cada novo num
Se existir algum rest em A com dist > D, então se existir algum rest em B com dis > D. Temos que colocar a dist como a menor entre a dist de A e dist de B 

### Distancia é Manhattan

| x1-x2 | + | y1 - y2 |
s=x+y, t= x-y

distancia:
max(|s_i - s_j|, | t_i - t_j |)

logo para encontrar a maior distancia entre dois conjuntos basta conhecer:

maior x+y
menor x+y

maior x-y
menor x-y

só precisamos olhar 8 valores e não todos do conjunto

Técnica para memorizar:

Manhattan → x+y e x-y → extremos.

maxDist(A,A) <= D
maxDist(V,V) <= D

Se isso acontecer D é impossível

### algoritimo mental - bool check(D)

check(D):

    grupo A = {}
    grupo B = {}

    coloque um ponto em A

    enquanto existirem pontos sem grupo:

        encontre um ponto x que:

            não pode ficar em A
            ou
            não pode ficar em B

        se não pode A:
            coloque em B

        senão se não pode B:
            coloque em A

        senão:
            coloque arbitrariamente em A

    verifique:
        maxDist(A,A) <= D
        maxDist(B,B) <= D

Fazendo uma busca binária até achar D

while (lo <= hi) {
    mid = (lo + hi) / 2;

    if (check(mid))
        hi = mid - 1;
    else
        lo = mid + 1;
}

Complexidade
O(N log N + N log C)

### Estrutura/raciocinio

"minimizar o máximo"
        ↓
busca binária na resposta
        ↓
"para uma distância D, é possível?"
        ↓
pares com distância > D
não podem ficar juntos
        ↓
restrição de 2 grupos
        ↓
bipartição / 2-coloração
        ↓
não posso criar todas as N² arestas
        ↓
preciso detectar conflitos geometricamente
        ↓
Manhattan
        ↓
x+y / x-y
        ↓
máximos e mínimos


### Revendo matematica

- Entendi a transformação

Identificar a maior distancia entre quaisquer dois pontos

Pela formula, basta encontrar:
maior diferença de s
OU
maior diferença de t

logo quando precisamos simplesmente pegar o:
max(s), min(s), max(t), min(t)

Porem sendo dois conjuntos temos duas possibilidades:

distancia maxima dos dois conjuntos é:
max(
    max(sa)-min(sb),
    max(sb)-min(sa),
    max(ta)-min(tb),
    max(tb)-min(ta)
)

Se
distância > D
        ↓
     conflito
        ↓
não podem ter a mesma cor
        ↓
     2 grupos
        ↓
   bipartição


### logica importante

Manhattan
    ↓
s = x+y
t = x-y
    ↓
dist(i,j) = max(|si-sj|, |ti-tj|)
    ↓
maior distância em um conjunto:
max(maxS-minS, maxT-minT)
    ↓
maior distância entre A e B:
4 combinações de extremos