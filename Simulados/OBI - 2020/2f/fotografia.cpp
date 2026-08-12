#include <bits/stdc++.h>
using namespace std;

/*
moldura onde a foto seja menor -> area da moldura >> fotografia

a area da moldura da moldura que foto não ocupa, minima possivel
area moldura - fotografia menor possivel
*/


int Alt_f, Larg_f;
int area_f;
struct moldura{int largura; int altura; int indice;};

vector<moldura> molduras;

bool comp(moldura a, moldura b){
    // modo 1

    // modo 2 

    if((a.largura * a.altura) == (b.largura * b.altura)){
        return a.indice < b.indice;
    }
    return ((a.largura * a.altura) < (b.largura * b.altura));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Alt_f >> Larg_f;
    area_f = Alt_f * Larg_f;

    int N; cin >> N;

    for(int i =0; i<N;i++){
        moldura moldura_at;

        cin >> moldura_at.altura >> moldura_at.largura;
        moldura_at.indice = i+1;
        // excluindo molduras que não obedeçam requisito 1
        if(Alt_f > Larg_f){
            if(max(moldura_at.largura, moldura_at.altura) < Alt_f || min(moldura_at.largura, moldura_at.altura) < Larg_f){
                continue;
            }  
        } else {
            if(max(moldura_at.largura, moldura_at.altura) < Larg_f || min(moldura_at.largura, moldura_at.altura) < Alt_f) continue;
        }

        molduras.push_back(moldura_at);
    }   

    if(molduras.empty()){
        cout << -1 << endl;
        return 0;
    }

    sort(molduras.begin(), molduras.end(), comp);

    cout << molduras[0].indice << endl;

}

// Deu 100% nos testes, mas deu 0 no oficial, submeti, no lugar errado por isso o erro; 100%! Foi MUITO rápido, coisa de 20 min
