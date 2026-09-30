#include <bits/stdc++.h>
using namespace std;


// problema da
int atlanta() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    
    // (a+2) * (b+2) = dimensão sala
    // A = (a+2)(b+2) - ab
    // -> A = 2a + 2b + 4 -> 2(a+b+2) = A

    // a*b = B; a+b = A/2-2;
    // logo é como se fosse uma soma e produto, achar um par a,b onde satisfaz duas eq acima

    // a x b = quantidade de ladrilhos brancos
    for (int a = 1; a * a <= B; a++) {

        if (B % a != 0) // não é divisor
            continue;

        int b = B / a;

        // Quantidade de azuis:
        // (a+2)(b+2) - ab
        int azuis = 2 * a + 2 * b + 4;

        if (azuis == A) {
            cout << min(a + 2, b + 2) << " "
                 << max(a + 2, b + 2) << '\n';
            return 0;
        }
    }

    cout << "-1 -1\n";
}

// MUITO fácil


// problema candidatas;

// MDC sempre mantem ou diminui
// gcd(a,b,c) = gcd(gcd(a,b),c)

#include <bits/stdc++.h>
using namespace std;

int L, C;
int tab[6][6];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int,int>> candidatas; // pontos possíveis de colocar


int resposta = 0;

bool dentro(int x, int y) {
    return x >= 0 && x < L && y >= 0 && y < C;
}

bool pode_colocar(int x, int y) {

    // Precisa estar ao lado de uma preta
    bool perto_preta = false;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (!dentro(nx, ny))
            continue;

        if (tab[nx][ny] == 1)
            perto_preta = true;

        // Não pode estar ao lado de outra branca
        if (tab[nx][ny] == 2)
            return false;
    }

    return perto_preta;
}


void backtrack(int pos, int quantidade) {
    // se a posição for a ultima candidata, vamos enviar o maximo que encontramos
    if (pos == (int)candidatas.size()) {
        resposta = max(resposta, quantidade);
        return;
    }

    // Opção 1: não colocar branca aqui
    backtrack(pos + 1, quantidade);

    // Opção 2: colocar branca
    auto [x, y] = candidatas[pos];

    if (pode_colocar(x, y)) {

        tab[x][y] = 2;

        backtrack(pos + 1, quantidade + 1);

        // desfaz
        tab[x][y] = 0; // para não atrapalhar futuros backtrack
    }
}

// Muito legal

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;

    int P;
    cin >> P;

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;

        --x;
        --y;

        tab[x][y] = 1;
    }

    // Descobrir quais casas podem receber brancas
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {

            if (tab[i][j] != 0)
                continue; //tem preta

            bool perto_preta = false;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (!dentro(ni, nj))
                    continue;

                if (tab[ni][nj] == 1)
                    perto_preta = true;
            }

            if (perto_preta)
                candidatas.push_back({i, j});
        }
    }

    backtrack(0, 0);

    cout << resposta << '\n';
}

// Muito legal

// Problema rede social
/*
Você fez uma priority_queue, mas criou uma lógica cheia de casos:

if(next_numero > FI_atual)
...
if(next_numero > numeros_passados)
...
if(next_numero == numeros_passados)
...

Isso é uma indicação importante:
quando o problema tem uma definição matemática muito direta, tente transformar a definição diretamente em código.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);

    for (int &x : a) // WOW eu nunca pensei nisso
        cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int resposta = 0;

    for (int i = 0; i < N; i++) {

        // i + 1 mensagens têm pelo menos
        // a[i] repostagens.

        if (a[i] >= i + 1) // se o valor atual de i é maior que o numero que já passaram, então a resposta pode ser i+1.
            resposta = i + 1;
        else
            break;
    }

    cout << resposta << '\n';
}

/*
Bem easy e rapido
*/


/*
Bobiei muito no BFS,esqueci que as arestas tem peso, não pode bfs com peso

Ideia:
1. Identificar todos os ciclos

Como cada vértice pertence a no máximo um ciclo, podemos decompor o grafo.

2. Para cada ciclo

Guardar:

comprimento do ciclo
3. Construir uma árvore de componentes

Cada ciclo vira uma espécie de "supernó".

4. Para uma consulta (X,T)

Precisamos encontrar o ciclo que:
pode comportar um trem de tamanho T

e que permite o menor percurso:
X → ciclo → volta pelo ciclo → X

Grafo ponderado
      ↓
há ciclos?
      ↓
cada vértice pertence a no máximo um ciclo
      ↓
decompor grafo em árvores + ciclos
      ↓
para cada consulta:
    distância até ciclos relevantes
      +
    percurso no ciclo


Essa busca pela ideia central que tenho que safar rápido
| A ideia principal do Trem da Mina é:

1. Descobrir quais estações pertencem a ciclos.
2. Calcular o comprimento de cada ciclo.
3. Para cada consulta (X,T), calcular a menor distância de X até cada ciclo usando Dijkstra.
4. Se chegarmos a um ciclo de comprimento C a uma distância D, o passeio custa:
2D+C
*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Aresta {
    int destino;
    int peso;
};

int E, R;

vector<vector<Aresta>> grafo; // lista adj

// Para descobrir os ciclos
vector<int> visitado;
vector<int> pai;
vector<int> profundidade;

vector<bool> em_ciclo;

// Cada ciclo terá: ciclo_tamanho[i] = comprimento do ciclo i
vector<long long> ciclo_tamanho;

// DFS para encontrar os ciclos
void dfs_ciclos(int u, int p) {

    visitado[u] = 1;
    pai[u] = p;

    for (auto aresta : grafo[u]) {

        int v = aresta.destino;

        // Não voltar imediatamente pela aresta que usamos
        if (v == p)
            continue;

        if (!visitado[v]) { // Não foi visitado definindo profundidade

            profundidade[v] = profundidade[u] + 1;

            dfs_ciclos(v, u);

        }
        else if (profundidade[v] < profundidade[u]) {
            // Já foi visitado e tem profundidade  menor - Encontramos uma aresta voltando para um ancestral.

            int atual = u;

            long long tamanho = aresta.peso;

            // Caminhamos pelos pais até chegar em v.
            while (atual != v) {
                em_ciclo[atual] = true; // colocar todos no ciclo

                // Precisamos descobrir o peso da aresta entre atual e pai[atual].
                for (auto e : grafo[atual]) {
                    if (e.destino == pai[atual]) {
                        tamanho += e.peso;
                        break;
                    }
                }

                atual = pai[atual];
            }

            em_ciclo[v] = true;

            ciclo_tamanho.push_back(tamanho);
            // MUITO massa
        }
    }
}


// Dijkstra

vector<long long> dijkstra(int origem) {

    vector<long long> dist(E + 1, INF);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[origem] = 0;

    pq.push({0, origem});

    while (!pq.empty()) {

        auto [d, u] = pq.top();
        pq.pop();

        // Essa informação já está desatualizada.
        if (d != dist[u])
            continue;

        for (auto aresta : grafo[u]) {
            int v = aresta.destino;
            int peso = aresta.peso;

            if (dist[v] > dist[u] + peso) { // se a distancia do vertice seguinte é maior que o atual + aresta
                dist[v] = dist[u] + peso;

                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// ------------------------------------------------------------

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> E >> R;

    grafo.resize(E + 1);

    for (int i = 0; i < R; i++) {

        int A, B, C;

        cin >> A >> B >> C;

        grafo[A].push_back({B, C});
        grafo[B].push_back({A, C});
    }


    
    // 1. Descobrir os ciclos
    visitado.assign(E + 1, false);
    pai.assign(E + 1, -1);
    profundidade.assign(E + 1, 0);
    em_ciclo.assign(E + 1, false);

    for (int i = 1; i <= E; i++) {
        if (!visitado[i]) {
            dfs_ciclos(i, -1);
        } //garantir que todos os vertices tenham sido visitados/todos os ciclos
    }

    // 2. Para cada estação consultada:
    //    - Dijkstra a partir de X
    //    - tentar chegar em cada ciclo
    int K;
    cin >> K;

    //Construindo ciclos:
    // ATENÇÃO:
    // ciclo_tamanho guarda apenas os tamanhos.
    // Para simplificar, vamos descobrir novamente,
    // para cada ciclo, quais estações pertencem a ele.

    /*
        A propriedade do problema garante que uma estação pertence a no máximo um ciclo.

        Portanto podemos agrupar as estações de ciclo
        através de componentes das arestas que pertencem a ciclos.

        Uma forma simples para este problema é:
        para cada estação em_ciclo, encontrar o menor caminho até ela.
    */

    // A solução abaixo usa uma reconstrução dos ciclos.
    // Vamos descobrir os ciclos novamente, agora agrupando suas estações.

    vector<vector<int>> ciclos;
    vector<bool> usado(E + 1, false);

    for (int inicio = 1; inicio <= E; inicio++) {

        if (!em_ciclo[inicio] || usado[inicio]) //se não tiver em ciclo ou tiver sido usado pular
            continue;

        vector<int> ciclo;

        int atual = inicio;
        int anterior = -1;

        while (true) {

            ciclo.push_back(atual);
            usado[atual] = true;

            int proximo = -1;

            for (auto e : grafo[atual]) {

                if (!em_ciclo[e.destino])
                    continue; // saindo do ciclo

                if (e.destino == anterior)
                    continue; // voltando

                proximo = e.destino;
                break;
            }

            if (proximo == inicio)
                break; // achamos todo ciclo

            anterior = atual;
            atual = proximo;
        }

        ciclos.push_back(ciclo);
    }

    // desenhamos todos os ciclos;
    // Agora testamos cada ciclo.
    

    for (auto &ciclo : ciclos) {

        long long tamanho_ciclo = 0;

        // Calcula o comprimento do ciclo
        for (int i = 0; i < (int)ciclo.size(); i++) {

            int u = ciclo[i];
            int v = ciclo[(i + 1) % ciclo.size()];

            for (auto e : grafo[u]) {

                if (e.destino == v) {

                    tamanho_ciclo += e.peso;
                    break;
                }
            }
        }
    }

    while (K--) {
        int X;
        long long T;

        cin >> X >> T;
        vector<long long> dist = dijkstra(X);

        long long resposta = INF;

        /*
            Precisamos descobrir a distância de X até cada ciclo.
            Como os ciclos são disjuntos, basta procurar
            a estação do ciclo mais próxima.
            Primeiro construímos uma lista das estações
            pertencentes a cada ciclo.
        */
        // Menor distância de X até qualquer estação
        // desse ciclo.
        long long distancia = INF;

        // testar cada ciclo, pegar menor distancia para o ciclo x, ver se ciclo x tem maior tamanho que T.
        for (int v : ciclos) {

            distancia = min(distancia, dist[v]);
        }


        if (distancia == INF)
            continue;

        // X -> ciclo -> X
        long long percurso = 2 * distancia + tamanho_ciclo;


        // O trem precisa caber nesse percurso.
        if (percurso >= T) {
            resposta = min(resposta, percurso);
        }

        if (resposta == INF)
            cout << -1 << '\n';
        else
            cout << resposta << '\n';
    }

    return 0;
}


