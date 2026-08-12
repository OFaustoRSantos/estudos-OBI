# Diagnóstico

## O principal diagnóstico que vejo é:

Você já está reconhecendo vários padrões algorítmicos. O seu maior gargalo agora não é “não saber programar”; é reconhecer rapidamente a estrutura matemática/algorítmica do problema e administrar o tempo.

## 1. Seu resultado na prova

Pelos arquivos que você mandou:

Questão	Tempo aproximado	Situação	Diagnóstico
Fotografia	~20 min	✅ 100%	Excelente
Estrada	~20 min	✅ 100%	Excelente
Quebra-cabeças	~20+ min	❌ não terminou	Faltou modelagem
Dona Formiga	~30 min + ~30 min debug	❌	Identificou DFS, mas modelou errado
Estratégia	—	⚠️	Tempo excessivo em uma questão

Na Fotografia, você identificou corretamente:

condição de encaixe;
possibilidade de rotação;
minimização da área;
desempate pelo índice.

E sua solução acabou passando nos testes locais, embora você tenha submetido no lugar errado. Seu próprio comentário registra isso.

Na Estrada, você rapidamente percebeu que precisava ordenar as cidades e calcular as vizinhanças pelos pontos médios.

Isso mostra uma coisa importante:

Você está ficando bom em transformar problemas geométricos/simples em algoritmos.

O problema aparece quando a solução exige uma modelagem menos óbvia.

## 2. O problema #1: Dona Formiga

Esse foi provavelmente o maior desperdício de tempo da prova.

Você imediatamente escreveu:

Grafo direcionado;
DFS

Isso foi meio caminho certo.

O problema foi a implementação.

### A observação fundamental

Se a formiga só pode deslizar de uma altura maior para uma altura menor:

100 → 80 → 50 → 20

então todo movimento diminui a altura.

Logo:

É impossível existir ciclo.

Isso transforma o problema em um DAG — Directed Acyclic Graph.

A consequência é gigantesca:

Não precisamos de visited.

Você percebeu isso no código:

// vis.assign(S,0); // 0 = não visitado, não tem ciclo, logo não preciso de visitado

Essa observação estava correta.

### Calculo por salao

Para cada salão:

dp[v] = maior número de salões que consigo visitar
        começando em v

Então:

dp[v] = max(1 + dp[u])

para todos os vizinhos u para os quais:

altura[v] > altura[u]

E se não há vizinhos:

dp[v] = 0

Isso é DP em DAG.

Você tentou fazer exatamente essa ideia com DFS:

salao_passados = 1 + DFS(i);

A ideia de recorrência estava boa.

O problema foi que você não tinha memoização correta.

Você criou:

vector<int> n_salao;

e tentou usar como DP.

Mas o seu DFS continua recalculando estados.

Imagine:

       A
      / \
     B   C
      \ /
       D

Quando você calcula:

A → B → D

e depois:

A → C → D

o D pode ser recalculado.

Em um grafo maior, isso explode.

E foi exatamente o sintoma que apareceu:

“estouro de memória em todos”


checklist C++
[ ] vectors foram dimensionados?
[ ] índices começam em 0 ou 1?
[ ] todas as variáveis foram inicializadas?
[ ] existe acesso fora do vector?
[ ] condição de parada existe?
[ ] recursão pode ser infinita?
[ ] estou recalculando o mesmo estado?
[ ] tipo int é suficiente?