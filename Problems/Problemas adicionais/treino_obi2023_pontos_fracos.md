# Treino Direcionado — Pós-mortem OBI 2023

**Contexto:** Na prova você gabaritou Pirâmide (força bruta com `next_permutation`, N pequeno) e Oficina (duas `priority_queue`, greedy), mas apanhou em Fast-Food (bipartição + busca binária na resposta + distância de Manhattan), Trio (DP de emparelhamento após ordenação) e Transporte (grafo com estado expandido / Dijkstra).

Isso vira **12 problemas originais**, divididos em 4 grupos. **Não role até a seção de Aulas/Soluções antes de tentar** — o objetivo é forçar o caminho:

> enunciado → identificar a estrutura → provar a observação → implementar

Se travar mais de ~40–45min num problema, isso já é sinal de aprendizado (anote *onde* travou) — só então vá ler a aula do tópico correspondente.

---

## Grupo 1 — Fácil (nível OBI Fase 2, N2)

### 1.1 — Fábrica de Brinquedos *(tópico: Fast-Food → busca binária na resposta)*

Uma linha de produção tem N tarefas **em sequência fixa** (não podem ser reordenadas), a i-ésima levando `t[i]` minutos. Você precisa dividir essa sequência em exatamente K turnos **contíguos** (um funcionário por turno), de forma a minimizar o **maior** tempo total entre os turnos.

**Entrada:** `N K` na primeira linha; depois N inteiros `t[1..N]`.
**Saída:** o menor valor possível para o maior turno.
**Restrições:** 1 ≤ K ≤ N ≤ 2×10⁵; 1 ≤ t[i] ≤ 10⁹.

**Exemplo**
```
Entrada:
5 2
7 2 5 10 8

Saída:
18
```
(divisão ótima: `[7,2,5]` = 14 e `[10,8]` = 18)

---

### 1.2 — Duplas de Treino *(tópico: Trio → DP de emparelhamento)*

N atletas têm níveis de força `a[i]`. Você deve formar **exatamente K duplas** (cada atleta em no máximo uma dupla; atletas sobrando ficam de fora sem custo). O custo de uma dupla com força `a` e `b` é `(a-b)²`. Minimize a soma dos custos das K duplas.

**Entrada:** `N K`; depois N inteiros `a[1..N]`.
**Saída:** menor soma total de custo.
**Restrições:** 2 ≤ N ≤ 2000; 1 ≤ K ≤ N/2; 1 ≤ a[i] ≤ 10⁹.

**Exemplo**
```
Entrada:
6 2
1 5 3 9 2 8

Saída:
2
```

---

### 1.3 — Passagem Livre *(tópico: Transporte → estado expandido)*

Um grafo não-direcionado tem N vértices e M arestas, cada uma com custo 1 para atravessar. Você possui exatamente K "cargas grátis": cada carga permite atravessar **uma aresta** do seu caminho sem custo (pode usar 0 a K cargas, em quaisquer arestas do trajeto). Determine o menor custo total para ir de S até T.

**Entrada:** `N M K S T`; depois M linhas `u v`.
**Saída:** menor custo total (ou -1 se impossível).
**Restrições:** 1 ≤ N, M ≤ 2×10⁵; 0 ≤ K ≤ 20.

**Exemplo**
```
Entrada:
6 5 2 1 6
1 2
2 3
3 4
4 5
5 6

Saída:
3
```

---

## Grupo 2 — Médio (nível OBI Fase 3, N2)

### 2.1 — Dois Bairros *(tópico: Fast-Food → busca binária + partição, versão 1D)*

N casas estão em posições `x[i]` sobre uma rua (1D). A prefeitura quer dividir as casas em **exatamente dois** bairros de forma que, dentro de cada bairro, a maior distância entre duas casas seja no máximo `D`. Ache o menor `D` para o qual essa divisão é possível.

**Entrada:** `N`; depois N inteiros `x[1..N]`.
**Saída:** o menor `D` possível.
**Restrições:** 2 ≤ N ≤ 10⁵; 0 ≤ x[i] ≤ 10⁹.

**Exemplo**
```
Entrada:
6
1 2 10 11 12 50

Saída:
11
```

> Dica de estrutura (sem contar a solução): pense em como você decidiria, olhando só os extremos (mínimo e máximo) de um grupo, se um novo ponto é *obrigado* a entrar no outro grupo.

---

### 2.2 — Trincas do Torneio *(tópico: Trio → versão completa, N médio)*

N atletas têm níveis de habilidade. Você deve formar **exatamente K trincas** de 3 atletas cada. Uma trinca com níveis `a ≤ b ≤ c` custa `(a-b)²`. Atletas fora das trincas não custam nada. Minimize o custo total.

**Entrada:** `N K`; depois N inteiros.
**Saída:** menor custo total possível.
**Restrições:** 3 ≤ N ≤ 3000; 1 ≤ K ≤ N/3.

**Exemplo**
```
Entrada:
9 2
10 1 2 8 9 3 7 4 15

Saída:
2
```

---

### 2.3 — Metrô Duplo *(tópico: Transporte → estado (vértice, sistema), 2 sistemas)*

Uma cidade tem N estações e duas linhas de metrô (0 e 1), com M ligações no total, cada uma pertencendo a exatamente uma linha e custando 1 para percorrer. Trocar de linha em qualquer estação custa `P` (fixo, igual para qualquer troca). Ache o menor custo de S até T.

**Entrada:** `N M P S T`; depois M linhas `u v linha` (linha ∈ {0,1}).
**Saída:** menor custo total (ou -1 se impossível).
**Restrições:** 1 ≤ N, M ≤ 10⁵; 0 ≤ P ≤ 10⁹.

**Exemplo**
```
Entrada:
4 3 5 1 4
1 2 0
2 3 1
3 4 0

Saída:
7
```

---

## Grupo 3 — Aprofundamento (OBI Fase 3, N2, versão mais completa)

### 3.1 — Fazendas Distantes *(tópico: Fast-Food → versão original completa, 2D + Manhattan)*

N fazendas têm coordenadas `(x,y)`. Uma cooperativa quer dividir as fazendas em **exatamente duas** rotas de entrega, de forma a minimizar a **maior** distância de Manhattan entre duas fazendas de uma mesma rota. Ache esse valor mínimo.

**Entrada:** `N`; depois N linhas `x y`.
**Saída:** o menor valor possível da maior distância intra-grupo.
**Restrições:** 2 ≤ N ≤ 10⁵; 0 ≤ x, y ≤ 10⁹.

**Exemplo**
```
Entrada:
5
0 0
10 0
0 10
100 100
101 99

Saída:
20
```

> Esse é, estruturalmente, o mesmo problema do seu `fastfood.cpp` — a intenção é você refazê-lo do zero, sem olhar seu código anterior, e comparar depois.

---

### 3.2 — Trincas com Limite *(tópico: Trio → DP + restrição adicional)*

Mesmo problema de "Trincas do Torneio", mas agora toda trinca escolhida deve satisfazer `c - a ≤ M` (não pode ser "espalhada" demais). Determine se é possível formar K trincas válidas e, se for, o menor custo total.

**Entrada:** `N K M`; depois N inteiros.
**Saída:** o menor custo total, ou `-1` se não for possível formar K trincas válidas.
**Restrições:** 3 ≤ N ≤ 5000; 1 ≤ K ≤ N/3; 0 ≤ M ≤ 10⁹.

**Exemplo**
```
Entrada:
9 2 3
10 1 2 8 9 3 7 4 15

Saída:
2
```

> A restrição `c - a ≤ M` some naturalmente com a mesma ideia de DP após ordenar — o desafio é decidir *onde* verificar essa condição sem quebrar a transição.

---

### 3.3 — Rede de Transportes Premium *(tópico: Transporte → versão original completa, K sistemas)*

N estações, M ligações, cada uma pertencente a um entre K sistemas de transporte, cada sistema `k` com preço `P[k]` cobrado sempre que você entra nele (trocar de sistema no meio da viagem paga o preço do novo sistema; ficar no mesmo sistema é grátis). Ache o menor custo de S até T.

**Entrada:** `N M K`; depois K inteiros `P[1..K]`; depois M linhas `u v sistema`; depois `S T`.
**Saída:** menor custo total (ou -1 se impossível).
**Restrições:** 1 ≤ N, M ≤ 2×10⁵; 1 ≤ K ≤ 2×10⁵ (soma de sistemas distintos usados ≤ M).

**Exemplo**
```
Entrada:
4 3 2
5 2
1 2 1
2 3 2
3 4 1
1 4

Saída:
9
```

> Esse é o mesmo espírito do seu `transport.cpp`. Vale a pena tentar reconstruir sozinho o truque do "vértice auxiliar" antes de olhar sua solução anterior — ele existe para evitar criar O(M·K) arestas diretamente.

---

## Grupo 4 — Misto (combinando com o que você já domina)

### 4.1 — Pirâmide de Trincas *(combina: força bruta em N pequeno + DP de emparelhamento)*

N atletas (N pequeno, múltiplo de 3) devem ser divididos em **todas** as trincas possíveis (nenhum atleta sobra). Cada trinca `a ≤ b ≤ c` custa `(a-b)²`. Minimize o custo total.

**Entrada:** `N` (N ≤ 12, múltiplo de 3); depois N inteiros.
**Saída:** menor custo total.
**Restrições:** N ≤ 12.

**Exemplo**
```
Entrada:
6
1 2 3 8 9 10

Saída:
2
```

> Pergunta-chave: por que a mesma DP de "Trincas do Torneio" (que deixa sobras) não serve direto aqui, já que agora **todo mundo** precisa estar em alguma trinca? N pequeno é o seu sinal de que outra ferramenta (parecida com o raciocínio da Pirâmide) está liberada.

---

### 4.2 — Oficina com Prazo Máximo *(combina: greedy com priority_queue + busca binária na resposta)*

Mesmo cenário da Oficina: N carros (tempo de serviço `t[i]`) e M mecânicos (fator `f[j]`, tempo real = `t[i] × f[j]`), fila única em ordem de chegada. Mas agora o objetivo **não** é minimizar a soma dos tempos de espera — é minimizar o **maior instante em que algum mecânico termina o último carro de sua fila**.

**Entrada:** `N M`; depois N inteiros `t[i]`; depois M inteiros `f[j]`.
**Saída:** o menor "makespan" possível.
**Restrições:** 1 ≤ N ≤ 2×10⁵; 1 ≤ M ≤ N.

**Exemplo**
```
Entrada:
4 2
5 3 6 2
1 2

Saída:
11
```

> A pergunta que deveria ficar automática (era o seu ponto fraco): "minimizar o máximo" → o que isso sugere de técnica? A partir daí, pense em como simular "é possível terminar tudo até o instante D?" usando a mesma estrutura de duas filas de prioridade da Oficina original.

---

### 4.3 — Trânsito Programado *(combina: grafo com estado expandido + greedy com priority_queue)*

N estações, duas linhas de metrô (0 e 1) como no "Metrô Duplo", mas agora cada linha tem uma capacidade: no máximo `C` passageiros podem estar "em trânsito" numa mesma linha simultaneamente vindos do seu grupo de amigos (K amigos, cada um querendo ir de uma origem a um destino, todos partindo no mesmo instante). Um amigo que não consiga entrar na linha desejada por causa da capacidade deve esperar 1 unidade de tempo e tentar de novo. Determine o instante em que **todos** os K amigos chegaram ao destino, assumindo que cada amigo, individualmente, sempre pega a rota de menor custo (grafo do "Metrô Duplo") a partir do instante em que consegue partir.

**Entrada:** `N M P C K`; depois M linhas `u v linha`; depois K linhas `origem destino`.
**Saída:** o instante em que o último amigo chega.
**Restrições:** N, M ≤ 2×10⁴; K ≤ 100.

> Este é o mais aberto dos 12 — não existe uma única "solução canônica" curta. O objetivo é você **modelar o estado** (que informação além da estação precisa entrar no estado de cada amigo?) e então decidir se um Dijkstra por amigo + uma simulação de fila greedy resolve, ou se precisa de algo mais integrado. Se travar na modelagem, essa trava *é* o ponto de treino.

---

# ═══ AULAS (leia só depois de tentar) ═══

## Aula 1 — Busca binária na resposta + partição (Fast-Food, Dois Bairros, Fazendas Distantes)

**Gatilho para reconhecer o padrão:** sempre que o enunciado pedir para **minimizar o máximo** (ou **maximizar o mínimo**) de alguma grandeza, e essa grandeza tiver uma propriedade de monotonicidade — se `D` funciona, todo `D' > D` também funciona — o reflexo correto é:

```
"minimizar o máximo"
      ↓
busca binária na resposta
      ↓
"para um valor D, é possível?" (função check(D))
```

A parte difícil nunca é a busca binária em si — é desenhar `check(D)` de forma eficiente. Em problemas de **partição em 2 grupos com restrição de distância máxima interna**, a ideia central é:

1. Pares com distância `> D` **não podem** estar no mesmo grupo → isso é uma restrição de **2-coloração** (bipartição), não uma escolha livre.
2. Não dá para testar todos os `O(N²)` pares — é preciso deduzir conflitos **sem enumerá-los todos**, olhando só os extremos (mínimo e máximo) de cada grupo formado até o momento.
3. Em 1D, isso significa acompanhar só `min` e `max` de cada grupo. Em 2D com distância de Manhattan, a transformação `s = x+y`, `t = x-y` converte a distância de Manhattan em `max(|Δs|, |Δt|)`, reduzindo o problema a acompanhar 4 extremos (`min s`, `max s`, `min t`, `max t`) por grupo em vez de todas as coordenadas.

**Checklist de prova (a parte que você pulou na prova):** antes de implementar, escreva por que o algoritmo guloso de 2-coloração está correto — por que sempre existe, em cada passo, um ponto que é *obrigatoriamente* forçado a um dos dois grupos (ou por que, se ninguém é forçado, qualquer escolha arbitrária é segura).

---

## Aula 2 — DP de emparelhamento após ordenação (Trio, Duplas de Treino, Trincas)

**Gatilho para reconhecer o padrão:** "escolher K coisas" + "existe uma ordem natural (ordenar ajuda)" + "as escolhas anteriores afetam o custo das próximas" + "queremos mínimo/máximo" → **DP sobre a sequência ordenada**.

**A observação-chave (a prova que faltou):** depois de ordenar, se um elemento `a[pos]` vai participar de um par/trinca como o "menor" elemento, é sempre ótimo pareá-lo com o elemento imediatamente anterior `a[pos-1]` (nunca compensa "pular" e pegar um elemento mais distante). Isso reduz o espaço de escolhas de exponencial para polinomial.

**Estrutura da DP:**
```
dp[pos][k] = menor custo usando os primeiros "pos" elementos (ordenados)
             para formar exatamente k grupos

Opção 1 — não usar a[pos] em nenhum grupo agora:
    dp[pos][k] = dp[pos-1][k]

Opção 2 — usar a[pos] junto com o(s) elemento(s) anterior(es):
    dp[pos][k] = dp[pos-tam_grupo][k-1] + custo(grupo)
```

O tamanho do "salto" (`pos-2` para pares, `pos-3` para trincas) e a fórmula de `custo(grupo)` mudam de problema para problema, mas a estrutura é sempre a mesma. Quando aparece uma restrição extra (como em "Trincas com Limite"), normalmente ela só afeta **onde você verifica a validade do grupo antes de aplicar a transição** — não muda a estrutura da DP em si.

**Por que "Pirâmide de Trincas" (Grupo 4) quebra essa DP:** aqui todo elemento precisa estar em algum grupo — não há a opção de "não usar". Isso significa que `dp[pos][k]` sozinho não captura mais o problema do jeito certo (tentar forçar sempre usar o elemento muda a lógica de "pular"). Com N ≤ 12, isso é exatamente o sinal — igual ao da Pirâmide original — de que força bruta (ou uma DP por bitmask sobre subconjuntos, uma generalização natural da ideia de "testar todas as permutações") é a ferramenta certa, não uma tentativa de forçar a DP linear a funcionar.

---

## Aula 3 — Estado expandido em grafos (Transporte, Metrô Duplo, Rede Premium)

**Gatilho para reconhecer o padrão:** sempre que o **futuro** de um caminho depender de alguma informação que **não está representada só pelo vértice atual** — nesse caso, essa informação precisa virar parte do estado do seu grafo/Dijkstra/BFS.

```
dist[vértice]  →  insuficiente
dist[(vértice, informação_extra)]  →  correto
```

Exemplos de "informação extra" que vira estado: sistema de transporte atual, número de cargas grátis já usadas, se já usou ou não um item especial, paridade de alguma contagem, etc. O número de estados vira `N × (tamanho do domínio da informação extra)`, e você roda Dijkstra/BFS normalmente **nesse grafo maior**.

**O truque do vértice auxiliar (Rede de Transportes Premium):** quando existem `K` sistemas diferentes e cada estação pode ter várias arestas de sistemas diferentes, criar diretamente as arestas de troca entre todos os pares de sistemas em cada estação custaria `O(K²)` por estação. A solução é criar **um vértice auxiliar por estação**, representando "estou na estação, ainda não decidi que sistema usar":

```
(estação, sistema) → aux[estação]     custo 0   (saio do sistema atual)
aux[estação] → (estação, sistema)     custo P[sistema]   (entro nesse sistema)
```

Isso reduz o número de arestas de troca de `O(K²)` para `O(K)` por estação, porque toda troca passa pelo vértice auxiliar em vez de ligar sistemas diretamente entre si.

**Por que "Metrô Duplo" (Grupo 2) não precisa desse truque:** com apenas 2 sistemas e um preço fixo de troca, o estado `(vértice, sistema)` já é pequeno o bastante (`2N` estados) para não precisar de otimização extra — é o degrau intermediário antes de generalizar para `K` sistemas.

---

# Notas de solução por problema (leia por último)

- **1.1 Fábrica de Brinquedos:** busca binária em D; `check(D)` = greedy — percorra as tarefas somando, sempre que ultrapassar D, "corte" um novo turno; conte turnos usados ≤ K.
- **1.2 Duplas de Treino:** ordene; `dp[i][k] = min(dp[i-1][k], dp[i-2][k-1] + (a[i]-a[i-1])²)`.
- **1.3 Passagem Livre:** BFS 0-1 (deque) no grafo expandido `(vértice, cargas_usadas)`; aresta grátis quando usa carga (custo 0, mesma camada de prioridade), aresta normal custo 1 avança de camada.
- **2.1 Dois Bairros:** binary search em D; `check` greedy 1D acompanhando só min/max de cada grupo (mesma lógica da Aula 1, sem a transformação de Manhattan).
- **2.2 Trincas do Torneio:** igual à Aula 2, com salto de 3 em 3 na DP.
- **2.3 Metrô Duplo:** Dijkstra direto no grafo expandido `(vértice, linha)`, com arestas de troca custando P entre `(v,0)` e `(v,1)`.
- **3.1 Fazendas Distantes:** binary search em D; `check` usa `s=x+y, t=x-y` e o algoritmo guloso de 2-coloração da Aula 1 acompanhando os 4 extremos por grupo.
- **3.2 Trincas com Limite:** mesma DP da 2.2, mas a transição só é válida quando `a[pos]-a[pos-2] ≤ M` (para trincas) — verifique isso antes de aplicar a opção 2.
- **3.3 Rede de Transportes Premium:** Dijkstra com o truque do vértice auxiliar da Aula 3.
- **4.1 Pirâmide de Trincas:** DP por bitmask: `dp[mask]` = menor custo cobrindo o subconjunto `mask`; transição escolhe os 3 menores índices livres de `mask` (ou testa combinações válidas) para formar a próxima trinca. Com N ≤ 12, `2^N × N` é tranquilo.
- **4.2 Oficina com Prazo Máximo:** binary search em D; `check(D)`: para cada mecânico, calcule quantos carros (na ordem dada) ele consegue processar sem estourar D usando uma priority_queue por "próximo horário livre" — se sobrar carro sem mecânico disponível, D é inviável.
- **4.3 Trânsito Programado:** modele o estado de cada amigo como `(amigo, estação, linha, instante)`; rode Dijkstra por amigo assumindo capacidade livre, depois simule a fila de entrada em cada linha por instante (parecido com a fila de mecânicos da Oficina) para achar quem espera.
