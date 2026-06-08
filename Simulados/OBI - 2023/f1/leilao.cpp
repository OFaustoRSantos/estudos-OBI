#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

struct lance{string nome; int valor;};

bool comp(lance a, lance b){
    return a.second < b.second;
}
int main(){
    int N;
    cin >> N;

    vector<lance> lances;
    
    string nome_at;
    int valor_at;
    lance l_lance_at;
    for(int i = 0; i< N; i++){
        cin >> nome_at >> valor_at;
        l_lance_at.first = nome_at;
        l_lance_at.second = valor_at;
        lances.push_back(l_lance_at);
    }
    sort(lances.begin(), lances.end(), comp);
    // endl 1° com certeza, segundo incerto, sol 1 com, sol 2 sem
    cout << lances[lances.end].first << endl;
    cout << lances[lances.end].second;
    return 0;
}
// OBS: acho que com sort nn funciona
// sem sort
string nome_at;
int valor_at;
int pos_big_lance = 0;
lance l_lance_at;
for(int i = 0; i < N; i++) {
    cin >> nome_at >> valor_at;
    l_lance_at.first = nome_at;
    l_lance_at.second = valor_at;
    lances.push_back(l_lance_at);
    if(valor_at > l_lance_at[pos_big_lance].second){
        pos_big_lance = i;
    }
}

return pos_big_lance

// mapa:
// 1 - Sem sort - s endl
// 2 - Sem sort - c endl
// 3 - Com sort - s endl
// 4 - Com sort - c endl

// Sem usar struct - mas duas listas somente,
// 5 - Sem sort - s endl
// 6 - Sem sort - c endl
// 7 - Com sort - s endl
// 8 - Com sort - c endl

// Sem usar struct - mas usando lista de pair, nn devo fazer pois nn lembro estrutura
// 9 - Sem sort - s endl
// 10 - Sem sort - c endl
// 11 - Com sort - s endl
// 12 - Com sort - c endl

