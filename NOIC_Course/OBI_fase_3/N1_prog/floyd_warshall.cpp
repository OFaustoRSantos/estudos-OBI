#include <bits/stdc++.h>
using namespace std;



int ideia_algor()
{
    /* - Objetivo:
    - Calcular menor distancia entre todos pares de vertices.
    - Dijkstra roda apenas 1 como início.
    */

    /* - Ideia:
        perceber todo menor caminho de u -> v ( com mais de 2 vertices)
        pode ser decomposto em dois menores caminhos: u -> k, k->v
    */
   /* - definindo d(u,v,k) como menor distancia de u para v com um intermediario de indice K.
        Para cada par de (u,v) vertices temos:
        d(u,v,k) = 
        w(u->v) se k=0 (sem intermediário)
        min(d(u,v,k-1),d(u,k,k-1) + d(k,v,k-1)), caso contrário.
        ou seja, uma recursividade.
    sendo w(u,v) o peso da aresta (u->v)
    se não houver um w(u,v), d(u,v,0) = inf;
    dessa forma tem uma recursividade  com o d(u,k,k-1) ir acessando outros elementos até ter k=0. sem intermediário, e isso vai subindo até termos a distância.   
   */
}

// Codigo algoritimo

const int maxn = 110;

int n;

// peso das arestas
int w[maxn][maxn];

// distância entre qualquer par de vértices
int d[maxn][maxn];

vector<vector<int>> dist; // min distancia entre dois pares de vertices

void floyd_warshall(void)
{
	// inicialmente, a distância de u->v será o peso da sua aresta (se existir)
	// caso não exista, então seu valor será infinito (um valor bem grande) ou 0 se u = v.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = w[i][j]; 
            // se existir um valor
            // se não inf

	for (int k = 1; k <= n; k++) // vértice intermediário
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[j][k]); 
                // recursão principal
        // K igual a um vai colocar todos com o intermediário j, e o D[i][k] + d[j][k] foi definido lá em cima.
        // legal que o d[j][k] é atualizado a cada interação então o caso de ter 3/4 intermediários também é considerado

    // para encontra o menor caminho de todos os pares temos: n^3 + n^2

    // mais eficiente que o dijkstra por vertice em grafos muito densos
}