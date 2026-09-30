#include <bits/stdc++.h>
using namespace std;


// problema da
int atlanta() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    
    // (a+2) * (b+2) = dimensão sala
    // A = (a+2)(b+2) - ab
    // -> A = 2a + 2b + 4 -> 2(a+b+2) = A

    // a*b = B; a+b = A/2-2;
    // logo é como se fosse uma soma e produto, achar um par a,b onde satisfaz duas eq acima

    // a x b = quantidade de ladrilhos brancos
    for (int a = 1; a * a <= B; a++) {

        if (B % a != 0) // não é divisor
            continue;

        int b = B / a;

        // Quantidade de azuis:
        // (a+2)(b+2) - ab
        int azuis = 2 * a + 2 * b + 4;

        if (azuis == A) {
            cout << min(a + 2, b + 2) << " "
                 << max(a + 2, b + 2) << '\n';
            return 0;
        }
    }

    cout << "-1 -1\n";
}

// MUITO fácil


// problema candidatas;

// MDC sempre mantem ou diminui
// gcd(a,b,c) = gcd(gcd(a,b),c)

#include <bits/stdc++.h>
using namespace std;

int L, C;
int tab[6][6];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<int,int>> candidatas; // pontos possíveis de colocar


int resposta = 0;

bool dentro(int x, int y) {
    return x >= 0 && x < L && y >= 0 && y < C;
}

bool pode_colocar(int x, int y) {

    // Precisa estar ao lado de uma preta
    bool perto_preta = false;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (!dentro(nx, ny))
            continue;

        if (tab[nx][ny] == 1)
            perto_preta = true;

        // Não pode estar ao lado de outra branca
        if (tab[nx][ny] == 2)
            return false;
    }

    return perto_preta;
}


void backtrack(int pos, int quantidade) {
    // se a posição for a ultima candidata, vamos enviar o maximo que encontramos
    if (pos == (int)candidatas.size()) {
        resposta = max(resposta, quantidade);
        return;
    }

    // Opção 1: não colocar branca aqui
    backtrack(pos + 1, quantidade);

    // Opção 2: colocar branca
    auto [x, y] = candidatas[pos];

    if (pode_colocar(x, y)) {

        tab[x][y] = 2;

        backtrack(pos + 1, quantidade + 1);

        // desfaz
        tab[x][y] = 0; // para não atrapalhar futuros backtrack
    }
}

// Muito legal

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> C;

    int P;
    cin >> P;

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;

        --x;
        --y;

        tab[x][y] = 1;
    }

    // Descobrir quais casas podem receber brancas
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {

            if (tab[i][j] != 0)
                continue; //tem preta

            bool perto_preta = false;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (!dentro(ni, nj))
                    continue;

                if (tab[ni][nj] == 1)
                    perto_preta = true;
            }

            if (perto_preta)
                candidatas.push_back({i, j});
        }
    }

    backtrack(0, 0);

    cout << resposta << '\n';
}

// Muito legal

// Problema rede social
/*
Você fez uma priority_queue, mas criou uma lógica cheia de casos:

if(next_numero > FI_atual)
...
if(next_numero > numeros_passados)
...
if(next_numero == numeros_passados)
...

Isso é uma indicação importante:
quando o problema tem uma definição matemática muito direta, tente transformar a definição diretamente em código.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);

    for (int &x : a) // WOW eu nunca pensei nisso
        cin >> x;

    sort(a.begin(), a.end(), greater<int>());

    int resposta = 0;

    for (int i = 0; i < N; i++) {

        // i + 1 mensagens têm pelo menos
        // a[i] repostagens.

        if (a[i] >= i + 1) // se o valor atual de i é maior que o numero que já passaram, então a resposta pode ser i+1.
            resposta = i + 1;
        else
            break;
    }

    cout << resposta << '\n';
}

/*
Brem easy e rapido
*/


/*
Bobiei muito no BFS,esqueci que as arestas tem peso, não pode bfs com peso

Ideia:
1. Identificar todos os ciclos

Como cada vértice pertence a no máximo um ciclo, podemos decompor o grafo.

2. Para cada ciclo

Guardar:

comprimento do ciclo
3. Construir uma árvore de componentes

Cada ciclo vira uma espécie de "supernó".

4. Para uma consulta (X,T)

Precisamos encontrar o ciclo que:
pode comportar um trem de tamanho T

e que permite o menor percurso:
X → ciclo → volta pelo ciclo → X

Grafo ponderado
      ↓
há ciclos?
      ↓
cada vértice pertence a no máximo um ciclo
      ↓
decompor grafo em árvores + ciclos
      ↓
para cada consulta:
    distância até ciclos relevantes
      +
    percurso no ciclo
*/