#include <bits/stdc++.h>
using namespace std;

/*
- Ideia temos uma arvore.
- temos um valor R onde todas as salas com distâncias menor ou igual a R da sala s (incluindo s) fiquem protegidas

-> Binary Search
R satisfaz a condição?
    Sim: Reduzir dir
    Não: Aumentar esq
*/

/* - Ideia condição:

Vamos para os galhos mais profundos:
Subir R para cima; definiremos todos os que passamos R acima como "acesos", e do ponto que chegamos faremos uma avaliação dos pontos a

Mais profundo 24, se tiver um 23 junto com ele, então automaticamente  ele vai ser aceso caso R = 4

Quando acesar o 24 os R pontos acima dele vão fazer um verify com um R-i, para ver se os pontos deles são envoltos.
sempre que for vamos tirar ele do vector<int> que estamos rodando

Mais fácil, definir uma profundidade cada nó terá.

farei um pq, com o profundides mais profundos.

*/


vector<int> id_verify; // lista de ids para verificar.

pair<int,int> calculo_profundidades (int atual, int profundidade_atual, const vector<vector<int>>& mat_adj, vector<pair<int,int>>& profundidades){
    int mais_profundo = 0;
    int profundidade = profundidade_atual;

    if(mat_adj[atual].size() == 0)
        profundidades.push_back({atual, profundidade});
        return {};
    
}

//Resposta
int ultimo_R_working;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K; cin >> N >> K;
    vector<pair<int,int>> profundidades;
    vector<vector<int>> mat_entrada(N,vector<int>());
    vector<vector<int>> mat_saida(N,vector<int>());
    // Primeira função lambda escrita 100$ sozinho

    for(int n=0; n<N;n++){
        int a,b; cin >> a >> b;

        mat_entrada[b].push_back(a);
        mat_saida[a].push_back(b);
    }

    // achar root: definir 
    int id_root;
    for(int root=0; root<N; root++){
        if(mat_entrada[root].size() == 0){
            id_root = root;
            break;
        }
    }   
    // Calcular profundidade cada nó.
    calculo_profundidades(id_root);

    auto condicao = [&](int R) -> bool {
        vector<bool> vis(N,false);

    };
    
    int esq; int dir;
    while(esq<dir){
        int meio = esq + (dir-esq)/2;
        
        if(condicao(meio)){
            dir = meio;
            ultimo_R_working = meio;
        } else{
            esq = meio+1;
        }
    }
}