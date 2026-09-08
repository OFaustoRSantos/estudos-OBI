#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void study(){
    /*
    Ideia -> usar um valor calculado antes para calcular o outro sem ter que ficar recalculando diversas vezes.
    Uma espécie de integração com memória
    */
    // Fazendo isso para fibonacci por exemplo:

const int maxn = 100010;

int n, dp[maxn];
bool mark[maxn];
// inicialmente o vetor é preenchido com 0

int fib(int x)
{
	// caso base
	if(x <= 1) return 1;
	
	// Se já visitamos esse estado retornamos o valor calculado
	if(mark[x] == 1) return dp[x];
	
	// marco o estado como visitado
	mark[x] = 1;
	
	// calculamos esse estado
	dp[x] = fib(x-1) + fib(x-2);

	return dp[x];
}

    /* - Ideia central é evitar recalcula, acelerando o código

    Parte mais difícil é modelar uma função ou uma estrutura de dados que permita você tomar uma decisão com base em uma decisão do passado recursivamente
    */

    /* - Onde é usada
    Muito usada em problemas chamados:
    OTIMIZAÇÃO Combinatória.
    - alguma coisa com um conjunto de regras dadas, e queremos extrair alguma informação desse conjunto
    > Melhor ou pior configuração, ou valor dessa configuração etc.

    > Exemplo problema de trio bonecas da OBI 2023 fase 3 p2

    - Além de casos em que só queremos saber se existe alguma construção dentro desse conjunto que satisfaça alguma outra propriedade especial.

    : De forma genérica DP é
    | contar, calcular o máximo/mínimo, saber se algo existe ou não
    
    */
}

void contrucao_DP (){
    /*
        A primeira parte do DP são os estados
        : Estados
        | Parametros que definirão a função
        - Coisas do passado que usamos para definir o presente. 
        Ou em informática

        dp[N][K] = min(dp[N-1][K], dp[N-1][K-1] + escolha)
        
        esse dp depende de duas coisas N, e K, ele informa um valor. e o dp do N, K atual é atualizado como minimo entre duas escolhas 
    */

    /* - Exemplo, temos n degraus e um atleta.
    Atleta pode anda i+1, ou i+2.

    quantas maneiras diferentes pode chegar no ultimo degrau do primeiro:
    
    Ideia:
    dp[n] = quantidade de formas de chegar no degrau n.

    dp[i] = dp[i-2] (formas de chegar no degrau 2 posições atrás) + dp[i-1] (formas de chegar no degrau imediatamente atrás)
    se i<= n-1 e se i<=1 -> dp[i] = 1; 
    */
   /*
    : Transição de um DP/escolhas 
    | Nada mais são que o conjunto de possibilidades para transitar entre estados
   */

   /*
   - A visualização seria:
   -> Pegar um problema grande quebra-lo em pedaços/partes menores fáceis de lidar (estados) e desenhar a ponte estre essas partes/estados (transições)
   - Parece um DAG - Grafo aciclico direcionado.

   */
  /*
  Busque propriedades dos estados ou transições que nos permite otimiza-los.
  */
    // OBS: Não pode ter nenhuma dependencia do proprio valor de x para acharmos o valor dele se não quebra
}

/* - 15 min = Tempo médio para problemas - Farei hoje a tarde eles:
Encontraveis em: https://noic.com.br/materiais-informatica/curso/dp-01/

*/

void fibonacci_cansado(){

}

void salto_fibonacci(){

}

void fibonacci_ambicioso(){

}

/* - Problemas extras

1. O primeiro exercicio é simplesmente tentar implementar o 3º exercício só que com um limite no intervalo de movimento, ou seja o movimento é limitado ao intervalo [i+1, i+k] e os passos tem de ser crescentes.

2. Imagine novamente o problema igual ao 3º da seção anterior, porém dessa vez temos que os passos têm que ser decrescentes ao invés de crescentes.

3. Agora temos o problema semelhante ao problema inicial com Pisano, no qual so podíamos andar 1 ou 2 degraus por passada, porém dessa vez Pisano encontrou um amigo, o qual está no final da escada. Em cada movimento eles se comunicam e podem decidir qual dos dois vai se mover em cada vez e você tem a missão de descobrir a quantidade de maneiras que eles tem de se encontrar em cada degrau da escada.

*/

void tipos_abordagem(){
    /* - Duas maneiras de se implementar DP:
    - implementação recursiva / Top-down.
    > Foi a desenvolvida acima. uso maior de funções
    | Mais intuitiva, pode ser mais facil ter uma implementação intendivel.
    | Não é a mais eficiente - em tempo e memória, por isso é mais para introdução.

    - implementação iterativa / Bottom-up
    | Metodo mais usado - Tempo de execução mais rápido e muito mais fácil otimizar ( alguns problemas só é possível otimizar com esse modelo)
    | Precisa definir ordem correta para percorrer os itens, um pouco mais difícil para acostumar.
    */

    /* - Duas formas de implementar uma dp iterativa
    - pull DP  - cada estado usarmos os vetores já calculados anteriormente para calcular o estado atual.
    | Mais comum. Pelo menos foi o que mais vi

    - push DP - cada estado usamrmos o valor que já foi calculado nele para atualizarmos os valores seguintes da DP.
    tipo:
    estado a -> adicionará dp[a] + max (escolha) em todos na frente.

    - Esse dp push me parece mais complexo.
    */

    // - Exemplo abordagens 
    //Possibilidade 1 - PULL dp
    /*
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= k && i - j >= 1; j++)
			dp[i] += dp[i-j];
	*/
	// Possibilidade 2 - PUSH dp
	/*
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k && i + j <= n; j++)
			dp[i+j] += dp[i];
	*/

}