#include <iostream>
using namespace std;

int main(){
    int N,M,S;
    int I = -1;
    cin >> N >> M >> S;
    int Sum_dig_at;
    for(int i = N; i<= M; i++){
        Sum_dig_at = i/10000 + i%10000/1000 + i%10000%1000/100 + i%10000%1000%100/10 + i%10000%1000%100%10;
        if(Sum_dig_at == S){    
            I = i;
        }
    }

    cout << I;
    return 0;
}
// 100% de acerto 
//Caso tenha valores negativos não pode dar break quando passa de S.
// Caso N,M possam ser grandes, use long long para intervalos