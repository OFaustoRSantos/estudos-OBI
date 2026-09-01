#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> pai;
    vector<ll> soma;
    vector<vector<int>> candidatos;

    DSU(vector<ll>& valor) {
        int n = valor.size();

        pai.resize(n);
        soma = valor;
        candidatos.resize(n);

        for (int i = 0; i < n; i++) {
            pai[i] = i;
            candidatos[i].push_back(i);
        }
    }

    int find(int x) {
        if (pai[x] == x)
            return x;

        return pai[x] = find(pai[x]);
    }

    void unir(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        // Small-to-Large:
        // queremos colocar o vetor menor no maior.
        if (candidatos[a].size() < candidatos[b].size())
            swap(a, b);

        pai[b] = a;

        soma[a] += soma[b];

        for (int x : candidatos[b])
            candidatos[a].push_back(x);

        candidatos[b].clear();
    }
};

// Parece uma ideia muito legal mas tenho que estudar


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int V = N * M;

    vector<ll> valor(V);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> valor[i * M + j];
        }
    }

    vector<int> ordem(V);

    for (int i = 0; i < V; i++)
        ordem[i] = i;

    sort(ordem.begin(), ordem.end(), [&](int a, int b) {
        return valor[a] < valor[b];
    });

    DSU dsu(valor);

    vector<bool> ativo(V, false);
    vector<ll> resposta(V, -1);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int pos : ordem) {

        ativo[pos] = true;

        int i = pos / M;
        int j = pos % M;

        for (int d = 0; d < 4; d++) {

            int ni = i + dx[d];
            int nj = j + dy[d];

            if (ni < 0 || ni >= N ||
                nj < 0 || nj >= M)
                continue;

            int viz = ni * M + nj;

            if (!ativo[viz])
                continue;

            int a = dsu.find(pos);
            int b = dsu.find(viz);

            if (a == b)
                continue;

            /*
                Se a soma da componente vizinha
                é menor que o poder da célula atual,
                nenhum candidato daquela componente
                consegue chegar até a célula atual.
            */
            if (dsu.soma[b] < valor[pos]) {

                for (int candidato : dsu.candidatos[b]) {
                    resposta[candidato] = dsu.soma[b];
                }

                dsu.candidatos[b].clear();
            }

            dsu.unir(a, b);
        }
    }

    /*
        Os candidatos que sobreviveram até o final
        conseguem dominar a componente inteira.

        Como a matriz é conexa, essa componente
        contém todas as células.
    */
    int raiz = dsu.find(0);

    for (int candidato : dsu.candidatos[raiz]) {
        resposta[candidato] = dsu.soma[raiz];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (j)
                cout << ' ';

            cout << resposta[i * M + j];
        }

        cout << '\n';
    }
}