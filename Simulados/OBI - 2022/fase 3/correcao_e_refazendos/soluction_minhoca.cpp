#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N, K;
// Matriz adjacencia
vector<vector<int>> adj;
// Matrix de parente
vector<int> parent;
// 
vector<int> ordem;


void criar_arvore() {

    parent.assign(N, -1);
    ordem.clear();

    queue<int> q;

    // BFS simples para popular a matrix
    // também já da a "ordem que foi feito o bfs"

    q.push(0);
    parent[0] = 0;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        ordem.push_back(u);

        for (int v : adj[u]) {

            if (v == parent[u])
                continue;

            parent[v] = u;
            q.push(v);
        }
    }
}

// TESTANDO UM VALOR DE r
bool consegue(int R) {

    /*
    distancia do vertice u até vertice desprotegido mais profundo dentro dele;
    -1 não existir um vertice nessa condição
    */
    vector<int> des(N, -1);

    // Distancia de u até radar mais próximo dentro de u. INF -> Não existe radar na subarvore
    vector<int> rad(N, INF);


    int quantidade_radares = 0;


    // Processamos de baixo para cima.
    /* Com a ordem foi criada pela BFS:
        pai aparece antes do filho.
        por isso podemos fazer um reverse nessa ordem ou simplesmente processar de trás para frente : filhos aparecem antes dos pais
    */

    for (int i = N - 1; i >= 0; i--) {
        // vertice atual, já são necessáriamente os mais profundos os ultimos
        int u = ordem[i];


        // testando se algum filho apresenta radar
        for (int v : adj[u]) {
            //testando todos os próximos

            // acessando o parente de v tem que ser u, pois assim ele é filho.
            if (parent[v] != u)
                continue; 

            // Existe radar na subárvore de v.
            if (rad[v] != INF) {

                rad[u] = min(rad[u], rad[v] + 1);
            }
            // caso não exista manter no INF;
        }


        // Agora procuramos o vértice desprotegido mais profundo entre os filhos.
        
        for (int v : adj[u]) {
            // pegando só os filhos
            if (parent[v] != u)
                continue;

            // se tem algum deprotegido em v
            if (des[v] != -1) {
                // deprotegido do atual = max entre atual e o desprotegido do filho + 1
                des[u] = max(des[u], des[v] + 1);
            }
        }


        // O próprio u pode estar desprotegido.
        // Para a raiz isso não é necessário inicialmente,
        // mas para os outros vértices consideramos a
        // possibilidade através da lógica abaixo.

        // u == 0 -> u = nossa raiz.
        // Caso de estarmos pegando os mais profundos
        if (u != 0) {
            // se o desprotegido de u for -1, mas ele não tiver ngm abaixo, então des[u] é 0.
            // foram varias vezes tentando mudar esse valor, mas se não deu quer dizer que o mais profundo desprotegido é ele mesmo
            if (des[u] == -1) {

                des[u] = 0;
            }
        }


        // Dois casos:
        // 1- Existe um radar que consegue alcançar o vértice desprotegido mais profundo?
        // Se: rad[u] + des[u] <= R
        // então o radar consegue proteger esse vértice.
        
        // des[u] -> não pode ser -1 (não pode ser o root), tem que ter um radar mais próximo definido, radar mais próximo + a distancia do vertice mais profundo tem que ser <= R
        if (des[u] != -1 &&
            rad[u] != INF &&
            rad[u] + des[u] <= R) {
            
            des[u] = -1;
            // Se tudo isso for verdade, então não tem radar desprotegido na arvore u
        }


        
        // 2 Caso: O vértice desprotegido chegou a distância R | Se deixarmos ele subir mais um nível, não haverá como colocar um radar acima e ainda protegê-lo.
        // -> Então colocamos um radar em u.
        // se for menor que R quer dizer que podemos subir mais um pouco

        if (des[u] == R) {
            quantidade_radares++;
            if (quantidade_radares > K)
                return false; // Early stop

            rad[u] = 0; // radar mais longe é nele mesmo

            // O vértice que provocou a colocação do radar agora está protegido; logo não tem mais nada desprotegido em u
            des[u] = -1;
        }
    }


    
    // Caso especial: Ainda pode existir um vértice desprotegido próximo da raiz - Pós o loop acontecer
    // Para esses casos, precisamos verificar se um dos radares já existentes consegue alcançá-lo.
    
    // se o desprotegido na root for diferente de -1, logo existir
    if (des[0] != -1) {

        // Se a distância do radar mais próximo até o desprotegido não for suficiente, precisamos de mais um radar.

        // se distancia até radar[0] não tiver sido citado, ou a distancia + o destino for maior que R
        if (rad[0] == INF ||
            rad[0] + des[0] > R) {

            quantidade_radares++;

            if (quantidade_radares > K)
                return false;
        }
    }


    return true;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> N >> K;


    adj.resize(N);


    for (int i = 0; i < N - 1; i++) {

        int a, b;
        cin >> a >> b;

        --a;
        --b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // Enraizamos a árvore no vértice 0.
    criar_arvore();


    // Busca binária.
    // R = 0 sempre seria suficiente se pudéssemos colocar um radar em cada vértice, mas precisamos respeitar K.
    // Um limite seguro é N.
    
    int esquerda = 0;
    int direita = N;

    while (esquerda < direita) {

        int meio = (esquerda + direita) / 2;


        if (consegue(meio)) {

            // meio funciona.
            // Tentamos um raio ainda menor.
            direita = meio;

        } else {

            // meio não funciona.
            // Precisamos aumentar R.
            esquerda = meio + 1;
        }
    }


    cout << esquerda << '\n';

    return 0;
}