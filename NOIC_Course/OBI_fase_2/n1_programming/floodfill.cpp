#include <iostream>
#include <vector>
using namespace std;

/*
/ componente[i] se trata da componente do vértice i
// inicialmente, componente[i] = -1 para todo vértice
// faremos a DFS como sendo uma função recursiva
// antes de chamar a DFS no primeiro nó, definimos sua componente
 
DFS(vértice X):
    para todo V vizinho a X:
        se (componente[V] == -1):
            componente[V] = componente[X]
            DFS(V)
*/
/*

//  o código a seguir é uma BFS partindo do vértice X
//  o array componente está inicializado para -1 em todas suas casas

fila.insere(X)
componente[X] := valor

enquanto (fila.tamanho > 0) faça:

    //vamos trabalhar com o primeiro da fila
    V = fila.frente
    fila.remove_frente
    
    para todo Y vizinho de V, faça:
        se (componente[Y] = -1):
            componente[Y] = componente[V]
            fila.insere(Y)
*/

int main(){
    
    return 0;
}


//
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