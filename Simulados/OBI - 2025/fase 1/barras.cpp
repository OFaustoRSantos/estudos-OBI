#include <iostream>
#include <vector>
using namespace std;

// grafico, popularidade
vector<int> brinquedos;
vector<vector<int>> matrix;
int main (){
    int N; // numeros de brinquedos
    cin >> N;
    int ni; // numero de votos cada brinquedo
    int max = 0; // sempre inicializar valor
    for(int i =0; i<N; i++){
        cin >> ni;
        if(ni > max){
            max = ni;
        }
        brinquedos.push_back(ni);
    }

    
    for(int j=max; j>=0; j--){ // linhas, começando da lá em baixo
        vector<int> linha_at;
        for(int i =0; i<N; i++){ // colunas
            if(brinquedos[i] == j){
                linha_at.push_back(1);
                brinquedos[i]--;
            } else{
                linha_at.push_back(0);
            }
        }
        matrix.push_back(linha_at);
    }

    for(int i = 0; i<max; i++){
        for(int j =0; j<N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// 100% com os exemplos