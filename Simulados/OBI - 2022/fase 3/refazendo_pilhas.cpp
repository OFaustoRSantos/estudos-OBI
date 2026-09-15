#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 500*500*10;

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);

    int N, K; cin >> N >> K;

    vector<int> alt_pilhas(N,0);

    for(int i=0;i<N;i++){
        cin >> alt_pilhas[i];
    }

    sort(alt_pilhas.begin(), alt_pilhas.end());

    /*
    dp[numero de elementos][numero de K] = quantidade minima de moedas
    */
    vector<vector<int>> dp (N+1, vector<int>(K+1, INF));
    vector<vector<int>> dp_n_elementos_ultima_pilha (N+1, vector<int>(K+1, 1));

    dp[0][0]=0;
    /* - Transições
        - Puxar anteriores para uma nova pilha, 
        3 elementos e 3 pilhas,
        agora quero 4 elementos e 3 pilhas:
        4 elementos e 1 pilha -> tudo vai para o ultimo
        4 elementos e 2 pilhas -> divide em dois;


        - Juntar duas pilhas:
        tenho 3 elementos e 3 pilhas, agora quero por 4 elementos e 3 pilhas
        -> Juntar é igual fazer:
        3 elementos e duas pilhas -> ultima pilha é o 4° elemento
    */
    
    for(int n=1;n<=N;n++){
        //cout << "comecando DPs com elemento " << n << " ou seja: " << alt_pilhas[n-1] << endl;
        // Devo por k<= k ou k<= N (pois no final não pode ter K=2 com um N)

        if(n>1 && alt_pilhas[n-1] == alt_pilhas[n-2]){
            //cout << "dp do numero ja foi feito antes " << endl;
            for(int k=1; k<=K; k++){
                if(n<k) break;
                dp[n][k]=dp[n-1][k];
                dp_n_elementos_ultima_pilha[n][k]= dp_n_elementos_ultima_pilha[n-1][k] + 1;
            }
            continue;
        }

        // Ignorar
        for(int k=1;k<=K; k++){
            //cout << "|  - Comecando dp do numero n primeiros, com o k= " << k << endl;
            if(n==k){
                //cout <<  "|     - Caso base temos X numeros e X grupos, logo dp[n][k] = a 0" << endl;
                dp[n][k] = 0;
                break;
            }
            /*Puxar_pilha:
            Tenho 3 elementos, k=1;
            preço para puxar pilha é igual:
            dp[2 elementos][1] + dp[2 elementos] *
            */  
            int puxar_pilha = 0;
            if(n != 1){
                if(k==1)
                puxar_pilha = dp[n-1][k] + dp_n_elementos_ultima_pilha[n-1][k]*(alt_pilhas[n-1] - alt_pilhas[n-2]);
                else
                puxar_pilha = dp[n-1][k] + dp_n_elementos_ultima_pilha[n][k-1]*(alt_pilhas[n-1] - alt_pilhas[n-2]);

            } else puxar_pilha = INF;
            int juntar_pilha = dp[n-1][k-1];

            if(puxar_pilha <= juntar_pilha){
                dp_n_elementos_ultima_pilha[n][k]= dp_n_elementos_ultima_pilha[n][k-1]+1;
                //cout << "|      - Decidido puxar pilha " << endl;
            } else{
                dp_n_elementos_ultima_pilha[n][k]=1;
                //cout << "|      - Decidido juntar pilha " << endl;
            }
            dp[n][k] = min(juntar_pilha, puxar_pilha);

            //cout << "|     - dp[n][k] " << n << " " << k << " = " << dp[n][k] << endl;
        }
    }

    cout << dp[N][K] << endl;
}


/* - Eu esqueci da solução da soma prefixada ...
de novo, por isso tentei resolver do mesmo jeito que da ultima vez.
*/

// Solução

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<ll> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // ------------------------------------------------------------
    // 1. Ordenamos as pilhas
    // ------------------------------------------------------------
    sort(a.begin(), a.end());

    /*
        Depois de ordenar, uma solução sempre pode ser vista como
        grupos consecutivos.

        Exemplo:

        1 2 2 5 5 8

        Podemos fazer:

        [1 2 2] [5 5] [8]

        Cada grupo será transformado na altura do seu maior elemento.
    */


    // ------------------------------------------------------------
    // 2. Soma prefixada
    // ------------------------------------------------------------
    /*
        prefix[i] = soma dos primeiros i elementos.

        Exemplo:

        a =      1 2 2 5 5
        prefix = 0 1 3 5 10 15
    */

    vector<ll> prefix(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }


    // ------------------------------------------------------------
    // 3. Função que calcula o custo de uma pilha
    // ------------------------------------------------------------
    /*
        Queremos transformar:

        a[l], a[l+1], ..., a[r]

        todos para a altura a[r].

        Portanto:

        custo =
            (a[r] - a[l])
          + (a[r] - a[l+1])
          + ...
          + (a[r] - a[r])

        Podemos reorganizar:

        quantidade * a[r] - soma

        quantidade = r-l+1

        soma = prefix[r+1] - prefix[l]
    */

    auto custo = [&](int l, int r) -> ll {

        ll quantidade = r - l + 1;

        ll soma = prefix[r + 1] - prefix[l];

        return quantidade * a[r] - soma;
    };


    // ------------------------------------------------------------
    // 4. DP
    // ------------------------------------------------------------
    /*
        dp[i][k] = menor custo para transformar as primeiras
                   i pilhas em exatamente k pilhas de alturas distintas.

        IMPORTANTE:

        i representa QUANTAS pilhas já processamos.

        Portanto:

        dp[0][0] = 0
    */

    vector<vector<ll>> dp(
        N + 1,
        vector<ll>(K + 1, INF)
    );

    dp[0][0] = 0;


    // ------------------------------------------------------------
    // 5. Transição
    // ------------------------------------------------------------
    /*
        Vamos calcular dp[i][k].

        Imagine que a ÚLTIMA pilha começa na posição j.

        Então:

            j ... i-1

        formam uma única pilha.

        Tudo antes de j:

            0 ... j-1

        precisa formar k-1 pilhas.

        Logo:

        dp[i][k] =
            min(
                dp[j][k-1] + custo(j, i-1)
            )

        para todos os j possíveis.
    */

    for (int i = 1; i <= N; i++) {

        for (int k = 1; k <= K; k++) {

            // Não podemos ter mais pilhas distintas
            // do que elementos.
            if (k > i) {
                break;
            }

            /*
                j = começo da última pilha.

                Para termos k pilhas:
                antes de j precisamos ter pelo menos k-1 elementos.

                Por isso:

                j >= k-1
            */

            for (int j = k - 1; j < i; j++) {

                if (dp[j][k - 1] == INF) {
                    continue;
                }

                // A última pilha será:
                //
                // a[j], a[j+1], ..., a[i-1]
                //
                // e todos serão elevados para a[i-1].

                ll novo_custo =
                    dp[j][k - 1]
                    + custo(j, i - 1);

                dp[i][k] = min(
                    dp[i][k],
                    novo_custo
                );
            }
        }
    }


    cout << dp[N][K] << '\n';

    return 0;
}