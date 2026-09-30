
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {

    // Quantidade de subsequências candidatas
    ll resposta = 0;

    // GCD do segmento inteiro
    int gcd_total = 0;

    // (gcd, quantidade)
    // Todos os prefixos do segmento são agrupados
    // pelo valor do seu GCD.
    
    vector<pair<int, ll>> pref;

    // Mesma ideia, mas para sufixos.
    vector<pair<int, ll>> suf;
};

int N, M;
vector<int> a;
vector<Node> seg;


/*
    Adiciona (g, qtd) ao vetor.

    Se o último GCD já for g, apenas somamos
    as quantidades.
*/
void adiciona(vector<pair<int, ll>>& v, int g, ll qtd) {

    if (!v.empty() && v.back().first == g) {
        v.back().second += qtd;
    } else {
        v.push_back({g, qtd});
    }
}


/*
    Junta dois nós:

             esquerda | direita

    Precisamos descobrir:
    1. resposta da esquerda
    2. resposta da direita
    3. subsequências que atravessam a divisão
*/
Node merge_node(const Node& L, const Node& R) {

    Node res;

    // --------------------------------------------------
    // 1. GCD do segmento inteiro
    // --------------------------------------------------

    res.gcd_total = gcd(L.gcd_total, R.gcd_total);


    // --------------------------------------------------
    // 2. Resposta das partes isoladas
    // --------------------------------------------------

    res.resposta = L.resposta + R.resposta;


    // --------------------------------------------------
    // 3. Prefixos
    // --------------------------------------------------

    // Primeiro copiamos os prefixos da esquerda.
    for (auto [g, qtd] : L.pref) {
        adiciona(res.pref, g, qtd);
    }

    /*
        Agora vêm os prefixos que:
        
        - pegam todo o segmento esquerdo
        - e algum prefixo do segmento direito

        Se o GCD do segmento esquerdo é G,
        e o prefixo da direita possui gcd H:

            gcd(G, H)
    */

    for (auto [g, qtd] : R.pref) {

        int novo_gcd = gcd(L.gcd_total, g);

        adiciona(res.pref, novo_gcd, qtd);
    }


    // --------------------------------------------------
    // 4. Sufixos
    // --------------------------------------------------

    // Primeiro, os sufixos da direita.
    for (auto [g, qtd] : R.suf) {
        adiciona(res.suf, g, qtd);
    }

    /*
        Agora os sufixos que:

        - pegam algum sufixo da esquerda
        - e todo o segmento direito
    */

    for (auto [g, qtd] : L.suf) {

        int novo_gcd = gcd(g, R.gcd_total);

        adiciona(res.suf, novo_gcd, qtd);
    }


    // --------------------------------------------------
    // 5. Subsequences que atravessam a divisão
    // --------------------------------------------------

    /*
             esquerda | direita

        Uma subsequência que atravessa a divisão é:

             sufixo da esquerda
             +
             prefixo da direita

        Se:

            gcd(sufixo esquerdo) = G
            gcd(prefixo direito) = H

        então:

            gcd(G,H)
    */

    for (auto [g1, qtd1] : L.suf) {

        for (auto [g2, qtd2] : R.pref) {

            if (gcd(g1, g2) > 1) {

                res.resposta += qtd1 * qtd2;
            }
        }
    }

    return res;
}


/*
    Constrói a Segment Tree.
*/
void build(int node, int l, int r) {

    if (l == r) {

        seg[node].gcd_total = a[l];

        // O único prefixo é o próprio elemento.
        seg[node].pref.push_back({a[l], 1});

        // O único sufixo também é o próprio elemento.
        seg[node].suf.push_back({a[l], 1});

        // Uma subsequência: [l,l].
        //
        // Ela é candidata se a[l] > 1.
        if (a[l] > 1) {
            seg[node].resposta = 1;
        }

        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    seg[node] = merge_node(
        seg[node * 2],
        seg[node * 2 + 1]
    );
}


/*
    Atualização de uma posição.
*/
void update(int node, int l, int r, int pos, int valor) {

    if (l == r) {

        seg[node] = Node();

        seg[node].gcd_total = valor;

        seg[node].pref.push_back({valor, 1});
        seg[node].suf.push_back({valor, 1});

        if (valor > 1) {
            seg[node].resposta = 1;
        }

        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid) {
        update(node * 2, l, mid, pos, valor);
    } else {
        update(node * 2 + 1, mid + 1, r, pos, valor);
    }

    seg[node] = merge_node(
        seg[node * 2],
        seg[node * 2 + 1]
    );
}


/*
    Consulta um intervalo [ql, qr].
*/
Node query(int node, int l, int r, int ql, int qr) {

    // Segmento completamente dentro da consulta.
    if (ql <= l && r <= qr) {
        return seg[node];
    }

    int mid = (l + r) / 2;

    // Consulta só na esquerda.
    if (qr <= mid) {
        return query(node * 2, l, mid, ql, qr);
    }

    // Consulta só na direita.
    if (ql > mid) {
        return query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    // A consulta atravessa a divisão.
    Node esquerda = query(
        node * 2,
        l,
        mid,
        ql,
        qr
    );

    Node direita = query(
        node * 2 + 1,
        mid + 1,
        r,
        ql,
        qr
    );

    return merge_node(esquerda, direita);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    seg.resize(4 * N);

    build(1, 0, N - 1);


    for (int op = 0; op < M; op++) {

        int tipo;
        cin >> tipo;

        if (tipo == 1) {

            int i, v;
            cin >> i >> v;

            --i;

            a[i] = v;

            update(
                1,
                0,
                N - 1,
                i,
                v
            );
        }

        else {

            int E, D;
            cin >> E >> D;

            --E;
            --D;

            Node resultado = query(
                1,
                0,
                N - 1,
                E,
                D
            );

            cout << resultado.resposta << '\n';
        }
    }

    return 0;
}