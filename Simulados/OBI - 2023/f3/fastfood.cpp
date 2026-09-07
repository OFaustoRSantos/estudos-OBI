#include <bits/stdc++.h>
using namespace std;


/*
Pizza, hamburguer
*/

struct restaurante{int x; int y;};

vector<vector<int>> grid;

// Calculo distacia entre dois restaurantes
int distancia(int Xi, int Yi, int Xj, int Yj){
    return max(Xi-Xj, Xj-Xi) + max(Yi-Yj, Yj-Yi);
}

/*
Se X > X_med; Y > Y_med
*/

/*
minha idea:

Fazer uma regressão linear. 
linha que separa os dois tipos.
- Escolher os dois pontos mais distantes da linha - restaurantes de referencia
- Escolher os dois pontos mais distantes da referencia, mais pertos da linha

*/

restaurante ponto_medio;

bool comp(restaurante a, restaurante b){

    // Definir se está do lado "direito" ou "esquerdo"
    if(a.x > b.x) {
        if(distancia(a.x,a.y, ponto_medio.x, ponto_medio.y)>distancia(a.x,a.y, ponto_medio.x, ponto_medio.y)){
        }
    }
}

vector<int> coord_X;
vector<int> coord_Y;

/*
Minha ideia:
definir: Média de X, e Média de Y.

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N; // N prédios;

    // Coordenadas prédios
    for(int i=0; i <N;i++){
        int X_at;
        cin >> X_at; coord_X.push_back(X_at);
    }

    /*
    Objetivo reduzir a distancia máxima entre todos os pares da mesma rede
    Dado N prédios, definir qual é cada tipo,
    e definir distancia máxima entre dois restaurantes de uma mesma rede

    */

    // grid 
}


/*
- Não sei resolver esse fastfood
*/

// Solução didática

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Ponto {
    ll x, y;

    ll s() const {
        return x + y;
    }

    ll t() const {
        return x - y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Ponto> p(N);

    // pegando os pontos
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    /*
        Ordenamos os pontos pelas transformações:

            s = x + y
            t = x - y

        Isso vai nos permitir encontrar os extremos
        dos pontos que ainda não foram classificados.
    */

    vector<int> ordemS(N);
    vector<int> ordemT(N);
    /*
    iota:
    comece em 0 e vá colocando numeros consecutivos no vetor.

    - Uma forma inteligente de guardar indices mantendo o vetor intacto. Assim guardamos bem a ordem S e T - duas caracteristicas de um ponto
    */
    iota(ordemS.begin(), ordemS.end(), 0);
    iota(ordemT.begin(), ordemT.end(), 0);
    // lambda function do comp
    sort(ordemS.begin(), ordemS.end(), [&](int a, int b) {
        return p[a].s() < p[b].s();
    });

    sort(ordemT.begin(), ordemT.end(), [&](int a, int b) {
        return p[a].t() < p[b].t();
    });


    /*
        Função que verifica se uma distância máxima D
        é possível.
    */

    // -> datatype : declara explicitamente o tipo de retorno da lambda

    auto check = [&](ll D) -> bool {

        /*
            cor[i]:

            -1 = ainda não classificado
             0 = grupo A
             1 = grupo B
        */
        vector<int> cor(N, -1);

        /*
            Extremas de cada grupo.

            Para cada grupo guardamos:
                menor s
                maior s
                menor t
                maior t
        */
        // usamos duas constantes para definir a função
        ll minS[2] = {LLONG_MAX, LLONG_MAX};
        ll maxS[2] = {LLONG_MIN, LLONG_MIN};

        ll minT[2] = {LLONG_MAX, LLONG_MAX};
        ll maxT[2] = {LLONG_MIN, LLONG_MIN};


        /*
            Pontos ainda não classificados.

            Para conseguir atualizar os extremos,
            usamos sets.

            O set contém pares:
                (valor, índice)
        */

        set<pair<ll, int>> S;
        set<pair<ll, int>> T;

        for (int i = 0; i < N; i++) {
            S.insert({p[i].s(), i});
            T.insert({p[i].t(), i});
        }

        /*
            Coloca um ponto no grupo g.
        */

        auto adiciona = [&](int id, int g) {

            cor[id] = g;

            // atualiza o min max do conjunto se necessário
            minS[g] = min(minS[g], p[id].s());
            maxS[g] = max(maxS[g], p[id].s());

            minT[g] = min(minT[g], p[id].t());
            maxT[g] = max(maxT[g], p[id].t());

            // Tira da lista de não classificados
            S.erase({p[id].s(), id});
            T.erase({p[id].t(), id});
        };


        /*
            Começamos colocando o ponto 0 no grupo 0.
        */

        adiciona(0, 0);


        while (!S.empty()) {

            /*
                Vamos procurar um ponto ainda não classificado
                que seja obrigado a entrar em algum grupo.
            */

            int escolhido = -1;
            int grupoEscolhido = -1;


            /*
                --------------------------------------------------
                Procuramos um ponto que NÃO PODE ficar no grupo 0.
                --------------------------------------------------
            */

            // ou seja, existe algo no grupo 0
            if (minS[0] != LLONG_MAX) {

                // Ponto ainda não classificado com menor s
                auto it = S.begin();

                ll sMin = it->first;
                int id = it->second;


                if (maxS[0] - sMin > D) {
                    // Temos um problema, o sMin vai para 1
                    escolhido = id;
                    grupoEscolhido = 1;
                }

                // Ponto ainda não classificado com maior s - pode entrar no grupo 1
                if (escolhido == -1) {
                    auto it2 = prev(S.end());

                    ll sMax = it2->first;
                    int id2 = it2->second;
                        // testamos se ele é obrigado a ir para o outro grupo
                    if (sMax - minS[0] > D) {
                        escolhido = id2;
                        grupoEscolhido = 1;
                    }
                }
            }


            /*
                Fazemos a mesma coisa para t.
                caso não tenhamos achado alguem obrigado
                
            */

            if (escolhido == -1 && minT[0] != LLONG_MAX) {

                auto it = T.begin();

                ll tMin = it->first;
                int id = it->second;

                if (maxT[0] - tMin > D) {
                    escolhido = id;
                    grupoEscolhido = 1;
                }

                if (escolhido == -1) {
                    auto it2 = prev(T.end());

                    ll tMax = it2->first;
                    int id2 = it2->second;

                    if (tMax - minT[0] > D) {
                        escolhido = id2;
                        grupoEscolhido = 1;
                    }
                }
            }


            /*
                --------------------------------------------------
                Agora verificamos se alguém NÃO PODE ficar
                no grupo 1.
                --------------------------------------------------
            */

            if (escolhido == -1 && minS[1] != LLONG_MAX) {

                auto it = S.begin();

                ll sMin = it->first;
                int id = it->second;

                if (maxS[1] - sMin > D) {
                    escolhido = id;
                    grupoEscolhido = 0;
                }

                if (escolhido == -1) {
                    auto it2 = prev(S.end());

                    ll sMax = it2->first;
                    int id2 = it2->second;

                    if (sMax - minS[1] > D) {
                        escolhido = id2;
                        grupoEscolhido = 0;
                    }
                }
            }


            if (escolhido == -1 && minT[1] != LLONG_MAX) {

                auto it = T.begin();

                ll tMin = it->first;
                int id = it->second;

                if (maxT[1] - tMin > D) {
                    escolhido = id;
                    grupoEscolhido = 0;
                }

                if (escolhido == -1) {
                    auto it2 = prev(T.end());

                    ll tMax = it2->first;
                    int id2 = it2->second;

                    if (tMax - minT[1] > D) {
                        escolhido = id2;
                        grupoEscolhido = 0;
                    }
                }
            }


            /*
                Se encontramos alguém obrigado,
                colocamos no grupo correspondente.
            */

            if (escolhido != -1) {

                adiciona(escolhido, grupoEscolhido);

            } else {

                /*
                    Ninguém está sendo obrigado.

                    Podemos colocar qualquer ponto
                    arbitrariamente no grupo 0.
                */

                int id = S.begin()->second;

                adiciona(id, 0);
            }
        }


        /*
            Todos foram classificados.

            Agora verificamos se existe algum par
            dentro do mesmo grupo com distância > D.

            Como a maior distância de um conjunto é:

                max(
                    maxS - minS,
                    maxT - minT
                )

            basta verificar isso para cada grupo.
        */

        for (int g = 0; g < 2; g++) {

            ll maiorDist = max(
                maxS[g] - minS[g],
                maxT[g] - minT[g]
            );

            if (maiorDist > D) {
                return false;
            }
        }

        return true;
    };


    /*
        Descobrimos um limite superior para a resposta.

        A maior distância Manhattan possível entre dois
        pontos está limitada pelos extremos de s e t.
    */

    ll maior = 0;

    ll minS = LLONG_MAX;
    ll maxS = LLONG_MIN;
    ll minT = LLONG_MAX;
    ll maxT = LLONG_MIN;

    for (auto ponto : p) {

        minS = min(minS, ponto.s());
        maxS = max(maxS, ponto.s());

        minT = min(minT, ponto.t());
        maxT = max(maxT, ponto.t());
    }

    maior = max(
        maxS - minS,
        maxT - minT
    );


    /*
        Busca binária na resposta.
    */

    ll lo = 0;
    ll hi = maior;

    while (lo < hi) {

        ll mid = (lo + hi) / 2;

        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';
}