#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

}

int problema_dp(){
    /*
    conjunto de n elementos, para todo 1<= i<=n
    elemento i tem peso e valor

    Mochila de capacidade C.
    A soma dos pesos tem que ser <= C.
    Soma dos valores.

    | dp[V][P] -> maximo de valor com peso P
    - Não tão legal
    */
    // Sort dos elementos mais valiosos primeiro? Ou dos mais leves?
    /*
        Se o valor é igual, menor peso favorecido

        dp[P] -> maior valor para um conjunto com esse peso
        ou
        dp[V] -> conjunto com esse valor que possui menor peso
        -> Escolher o menor pela restrição do problema
    */

    /* dp[P]
    porém temos que indicar os elementos que já foram usados, para não ter repetição
    por isso faremos um:
    dp[i][P]
    = conjunto com peso p, com indice 1 a i onde valor é máximo
    sempre definir o dp
    */

    /* - transições
    - Adiciono o item, adiciono seu valor e aumento o peso
    ou vou para o proxio estado com mesmo peso sem adicionar o item
    dp(i,P) = max(dp(i+1,P), dp(i+1,P-pi)+vi);

    */
   return 0;
}

int sol_recursiva(){
    const int maxn = 110, maxp = 1e5+10;

    /* 
    v[i] = valor indice i
    p[i] = peso indice i
    n = numero de indices
    */
    int v[maxn], p[maxn], n;
    
    /*
    dp[n][p] = Valor máximo de conjunto até indice n com peso p
    */
    long long dp[maxn][maxp];

    // Memoria se foi visitado, sómente isso
    bool vis[maxn][maxp];

    long long solve_(int i, int P){
        if(i == n+1) return 0; // caso base, não há mais itens para se considerar

        if(vis[i][P]) return dp[i][P]; // já calculado
        
        // Começando calculo
        vis[i][P] = 1;
        
        // primeira possibilidade, não adicionar o elemento
        dp[i][P] = solve(i+1, P);
        
        // segunda possibilidade, adicionar o elemento.
        // Lembrar de tirar o máximo com o valor já calculado da primeira possibilidade
        if(P >= p[i])
            dp[i][P] = max(dp[i][P], solve(i+1, P - p[i]) + v[i]);
        
        return dp[i][P];
    }

    int main() {
        int C; scanf("%d %d", &n, &C);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &p[i], &v[i]);
        printf("%lld\n", solve(1, C));
    }

}

int sol_iterativa(void){
    const int maxn = 110, maxp = 1e5+10;
    const long long inf = 0x3f3f3f3f3f3f3f3f; // ~= 10^18

    int v[maxn], p[maxn];
    long long dp[maxn][maxp];

    int main(){
        int n, C; scanf("%d %d", &n, &C);
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &p[i], &v[i]);
        
        long long ans = 0;
        // inicializando o vetor
        for(int i = 1; i <= n; i++)
            for(int P = p[i]; P <= C; P++)
                dp[i][P] = -inf;
        // definindo o caso base
        dp[0][0] = 0;
        
        // Ideia é só marcar quando o P-p[i] é 0, ou seja tem esse peso exato no começo
        for(int i = 1; i <= n; i++) {
            for(int P = 0; P <= C; P++) {
                dp[i][P] = dp[i-1][P];
                if(P >= p[i])
                    dp[i][P] = max(dp[i][P], dp[i-1][P-p[i]] + v[i]);
                ans = max(ans, dp[i][P]);
            }
        }
        
        printf("%lld\n", ans);
    }
}


/* - Muito legal

*/