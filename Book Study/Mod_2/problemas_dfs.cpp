#include <bits/stdc++.h>
using namespace std;

void ilhas();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ilhas();

}

// problema 1
// Conte quantas ilhas existem numa grid de terra/água
vector<vector<int>> matrix; // 0 = Agua. 1 = Terra
vector<vector<int>> vis; // 0 = Não visitado, 1 = visitado

vector<int> dir_x = {1,-1,0,0};
vector<int> dir_y = {0,0, 1,-1};

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
            cout << "pos: " << temp.first << temp.second << " adicionar uma ilha, total ilhas: " << n_ilhas << endl;
        }
        
    }

    cout << n_ilhas << endl;

}

//tava dando muito erro, pelo menos tive uma boa prática de debugar

// tive que mudar de stack para queue, e começou a dar certo, tava mo trampo.

// Porque a stack não estava funcionando?

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