#include <bits/stdc++.h>
using namespace std;

/*
Deixar que todos tenham a mesma autura

cada fase só pode aumentar em uma unidade a quatidade de anderes de predios consecutivos

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> andares(N,0);
    vector<int> grupos(N,0); //numero de elementos atrás dele com mesmo valor

    /*
    pq.first => Valor numero
    pq.second => Numero de elementos no grupo,
    pq.third => id no grupo
    */
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<int> vis(N,0);
    int v_max = 0;
    for(int i =0;i<N;i++){
        cin >> andares[i];
        v_max = max(v_max, andares[i]);
        if(i>0){
            if(andares[i] == andares[i-1]){ 
                grupos[i] = grupos[i-1]+1;
            }   
            else{
                // diferente quebrou um grupo
                // colocar no id do primeiro o grupo negativo indicando que é para frente
                grupos[i-1 - grupos[i-1]] = -grupos[i-1];
                pq.push({andares[i-1], -grupos[i-1], i-1});
            }
        }
    }
    // tenho todos os grupos aqui
    pq.push({andares[N-1], -grupos[N-1], N-1});

    int fases = 0;
    while(!pq.empty()){
        auto [valor, n_elementos, id] = pq.top();
        pq.pop();
        if(vis[id] == 1) continue;
        //cout << "v: " << valor << "; n_ele: " << n_elementos << "; id: " << id << endl;
        n_elementos = -n_elementos; // invertendo o sinal
        vis[id] = 1;

        if(valor == v_max){
            break;
        }
        if(id-n_elementos==0){
            if (id == N-1){
                break;
            }
        }

        if(id-n_elementos>0){
            // tem elementos atrás
            if(valor+1 == andares[id-n_elementos-1]){
                // numero de elementos aumenta
                vis[id-n_elementos-1] = 1;
                n_elementos += -grupos[id-n_elementos-1];
            }
        }
        if(id+1 < N){
            // tem elementos na frente
            if(valor+1 == andares[id+1]){
                // aumentar o grupo para frente / achar novo id
                if(grupos[id+1]==0) {
                    id++; n_elementos++;}
                else if(grupos[id+1] < 0){
                    n_elementos+= 1-grupos[id+1];
                    id+= 1-grupos[id+1];
                }
            } else{
                // nunca vai ser menor
                vis[id]=0;
            }
        }
        fases++;
        if(id-n_elementos==0){
            if (id == N-1){
                break;
            }
        }
        pq.push({valor+1, -n_elementos, id});
    }

    cout << fases << endl;

}

/*
- fui muito bem, fiz em 34 minutos, mas no primeiro teste passou quase tudo
foi 100%, mas a minha lógica de n_elementos nn funcionou, mas estranhamente deu certo nos exemplos. 
terminei no min 180 - 51 minutos
*/