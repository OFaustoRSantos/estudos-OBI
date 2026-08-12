#include <bits/stdc++.h>
using namespace std;

/*
1 tunel conecta exatamente dois salões

Cada salão está a uma altura no formigueiro

Grafo direcionado;
N max de salão que pode visitar.
DFS
*/

vector<vector<int>> mat_adj;
vector<int> n_salao;
vector<int> alturas;
int max_salao = 0;

/* 
    posso fazer recursivo ou com stack, farei recursivo

*/
int DFS(int pos_at){
    //cout << "DFS na Pos: " << pos_at << endl;
    int posi_at = pos_at;
    int salao_passados = 0;
    for(int i : mat_adj[posi_at]){
        //cout << "vizinho " << i << " de " << pos_at << endl;
        salao_passados = 1 + DFS(i); 
        //cout << "passou por " << salao_passados << " com " << i << " viz de " << pos_at << endl;
        if(salao_passados > n_salao[posi_at]){
            n_salao[posi_at] = salao_passados;
        }
        // função 
    }

    if(n_salao[posi_at] < salao_passados) 
        n_salao[posi_at] = salao_passados;

    return n_salao[posi_at];
}

// DFS modifica o n_salao[pos_at]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int S,T, P; // N salao, T tuneis, P salão que inicia
    cin >> S >> T >> P;
    
    //alturas.assign(S+1,0); //- Não precisa pois vai em ordem o input das alturas mas tentarei do mesmo jeito
    
    mat_adj.assign(S+1,vector<int>({}));
    // vis.assign(S,0); // 0 = não visitado, não tem ciclo, logo não preciso de visitado

    n_salao.assign(S+1,0);
    // salão de 1 a S -> Matrix adj
    alturas[0] = 999999;
    for(int i=1; i<S+1;i++){
        int alt_at;
        cin >> alt_at;
        alturas.push_back(alt_at);
    }

    for(int i=0; i<T; i++){
        int A,B;
        cin >> A >> B;

        if(alturas[A] == alturas[B]){
            mat_adj[A].push_back(B);
            mat_adj[B].push_back(A); 
        } 
        else if(alturas[A] > alturas[B]){
            mat_adj[A].push_back(B);
            //cout << "add " << B << " em " << A << endl;
        } else 
        {
            mat_adj[B].push_back(A); 
            //cout << "add " << A << " em " << B << endl;
        }
        
    }
    
    DFS(P);
    cout << n_salao[P] << endl;
    return 0;
}  

// fiquei meia hora debugando essa meleca. Terminei rapidamente em 20 min para ficar 30 min debugando

// Para ganhar 20/100, consegui aumentar o acerto mas o que aumentei eu perdi pq, ele estourou o limite de memoria
// ta dando agora estouro de memoria em todos


// Solução do chatgpt

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> altura;
vector<int> dp;

int DFS(int v) {
    // memoria
    if (dp[v] != -1)
        return dp[v];
    // Se nunca tiver sido explorado

    dp[v] = 0;

    // atualização por vizinho, genial
    for (int u : adj[v]) {
        dp[v] = max(dp[v], 1 + DFS(u));
    }

    return dp[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, T, P;
    cin >> S >> T >> P;

    altura.resize(S + 1);
    dp.assign(S + 1, -1);
    adj.resize(S + 1);

    // pegar alturas
    for (int i = 1; i <= S; i++)
        cin >> altura[i];

        // criação tuneis
    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        if (altura[a] > altura[b])
            adj[a].push_back(b);
        else if (altura[b] > altura[a])
            adj[b].push_back(a);
    }

    cout << DFS(P) << '\n';
}

// N estava tão atrás

/*
- Outra solução:
Mas existe uma segunda solução ainda melhor para você aprender

Como S ≤ 200, dá para pensar de outra maneira:

Ordenamos os salões por altura crescente.

Como toda aresta vai de maior → menor, quando processamos um salão, todos os estados dos destinos já podem estar calculados.

Então:

ordenar por altura
        ↓
processar do menor para o maior
        ↓
dp[v] = max(1 + dp[u])

Isso é DP topológica.

*/

/* Ordem do pensamento:
movimento só para altura menor
↓
não existem ciclos
↓
DAG
↓
cada salão tem uma resposta ótima
↓
DP
↓
DFS + memoização
*/