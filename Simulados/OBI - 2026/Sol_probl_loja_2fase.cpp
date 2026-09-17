#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long lint;
 
const int MAX = 810;

/* - Submatrix valida:
escolhendo linha i da coluna j -> l
Dentro de cada linha
a[i][j] < a[i][j+1] < ... < a[i][l]
Entre duas linhas consecutivas:
a[i][l] < a[i+1][j]
*/

/* - Pre -> maior intervalo crescente começando em i,j
linha:
1 2 5 7 3 4
Se torna

pre:
4 3 2 1 2 1
*/


/* 
    dp[i][j] => Quantas colunas consigo pegar a partir de j na linha i, garantindo que o final dessa linha seja menor que o começo da linha [i+1] na coluna [j]?


*/
int mat[MAX][MAX], pre[MAX][MAX], dp[MAX][MAX];
 
stack<pii> s;
lint area;
 
// ver por ultimo, 
/* Add - guarda par <altura,largura>
onde:
| h = largura máxima que o retângulo consegue ter
| l = quantas linhas esse pedaço representa
*/
void add(int h, int l) {
    // cnt = chave: "posição", numero linhas 
	int cnt = 0;
    // enquanto s estar vazio ou nossa largura/colunas serem menores que o limite
    // 
	while(!s.empty() && h < s.top().first) {
		cnt += s.top().second; //se for de um dp é 0, se for de um pre é 1.
		area = max(area, lint(cnt)*s.top().first);
		s.pop();
	}
	s.push({h, cnt + l});
}
 
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	area = 0;

	for(int i = 0; i < n; i++) {
        // computa a linha, coloca na matrix
		for(int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
			pre[i][j] = 0;
		}

		mat[i][m] = INT_MIN; //para caso acessar o [i][m]
        // calcula o pre dito acima. - forma de definir o limite também.
		for(int j = m - 1; j >= 0; j--) {
			// começa pelos limites, até o zero.
            pre[i][j] = 
            ((mat[i][j] < mat[i][j + 1]) ? 
            pre[i][j + 1] : 0) + 1;
            
            // Se o próximo elemento é maior que o atual, posso continuar o intervalo crescente. Caso contrário, meu intervalo termina aqui.
            
		}

	}

    // definindo um limite para a matrix. na linha de borda definir int_max. Na coluna da borda int_min. pelas regras já vão ser desconsiderados

	for(int i = 0; i < m; i++) mat[n][i] = INT_MAX;

    /*
    Populando DP, testando começar em todos os pontos
    */
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
            // Qual é a primeira posição cujo valor é >= mat[i+1][j]?
            // se for temos que acabar o "ciclo"

			dp[i][j] = 
            lower_bound(mat[i] + j, mat[i] + j + pre[i][j], mat[i + 1][j]) - (mat[i] + j);
            /* - lowerbound faz exatamente isso.
            Faça lower_bound no pedaço do array mat[i] que começa em j e tem pre[i][j] elementos, procurando mat[i+1][j].

            ou seja:
            ponteiro begin = mat[i] + j,
            ponteiro final = mat[i]+j + n° elementos que pode ter naquele grupo,
            elemento buscando.
            */
           // exemplo se começarmos em [i][j] podemos pegar no máximo dp[i][j] colunas
		}
	}

    /*
    Portanto, para uma largura W funcionar...

    Imagine fixarmos a coluna inicial j.

    Queremos uma submatriz com largura:
    W

    Para cada linha precisamos:
    pre[i][j] >= W

    E entre cada par de linhas:
    dp[i][j] >= W

    Então temos algo assim:

    linha 0:   pre[0][j]   = 5
                |
            dp[0][j]    = 3
                |
    linha 1:   pre[1][j]   = 4
                |
            dp[1][j]    = 2
                |
    linha 2:   pre[2][j]   = 6

    Se quisermos largura W = 2:

    5
    3
    4
    2
    6

    da certo!
    */

    /* - Aqui nesse ponto esse problema muda para um "maior retangulo em histograma"

    Só que:
    a altura do histograma = largura possível da submatriz

    e:

    a largura horizontal do histograma = quantidade de linhas

    Isso é uma transformação MUITO importante de aprender.
    */

    // Transformei um problema complexo em um muito mais simples

	for(int j = 0; j < m; j++) {
		s = stack<pii>();
		for(int i = 0; i < n; i++) {
			add(pre[i][j], 1); // linha real - exemplo: consigo andar 5 para o lado aqui
			add(dp[i][j], 0); // fronteira duas linhas, exemplo mas só consigo andar 3 se for usar a linha de baixo.

		}
		add(0, 0); // ultimo é o zero zero. que é adicionado a cada coluna.
        // uma forma de tipo zerar possiveis valores de fila sobrando - esvazia a fila
	}

	printf("%lld\n", area);
	return 0;
}