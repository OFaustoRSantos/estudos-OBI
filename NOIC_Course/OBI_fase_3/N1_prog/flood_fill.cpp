#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

}

void idea_algor(){
    /*
    - Contar numero de componentes conexas / subgrafos
    - Exemplo grafo onde cada vertice tem conexão com outras duas pessoas que pertencem a uma mesma família
    */

    // Preencher o grafo como se fosse um fluxo

    // Duas maneiras de resolver: DFS e BFS

    // DFS: A cada passo olhá vizinhos do nó v. Para cada um deles cujo componente não foi determinada fazer sua componente ser a mesma de v.
    // mais fácil e rápida de implementar e debugar

    // BFS - é a mesma lógica mas usando o sistema de fila

    /*
    // componente[i] se trata da componente do vértice i
// inicialmente, componente[i] = -1 para todo vértice
// faremos a DFS como sendo uma função recursiva
// antes de chamar a DFS no primeiro nó, definimos sua componente
 
    DFS(vértice X):
        para todo V vizinho a X:
            se (componente[V] == -1):
                componente[V] = componente[X]
                DFS(V)
    */
}

// Solução um problema com a ideia:
//  familias_de_troia.cpp
//
//  Created by Lucca Siaudzionis on 06/05/15.
//
//  Famílias de Troia – OBI 2013 P2F2

#include <cstdio>
#include <vector>
using namespace std;

//————————
#define MAXN 50050

int n, m;
int componente[MAXN];
vector<int> lista[MAXN];
//————————

void dfs(int x){
    
    // percorremos por todos os vizinhos
    for(int i = 0;i < (int)lista[x].size();i++){
        
        int v = lista[x][i];
        
        if(componente[v] == -1){ // checamos se V ainda não foi visitado
            componente[v] = componente[x];
            dfs(v);
        }
    }
}

int main(){
    
    scanf("%d %d", &n, &m);
    
    for(int i = 1;i <= n;i++) componente[i] = -1; // inicializamos as componentes
    
    for(int i = 1;i <= m;i++){
        
        int a, b;
        scanf("%d %d", &a, &b);
        
        // adicionamos cada um a lista do outro
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    
    int numero_componentes = 0;
    for(int i = 1;i <= n;i++){
        
        if(componente[i] == -1){ // i ainda não tem componente
            
            // começaremos uma dfs a partir de i
            // assim, i será o começo de uma nova componente
            
            numero_componentes++;
            componente[i] = numero_componentes;
            
            dfs(i);
        }
        
    }
    
    printf("%d\n", numero_componentes); // por fim, imprimimos a resposta
    
    //  Note que, por simplicidade, não precisávamos ter guardado
    //  a componente a que cada vértice pertence.
    //  Simplesmente poderíamos ter guardado se um vértice já tinha
    //  sido visitado ou não. É o que eu faria normalmente, já que
    //  o problema não pede as componentes de cada vértice.
    //  Porém, é interessante ver esta abordagem, resolvendo o
    //  problema de uma maneira mais completa
    
    return 0;
}

// Não achei problema do codeforce sobre isso