#include <bits/stdc++.h>
using namespace std;

//https://noic.com.br/materiais-informatica/ideias/bitmask/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void intro(){
    /*
    Bitmask - técnica de força bruta usada para testar todas possibilidades.
    */

    /* - Ideia - Eu acho muito legal:
    temos 6 viagens e vamos verificar se elas já foram visitadas.
    - para problemas com binários
    000000 -> cada bit é uma cidade se for 1 já foi visitada, se for 0 não foi.
    cada configuração acaba tendo um id:
    000001 = 2. ...
    */
}

void manipulando_bit(){
    // - Operações binárias:
    // verificando se o bit j está ligado em n 
    
    bool ligado (int n, int j) {
	    if(n & (1 << j)) return true;
	    else return false;
    }
    /* n&2^j maior que 0 */
    // ligando o bit j no numero n
    void ligar(int &n, int j)
    {
	    n = n | (1 << j);
    }
    /*
    O j ele inicia em 0 ou em 1
    */
}

class exemplo_problemas(){
    /* P1:
    Você tem n questões. Você estimou a dificuldade da i-ésima questão como c. Agora você tem que preparar uma prova com essas questões tal que a dificuldade total das questões seja pelo menos l e no máximo r e que a diferença entre a questão mais difícil e a mais fácil seja pelo menos x. 
    Calcule a quantidade de maneiras de preparar a prova.
    */
    /* - solução
    Podemos armazenar numa bitmask que guarda as questões que estamos usando, ou seja, se o bit i está ligando então estamos usando a i-ésima questão na prova. Então vamos percorrer todas as bitmasks possíveis e checar se ela satisfaz os requisitos para a prova. Segue a implementação:
    */
    #include <bits/stdc++.h>
    using namespace std;
    const int inf = 1e9 + 10;

    /*
    n = n° questões
    l = dificuldade total min
    r = dificuldade total max
    x = diferença entre dif unitaria min quest e dif unitaria max quest na prova
    */
    int n, l , r, x;
    /*
    dificuldade cada questão
    */
    int v[20];
    long long resp;

    int main()
    {
        ios::sync_with_stdio(false), cin.tie();

        cin >> n >> l >> r >> x;

        for(int i = 0; i < n; i++)
            cin >> v[i];

        // Se temos n opções que podem estar ligadas ou desligadas, temos 2^n combinações.

        // (1<<n) é uma forma rápida de ver o numero de combinações possíveis com esses 6 itens
        for(int mask = 0; mask <= (1 << n) - 1; mask++)
        // percorro todas as bitmasks
        {
            // soma total dificuldade
            long long s = 0;

            int maior = 0;
            int menor = inf;

            for(int i = 0; i < n; i++)// percorro todos os bits
            {
                if(mask & (1 << i)) //checo se a questão está na prova que estou olhando
                {
                    s += v[i];
                    maior = max(maior, v[i]); // calculo a maior dificuldade
                    menor = min(menor, v[i]); // calculado a menor dificuldade
                }
            }

            if(s >= l and s <= r and (maior - menor) >= x) resp++; // se a prova é valida, adiciono um no contador
        }
        cout << resp << "\n";
        return 0;
    }
    // força bruta porém muito legal

    /* - exemplo 2
    Temos n cidades e m estradas de mão dupla entre elas. Queremos saber o menor custo para visitar todas as cidades sem passar por uma cidade mais de uma vez, começando da cidade 0.
    */

    /* - idea solução
    -> usar dp, com bitmask:
    dp[2^n][n] -> menor custo para visistar a combinação 2^n sendo a ultima cidade visitada [i]
    */
   /*  - definindo transições
   dp[mask][i] =
   { 0 -: se mask = 2^n-1 (todas ativas)
     min(0<= v <= n-1) (dp[mask|1 << v][v] + C[i][v]), se mask não for a ultima
   }
   
    */
    #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// maxm = todas combinações possíveis
const int maxn = 16, maxm = (1 << 15) + 10;

int n, m;
int mat[maxn][maxn], dp[maxm][maxn];

int solve(int mask, int i)
{
    // se mask = ultima configuração

	if(mask == (1 << n) - 1) return dp[mask][i] = 0; // caso todas as cidades já tenham sido visitadas, logo não custa nada visitar as outras pois não tem mais qual visitar

	if(dp[mask][i] != -1) return dp[mask][i]; // se a DP ja foi calculada -> memória
	
	int ans = 1e9;
	
	for(int v = 0; v < n; v++)
	{
		if(mask & (1 << v) or !mat[i][v]) continue; // se a cidade atual já foi visitada ou não há rota de i à v

		ans = min(ans, solve((mask | (1 << v)), v) + mat[i][v]); 
        // pego o minimo entre ir para cada vizinho
	}

	return dp[mask][i] = ans; // muito maneiro, nesse caso começamos na 0 e vamos indo
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	cin >> n >> m;

	while(m--)
	{
		int a, b, w;

		cin >> a >> b >> w;
		mat[a][b] = mat[b][a] = w;
	}
    
    // ideia é colocar -1 em toda matrix do dp
	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << "\n"; // começando da cidade 0


}
}


/* - Problemas para fazer:
Preparing Olympiad	https://codeforces.com/problemset/problem/550/B
Vitamins	https://codeforces.com/contest/1042/problem/B

Combate à Dengue	https://www.urionlinejudge.com.br/judge/pt/problems/view/2088
Rota do Taxista	https://www.urionlinejudge.com.br/judge/pt/problems/view/1947
Penalização	https://www.urionlinejudge.com.br/judge/pt/problems/view/2225
Artskjid	https://dmoj.ca/problem/cco15p2
Paths	https://boi18-day2-open.kattis.com/problems/boi18.paths

*/