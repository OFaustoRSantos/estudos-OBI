#include <iostream>
using namespace std;

// a MIN, b max, C capacidade
// cada dose possui D
// Preenche de leite
int main (){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int intervalo = B-A;
    char answer = 'N';
    // Testar todos os ponteiros
    for(int i = 0; i<=intervalo; i++){
        if((C-(A+i))%D == 0){
            answer = 'S';
        }
    }

    cout << answer;
    return 0;
}
// 100% com os exemplos