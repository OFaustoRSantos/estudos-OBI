/* - Modo como fiz, completamente errado se quer compila - 0/100
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
/*
void DFS(int distancia, int vertice_at, int last_par, int last_impar, int inicio);

vector<vector<int>> adj;
vector<int> max_tamanhos;

int main(){

    int N, M;
    cin >> N >> M;

    adj.assign(N,vector<int>());

    max_tamanhos.assign(N,0);

    
    for(int i=0; i<M;i++){
        int A,B;
        cin >> A >> B;
        
        adj[A].push_back(B);
        
        
        adj[B].push_back(A);
          
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
/*
    // modo como farei
    for(int i=0; i<N;i++){
        if(i%2 == 0)
        DFS(0,i, i, -1, i);
        else 
        DFS(0,i, -1, i, i);
    }
    // no maximo terei que colocar para o i começar em todos os possíveis,
    for(int i=0; i<N;i++){
        cout << max_tamanhos[i] << " ";
    } // ou posso colocar no de cima
    
    cout << endl;
    return 0;
}
*/

// Não acredito que terão circulos, caso tiver a ideia do inicio não funcionará, e terei que adicionar no DFS um int ultimo_vertice. Para evitar ficar dando voltas infinitas (embora eu ache que o last_impar e o last_par já resolvem isso)
// colocar o inicio não faz diferença agora que to pensando, pois a logica de last_par/last_impar, impede voltar
/*
void DFS(int distancia, int vertice_at, int last_par, int last_impar, int inicio){
    distancia++;
    if(distancia > max_tamanhos[inicio]){
        max_tamanhos[inicio] = distancia;
    }
    for(int i : adj[vertice_at]){
        // para não ficar repetindo - indo e voltando
        
            if(i%2 == 0){
                if(i>last_par){
                    DFS(distancia, i, i, last_impar, inicio);
                }
            }
            else{
                if(i>last_impar){
                    DFS(distancia, i, last_par, i, inicio);
                }
            }
          
    }
}
*/
// Feedback gemini -> Fiz um PÉSSIMO DFS, nem mesmo compila, Ideal é usar sistema de memoria