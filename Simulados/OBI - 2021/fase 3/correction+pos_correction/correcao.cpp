#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int falha_tutoria(){

    // Como comparar duas strings sem comparar caractere por caractere.

    //Opção A — substr
    //string parte = s.substr(1, 3);  
    /* Isso significa:
    // começa no índice 1
    // pega 3 caracteres
    Então:

    s = "abcdef";
    s.substr(1, 3)

    produz:
    "bcd"

    E você pode fazer: */

    //if(s.substr(1, 3) == outra)
    /*
    Muito simples.
    Mas existe uma pegadinha
    substr cria uma nova string. 
    */
    //Então, conceitualmente:

    // s.substr(1, 3)
    //faz uma cópia de "bcd".

    /*
    Opção B — string::compare

    Essa é provavelmente a técnica que você estava procurando.

    s.compare(1, 3, outra)

    Significa:

    Compare a substring de s, começando no índice 1, com comprimento 3, contra outra.

    Por exemplo:

    string s = "abcdef";
    string t = "bcd";

    if(s.compare(1, 3, t) == 0){
        cout << "iguais";
    }

    Vai dar:

    iguais

    Porque está comparando:

    s:
    abcdef
    ↑───
    bcd

    t:
    bcd  
    */

    // Uma outra opção legal é o grande.find(pequena) -> posição 1° char se true, string::npos se não tiver.

}

int root_tree(){
    /*
    como achar o root de uma árvore?

    Aqui tem uma distinção MUITO importante.

    Uma árvore originalmente:

        1
        / \
        2   3
        / \
        4   5

    não possui necessariamente um "root".

    Você escolhe um vértice para ser a raiz.

    Por exemplo:

    int root = 1;

    E faz DFS/BFS a partir dele.

    6. BFS para "enraizar" a árvore

    Imagine:

            1
        / \
        2   3
            / \
            4   5

    Começamos em:

    root = 1

    Então:

    queue<int> q;

    q.push(root);
    pai[root] = -1;
    dist[root] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(v == pai[u]) continue;

            pai[v] = u;
            dist[v] = dist[u] + 1;

            q.push(v);
        }
    }

    Agora temos:

    vértice    pai       profundidade

    1          -1        0
    2           1        1
    3           1        1
    4           3        2
    5           3        2

    A árvore ficou efetivamente:

            1
            /   \
        2     3
                / \
            4   5
    7. "Mas como eu descubro o melhor root?"

    Aí é outra pergunta.

    Existem três conceitos que você precisa começar a separar:

    Root arbitrário

    Você escolhe qualquer:

    root = 0;

    Serve para:

    DFS
    calcular profundidade
    descobrir pai
    subtree
    DP em árvore
    Centro da árvore

    É outra coisa.

    Uma árvore pode ter:

    diameter

    e seu centro pode ser:

        A
        |
        B
        |
        C
        |
        D
        |
        E

    Nesse caso os centros são:

    C

    Se o diâmetro tiver número par de arestas, há um centro.

    Se tiver número ímpar, existem dois centros.

    Endpoint do diâmetro

    E isso é justamente o que precisamos em Minhoca.
    */

}

//  

int solu_minhoca(){
    /*
    Dona Minhoca: aqui está o grande aprendizado

    O enunciado diz que temos uma árvore com:

    N salas
    N - 1 túneis

    e queremos adicionar um túnel para formar um ciclo.

    Imagine:

    A -------- B

    A --- ... --- B

    Se colocarmos uma aresta:

    A -------- B

    o ciclo será formado pelo caminho original entre A e B + a nova aresta.

    Se:

    dist(A,B) = 4

    então o ciclo possui:

    4 arestas antigas + 1 nova
    = 5 arestas

    e portanto:

    5 salas

    Logo:

    maior ciclo = diâmetro da árvore + 1.

    Essa é a primeira grande sacada.
    */

    /*
    Dona Minhoca: aqui está o grande aprendizado
    9. Como encontrar o diâmetro?

    Aqui entra uma técnica que você precisa decorar para OBI.

    BFS duas vezes.

    Escolha qualquer vértice:

    1

    Faça BFS.

    Encontre o vértice mais distante dele:

    U

    Agora faça outra BFS, dessa vez começando em:

    U

    Encontre o vértice mais distante:

    V

    Então:

    dist(U,V) = diâmetro

    Visualmente:

                árvore

                    U
                    |
                    |
                    |
                    V

            distância máxima
    */
    // Muito legal


pair<int, vector<int>> bfs(int inicio, vector<vector<int>>& adj){
    int n = adj.size(); // numero de vertices na adjacente

    vector<int> dist(n, -1); 

    queue<int> q;
    q.push(inicio);
    dist[inicio] = 0;

    int mais_longe = inicio;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(dist[v] != -1) continue;

            // nn vimos v ainda
            dist[v] = dist[u] + 1;
            q.push(v);

            if(dist[v] > dist[mais_longe]){
                mais_longe = v;
            }
        }
    }

    return {mais_longe, dist};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> adj(N);

    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;

        --a;
        --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1ª BFS: descobrir uma extremidade do diâmetro
    auto [u, dist1] = bfs(0, adj);

    // 2ª BFS: a partir da extremidade
    auto [v, dist2] = bfs(u, adj);

    int D = dist2[v];

    int maneiras = 0;

    for(int x : dist2){
        if(x == D){
            maneiras++;
        }
    }

    cout << D + 1 << '\n';
    cout << maneiras << '\n';
}
}

int sacada_casamento(){
    // passamos, mas se x^2 = y^3.
    // isso quer dizer que necessáriamente existe um k^6 = x^2 = y^3
    // a partir dai mesma solução

}

int casamento(){
    // aqui você complicou uma coisa simples

    /*
    O enunciado só pede:

    alinhar os números pela direita;
    comparar cada dígito;
    manter o maior;
    ordenar os dois resultados.
    */
   /*
   Você frequentemente tenta transformar número em:

    pow(10, ...)
    pow(...)
    sqrt(...)

    quando não precisa.

    Por exemplo, para construir um número:

    x = x * 10 + digito;

    Muito mais seguro.

    Exemplo:

    int x = 0;

    for(char c : s){
        x = x * 10 + (c - '0');
    }
   */

}

int feedback_geral(){

    /*
    Olha Minhoca:

    árvore
    +
    maior ciclo ao adicionar uma aresta

    Você pensou:

    Dijkstra?
    BFS?
    todas as folhas?
    matriz de distâncias?

    O competidor mais experiente pensa:

    Adicionar uma aresta numa árvore
            ↓
    cria ciclo
            ↓
    tamanho do ciclo = distância(u,v)+1
            ↓
    maior ciclo
            ↓
    DIÂMETRO
            ↓
    BFS duas vezes

    Essa transformação:

    ENUNCIADO → PADRÃO

    é exatamente o que precisamos t
    */
}

int sol_falha(){
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    // Otimização de entrada/saída padrão para a OBI
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> senhas(N);
    unordered_map<string, int> frequencia_senhas;

    // 1. Ler as senhas e contar a frequência de cada uma
    for (int i = 0; i < N; i++) {
        cin >> senhas[i];
        frequencia_senhas[senhas[i]]++;
    }

    long long total_pares = 0;

    // 2. Para cada senha, extrair suas substrings únicas
    for (int i = 0; i < N; i++) {
        const string& S = senhas[i];
        int tam = S.size();
        
        unordered_set<string> substrings_unicas;

        // Gerar todas as substrings contíguas possíveis
        for (int inicio = 0; inicio < tam; inicio++) {
            for (int len = 1; inicio + len <= tam; len++) {
                substrings_unicas.insert(S.substr(inicio, len));
            }
        }

        // 3. Ver quantas senhas do banco combinam com essas substrings
        for (const string& sub : substrings_unicas) {
            if (frequencia_senhas.count(sub)) {
                total_pares += frequencia_senhas[sub];
            }
        }
    }

    // 4. Subtrair N pois cada usuário dá match consigo mesmo (A e B devem ser distintos)
    total_pares -= N;

    cout << total_pares << "\n";

    return 0;
}
}