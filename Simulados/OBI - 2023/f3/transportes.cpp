#include <bits/stdc++.h>
using namespace std;

/*
Regras:

Cada sistema K tem um preço, independente da estação;
A passagem só deve ser paga quando o usuário entrar no sistema. Um por vez; Pode percorrer mais de uma estação se não sair do meio de transporte.
*/

int menor_custo = 10e7;

struct estacao {
    int destino; int linha;
};

vector<int> cost_pas;
// mat_adj[saida][estação_possivel]
vector<vector<estacao>> mat_adj; 

void BFS(){
    // antes de adicionar na fila fazer um sort com base no preço; assim acelero um pouco mais o algoritimo - esquece dificil.
    // BFS com certeza vai quebrar em algum teste

}
void Djakstra(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    N estações
    K sistemas de transporte
    M ligações entre os pares
    */
    int N, K, M; cin >> N >> M >> K;

    cost_pas.assign(K,0);

    // Preços por sistema - verificar se é mais rápido fazer o assign e colocar +1 ou só ir por push.
    for(int i=0; i<K; i++){
        cin >> cost_pas[i];
    }

    // Construção grafo
    for(int i=0; i<M;i++){
        int V,U,T; cin >> V >> U >> T;
        V--; U--; T--;
        estacao estacao_ida; 
        estacao_ida.destino = U; estacao_ida.linha = T;
        // bidirecional
        // cada par existe no maximo uma ligação de um sistema específico
        mat_adj[V].push_back(estacao_ida);
        estacao_ida.destino = V;
        mat_adj[U].push_back(estacao_ida);
    }
    // A = Saida; B = Destino;
    int A,B; cin >> A >> B;

    /*
        Objetivo, dar um cout naquele com menor custo total da viagem;
        Djakstra, porém se a linha for = temos custo zero.
        Ou usar um BFS - mais certeiro; 
        Duas opções: Priority_queue, ou BFS.
        vou começar com um BFS
    */  

}

// Solução


#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
Destino e custo
*/
struct Aresta {
    int destino;
    ll custo;
};

/*
u = saida, v = chegada, sistema=sistema usado
*/
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

    // numero de arestas originais -> tirando auxiliares
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

    // os primeiros M ids são das arestas originais

    /*
        Agora criamos uma auxiliar para cada estação.

        aux[u] representa:

        "estou na estação u e posso escolher qualquer sistema disponível aqui"
    */

    vector<int> aux(N + 1);

    for (int u = 1; u <= N; u++) {
        // estamos adicionando outros N vertices
        aux[u] = qtd_vertices++;
        // a 1° auxliar tem o id : qtd_vertices e aumentamos sempre ela. 
    }

    /*
        Agora sabemos o número total de vértices.
        originais mais auxiliares
    */

    vector<vector<Aresta>> grafo(qtd_vertices); //matrix adj

    /*
        1) Arestas originais

        u --s-- v

        vira:

        (u,s) --0-- (v,s)
    */

    // A ideia desenhando é muito bonita

    for (auto e : arestas) {
        // saida vertice a, sistema da mesma
        int a = get_id(e.u, e.sistema);
        // saida vertice b
        int b = get_id(e.v, e.sistema);

        // a e b não são os vertices, mas o indice do vertice com aquele sistema
        // por isso estamos usando ids
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
        int u = estado.first; // o vertice em questão, id do vertice
        int sistema = estado.second; // o sistema

        // Sair do sistema atual
        // para todo id - só os vertices originais tem id definido, iremos adicionar o respecitivo auxiliar
        grafo[vertice].push_back({
            aux[u], // já tem o indice dele salvo aqui
            0
        });

        // Entrar nesse sistema - paga o preço passagem
        grafo[aux[u]].push_back({
            vertice,
            P[sistema]
        });
    }

    /*
        Agora temos um grafo comum.

        Vamos rodar Dijkstra.
    */

    // | Estrutura Dijkstra
    /*
    | 1 -definir distancia todos os vertices como infinito
    */

    const ll INF = 4e18;

    vector<ll> dist(qtd_vertices, INF);

    /*
    | 2 - Criar priority queue, para ele sempre favorecer o caminho mais curto/barato
    */
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
            // se for igual é porque esse caminho é o com menor distancia

            
        // todas arestas vizinhas do nosso vertice
        for (auto e : grafo[u]) {

            int v = e.destino;
            ll nova_dist = dist_atual + e.custo;

            if (nova_dist < dist[v]) {

                dist[v] = nova_dist;
                // já atualiza a distancia, pois no começo do loop pegamos a distancia pelo vertice.

                pq.push({
                    dist[v],
                    v
                });
                // adiciona na fila
            }
        }
    }

    /*
        Podemos terminar em qualquer sistema.

        Por isso usamos a auxiliar do destino.
    */

    cout << dist[aux[destino]] << '\n';
}

// MUITO LEGAL!