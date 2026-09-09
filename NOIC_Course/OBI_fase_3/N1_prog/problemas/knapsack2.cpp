#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Problema: https://atcoder.jp/contests/dp/tasks/dp_e

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    N = Numero de elementos
    C = peso max_mochila
    */
    int N, C; cin >> N >> C;

    int value[N+1]; int weight[N+1];

    for(int i=1; i<=N;i++){
        cin >> weight[i] >> value[i];
    }
    //cout << "dados recebido" << endl;
    // tako vai escolher:
    /* N itens.
    tem uma mochila que aguenta W;
    soma de pesos dos itens deve ser W;
    - encontre o valor maximo da soma de itens que taro tem que levar.
    */

    // valor máximo é 10^5;

    /* dp[i][v]
    Menor peso do conjunto com os i primeiros elementos, e valor v.
    */

    int maxv = 1e5;
    vector<vector<ll>> dp(N + 1, vector<ll>(maxv + 1));

    const ll inf = 8e12;

    // assign values
    for(int v = 1; v <= maxv; v++)
        dp[0][v] = inf;

    dp[0][0] = 0; //caso base, sem nenhum item não tem como ter nenhum valor e tbm nenhum peso


    // Inicio DP

    for(int i=1; i<=N;i++){
        for(int v=0; v<maxv+1; v++){
            dp[i][v] = dp[i-1][v]; // caso não escolhendo o item

            if(v >= value[i] && dp[i - 1][v - value[i]] != inf){
                dp[i][v] = 
                min(dp[i-1][v-value[i]] + weight[i], dp[i][v]);
            }
           
        }
    }

    int max_value = 0;

    for(int v=0; v<= maxv; v++){
        if(dp[N][v] <= C){
            max_value=v;
        }
    }
    cout << max_value << endl;

}