#include <bits/stdc++.h>
using namespace std;

void ilhas();
void grafo_direcionado();
void tam_maior_comp_conexa();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // ilhas();
    //grafo_direcionado();
    tam_maior_comp_conexa();

}

// problema 1
// Conte quantas ilhas existem numa grid de terra/água


/*
Lógica que eu queria usar mas não usarei para poder tentar implementar o DFS:

Fazer uma matrix de ativado;
para cada ponto verificar como a ativação dele influencia.
Se ele tiver ao menos um terra ativado do lado, pular - não faz nada
Se ele não tive
*/

/* | Não sei se é o certo mas parece funcionar 
N máximo de terras = N*M/4;
sempre que tiver ao menos uma terra do lado tirar um 
*/

/* | Nova ideia:
Se tiver alguma Terra visitada ao redor, não contar ilha
Se não tiver nenhuma terra visitada ao redor, adicionar 1 ilha.

*/

int n_ilhas=0;

void ilhas(){
    vector<vector<int>> matrix; // 0 = Agua. 1 = Terra
    vector<vector<int>> vis; // 0 = Não visitado, 1 = visitado

    vector<int> dir_x = {1,-1,0,0};
    vector<int> dir_y = {0,0, 1,-1};

    int n_ilhas=0;

    int N, M; // dimensões matrix

    cin >> N >> M;
    
    // definindo matrizes default, N linhas, M colunas
    
    vis.assign(N,vector<int>(M,0));
    matrix.assign(N,vector<int>(M,0));

    // pensando que ele faz um grid, com letras como input
    for(int i =0; i<N;i++){
        string M_at;
        cin >> M_at;
        for(int j=0; j<M; j++) {
            if(M_at[j] == 'T'){
                matrix[i][j] = 1;
            }
        }
    }

    queue<pair<int,int>> pilha;
    vis[0][0] = 1;
    pilha.push({0,0});

    while(!pilha.empty()){
        auto temp = pilha.front();
        pilha.pop();

        bool rodeada_terra_vis = false;
        // Se já tiver visitado iremos só pular
        // cout << "posicao atual " << temp.first << temp.second << endl;        

        // lógica para contagem de ilhas
        // pelo conceito da stack, ele primeiro fará uma varredura para baixo, depois fará a 2° ao lado e

        /*if(temp.first == 3 && temp.second == 0){
            cout << "analisando" << 30 << endl;
        }
        if(temp.first == 3 && temp.second == 1){
            cout << "analisando" << 31 << endl;
        } */
        
        // Explorando vizinhos
        for(int j = 0; j<4;j++){
            int nx = temp.first + dir_x[j];
            int ny = temp.second + dir_y[j];
            
            // definindo limites
            if(nx <= -1 || ny <= -1 || nx > N - 1 || ny > M - 1){
                continue;
            }
            // se for terra

            /*if(temp.first == 3 && temp.second == 0){
                cout << "analisando vizinho " << nx << ny << " do " << 30 << endl;
            }
            if(temp.first == 3 && temp.second == 1){
                cout << "analisando vizinho " << nx << ny << " do " << 31 << endl;
            } */

            if(matrix[nx][ny] == 1 && vis[nx][ny] == 1){
                rodeada_terra_vis = true;
                /* if(temp.first == 3 && temp.second == 0){
                cout << 30 << " tem vizinho visitado, com terra ao lado" << nx << ny << endl;
                }   
                if(temp.first == 3 && temp.second == 1){
                cout << 31 << " tem vizinho visitado, com terra ao lado" << nx << ny << endl;
                }   */
            }
            if(vis[nx][ny] == 0){
                // cout << "Adicionar vizinho " << nx << ny << " ao " << temp.first << temp.second << endl;
                vis[nx][ny] = 1;
                pilha.push({nx,ny});
            }
        }
        if(matrix[temp.first][temp.second] == 1 && !rodeada_terra_vis){
            n_ilhas++;
            //cout << "pos: " << temp.first << temp.second << " adicionar uma ilha, total ilhas: " << n_ilhas << endl;
        }
        
    }

    cout << n_ilhas << endl;

}

//tava dando muito erro, pelo menos tive uma boa prática de debugar

// tive que mudar de stack para queue, e começou a dar certo, tava mo trampo.

// Porque a stack não estava funcionando?
// acabava que ela lia as aguas ao lado primeiro então estragava o plano, foi só mudar para fila que funcionou
// Para manter na stack eu deveria criar uma outra matrix chamada ilha_terra -> e que somente poderá mudar o valor do ponto ao lado se o ponto atual for uma terra.

// 

/*
input teste
4    
5
ATTAA
TTAAT
AAATT
TTAAA
*/

// não está analisando o 40

// Problema 2 - verificar se um grafo direcionado
void grafo_direcionado(){
    vector<vector<int>> adj; // matrix de adjacencia
    vector<pair<int,int>> vis_ares; 
    // segundo = inicio de origem
    
    vector<bool> recebe_aresta;

    int N,M; // N = numero de vertice, e M = de arestas
    cin >> N >> M;

    bool tem_ciclo = false;

    adj.assign(N, vector<int>({}));
    vis_ares.assign(N,{0,-1});
    recebe_aresta.assign(N,false);

    for(int i =0; i<M; i++){
        int A, B; // Saida -> Destino, unidirecionado
        cin >> A >> B;

        adj[A].push_back(B);
        recebe_aresta[B] = true;
    }

    // preciso de alguma forma verificar se tem um ponto em que não recebe seta nenhuma -> Inicios
    // testagem para ver se tem ciclo => testar aresta com stack, se alcançar um lugar já visitado tem ciclo

    stack<int> pilha;
    // Colocando todos os inicios na fila
    for(int i=0; i<N; i++){
        if(recebe_aresta[i]){
            continue;
        }
        vis_ares[i] = {1,i};
        pilha.push(i);

        // Preciso fazer o while aqui, pq se não quanto um inicio novo tocar um já visto iria apontar ciclo, sem ser ciclo - mentira farei uma solução que vis_ares só forma ciclo se tiver mesmo pair.second - inicio de origem;
        while(!pilha.empty()){
            auto temp = pilha.top();
            pilha.pop();

            for(int j : adj[temp]){
                if(vis_ares[j].first == 1){
                    if(vis_ares[j].second == vis_ares[temp].second){
                        // mesmo inicio
                        tem_ciclo = true;
                        break;
                    }
                } else{ 
                    vis_ares[j] = {1, vis_ares[temp].second};
                    pilha.push(j);
                }
            }
            if(tem_ciclo){
                break;
                // ou só precisava mandar um cout e um return
            }
        }
        if(tem_ciclo){
            break;
            // ou só precisava mandar um cout e um return
        }
    }
    
    if(tem_ciclo){
            cout << "S" << endl;
    } else{
            cout << "N" << endl;
    }

}

// Criarei desafio pelo gemini, mais facil ter input teste e estrutura
// Problema: Ache o tamanho da maior componente conexa.
// Inclui no .md 

/* - maior-cluster-servidores

*/

void tam_maior_comp_conexa(){
    vector<vector<int>> mat_adj;
    vector<int> visitadas;
    int tam_caminho_max=1;


    int N, M; // N_servidores (1 a N), logo add um para ajustar quando tiver o vetor

    cin >> N; 
    cin >> M;

    visitadas.assign(N,0);
    mat_adj.assign(N, vector<int>({}));

    // bidirecional; eles estão conectados se tem um caminho entre eles;

    for(int i =0; i<M;i++){
        int A,B;
        cin >> A >> B;

        mat_adj[A].push_back(B);
        mat_adj[B].push_back(A);
    }

    stack<int> pilha;
    for(int i=0; i<N;i++){
        // é inicio se só tem uma conexão e não foi visitado (é final se for)
        if(mat_adj[i].size() == 1 && visitadas[i] == false){
            visitadas[i] = true;
            pilha.push(i);
        }
        
        int tam_caminho_at = 1;


        while(!pilha.empty()){
            auto temp = pilha.top();
            pilha.pop();

            for(int j : mat_adj[temp]){
                if(visitadas[j] == 1){
                    
                } //ainda não foi visitada
                else{
                    visitadas[j] = 1;
                    pilha.push(j);
                    tam_caminho_at++;
                }
            }
        }
        // quando terminar o loop, terminou o caminho daquele inicio

        if(tam_caminho_at > tam_caminho_max){
            tam_caminho_max = tam_caminho_at;
        }
        // EARLY STOPS

    }

    cout << tam_caminho_max << endl;

}