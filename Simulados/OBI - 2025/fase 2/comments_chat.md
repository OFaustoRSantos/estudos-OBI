# Coments Chat

## Overview da prova

Problema	Sua abordagem	Qualidade	Minha avaliação
Placar	Ordenação + simulação	🟢 Excelente	Solução essencialmente ideal
Distinto	Greedy escolhendo A, A+1,...	🟢 Conceito correto	Ideia ótima, implementação pode ficar matemática
Mania	Análise local + várias passadas	🔴 Gambiarra	Você percebeu a estrutura, mas não a propriedade fundamental
Feira	Vetores ordenados + ponteiro global	🟡 Boa intuição	Quase chegou numa solução boa, mas a estrutura de dados ficou frágil


## Placar

100% zero comentário

## Distinto

Problema -> Minha solução é pode ser lenta, pois ela faz uma rodada por vez.

Podemos usar uma formula matemática para isso

(k−1)(2A+k−2)​<2L

- Muito legal, uma busca binária

## Mania

- Errei a lógica, fiz num modelo de consertar a matrix

Mais fácil era enxergar que para conseguir a configuração desejava, bastava configurar como:
par impar ...
impar par ...
...

ou
impar par ...
par impar ...
...

Bem mais rápido, inteligente e mais fácil de implementar

## Feira

Minha solução ficou boa, mas era mais fácil ter guardado o id do objeto e fazer um check se for vendido ou não

solução ideal
#include <bits/stdc++.h>
using namespace std;

struct Objeto {
    int tipo;
    int preco;
    int id;
};

struct CompareGlobal {
    bool operator()(const Objeto& a, const Objeto& b) const {

        if (a.preco != b.preco)
            return a.preco > b.preco;

        if (a.tipo != b.tipo)
            return a.tipo > b.tipo;

        return a.id > b.id;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<int> tipo(N);
    vector<int> preco(N);

    for (int i = 0; i < N; i++)
        cin >> tipo[i];

    for (int i = 0; i < N; i++)
        cin >> preco[i];

    // Objetos separados por tipo
    vector<vector<pair<int,int>>> porTipo(T + 1);

    // Fila com todos os objetos disponíveis
    priority_queue<
        Objeto,
        vector<Objeto>,
        CompareGlobal
    > fila;

    for (int i = 0; i < N; i++) {

        porTipo[tipo[i]].push_back({preco[i], i});

        fila.push({
            tipo[i],
            preco[i],
            i
        });
    }

    // Ordenar objetos de cada tipo por preço
    for (int t = 1; t <= T; t++) {
        sort(porTipo[t].begin(), porTipo[t].end());
    }

    // Ponteiro para o próximo objeto de cada tipo
    vector<int> pos(T + 1, 0);

    vector<bool> vendido(N, false);

    int C;
    cin >> C;

    long long resposta = 0;

    for (int i = 0; i < C; i++) {

        int cliente;
        cin >> cliente;

        // Cliente decidido
        if (cliente != 0) {

            if (pos[cliente] == porTipo[cliente].size())
                continue;

            int precoCompra =
                porTipo[cliente][pos[cliente]].first;

            int id =
                porTipo[cliente][pos[cliente]].second;

            pos[cliente]++;

            vendido[id] = true;

            resposta += precoCompra;
        }

        // Cliente indeciso
        else {

            // Remover objetos já vendidos
            while (!fila.empty() && vendido[fila.top().id])
                fila.pop();

            if (fila.empty())
                continue;

            Objeto obj = fila.top();
            fila.pop();

            vendido[obj.id] = true;

            resposta += obj.preco;
        }
    }

    cout << resposta << '\n';
}