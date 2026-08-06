#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/*
    Sala M, N;
    armario = barreira, parece um BFS, mas não é
 
    Ou seja, um armário na posição (i, j) da sala, ao cair irá ocupar uma das seguintes opções:

    As células (i, j) e (i, j + 1);
    As células (i, j) e (i, j - 1);
    As células (i, j) e (i + 1, j); ou
    As células (i, j) e (i - 1, j).

    dei as dimensões, objetivo = criar maior caminho para ser percorrido entre entrada e saida
*/


// 1° tentativa
/*
vector<vector<int>> matrix;

// indices: 0 = andavel, 1 = armário

struct ponto{int x; int y;};
ponto inicio, saida;

// acredito que preciso enxergar isso matematicamente, não vou olhar agora essa questão irei para a próxima;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> row_default {M,0};
    
    cin >> inicio.x >> inicio.y;
    cin >> saida.x >> saida.y;

    matrix.assign(N,row_default);

    
}
*/

/*
Apanhei muito para a prova de 2018, só consegui realizar uma questão, estudando solução das outras 2

*/

/*
    Só tem um caminho do inicio ao fim, violet e klaus decidiram o caminho que ele vai seguir

    Testando alguns casos na mão, é possível ver que podemos obrigar Conde Olaf a seguir qualquer caminho simples (que não repete nenhuma posição) que começa em inicio e termina em saida.

    fui burro, era só caçar o maior caminho
*/
/* - Errado por usar BFS

//vector<vector<int>> matrix; - Não acredito que vou precisar disso
vector<vector<int>> dist;

// indices: 0 = andavel, 1 = armário

struct ponto{int x; int y;};
ponto inicio, saida;

// acredito que preciso enxergar isso matematicamente, não vou olhar agora essa questão irei para a próxima;

void BFS(){
    queue<ponto> fila;
    fila.push(inicio);
    vector<int> dir_x = {2, -2, 0, 0};
    vector<int> dir_y = { 0, 0, 2, -2};
    
    while (!fila.empty()){
        ponto ponto_at = fila.front();
        fila.pop();

        for(int i=0; i<4;i++){
            int nx = ponto_at.x + dir_x[i];
            int ny = ponto_at.y + dir_y[i];

            // duas opções:
            // 1° olhar a matrix inteira

            if(nx < 0 || nx >= dist[0].size() || ny < 0 || ny >= dist.size()){
                continue;
            }

            if(dist[nx][ny] < dist[ponto_at.x][ponto_at.y] + 2){    
                dist[nx][ny] = dist[ponto_at.x][ponto_at.y] + 2;
                ponto n_ponto; n_ponto.x = nx; n_ponto.y = ny;

                fila.push(n_ponto); // relaxar novamente
            }

            // 2° olhar a região entre inicio e fim ou seja nn pode ser menor que inicio.x - n farei assim
        }
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> row_default (M,0);
    
    cin >> inicio.x >> inicio.y;
    cin >> saida.x >> saida.y;

    //matrix.assign(N,row_default);
    dist.assign(N,row_default);

    BFS();

    cout << dist[saida.x][saida.y] *2 << endl;
}
*/
// BFS de 2 em 2, e depois multiplicar por dois para enviar a resposta.

// Fiz o BFS certo, mas o BFS não serve para maior caminho


// Solução:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ponto {
    int x, y;
};

int N, M;
Ponto inicio, saida;
vector<vector<bool>> vis;
int maior_caminho = 0;

int dir_x[] = {2, -2, 0, 0};
int dir_y[] = {0, 0, 2, -2};

void dfs(int x, int y, int passos) {
    // Chegou ao objetivo
    if (x == saida.x && y == saida.y) {
        maior_caminho = max(maior_caminho, passos);
        return;
    }

    vis[x][y] = true; // para não permitir a volta

    for (int i = 0; i < 4; i++) {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];

        // Verifica se o movimento está dentro dos limites e não foi visitado
        // Se limites respeitados e não for voltando:
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !vis[nx][ny]) {
            dfs(nx, ny, passos + 2);
        }
    }

    // Backtracking: desmarca a célula para permitir outros caminhos
    vis[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    // Convertendo coordenadas 1-based da OBI para 0-based do C++
    cin >> inicio.x >> inicio.y;
    cin >> saida.x >> saida.y;
    // consertar coordenadas: 
    inicio.x--; inicio.y--;
    saida.x--; saida.y--;

    vis.assign(N, vector<bool>(M, false));

    dfs(inicio.x, inicio.y, 1);

    cout << maior_caminho << "\n";

    return 0;
}


// 80% pois excedeu alguns limites de tempo, mas só consegui

/*
Limite de tempo permitido	4,0 s
Limite de memória permitido	64.0 MB
Máximo tempo usado	0,192 s
Máxima memória usada	612.0 KB
*/

// Como posso reduzir esses limites de tempo: 
/*
Subtarefa 5 - 0 / 20
#	Resultado	Detalhes	Tempo de execução	Memória usada
1	Correto	A saída está correta	0,002 seg	324.0 KB
2	Incorreto	Excedeu o tempo limite de execução	0,192 seg	504.0 KB
3	Correto	A saída está correta	0,001 seg	504.0 KB
4	Correto	A saída está correta	0,015 seg	324.0 KB
5	Incorreto	Excedeu o tempo limite de execução	0,104 seg	504.0 KB
6	Incorreto	Excedeu o tempo limite de execução	0,19 seg	324.0 KB
7	Incorreto	Excedeu o tempo limite de execução	0,146 seg	612.0 KB
8	Incorreto	Excedeu o tempo limite de execução	0,153 seg	324.0 KB
*/