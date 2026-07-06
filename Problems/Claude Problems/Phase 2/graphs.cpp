#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> matrix_tipo;
vector<vector<int>> matrix_dist; // matrix distancia
// 0 - . passavel, 1 = barreira, 2 = entrada, 3 = saida,  
int main(){
    int N,M; //dimensões
    cin >> N >> M;
    
    struct position {int p_i; int p_j;};
    // montando matrix com tipos
    position S;
    position E;
    for(int i =0; i < M; i++){
        vector<int> camada_at;
        vector<int> camada_at_dist;
        string s_camada_at;
        cin >> s_camada_at;
        // Caso tenha mais que um esse position seria um vetor. 
        for(int j = 0; j < N; j++){
            int tipo_at = -1;
            if(s_camada_at[j] == 'S'){
                tipo_at = 2;
                S.p_i = i;
                S.p_j = j;
            } else if(s_camada_at[j] == 'E'){
                tipo_at = 3;
                E.p_i = i;
                E.p_j = j;
            } else if(s_camada_at[j] == '.'){
                tipo_at = 0;
            } else if(s_camada_at[j] == '#'){
                tipo_at = 1;
            }
            camada_at.push_back(tipo_at);
            camada_at_dist.push_back(-1);
        }
        matrix_tipo.push_back(camada_at);
        matrix_dist.push_back(camada_at_dist);
    }

    // montando lista de adjacência, não acho que será necessário
    position p_at;
    p_at.p_i = S.p_i;
    p_at.p_j = S.p_j;
    bool trip = true;
    int passos = 0;
    vector<position> fila;
    // matriz onde i,j é a distancia de passos minima de i, j até S
    while(trip){
        // passos que demorou até a póxima
        if(matrix_dist[p_at.p_i][p_at.p_j] == -1) {
            matrix_dist[p_at.p_i][p_at.p_j] = passos;
        }

        
    }

}