#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//100% nos exemplos
// Bem rapido + ou - 12 minutos

int main(){
    // 3 pokemons

    int N;
    cin >> N; // N de doces

    vector<int> pokemons{3,0};
    cin >> pokemons[0] >> pokemons[1] >> pokemons[2];


    int max_evolve;
    
    if(pokemons[0] > pokemons[1]){
        int temp = pokemons[0];
        pokemons[0] = pokemons[1];
        pokemons[1] = temp;
    }
    if(pokemons[1] > pokemons[2]){
        int temp = pokemons[1];
        pokemons[1] = pokemons[2];
        pokemons[2] = temp;
    }
    if(pokemons[0] > pokemons[1]){
        int temp = pokemons[0];
        pokemons[0] = pokemons[1];
        pokemons[1] = temp;
    }
    // o sort do algorithm nn funcionou então fiz na mão mesmo
    // Quando usei o sort(pokemons.begin(), pokemons.end()) o maior aparecia no meio, não sei pq.

    if(N < pokemons[0]){
        max_evolve = 0;
    } else{
        N-= pokemons[0];
        if (N<pokemons[1]){
            max_evolve =1;
        } else{
            N-= pokemons[1];
            if (N<pokemons[2])
            {
                max_evolve=2;    
            } else {
                max_evolve=3;
            }
        }
    }

    cout << max_evolve;
}