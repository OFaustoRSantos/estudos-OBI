#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* - Problema: 
adicionar moeda nova nas pilhas.
numero minimo de moeda deve adicionar para ter K numeros distintos
*/

struct pilhas{int qntd_pilhas; int qntd_na_pilha;};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // N = N° de pilhas de moeda, K = max_n_distintos
    int N, K; cin >> N >> K;

    vector<int> alt_pi(N,0);
    int n_distintos=0;
    //map<int,int> id_numero; // queria usar mas não lembro
    vector<int> qnt_n_fila(501,0); // o limite nas restrições é 500

    // vetor que tem o par: id_numero, qnt_vezes na fila.

    for(int i=0; i<N; i++){
        cin >> alt_pi[i];
        qnt_n_fila[alt_pi[i]]++;
    }

    // ideia:
    /*
    achar a menor distancia de dois conjuntos de numeros distintos.
    ou seja, se eu tenho 5 pilhas, e tenho K =2
    cada pilha tem que apontar para um numero
    */

    // tenho que mexer em K-n_distintos numeros
    
    sort(alt_pi.begin(), alt_pi.end());

    const int INF = 500*500;
    
    // vou fazer um dp
    /* dp[numero de pilhas][numero itens na fila][opt] = min de moedas a adicionar para ter y numero de pilhas com nos x primeiros itens na fila 
    Opt 0 = moedaas para chegar até ela
    Opt 1 = numero de pilhas ultima pilha
    */
    vector<vector<pair<int,int>>> dp(N, vector<pair<int,int>> (K+1, {INF,0}));

    dp[0][0].first = 0; // caso base: 0 itens 0 pilhas
    dp[0][0].second = 0;
    dp[1][0] ={0,0};
    // transições DP:
    // Ao colocar um item (está sorted, então proximo sempre será maior ou igual) novo temos algumas opções: 
    // - escolher n° atual como ancora: 
        // - subir os mais proximos dele para ele -> criando um grupo
    // 
    alt_pi[0] = 0;
    dp[1][1] = {0,1};
    for(int i=2; i<N;i++){
        dp[1][i].first = dp[1][i-1].first + (alt_pi[i] -alt_pi[i-1]);
        dp[1][i].second = i;
    }
    for(int i=1; i<K;i++){
        dp[K][1] = {0,1};
    }
    
    if(K==1){
        cout << dp[N-1][1].first << endl;
        return 0;
    }

    for(int j=2; j<= K;j++){
        for(int i=1; i<N;i++){
            // n atual = alt_pi[i];

            // cada novo numero temos duas opções:
            /*
            - levar ancora mais perto até ele. ou
            - juntar duas ancoras e deixar ele sozinho
            */
           // juntar duas ancoras:
           // dp[j][i-1] - dp[j-1][i-1]
           // levar ancora mais perto até ele
           // alt_pi[i]-alt_pi[i-1] = moedas até ele; 
           // preciso da informação numero de pilhas com valor imediatamente antes dele
            
           dp[j][i].second =  1;

           int preco_juntar_pilhas = dp[j][i-1].first - dp[j-1][i-1].first;

           int preco_puxar_pilhas = dp[j][i-1].second * (alt_pi[i]-alt_pi[i-1]);
           if(preco_puxar_pilhas <= preco_juntar_pilhas){
                // puxar as dp[j][i-1] para nova pilha:
                dp[j][i].second = dp[j][i-1].second+1;
           }
           dp[j][i].first = min(preco_juntar_pilhas,preco_puxar_pilhas);

        }
    }

    /* - Criar lista nova:
    - distancia do 1 até o numero atual:
    escolher K pontos com menor:
    lista_nova[ponto_1] - lista_nova[0] + lista_nova[ponto_2] - lista_nova[ponto_1 +1] ...

    // cada novo numero temos duas opções:
    levar ancora mais perto até ele. ou
    juntar duas ancoras e deixar ele sozinho
    */


    // só posso mudar os menores -> aos maiores.


    // Preciso escolher os k numeros mais proximo somando de outro conjunto



    // re-estudar função get_id, usada no dijkstra
    //int get_id(int n){
        //if(id_numero.count(n) > 1) return id_numero;
        // Não tem esse numero aqui
        //id_numero[n] = n_distintos++;
    //}

    cout << dp[N-1][K].first << endl;
}

/* - Esse codigo seria bom fazer usando a fução get_id que tinha aprendido no dijkstra, mas não lembro dela.
Perdi um tempinho indo no banheiro

Posso conseguir até 34 pontos na cara de pau

Parei no meio, fiquei uns 40 min aqui.
Dificil
*/

/* - Não to conseguindo fazer, não sei se tento outra solução usando binary search para encontrar os pontos onde seriam as stacks.

Gosto da solução da dp, mas não consigo resolver com ela

Desisti
*/