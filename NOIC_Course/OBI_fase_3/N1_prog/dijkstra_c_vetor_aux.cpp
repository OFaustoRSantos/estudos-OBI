#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    return 0;
}


// Caso 1: 

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

// Caso 2: Uso de cupom disponível em um avião/em um caminho.
// Se tivermos X cupons faremos x caminhos completos e cada vertice terá X opções:
// ir para o caminho sem o cupom com peso y e o com caminho do cupom com um peso y/2 (exemplo).
// No final colocar todos os destinos apontando para um vertice aux chamado chegada, e usar o dist[chegada]


// em codigo:

int cod_aviao(){

    
#define tii tuple<int,int,int>

priority_queue<tii, vector<tii>, greater<tii>> pq;

pq.push({0, 1, 0}); //sem usar cupom no 1°

vector<vector<int>> dist; // aqui ele tem a menor distancia para cada vertice com duas condições se usou o cupom ou não

vector<vector<pair<int,int>>> adj; //matrix_adj, duas * n orignal de opções -> ir com cupom e ir para uma segunda matrix, ou sem.
// a contrução disso é parecida com transporte, pegamos o ID.

while(pq.size()){
	auto[d, u, cupom] = pq.top(); pq.pop();
	// d = distancia de u, u = vertice, cupom = já usou ou não o cupom
	if(dist[u][cupom] < d) continue; // pular vertice aonde a distancia até ele é maior que o minimo

	for(auto [v, w] : adj[u]){
        // dois pushs na aresta que escolher cupom.
		if(dist[v][cupom] > d+w) // não usar o cupom
			dist[v][cupom] = d+w, pq.push({d+w, v, cupom});

		if(cupom==0 && dist[v][1] > d+w/2) // usar o cupom
			dist[v][1] = d+w/2, pq.push({d+w/2, v, 1});
	}
    }

}

// Nesse caso ele não chega a criar uma matrix inteira nova - legal, ele simplesmente coloca o estado na matrix dis, e na adj coloca se ta com cupom ou não.

// Caso 2:

/*
Grafo com custo e tempo
Caminho com menor tempo com custo menor ou igual a S entre inicio e fim

Digamos que S é pequeno (200)

faremos um dist[N][S]; Se avançar para o proximo verice faz S > 200 parar.

Uso de id faz muita diferença pois cada vertice do grafo auxiliar: com id é processado apenas uma vez
*/

//Problemas para fazer:
/*
https://codeforces.com/group/FL7L0PyRjp/contest/427349/problem/A

https://codeforces.com/group/FL7L0PyRjp/contest/427349/problem/B 

https://codeforces.com/group/FL7L0PyRjp/contest/427349/problem/C
*/
