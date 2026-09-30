#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;

    vector<int> forca(N,0);

    for(int i=0; i<N;i++){
        cin >> forca[i];
    }

    // formar K duplas -> um atleta por dupla
    // custo dupla = (a-b)^2
    sort(forca.begin(), forca.end());

    // dp[][] soma dos custos de duplas com os N primeiros itens das K duplas
    /*
    Transições:
    Escolher numero atual:
    não escolher

    dp[n][k]  = dp[n-1][k]

    dp[n][k-1] // preço não escolhendo uma dupla agora;
    dp[n-1][k-1] //
    */

    vector<vector<int>> dp(N, vector<int>(K,0));
    for(int i=1;i<=N;i++){
        for(int j=1; j<=K;j++){
            if(j > i/2) break;

            
        }
    }
} 