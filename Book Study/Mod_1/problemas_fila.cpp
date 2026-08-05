#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int main(){
    return 0;
}

void fila_atendimento(){

    int N;
    cin >> N;

    queue<int> fila;
    for(int i =0; i<N; i++){
        int N_at;
        cin >> N_at;
        fila.push(N_at);
    }

    while(!fila.empty()){
        cout << "Numero atual: " << fila.front();
        cout << endl;
        fila.pop();
    }
}

struct ponto{int x; int y;};


vector<vector<int>> matrix;
vector<vector<int>> mat_distancia; 


// setando direções, excluindo diagonal;
vector<int> dir_x = {1,-1,0,0};
vector<int> dir_y = {0,0,1,-1};

queue<ponto> fila;
queue<int> dist_at;

void BFS(int dist, ponto p_at);
// Menor caminho em grid sem peso (BFS)
void min_path_s_peso(){
    // grid logo matrix


    int N, M;
    cin >> N >> M;

    // populando matrix distancia com os valores -1
    vector<int> dist_row_default; dist_row_default.assign(M,-1);
    mat_distancia.assign(N,dist_row_default);

    for(int i=0; i<N; i++){
        vector<int> row_at;
        for(int j=0; j<M;j++){
            int N_at;
            cin >> N_at;
            row_at.push_back(N_at);
        }
        matrix.push_back(row_at);
    }
    // Setando inicio
    
    ponto inicio; inicio.x = 0; inicio.y =0;

    mat_distancia[0][0] = 0;
    // começando da ponta
    fila.push(inicio);
    dist_at.push(0);
    
    while (!fila.empty()){
        // setando tempo com dados
        ponto temp = fila.front();
        fila.pop();
        int _dist_at = dist_at.front();
        dist_at.pop();
        BFS(_dist_at, temp);
    }

    cout << mat_distancia[N-1][M-1] << endl;
}

/*BFS não tão ideal, certo marcar distancia no momento em que colocar na fila, não no inicio da função, assim adiciona menos fatores na fila*/
void BFS(int dist, ponto p_at){
    // atualizando valor
    if (mat_distancia[p_at.x][p_at.y] != -1){

    } else{
    int dist_ponto = dist;
    dist_ponto++;
    mat_distancia[p_at.x][p_at.y] = dist_ponto;
    // Fazendo a busca

    // 1° Testar se destino é possivel, 2° Testar se destino já foi setado;
    for(int i = 0; i<4; i++){
        ponto p_dest;
        p_dest.x = p_at.x + dir_x[i];
        p_dest.y = p_at.y + dir_y[i];
        
        // Se X for permitido
        if(p_dest.x >= 0 && p_dest.x < matrix.size()){
        // Se Y for permitindo
            if(p_dest.y >= 0 && p_dest.y < matrix[0].size()){
                fila.push(p_dest);
                dist_at.push(dist_ponto);             
            }
        }
    }

    }
}
// não sei como incluir a dist com qualidade então farei duas queue, uma de dist, outra de posição
void BFS(int dist, ponto p_at){
    // atualizando valor
    if (mat_distancia[p_at.x][p_at.y] != -1){

    } else{
    int dist_ponto = dist;
    dist_ponto++;
    mat_distancia[p_at.x][p_at.y] = dist_ponto;
    // Fazendo a busca

    // 1° Testar se destino é possivel, 2° Testar se destino já foi setado;
    for(int i = 0; i<4; i++){
        ponto p_dest;
        p_dest.x = p_at.x + dir_x[i];
        p_dest.y = p_at.y + dir_y[i];
        
        // Se X for permitido
        if(p_dest.x >= 0 && p_dest.x < matrix.size()){
        // Se Y for permitindo
            if(p_dest.y >= 0 && p_dest.y < matrix[0].size()){
                fila.push(p_dest);
                dist_at.push(dist_ponto);             
            }
        }
    }

    }
}
/* BFS ideal, tirando queue dist, e consertando/reorganizando quando atualiza valor*/

void BFS_ideal(ponto p_at){
    // Fazendo a busca

    // 1° Testar se destino é possivel, 2° Testar se destino já foi setado;
    for(int i = 0; i<4; i++){
        ponto p_dest;
        p_dest.x = p_at.x + dir_x[i];
        p_dest.y = p_at.y + dir_y[i];
        
        // Se X for permitido
        if(p_dest.x >= 0 && p_dest.x < matrix.size()){
        // Se Y for permitindo
            if(p_dest.y >= 0 && p_dest.y < matrix[0].size()){
                if(mat_distancia[p_dest.x][p_dest.y] != -1){

                } else{
                    mat_distancia[p_dest.x][p_dest.y] = mat_distancia[p_at.x][p_at.y] +1;
                    fila.push(p_dest);
                }
            }
        }
    }
}


// Os dois jeitos funcionam, mas a solução mais ideal possivel é bem mais simplificada na principal:

/*
struct ponto {
    int x;
    int y;
};

vector<vector<int>> matrix;
vector<vector<int>> mat_distancia;

vector<int> dir_x = {1, -1, 0, 0};
vector<int> dir_y = {0, 0, 1, -1};

queue<ponto> fila;
- parte igual
*/
// faz hile em si mesmo, sem recursividade
void BFS(ponto inicio) {

    // Distância do início para ele mesmo
    mat_distancia[inicio.x][inicio.y] = 0;

    fila.push(inicio);

    while(!fila.empty()) {

        ponto atual = fila.front();
        fila.pop();

        for(int i = 0; i < 4; i++) {

            int nx = atual.x + dir_x[i];
            int ny = atual.y + dir_y[i];

            // Fora do grid
            if(nx < 0 || nx >= matrix.size() ||
               ny < 0 || ny >= matrix[0].size()) {
                continue;
            }

            // Já visitado
            if(mat_distancia[nx][ny] != -1) {
                continue;
            }

            // verificando se tem barreira
            if(matrix[nx][ny] == 1){
                continue;
            }

            // Define distância e visita
            mat_distancia[nx][ny] =
                mat_distancia[atual.x][atual.y] + 1;

            fila.push({nx, ny});
        }
    }
}

void min_path_s_peso_ideal() {

    int N, M;
    cin >> N >> M;

    matrix.assign(N, vector<int>(M));
    mat_distancia.assign(N, vector<int>(M, -1));
    // esqueci possibilidade de ter barreira

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    ponto inicio = {0, 0};

    BFS(inicio);

    cout << mat_distancia[N-1][M-1] << endl;
}

// Errei horário, tenho mais 20 minutos hoje, vou usa-los para tentar terminar mais um problema do topico filas e ficar devendo o Leetcode e o ultimo problema somente 

// K-ésimo maior elemento com stream de números (priority queue) — médio


void mon_lat_jogo(){
    // maior na frente, ele quer que eu use priority queue, embora me parece mais ineficiente.
    // minha ideia original era

    
    priority_queue<int, vector<int>> pq;
    
    // Cada novo ping, informar qual o 3° pior (maior ping) registrado até aquele momento

    vector<int> fila_inicial = {45, 90, 120, 75};
    for(int i : fila_inicial){
        pq.push(i);
    }
    vector<int> prox_numeros = {110, 85, 150, 60};

    vector<int> retirados = {0,0};
    for(int i : prox_numeros){
        pq.push(i);
        for(int i=0; i<2; i++){
            int temp = pq.top();
            pq.pop();
            retirados[i] = temp;
        }
        cout << pq.top() << endl;
        // refazer fila:
        for(int i : retirados){
            pq.push(i);
        }
    }

}