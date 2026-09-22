#include <bits/stdc++.h>
using namespace std;

// Corrigindo com Chatgpt, link acesso: https://chatgpt.com/c/6aa3f190-5834-83e9-ac61-ba4b0f663a23
int main(){

}

void diagnostico_geral(){
    /*
    Problema	Resultado	Tempo aprox.	Minha avaliação
Caravana	✅ 100%	~8 min	Excelente
Dígitos	✅ 100%	~55–60 min	Boa solução, mas muito trabalhosa 
Rodovia	✅ 100% exemplos	~55 min	Ideia interessante, mas solução perigosa
Pilhas	❌ incompleto	~40 min	Você estava perto de uma DP, mas modelou o estado errado
Dona Minhoca	❌ incompleto	—	Você identificou corretamente que era um problema de cobertura em árvore, mas faltou a transformação
    */
   // Droga, sabia que estava perto do pilhas

   // Eu interpretaria como:

    // Você já consegue resolver problemas de implementação/observação e começar problemas difíceis, mas ainda não tem repertório suficiente para transformar algumas estruturas mais abstratas em um estado/greedy eficiente.

}

void raciocinio_minhoca(){
    /*
    temos uma árvore;
    -> Make sense, se temos N vertices, N-1 arestas e está tudo conectado.

    podemos colocar exatamente K radares;
    todos possuem o mesmo raio R;
    um radar cobre todos os vértices a distância ≤ R;
    queremos o menor R.
    */

    /* - Melhor idea: binary search.
    Em vez de: Qual é o menor R -> 
    fazer: "Se eu fixar R, consigo proteger tudo usando no máximo K radares?
    -> Caso positivo, então ir para o binary search reduzindo R. caso negativo aumentando
    */

    /*
    R possível → todos maiores também possíveis
    R impossível → todos menores também impossíveis
    while (esq<= dir){
        meio = esq + (dir-esq)/2
        if(lista[meio] ...){
        true:
        dir = meio-1;
        } else
        esq = meio+1;
    }
    */

    /* - Como testar R:
    
        Quando existe uma parte da árvore que ainda não está coberta, pegue a folha mais profunda dessa parte.
        // Não comece de cima! 
        // faça das folhas até raiz

        Chame essa folha de v.

        Se o raio é R, então:
        - o radar deve ser colocado o mais alto possível sem deixar v descoberta.
        | ou seja se é R então a folha será a R-1 acima da v. (ou nesse caso R mesmo, pois são R vertices ao redor que protege)
        -> Por v ser a mais profunda todos os outros ganhos vão estar "cobertos"

        Ou seja:
        v
        ↑
        ↑
        ↑
        R arestas
        ↑
        RADAR

        Por quê?
        Porque se você colocar o radar mais abaixo, você desperdiça alcance para cima.
        -> Se colocar mais acima, v deixa de estar protegida.

        Então a posição ótima é:
        "ancestor(v, R)"

        Isso é uma ideia MUITO importante para guardar:
        | Em problemas de cobertura de árvore, quando uma folha precisa ser coberta, empurre o centro o máximo possível para cima.
    */
   /* - Mas não da para fazer:
   para cada folha:
    subir R
    colocar radar
   
   > pois são 300.000 folhas!
    */

    /*
    
    | ## O modelo mental correto

    Pense na árvore enraizada.
    Para cada subárvore, precisamos saber algo como:
    - "Qual é a situação da parte dessa árvore que ainda precisa ser coberta?"

    Uma forma muito útil de pensar é 
    **manter distâncias**.

    Durante um DFS de baixo para cima:

    Estado 1
    Existe um radar dentro da subárvore.
    Guardamos:
    distância até o radar mais próximo
    
    Estado 2
    Existe um vértice ainda não coberto.
    Guardamos:
    distância desse vértice até o atual

    Então podemos combinar informações dos filhos.
    Imagine:

           u
         / | \
        A  B  C

    Cada filho devolve alguma informação.

    Por exemplo:
    A → tem radar a distância 3
    B → tem vértice descoberto a distância 2
    C → tem vértice descoberto a distância 5

    Ao voltar para u, podemos decidir:
    | algum radar já cobre o vértice descoberto?
    | se não, precisamos colocar um radar;
    onde esse radar deve ficar?
    Esse é o coração da solução.
    */

    // tenho que usar mais ideias de binary_search
    /*
    Estou minimizando X?
        ↓
    Se eu fixar X, consigo verificar?
            ↓
    Se X funciona, X+1 também funciona?
            ↓
    BINARY SEARCH
    */


}

void tent_implementa_minhoca(){

}

void raciocinio_pilhas(){
    /*
    Aqui eu acho que você estava bem mais perto de resolver.

    O problema:

    Temos alturas:
    5 3 8 4 5 8

    Podemos somente aumentar as pilhas.
    Queremos no máximo K valores distintos.

    A prova deixa isso explícito: as moedas originais não podem mudar de pilha, só podemos adicionar moedas.
    */

    /* - E aqui está o insight que faltou no seu DP

    Você tentou pensar:
    "escolher uma âncora"

    Isso está correto.
    Mas você estava tentando decidir isso incrementalmente com:
    dp[j][i]

    e guardar:
    second = número de pilhas...

    - O problema é que o estado não estava representando qual é a "última altura escolhida".
    Esse é o dado essencial.

    Vamos reformular
    - Depois de ordenar:
    a[0] <= a[1] <= ... <= a[N-1]

    Suponha que queremos escolher **j alturas finais distintas**.
    Se uma determinada altura a[i] for escolhida como uma das alturas finais, todas as pilhas anteriores que forem atribuídas a ela podem ser aumentadas até a[i].
    || ou seja se escolher a[i] tudo entre a[i] e o ultimo escolhido tem que subir

    Por exemplo:
    3 4 5

    Se escolhermos 5:
    3 → 5 = 2
    4 → 5 = 1
    5 → 5 = 0
    custo = 3

    Portanto o custo de transformar um intervalo:
    || a[l], a[l+1], ..., a[r]
    em a[r] é:
    (a[r]-a[l]) + (a[r]-a[l+1]) + ... +
    (a[r]-a[r])

    ou:
    || sum(a[r] - a[x])
    - AAAAA, isso não era tão dificil.

    Isso pode ser calculado rapidamente com somas prefixadas.
    */
   /*
   | menor custo para transformar as primeiras i pilhas em exatamente k alturas distintas, sendo a[i-1] a última altura escolhida
   */
    /*
    dp[k][i] =
        min sobre j < i:
            dp[k-1][j]
            +
            custo(j, i)
    */
   /*
   custo(j,i)
    =
    (i-j)*a[i-1]
    -
    (sum[i]-sum[j])

    onde sum é prefix sum.
   */

    /*
    Uma coisa boa: sua intuição de DP estava certa

    Você escreveu:
        "levar âncora mais perto até ele"
        e
        "juntar duas âncoras"

    - Você estava tentando descobrir exatamente a estrutura de agrupamento.

    Só que a forma mais limpa é:
    ordenar -> cada altura final define um grupo -> cada grupo é um intervalo -> grupo [l,r] vira a[r]
    | -> DP escolhe os intervalos

    Isso é um padrão que quero que você reconheça no futuro:

    Quando existe uma sequência ordenada e você precisa dividir em K grupos contíguos, pense imediatamente em DP de particionamento.
    */
}
// bem de boa esse problema pilhas até, é legal

//caravana 100%

void outros_problemas_digitos(){


    // digitos — você resolveu, mas quero marcar um problema

    /*
    e a sequência pode ter 1000 dígitos.

    Portanto, não existe um long long capaz de representar o número inteiro.

    Você teve sorte de usar pow + long long em alguns casos, mas conceitualmente isso é perigoso.
    */
    // Bobiei, fiz desse jeito pois era mais fácil embora eu soubesse fazer com vector

    /*
    A ideia mais robusta

    Esse problema deveria ser tratado como:

    STRING

    e não como:

    long long

    Você tem:

    1 2 3 1 2 4

    e precisa descobrir onde colocar as divisões:

    123 | 124

    ou:

    12 | 31 | 24

    etc.

    A sequência precisa ser:

    A, A+1, A+2, ..., B

    Então basta testar possíveis tamanhos iniciais e verificar se a sequência continua.

    Sua ideia:

    "chutar tamanho de A"

    é, na verdade, uma boa ideia.

    O que eu mudaria é a representação.
    */
}
/*
Olha o que a prova te deu:

Caravana
observação matemática
Dígitos
string + parsing / construção
Pilhas
DP de particionamento
Minhoca
árvore + binary search + greedy/DP
Rodovia
grafos direcionados + reachability

Isso é uma Fase 3 muito boa para diagnosticar repertório.

E você conseguiu:

Caravana ✅
Dígitos   ✅
Rodovia  ✅

mas travou justamente quando era necessário reconhecer uma estrutura algorítmica mais específica.
*/

/*
🟢→🟡 Bom

Problemas de observação matemática

Caravana foi extremamente rápida.

🟡 Bom, mas precisa melhorar

String / construção

Você resolveu Dígitos, mas com uma representação perigosa e muita manipulação.

🟡 Em desenvolvimento

Grafos

Você já pensa naturalmente em:

DFS;
BFS;
parent;
adjacency;
reachability.

Isso é bom.

Mas ainda precisa melhorar muito a parte:

"qual propriedade do grafo permite evitar fazer uma busca enorme?"

🔴 Principal lacuna atual

Reconhecimento de DP

Você consegue escrever uma DP, mas ainda tenta construir o estado "durante o código".

Precisamos inverter:

problema
 ↓
qual é a decisão?
 ↓
qual informação o futuro precisa saber?
 ↓
estado
 ↓
transição
 ↓
código

e não:

vou fazer dp[i][j]
↓
vamos ver o que cabe
6. E a Minhoca revela outra lacuna

Você já conhece:

árvore;
DFS;
distância;
binary search.

Mas ainda não está fazendo automaticamente a composição:

"minimizar uma resposta → binary search → problema de decisão → greedy/DP na árvore."

Essa composição é exatamente o tipo de coisa que começa a aparecer bastante nas Fases 3.
*/