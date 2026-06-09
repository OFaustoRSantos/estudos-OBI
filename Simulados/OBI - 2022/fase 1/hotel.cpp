#include <iostream>
using namespace std;

// dia 2 até 15
int main(){
    int D; // diaria D(1)
    int A; // razão P.A
    cin >> D >> A;
    int N; // dia de chegada no hotel
    cin >> N;
    int total;
    
    // identificar a diária a depender do dia que entrou.
    if(N >= 16){
        D += 14*A;
        //cout << D << endl;
        total = D*(32-N);
    } else{
        D += (N-1)*A;
        //cout << D << endl;
        total = D*(32-N);
    }
    // Até dia 16 (não incluso) fica-se aumentando a diária

    cout << total;
    return 0;
}
// 100%, nem precisa de duas versões
// lembrar de tirar os couts