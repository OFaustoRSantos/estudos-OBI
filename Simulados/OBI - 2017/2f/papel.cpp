#include <bits/stdc++.h>
using namespace std;

// squencia de retangulos.

stack<int> altura;

// group

// chuta a mediana funciona? , não
// chute da moda/ menor?

int papeis = 2; // o primeiro, e o segundo pos corte

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int N;
    cin >> N;

    for(int i =0; i<N;i++){
        int int_at;
        cin >> int_at;

        if(int_at < altura.top()){
            papeis++;
        }

        altura.push(int_at);
    }

    cout << papeis << endl;
    // descobrir o cal
}


// Correção com gemini

/*
Você não encontrou a modelagem
Ordenação + componentes + sweep
*/

/*
A técnica é:
- Ordenação + manutenção de componentes conexos

Também podemos chamar isso de um tipo de:
- Sweep Line / processamento offline.
*/

/*
| Sweep Line - Em vez de analisar o problema inteiro de uma vez, movemos uma linha e mantemos apenas o estado relevante naquele momento.
| Conforme a linha se move, alguma propriedade muda apenas em determinados eventos.


Criar uma 2° lista
- Ordenar as alturas
> Agora do menor para o maior, faremos uma análise de como remover uma posição altera o numero de blocos

| Lógica do sistema

Qual altura cria o maior numero de blocos
-> Testar as menores alturas do sistema, um a um

Quando chegamos na altura de um retângulo, esse retângulo começa a fazer parte da região acima

Com isso temos 3 opções
1 - o novo retangulo, não tem vizinhos ativos 
-> Cria-se um novo grupo

2 - ele conecta dois grupos:
-> Reduz um grupo

3 - Prolonga um grupo

para cada altura:
    olha todos os N retângulos
    descobre os grupos

- atualizar somente o que mudou

| -> Esse raciocinio eu preciso ter!
é importante.

Ele começa do topo e vai baixando o corte.

Para cada retângulo que entra na região acima do corte, perguntamos:

┌─────────────────────────────┐
│ Qual é o vizinho da esquerda?│
│ Qual é o vizinho da direita? │
└─────────────────────────────┘

tabelinha de condições
Esquerda ativa	Direita ativa	Resultado
não	não	cria grupo → +1
sim	não	continua grupo → +0
não	sim	continua grupo → +0
sim	sim	conecta dois → -1

*/

// Sistema de ativação


/* - Codigo - papel

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> a;

    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;

        a.push_back({h, i});
    }

    sort(a.begin(), a.end());

    // 1 = ainda ativo
    // 0 = removido
    vector<int> ativo(N + 2, 1);

    int tiras = 1;
    int resposta = 1;

    for (int i = 0; i < N; i++) {

        int altura = a[i].first;
        int pos = a[i].second;

        ativo[pos] = 0;

        // Um bloco foi dividido em dois
        if (ativo[pos - 1] && ativo[pos + 1])
            tiras++;

        // Dois blocos foram unidos/eliminação do elo
        if (!ativo[pos - 1] && !ativo[pos + 1])
            tiras--;

        // Só podemos avaliar depois de processar
        // todas as posições com a mesma altura.
        if (i == N - 1 || a[i].first != a[i + 1].first) {
            resposta = max(resposta, tiras);
        }
    }

    cout << resposta + 1 << '\n';

    return 0;
}

*/