#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// terminado 100% - ~20 min

int main(){
    // linhas N, e colunas N, N sempre par
    // dois quadrados com figurinha, em qualquer posição
    // comprou uma barra, quer dividir

    // Por ser quadrado, ele pode dividir de 2 formas,
    // faremos os testes com essas duas formas
    int N; //dimensão quadrado
    cin >> N;
    struct position{int x; int y; int quadrante;};
    vector<position> figurinhas;
    position n_figurinha;
    n_figurinha.quadrante = -1;
    cin >> n_figurinha.x >> n_figurinha.y;
    figurinhas.push_back(n_figurinha);
    cin >> n_figurinha.x >> n_figurinha.y;
    figurinhas.push_back(n_figurinha);

    // ver posição fig_1 e definir a partir dela
    // quadrante 1: x < N/2, y<N/2
    // quadrante 2: x > N/2, y<N/2
    // quadrante 3: x < N/2, y>N/2
    // quadrante 4: x > N/2, y>N/2
    for(int i =0; i<2;i++){
        if(figurinhas[i].x <= N/2){
            if(figurinhas[i].y <= N/2){
                figurinhas[i].quadrante = 1;
            }else{
                figurinhas[i].quadrante = 3;
            }
        } else{
            if(figurinhas[i].y <= N/2){
                figurinhas[i].quadrante = 2;
            }else{
                figurinhas[i].quadrante = 4;
            }   
        }
    }
    if(figurinhas[0].quadrante != figurinhas[1].quadrante){
        cout << "S" << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}