#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
}

// Estrutura do problema transportes:

// Pegar as areas, criar um id para cada aresta original.

// id guarda o estado: vertice e sistema

// Cria os vertices auxiliares com seus ids já

// Criamos o grafo com a quantidade de vertices

/* - Construção grafo:
Sendo o vertice u, um sistema com v. fazemos pegando da aresta o custo zero entre os dois, pois iremos sempre sair do auxiliar para a linha

Todo vertice u aponta para o auxliar com o seu id, tendo um custo zero
todo auxiliar aponta para o vertice u tendo um custo P.

Fazemos a conexão entre cada id para ele ficar ligado ao auxiliar em questão, e o auxiliar a ele

(auto [estado, vertice] : id){
// vertice é o ide em questão
int u = estado.first -> O vertice atual
int v = estado.second -> O sistema em questão

// push do grafo[vertice] -> adj[u] com P = 0

// push do adj[u] -> grafo[vertice] com peso = P[v]

}

Criação do dijakstra:

definir um dist(qntd_vertices, INF)

criar priority queue.
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
/*
(min-heap) que armazena pares (pair) ordenados pelo primeiro valor (ll), com desempate automático pelo segundo (int). 
*/

/*

pq.push({0,0}) // 0 ou aux[inicio]

while(!pq.empty()){
    auto [dist_atual, u] = pq.top();
    pq.pop();

    // vamos tirar valores que entrarem depois de termos descobrido o menor preço já
    if(dist_atual != dist[u]){
        
    }
    // pois antes de colocar o numero na lista iremos atualizar o dist[u], e só faz sentido fazer o Dijkstra no vertice/id, se ele for o menor.
}

*/