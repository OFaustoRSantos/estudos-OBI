#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, X1, X2; cin >> N >> X1 >> X2;

    pair<int,int> defaul; 

    /*
    first -> inclinação
    second -> ponto que cruza eixo y => b
    */
    vector<pair<int,int>> retas(N, defaul);

    for(int i=0;i<N;i++){
        cin >> retas[i].first >> retas[i].second;
    }

    /*
    Quantas interseções ocorrem nesse intervalo de X2-X1;    
    */

    /*
    temos um numero absurdo de retas, logo olgar onde cada uma delas intercepta entre si seria N*N -> loucura,
    Talvez com memória seja possível reduzir para N

    olhar cada ponto não faz sentido pq seria (X2-X1) * N; com um set.count; porém X2-X1 pode ser até 2*10^9

    todas as retas vão se interseptar em algum ponto do espaço
    n° maximo de interseções N(N-1)/2 -> ~N^2
    */

    /*
    Duas formas -> Testar cada X;
    Testar cada reta
    */
    int intersecoes =0;
    map<pair<int,int>, int> id;
    set<pair<int,int>> sets;
    // Pura força bruta
    if(X2-X1 < N){
        for(int i=X1; i<=X2; i++){
            set<int> ys;
            for(int j=0; j<N;j++){
                int y = retas[j].first * i + retas[j].second;
                ys.insert(y);
                if(ys.count(y) == 2) intersecoes++;
            }
        }

        cout << intersecoes << endl;
        return 0;
    } 
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            int encontro = (retas[i].second - retas[j].second) / (retas[j].first - retas[i].first);
            int val_encontro = encontro * retas[i].first + retas[j].second;

            if(X1 <= encontro || encontro <= X2){
                // verificar se ponto já foi interceptado
                if(sets.count({encontro, val_encontro}) == 1) intersecoes++;

                sets.insert({encontro, val_encontro});
            }
        }
    }

    cout << intersecoes << endl;


    // Posso fazer um sort para o menor coeficiente angula amas nn sei o quanto ajuda
}

/*
fiz em uns 20 min
*/