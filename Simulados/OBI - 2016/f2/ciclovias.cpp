#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    cada rua até duas direções
    caminho P de tamanho K, é definido pela sequencia de interseçao

    // Regras
    os numeros pares da subsequencia e os impares devem estar em ordem crescente
    Procurar caminho de maior tamanho
*/

int max_distance = 0;
void DFS(int distancia, int vertice_at, int last_par, int last_impar, int inicio);

vector<vector<int>> adj;

int main(){

    int N, M;
    vector<int> inicios;
    cin >> N >> M;

    
    for(int i =0; i<N;i++){
        adj.push_back({-1});
    }
    for(int i=0; i<M;i++){
        int A,B;
        cin >> A >> B;
        if(adj[A][0] == -1){
            adj[A].pop_back();   
            adj[A].push_back(B);
            inicios.push_back(A);
        } else{
            adj[A].push_back(B);
            inicios.erase(remove(inicios.begin(), inicios.end(),A), inicios.end());
        }
        if(adj[B][0] == -1){
            adj[B].pop_back();
            adj[B].push_back(A);
            inicios.push_back(B);
        } else{
            adj[B].push_back(A);
            inicios.erase(remove(inicios.begin(), inicios.end(),B), inicios.end());
        }
    }
    // matrix de adjacencia montada
    /* - tentei fazer assim não consegui, desisti
    stack<int> pilha;
    for(int i : inicios){
        pilha.push(i);
    }
    int last_par = 0;
    int last_impar = 0;
    // não sei se é a forma mais inteligente explorar a partir dos inicios, acredito que o certo seria explorar vertice por vertice como inicio, mas isso teria uma complexidade muito maior, dentro da prova eu testaria primeiro sem essa ideia de inicios para caso aprovasse tudo não ter que deixar mais complexo com a ideia de inicios
    // ideia é explorar em modelo de DFS
    while (!pilha.empty()){

        int temp = pilha.top(); pilha.pop();
        // verificação regra        
        if(temp%2 == 0){
            // par
            if(temp < last_par){
                continue;
            } else {
                last_par = temp;
                tamanhos[temp] = tamanho;
            }
        } else{
            // impar
            if(temp < last_impar){
                continue;
            } else{
                last_impar = temp;
                tamanho++;
            }
        }
    }
    */
    // modo como farei
    for(int i : inicios){
        DFS(1,i, 0, 0, i);
    }
    // no maximo terei que colocar para o i começar em todos os possíveis,
    cout << max_distance << endl;
    return 0;
}

// Não acredito que terão circulos, caso tiver a ideia do inicio não funcionará, e terei que adicionar no DFS um int ultimo_vertice. Para evitar ficar dando voltas infinitas (embora eu ache que o last_impar e o last_par já resolvem isso)

void DFS(int distancia, int vertice_at, int last_par, int last_impar, int inicio){
    distancia++;
    if(distancia > max_distance){
        max_distance = distancia;
    }
    for(int i : adj[vertice_at]){
        // para não ficar repetindo - indo e voltando
        if( i != inicio){
            if(i%2 == 0){
                if(i>last_par){
                    last_par=i;
                    inicio=vertice_at;
                    DFS(distancia, i, last_par, last_impar, inicio);
                }
            }
            else{
                if(i>last_impar){
                    last_impar = i;
                    inicio=vertice_at;
                    DFS(distancia, i, last_par, last_impar, inicio);
                }
            }
        }   
    }
}