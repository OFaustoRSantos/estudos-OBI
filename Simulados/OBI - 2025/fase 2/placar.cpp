#include <bits/stdc++.h>
using namespace std;


/*
B, P, C

Pebolim X Toto

Afonso - Pacau

- Anotou quando foi feito cada gol

*/

struct gol{int min; int pessoa;};

vector<gol> gols;

bool comp(gol a, gol b){
    return a.min < b.min;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Entrada:
    int P; cin >> P;

    for(int i=0; i<P; i++){
        gol min_gol;
        cin >> min_gol.min;
        min_gol.pessoa = 0;
        gols.push_back(min_gol);
    }

    int C; cin >> C;
    for(int i=0; i<C; i++){
        gol min_gol;
        cin >> min_gol.min;
        min_gol.pessoa = 1;
        gols.push_back(min_gol);
    }

    // Sort
    sort(gols.begin(), gols.end(), comp);
    
    int gols_P = 0; int gols_C = 0;
    // Começo Jogo
    cout << "0 0" << endl;
    // saida: gold de paulo x gols de Camila
    for(int i=0; i<gols.size(); i++){
        if(gols[i].pessoa == 0){
            gols_P++;
        } else{
            gols_C++;
        }
        cout << gols_P << " " << gols_C << endl;
    }
}


// fácil 1° - 100% em + ou - 5 minutos