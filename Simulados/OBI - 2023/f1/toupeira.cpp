#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//int P_l[1000] = {-1}
vector<vector<int>> P_l;
int mat[1000][1000];


int main(){
    // grafo
    // 1 tunel por salão, multi direação
    // Cada salão tem um indicador

    // forma de descrever essa matrix i = salão, j = salão, mat[i][j] = 1 - tem conexão, 0 - não tem
    // dado mapa dos tuneis
    // dado lista sugestão de passeios
    // verify if mat[p[i]][p[i+1]] == 1

    int S,T;
    int c_poss;

    cin >> S >> T;
    int i_at, j_at;
    for(int i = 0; i<T; i++){
        cin >> i_at >> j_at;

        mat[i_at][j_at] = 1;
    }

    // if p = -1, acabou a lista, ou usar vector, mais easy

    int P =0;
    cin >> P;
    int n_at;
    int n_p;
    bool possible;
    
    for(int i =0; i<P; i++){
        cin >> n_p;
        possible = true;
        vector<int> P_at;
        for(int j=0; j< n_p; j++){
            cin >> n_at;
            P_at.push_back(n_at);
        }
        // O que comentei abaixo sobre;
        for(int j = 0; j<n_p -1; j++){
            if(mat[p_at[i]][p_at[i+1]] == 1){

            } else{
                possible = false;
                break;
            }
        }
        if(possible){
            c_poss++;
        }
        // Nem precisa do P_l mais
        P_l.push_back(P_at)
    }

    cout << c_poss;
    /* Ia fazer P_l primeiro depois mudar mas acho pauleira, maix prático fazer isso p_at
    for(int i = 0; i<P; i++){
        for(int j =0; j<)
        if(mat[p[i]][p[i+1]] == 1)
    }*/
}

// mapa de soluções:
// modelo atual - uma com endl, outra sem, no final
// usando matrix = vetor - uma com endl, outra sem, no final
//tirando P_L - uma com endl, outra sem, no final
// usando matrix = vetor + sem PL - uma com endl, outra sem, no final