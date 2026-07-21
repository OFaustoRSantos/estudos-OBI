# Busca (DFS,BFS, 0-1 BFS, Dijkstra)

## DFS

Quando usar, implementação (com loop ou recursividade), aplicação em flood fill / convexos

### Ideia

Labirinto onde você anda sempre em frente até bater numa parede
Isso é DFS: aprofunda o máximo possível antes de retroceder (backtrack).

Você tem um mapa de terra e água (grid de 0s e 1s) e precisa contar quantas ilhas (grupos de terra conectada) existem. Para cada célula de terra ainda não visitada, você quer "pintar" toda a ilha conectada a ela de uma vez—isso é flood fill, feito com DFS (ou BFS).

### Soluções

Solução 1 (força bruta): para cada célula de terra, verificar manualmente se já foi contada, comparando com todas as anteriores → lento e complicado.
-> Complicadissimo

Solução final: para cada célula de terra não visitada, faça DFS marcando toda a ilha como visitada, e incremente o contador de ilhas uma vez por chamada → O(N·M), cada célula visitada uma única vez.

// faço um for com as difereções se for terra a gente avança, se não ou já tiver sido visitada ignora

### Estrutura do algoritmo

```txt
dfs(nó):
    marca nó como visitado
    para cada vizinho do nó:
        se vizinho não visitado:
            dfs(vizinho)
```

#### Implementação manual — grafo com lista de adjacência (recursiva)

```cpp
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    // processar u aqui, se necessário (ex: contar tamanho da componente)
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
```

### Implementação STL — grid (matriz), o seu ponto de atenção

```cpp
int n, m;
vector<vector<int>> grid;         // 0 = terra, 1 = parede, por exemplo
vector<vector<bool>> visited;

// Direções a se ir.
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int i, int j) {
    visited[i][j] = true;
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue; // limites
        //verificando se passou da borda
        if (grid[ni][nj] == 1) continue;                       // obstáculo
        if (visited[ni][nj]) continue;                          // já visitado
        // Se tudo de cima for falso:
        dfs(ni, nj);
    }
}
// forma que eu faria
```

#### DFS iterativo (com pilha explícita — evita estouro em grafos grandes)

```cpp
stack<int> st;
// FILO -> 1° entrar ultimo a sair
// funciona somente com matrix de adjacencia acho
st.push(origem);
visited[origem] = true;

while (!st.empty()) {
    int u = st.top(); st.pop();
    // pega o 1° e depois o tira da lista
    for (int v : adj[u]) {
        // analisa os vizinhos 
        if (!visited[v]) {
            visited[v] = true;
            st.push(v);
        }
    }
}
```

### Complexidade

| Operação | Complexidade |
|---|---|

| DFS completo (grafo com V nós, E arestas) | O(V + E) |
| DFS completo (grid n×m) | O(n·m) |

### Visualizações

```md
Grid:            Ordem de visita (DFS a partir de (0,0)):
1 1 0            1 → 2 → 3
1 0 0            desce, desce, direita...
0 0 1            (vai fundo antes de "espalhar")
```

### Erros clássicos

- Esquecer de marcar `visited` **antes** de continuar a recursão → loop infinito
- Não checar limites antes de acessar `grid[ni][nj]` → acesso inválido
- Usar DFS recursivo em grid muito grande (ex: 1000×1000) sem cuidado → risco de estouro de pilha; considere DFS iterativo ou BFS
- Achar que DFS encontra **menor** caminho — DFS não garante isso, apenas conectividade/alcançabilidade

// Erro 3 me parece o mais perigoso, logo ideal não usar DFS e usar somente BFS

### Problemas clássicos

1. Contar componentes conexas num grafo simples (fácil)
2. Contar ilhas num grid (flood fill) (médio)
3. Detectar ciclo em grafo direcionado usando DFS com 3 estados (difícil)

### Padrões — quando pensar em DFS

| Se o enunciado diz... | Pense em... |
|---|---|

| Contar "grupos"/"regiões"/"ilhas" conectadas | DFS (flood fill) |
| Detectar ciclo | DFS |
| Verificar se existe caminho (sem se importar com distância) | DFS ou BFS |
| Explorar todas as possibilidades / backtracking | DFS |
| Ordenação topológica | DFS (uma das formas) |

🟩 Quando usar a BFS (Busca em Largura)

Caminho Mínimo: Essencial para encontrar a menor distância entre vértices em grafos sem peso (arestas iguais a 1).
Problemas de Nível e Estado: Útil quando você precisa explorar o grafo camada por camada (nível a nível) ou simular passos simultâneos.
Complexidade: Ocupa mais memória, pois precisa armazenar todos os nós de um mesmo nível na fila.

🟪 Quando usar a DFS (Busca em Profundidade)

Exploração Exhaustiva: Ideal para percorrer um caminho até o fim antes de retroceder (backtracking).
Estruturas Específicas: Indispensável para Ordenação Topológica, detecção de ciclos e componentes fortemente conexas.
Complexidade: Consome menos memória que a BFS ao usar a pilha de recursão do sistema, mas pode causar Stack Overflow em grafos extremamente profundos.

### Casos onde NÃO usar

- Quando o problema pede **menor caminho/menor número de passos** sem pesos — use BFS, não DFS
- Grafos muito profundos com recursão sem cuidado de estouro de pilha

### Outros problemas_DFS

- CSES: "Counting Rooms" (flood fill clássico)
- LeetCode: "Number of Islands" (fácil/médio)

### Cheatsheet_DFS

```cpp
// Grafo (lista de adjacência)
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfs(v);
}

// Grid
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs(int i, int j) {
    visited[i][j] = true;
    for (int d = 0; d < 4; d++) {
        int ni = i+dx[d], nj = j+dy[d];
        if (ni<0||ni>=n||nj<0||nj>=m) continue;
        if (grid[ni][nj]==1 || visited[ni][nj]) continue;
        dfs(ni, nj);
    }
}
```

### Desafios_DFS

1. Conte quantas ilhas existem num grid de terra/água. //Parece muito legal
2. Detecte se um grafo direcionado tem ciclo. // ou seja, tenho lista de adjacencia
3. Ache o tamanho da maior componente conexa.
4. Pinte (flood fill) uma região a partir de um pixel, como na ferramenta "balde de tinta". // identico contar ilha
5. Implemente DFS iterativo e compare a ordem de visita com a versão recursiva. // FILO a versão iterativa

### Mini-projeto_DFS

Implemente uma ferramenta de "balde de tinta" simples: dado um grid de cores e um pixel clicado, repinte toda a região conectada da mesma cor.

### Checklist de maestria_DFS

**Conhecimento**

- [ ] Sei explicar por que DFS não acha menor caminho
- [ ] Sei quando DFS recursivo pode estourar a pilha

**Implementação**

- [ ] Consigo implementar DFS recursivo em grafo e em grid
- [ ] Consigo implementar DFS iterativo com stack explícita

**Reconhecimento**

- [ ] Reconheço "contar ilhas/regiões" como flood fill/DFS
- [ ] Reconheço "detectar ciclo" como problema de DFS

**Competição**

- [ ] Resolvi pelo menos 3 problemas de DFS/flood fill em grid

## BFS

Foco: Estratégias de menor caminho, percorrendo como se fosse uma gota caindo num copo calmo, formato de onda

Você tem um mapa (grid) com paredes e espaços livres. Quer saber o menor número de movimentos entre um ponto A e um ponto B, onde cada movimento (cima/baixo/esquerda/direita) custa o mesmo.
Um GPS que sempre te dá a rota mais curta usa essa mesma ideia (em grafos com pesos, seria Dijkstra — ver 2.D)

### Soluções pro problema

Solução 1 (força bruta) — DFS testando todos os caminhos: funciona, mas não garante achar o menor caminho de forma eficiente, e pode reprocessar o mesmo nó várias vezes.

Solução final: BFS com fila, processando por camadas, marcando dist no momento em que o nó entra na fila → O(V + E), ou O(n·m) em grid

### Estrutura do Algoritimo

bfs(origem):
    dist[origem] = 0
    fila.push(origem) // fila FIFO, para analisar qual vão ser "pesquisados"/relaxados
    enquanto fila não vazia:
        u = fila.pop_front()
        para cada vizinho v de u:
            se dist[v] não definida: // Não tem caso de mudar o valor, pois no final não tem aresta
                dist[v] = dist[u] + 1
                fila.push(v)
            // caso já tenha sido definido então os vizinhos do nó já foram relaxados

### Implementação

#### Lista adjacencia


```cpp
vector<int> dist(n + 1, -1);
queue<int> q;

dist[origem] = 0;
q.push(origem);

while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

#### Grid

```cpp
int n, m;
vector<vector<int>> grid; 
// 0 = livre, 1 = parede
vector<vector<int>> dist(n, vector<int>(m, -1));
// Já preencheu o vetor com o valor -1
queue<pair<int,int>> q;
// pair posição

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

dist[si][sj] = 0;
q.push({si, sj});

while (!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue; // limites
        if (grid[ni][nj] == 1) continue;                       // obstáculo
        if (dist[ni][nj] != -1) continue;                      // já visitado
        dist[ni][nj] = dist[i][j] + 1;
        q.push({ni, nj});
    }
}
```

**Decore a ordem das 4 checagens: limites → obstáculo → visitado → marcar e empilhar.**

### Complexidade_BFS

| Operação | Complexidade |
|---|---|

| BFS completo (grafo) | O(V + E) |
| BFS completo (grid n×m) | O(n·m) |

### Erros clássicos_BFS

- Marcar como visitado **depois** de processar em vez de **ao inserir na fila** — o mesmo nó pode entrar várias vezes na fila // ERRO GRAVE!
- Esquecer de checar limites antes de acessar `grid[ni][nj]`
- Confundir BFS com DFS quando o problema pede explicitamente "menor caminho"
- Esquecer de tratar múltiplas origens (ver seção 18) // Multi Source, Interessante

### Padrões — quando pensar em BFS

| Se o enunciado diz... | Pense em... |
|---|---|

| Menor número de movimentos/passos | BFS |
| Labirinto sem pesos | BFS |
| Grade (grid), sem peso | BFS |
| Distância mínima em grafo não ponderado | BFS |
| Várias fontes/origens simultâneas | Multi-source BFS |

### Comparações — DFS vs BFS vs Dijkstra

| Critério | DFS | BFS | Dijkstra |
|---|---|---|---|

| Garante menor caminho? | Não | Sim (sem peso) | Sim (com peso) |
| Estrutura usada | Pilha (ou recursão) | Fila | Priority Queue |
| Complexidade | O(V+E) | O(V+E) | O((V+E) log V) |
| Uso típico | Conectividade, ciclos | Menor caminho sem peso | Menor caminho com peso |

// Muilti-Source muito interessante para problemas de propagação - Fogo, agua, infecção

### Outros problemas_BFS

- CSES: "Labyrinth", "Message Route" (BFS com reconstrução de caminho)
- LeetCode: "Rotting Oranges" (multi-source BFS clássico)

### Cheatsheet

```cpp
queue<pair<int,int>> q;
int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
dist[si][sj] = 0; q.push({si,sj});
while(!q.empty()){
    auto [i,j]=q.front(); q.pop();
    for(int d=0; d<4; d++){
        int ni=i+dx[d], nj=j+dy[d];
        if(ni<0||ni>=n||nj<0||nj>=m) continue;
        if(grid[ni][nj]==1 || dist[ni][nj]!=-1) continue;
        dist[ni][nj]=dist[i][j]+1;
        q.push({ni,nj});
    }
}
```

### STL — Multi-source BFS

Quando há múltiplas origens simultâneas, coloque **todas** na fila antes do loop principal, todas com distância 0:

```cpp
queue<pair<int,int>> q;
for (auto [i, j] : origens) {
    dist[i][j] = 0;
    q.push({i, j});
}
// Simples e funcional
while (!q.empty()) {
    // resto do BFS é idêntico ao template padrão
}
```

### Reconstrução de caminho (guardando de onde veio)

// não entendi, eu pensei primeiro em criar uma matrix com o vetor path, principalmento no dijkstra, para preservar a ideia do menor caminho, embora claro isso teria um gasto severo de memória, essa ideia de reconstruir não ficou tão visivel assim no codigo abaixo, talvez por estar mais incompleto, por isso pedi ajuda ao gemini e ele me deu o segundo codigo

```cpp
vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

// dentro do BFS, ao marcar dist[ni][nj]:
// Quando colocar a distancia, incluir no parente de ni o nj 
parent[ni][nj] = {i, j};

// depois, para reconstruir o caminho do destino até a origem:
vector<pair<int,int>> caminho;
pair<int,int> atual = {destino_i, destino_j};
while (atual != make_pair(-1,-1)) {
    caminho.push_back(atual);
    atual = parent[atual.first][atual.second];
}
reverse(caminho.begin(), caminho.end());
```

#### Codigo 2 - Gemini BFS - rebuild path
A sua intuição inicial de guardar o caminho inteiro a cada passo faz todo o sentido lógico — se você quer saber o caminho, por que não ir anotando ele conforme anda? O problema, como você mesmo percebeu, é o gasto severo de memória e de processamento (copiar vetores inteiros a cada movimento custa muito caro).

A sacada da matriz parent (ou "pai") é muito mais elegante: em vez de você carregar a sua "rota completa" na mochila durante toda a viagem, você apenas deixa uma placa em cada lugar novo que visita, apontando para o lugar de onde você acabou de vir.

Quando você chega no destino, basta ler essa placa, dar um passo para trás, ler a próxima placa, e assim por diante, até chegar na origem.

Aqui está um código completo, didático e comentado para você rodar e entender como essas peças se encaixam na prática

Entendi: Por isso o while pair {-1,-1}, pois menos -1 e -1 quer dizer que chegamos no inicio, dessa forma a partir do destino faremos um backtrack até o inicio e por fim invertemos a lista

### Template completo_BFS

```cpp
int n, m, si, sj, ti, tj;
// si,sj, seriam inicio, ti,tj seriam destino
vector<vector<int>> grid; // mapa
vector<vector<int>> dist;
vector<vector<pair<int,int>>> parent;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

int bfs() {
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));
    // assign -> Redefinir tamanho do vetor e preenche-lo com um valor padrão uma só vez -> Para vetores vazios, ou já usados, logo pode zerar o sistema.

    queue<pair<int,int>> q;
    dist[si][sj] = 0;
    q.push({si, sj});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int ni = i+dx[d], nj = j+dy[d];
            if (ni<0||ni>=n||nj<0||nj>=m) continue;
            if (grid[ni][nj]==1 || dist[ni][nj]!=-1) continue;
            dist[ni][nj] = dist[i][j]+1;
            parent[ni][nj] = {i,j};
            q.push({ni,nj});
        }
    }
    return dist[ti][tj]; // -1 se inalcançável
}
```

### Desafios

1. Menor caminho num labirinto simples (sem reconstrução).
2. Menor caminho com reconstrução do caminho percorrido. //Bem de boa 1 e 2
3. Multi-source BFS: tempo até uma infecção alcançar cada célula. // Nunca fiz mas bem easy tbm
4. BFS num grafo (não grid) para achar distância mínima entre dois nós. // Parte mais trabalhosa é construir o grafo
5. Grid com "portais" (teletransporte) — adapte o BFS para considerar arestas extras. // WOW d+, isso aqui é maneiro

### Checklist de maestria

**Conhecimento**

- [ ] Sei explicar por que BFS garante menor caminho
- [ ] Sei quando usar multi-source BFS

**Implementação**

- [ ] Consigo escrever o template de BFS em grid sem consultar material
- [ ] Consigo implementar reconstrução de caminho

**Reconhecimento**

- [ ] Reconheço "menor número de movimentos" como BFS
- [ ] Reconheço "várias origens simultâneas" como multi-source BFS

**Competição**

- [ ] Resolvi pelo menos 1 problema da OBI usando BFS em grid
- [ ] Consigo resolver um problema de BFS em grid em menos de 30 minutos

---

## 0-1 BFS

Resolver problemas de menor caminho quando as arestas tem peso 1 ou 0, sem usar dijkstra (+complexo)

