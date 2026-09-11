#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Problema: 
Conectividade do reino = 
Numero de pares ordenados (x,y)
x != y.

construir uma nova rodovia.
Descobrir um par:
A != B,
não existe conexão direta (A,B), porém é possível ir de A,B
*/

void DFS(int atual, int parente_atual, const vector<vector<int>>& mat_adj, vector<pair<bool,int>> vis, const vector<vector<bool>>& mat_rota, vector<vector<bool>> mat_cone);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M; cin >> N >> M;

    vector<vector<int>> mat_adj(N+1,vector<int>());
    // Unidirecionada
    // minha ideia é fazer um:
    //vector<vector<int>> mat_con(N, vector<int>()); // demora mais para checar
    // talvez seja melhor ter um mat_cone de bool e um estrada de bool também
    vector<vector<bool>> mat_cone(N+1, vector<bool>(N+1,false));
    vector<vector<bool>> mat_rota(N+1, vector<bool>(N+1,false));
    vector<pair<bool,int>> vis(N+1,{false,-1});
   
    vector<bool> b_inicios(N+1, true);

    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;

        mat_adj[a].push_back(b);
        mat_cone[a][b] = true;
        mat_rota[a][b] = true;
        b_inicios[b] = false;
    }

    
    queue<pair<int,int>> fila;
    for(int i=1; i<N; i++){
        if(b_inicios[i] == true){
            fila.push({i,-1});
        }
    }

    /* - meu trabalho:
    Achar um A, B onde existe não existe a rota direta de A -> B, porém é possível chegar de A para B.
    Minha ideia 1:
    | Fazer um BFS, e para todo ponto, definir:
    uma mat_con:
    a lógica vai ser escolher um x aonde a matrix adj tenha 3 numeros mas a conexão tenha 4. (dessa forma o par será X, o 4° da conexão)
    Se não tiver imprimir -1;
    */
    /*
    fila.first = vertice_at
    fila.second = ultimo_vertice
    - mudei de fila para stack
    */
    
    // melhor um DFS acho.
    // fica mais fácil organizar a volta;
    /* 
    - Não posso interar um para cada vertice. Preciso usar uma lógica diferente.
    Talvez parent? ir atualizando todos os parentes
    */
    while(!fila.empty()){
        int atual = fila.front().first; fila.pop();
        DFS(atual, -1, mat_adj, vis, mat_rota,mat_cone);
    }
    cout << -1 << endl;
}

/* - Rodovia me parece a mais fácil entre as 3 faltando
*/

void DFS(int atual, int parente_atual, const vector<vector<int>>& mat_adj, vector<pair<bool,int>> vis, const vector<vector<bool>>& mat_rota, vector<vector<bool>> mat_cone){

    //cout << "iniciando DFS no " << atual << " veio do " << parente_atual << endl;

    //checando se existe conexão, entre as duas
        for(int proximo : mat_adj[atual]){
            
            if(vis[proximo].first == true) continue;

            //cout << "testando vizinho " << proximo << " do " << atual << endl;
            // parent != -1
            int parent = parente_atual;
            while(parent != -1){
                if(!mat_rota[parent][proximo]){
                    // fazer o cout de ambos e dar um break
                    cout << parent << " " << proximo << endl;
                    exit(0);
                }
                parent = vis[parent].second;
            }
            vis[proximo] = {true, atual};
            DFS(proximo, atual, mat_adj, vis, mat_rota, mat_cone);
        }
        
}

/* - 100 % nos exemplos, foi legall
->  demorei + ou - 55 minutos.
- Um pouco menos que a média que tenho por questão

Talvez não tenha sido a solução mais eficiente

*/