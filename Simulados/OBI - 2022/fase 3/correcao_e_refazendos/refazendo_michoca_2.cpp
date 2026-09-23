#include <bits/stdc++.h>
using namespace std;

/*
    - Ideia, fazer um binary search testando os valores de R para encontrarmos o menor possível.

    limites:
    K radares, R alcance, depende da configuração mas sabemos que 
    K*R deve ser no maximo o diametro da arvore
 

    > Base para condição do r:

    pegar os vertices mais distante, e fazer:
    se estado = aceso, continue;
    se estado = apagado, tentar subir o máximo e acender

    ideia é achar o ponto de dist <= R que ao ligar atingimos o maior numero de vertices.

*/

// Com este R, consigo cobrir a árvore usando K radares?

// N maximo de radares
int K; 

bool testando_r(const vector<vector<int>>& mat_adj, int R, const vector<int>& dist, const vector<int>& par, const vector<pair<int,int>>& par_dist_id){
    int n = mat_adj.size();
    // -1 = desligada, 1 = ligada
    vector<int> status_pontos(n, -1);
    vector<int> vis (n,-1);
    // fazendo teste para ver se é possível usar o radar de raio R;

    // Pegar lista vertices mais distantes:
        // Para isso fariamos 3 BFS: arbitario, extremidade, centro (usando o dist do centro)
    // fazer algo tipo um DFS neles
    // Se ligados: continue;
    // Se desligados: tentaremos achar o melhor ponto para ligar a uma distancia R dele que acenda o máximo de pontos possíveis

    // por ele ser o mais profundo atual, quer dizer que o ponto + R de distancia com menos profundidade é o melhor ponto nesse critério

    int K_adicionados=0;

    for(int i=0; i<n; i++){
        if(status_pontos[par_dist_id[i].second] != -1) continue;

        if(K_adicionados == K){ // pois já adicionamos K porém nn deu certo
            return false;
        }

        // vertice não acesso adicionando K:
        // R-1 pois vamos dizer que o R inclui ele mesmo
        int subidas = R;
        int id_ponto = par[par_dist_id[i].second];

        while(subidas > 0){
            id_ponto = par[id_ponto];
            subidas--;
        }

        // a partir de id_ponto vamos fazer um BFS simples de R largura; fila: id_ponto, profundidade do ponto relação a ponto do radar, parente atual;
        queue<tuple<int,int,int>> fila;
        fila.push({id_ponto, R, -1});
        while(!fila.empty()){
            auto [ponto_at, prof_max, parente] = fila.front(); fila.pop();

            for (int u : mat_adj[ponto_at]){
                if(u==parente) continue;

                status_pontos[u] = 1; // deixamos ela acessa

                //se já tivermos a uma distancia R não tem como descermos.
                if(prof_max > 0){
                    fila.push({u, prof_max-1, ponto_at});
                }
            }
        }

        K_adicionados++;
    }
    return true;
}

tuple<int, vector<int>, vector<int>> BFS(const vector<vector<int>>& mat_adj, int root){
    int n = mat_adj.size();
    vector<int> dist(n,-1);
    vector<int> par(n,-1);
    int mais_distante = root;
    queue<int> fila;

    fila.push(root);
    dist[root] = 0;

    while(!fila.empty()){
        auto ver_at = fila.front(); fila.pop();

        for(int u : mat_adj[ver_at]){
            if(dist[u] != -1) continue;

            dist[u] = dist[ver_at] + 1;
            par[u] = ver_at;
            if(dist[u] > dist[mais_distante]) mais_distante = u;

            fila.push(u);
        }
    }

    return {mais_distante, dist, par};
}   

// BFS centros: retorna vetor do par <profundidade, id_vetor>, dist, par
tuple<vector<pair<int,int>>, vector<int>, vector<int>> BFS_centros(const vector<vector<int>>& mat_adj, vector<int> centros){
    int n = mat_adj.size();
    vector<int> dist(n,-1);
    vector<int> par(n,-1);
    vector<pair<int,int>> par_dist_id;
    queue<int> fila;

    if(centros.size() == 2){
        fila.push(centros[1]);    
        dist[centros[1]] = 0;
        par_dist_id.push_back({0,centros[1]});
    }
    fila.push(centros[0]);    
    dist[centros[0]] = 0;
    int mais_distante = centros[0];
    par_dist_id.push_back({0,centros[0]});

    while(!fila.empty()){
        auto ver_at = fila.front(); fila.pop();

        for(int u : mat_adj[ver_at]){
            if( u == centros[0] || u == centros[1]) continue;
            if(dist[u] != -1) continue; // acho que isso já bloquei de ir para o outro centro, mas coloquei uma restrição acima a amis por segurança

            dist[u] = dist[ver_at] + 1;
            par[u] = ver_at;
            if(dist[u] > dist[mais_distante]) mais_distante = u;

            fila.push(u);
            par_dist_id.push_back({dist[u],u});
        }
    }

    return {par_dist_id, dist, par};
}

// indo do mais profundo ao menos profundo;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return (a.second > b.second);
    } 
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N; cin >> N >> K;

    vector<vector<int>> mat_adj(N, vector<int>());
    for(int i=0; i<N-1;i++){
        int a,b;
        cin >> a >> b;
        --a; --b;  
        mat_adj[b].push_back(a);
        mat_adj[a].push_back(b);
    }


    auto [extremidade_1, dist, parent] = BFS(mat_adj, 0 );

    auto [extremidade_2, dist_2, parent_2] = BFS(mat_adj, extremidade_1);

    // Achar centro:

    vector<int> caminho;
    // distancia entre as duas extremidades
    int D = dist_2[extremidade_2];
    int vert_at = extremidade_2;
    caminho.push_back(extremidade_2);
    for(int i =0; i<D-1; i++){
        vert_at = parent_2[vert_at];
        caminho.push_back(vert_at);
        // talvez eu tenha que dar um D-1, pois eu já inclui o extremidade_2 do lado de fora do loop        
    }
    vector<int> centros;
    // Unico centro
    if(D %2 == 0) {
        centros.push_back(caminho[D/2]);
    }
    else{
        // dois centros
        centros.push_back(caminho[D/2+1]);
        centros.push_back(caminho[D/2]);
    }
    
    // Encontrado o centro ou os centros:
    // Traçar dist final

    auto [par_dist_id, dist_final, parent_final] = BFS_centros(mat_adj, centros);

    sort(par_dist_id.begin(), par_dist_id.end(), comp);
    int esq = 1;
    int dir = D;
    int menor_d = -1;
    while(esq < dir){
        int meio = dir - (dir-esq)/2;

        if(testando_r(mat_adj, meio, dist_final, parent_final, par_dist_id)){
            // deu certo com esse r, vamos testar o próximo R, menor
            dir = meio;
            menor_d = dir;
        }else{
            esq = meio +1;
        }
    }

    cout << menor_d << endl;;
}


/* - Complexidade disso aqui está gigantes.

3 BFS: N, N, N - complexidade;
maximo de N = 300.000 logo 900.000 nessa parte

R_max = numero de R possívels
Teste de R, até log(R_max) * complexidade;
complexidade do teste é pelo menos N também
*/

// Erros na minha solução para estudar dps: http://chatgpt.com/c/6ab2983f-04c4-83e9-b0b8-1a5495d7cf02


// Estudo solução:

/*
sua ideia não está errada

Seu comentário:

"pegar os vertices mais distante"

e depois:

"se desligados: tentaremos achar o melhor ponto para ligar a uma distancia R dele"

está capturando uma ideia importante do problema.

> Erro um to subindo R+1  e nn R

lógica escolha ponto:
int id_ponto = par_dist_id[i].second;

for(int d = 0; d < R; d++){
    id_ponto = par[id_ponto];
}

// Problema - esse codigo pode acabar acessando par[-1]

existe um problema conceitual ainda maior

Você está tentando fazer:

"pego cada vértice profundo
 → subo R
 → coloco radar
 → BFS R
 → marco tudo"

Isso parece intuitivo, mas é muito difícil controlar corretamente porque você precisa responder:

"Este vértice está protegido por um radar que está em outra subárvore?"

Ideia mais legal:
manter:
rad[u] = distância até o radar mais próximo
des[u] = profundidade do vértice desprotegido mais profundo

Seu status_pontos não representa bem o problema

Você está tentando manter:

-1 = desprotegido
1 = protegido


BFS_centros é desnecessário

Você gastou uma quantidade considerável de tempo construindo;

// Pergunta a considerar:
Você realmente precisa do diâmetro para encontrar uma boa raiz?

Não.

A solução pode simplesmente enraizar a árvore em:
0

e fazer o processamento guloso nessa árvore.

*/

/*
As duas variáveis mágicas

Para cada u:

des[u]

A maior distância de u até algum vértice desprotegido dentro da subárvore.

Por exemplo:

u
|
A
|
B
|
C

Se C está desprotegido:

des[u] = 3
rad[u]

A menor distância de u até um radar que está dentro da subárvore.

Por exemplo:

u
|
A
|
B   ← radar

então:

rad[u] = 2
16. Aí acontece a mágica

Suponha:

        u
        |
        |
       ...
        |
 
Temos:

rad[u] = 2
des[u] = 3

E:

R = 5

Então:

rad[u] + des[u] = 5

Logo o radar consegue proteger o vértice desprotegido.

E quando precisamos colocar o radar?

Suponha:

des[u] = R

Isso significa:

        u
        |
        |
        X

e X está exatamente a R de distância.

Se continuarmos subindo:

pai[u]

a distância para X seria:

R + 1

Então não existe mais como um radar colocado acima de u proteger X.

Logo:

RADAR EM u

É exatamente nesse momento que o guloso toma a decisão.

O que eu acho mais importante é que você chegou sozinho em:

diâmetro
+
busca binária
+
guloso
+
processar vértices profundos
+
colocar radar R acima

Isso significa que você encontrou boa parte da estrutura da solução.

O que faltou foi transformar essa intuição em um estado correto de árvore.
*/