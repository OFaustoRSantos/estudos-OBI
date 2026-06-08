#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> notas;

int main(){
    int N = 0; // N° participantes
    int K = 0; // N° Aprovados
    int C = 0; // Nota de corte
    // for n participante, if N nota > C -> K +1
    cin.ignore();
    cin >> N;
    cin >> K;
    
    for(int i =0; i < N; i++){
        int Ai =0;
        cin >> Ai;
        notas.push_back(Ai);
    }

    sort(notas.begin(), notas.end());

    C = notas[N-K];

    cout << C<< endl;
    return 0;

}