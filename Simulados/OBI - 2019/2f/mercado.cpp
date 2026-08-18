// dp[x] = menor preço para conseguir pelo menos x gramas
/*
dp[min(1000, x + G)]
=
min(
    dp[min(1000, x + G)],
    dp[x] + P
)
*/

/*
- Mas há uma simplificação MUITO importante

Todos os supermercados continuam vendendo o mesmo produto.

Ou seja, depois de comprar um pacote de qualquer supermercado, podemos comprar outro pacote do mesmo supermercado.

Portanto temos um problema de menor caminho / unbounded knapsack.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<double> preco(N);
    vector<int> gramas(N);

    for (int i = 0; i < N; i++) {
        cin >> preco[i] >> gramas[i];
    }

    
    // dp[g] = menor preço necessário para conseguir
    // exatamente g gramas, considerando que g = 1000
    // significa "1000 ou mais".
    // Começamos com infinito.

    const double INF = 1e18;

    vector<double> dp(1001, INF);

    dp[0] = 0;

    
    // Para cada quantidade já alcançada, tentamos comprar
    // mais um pacote de cada supermercado.

    for (int g = 0; g <= 1000; g++) {

        if (dp[g] == INF)
            continue;

        for (int i = 0; i < N; i++) {
            int novaQuantidade =
                min(1000, g + gramas[i]);
            

            double novoPreco =
                dp[g] + preco[i];

            dp[novaQuantidade] =
                min(dp[novaQuantidade], novoPreco);
        }
    }
    // Muito legal

    cout << fixed << setprecision(2)
         << dp[1000] << "\n";

    return 0;
}