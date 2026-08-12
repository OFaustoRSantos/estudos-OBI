#include <bits/stdc++.h>
using namespace std;


/* - Detetive

Base de dados, conjunto de eventos e conjunto de implicações
A -> B (A,B = eventos)
Ou seja casualidade
A causa, B consequencia

- Evento é consequecia de cause, ele só ocorre se uma causa ocorrer
A -> B -> C
- Não existe sequencia circular.
> DAG


*/

vector<vector<int>> mat_adj;
// Matrix de volta
vector<vector<int>> mat_ida;

vector<int> dp;
vector<int> verdadeiros;
int solve(int v, bool prev, bool ida, bool inicio){
    //-1 = inexplorado, 1 = true, 0 = false
    // Ele só é acessado se o que está checkando ele é true
    if(dp[v] != -1 && !inicio) return dp[v]; 
    // Caso para frente:
    // colocar solve e deixa-los verdadeiros
    if(ida && inicio){
        if(mat_ida[v].empty()){  
            return 2;
        }
        for(int i:mat_ida[v]){
            if(dp[i] == -1){
                solve(i, false, true, false);
            }
        }
        return 2;
    }
    if(ida && !inicio){
        verdadeiros.push_back(v);
        dp[v] = 1;
        if(mat_ida[v].empty()){  
            return 2;
        }
        for(int i: mat_ida[v]){
            if(dp[i] == -1){
                solve(i, false, true, false);
            }
        }
        return 2;
    }

    // Casos voltando:
    if(inicio){
        for(int u : mat_adj[v]){
            solve(u, true, false, false);
            solve(u, true, false, true);
        }
        return 2;
    }

    if(prev == true){
    // 3 casos quando anterior é verdadeiro com certeza
        // se não tem nenhum -> True
        if(mat_adj[v].empty()){
            dp[v] = 1;
            verdadeiros.push_back(v);
            return dp[v];
        }
        else if(mat_adj[v].size() == 1){
            dp[v] = 1;
            verdadeiros.push_back(v);
            solve(mat_adj[v][0], true, false, false);
            return 1;
        } else {
            // Testar individualmente
            for(int u : mat_adj[v]){
                // se o solve retornar 1 quer dizer que dp[u] = true
                if(dp[u] == true){
                    return 1;
                } else solve(u,false, false, false);
            }
            
        }
    } 
    else{
        // entrou por uma bifurcação de um verdadeiro
        if(mat_adj[v].empty()){
            dp[v] = 0; // false
            return 0;
        }
        for(int u : mat_adj[v]){
            if(solve(u,false,false,false) == 1){
                dp[v] = true;
                verdadeiros.push_back(v);
                return 1;
            }
        }
        
    }
    // se tem um, o de baixo é True;
    // se tem dois ou mais: um dos 3 é true;
}

vector<int> inicios;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: Base de dados + Eventos determinados true pelo detetive.

    int E, I, V; // E = N_Evento, I=N_Inplicação, V=N_event_true
    
    cin >> E >> I >> V;

    mat_adj.assign(E+1,{});
    mat_ida.assign(E+1,{});
    dp.assign(E+1,-1);

    // Evento vazio

    // montando tabela adj
    for(int i =0; i<I;i++){
        int A, B; // A->B
        cin >> A >> B;

        mat_ida[A].push_back(B);
        mat_adj[B].push_back(A);
    }
    // Pegando os que são verdade:
    for(int i=0; i<V;i++){
        int A;
        cin >> A;
        dp[A] = 1; // A = Verdade
        verdadeiros.push_back(A);
        inicios.push_back(A);
    }
    for(int i=0; i<inicios.size(); i++){
        //
        if(!mat_ida[inicios[i]].empty()){
            //cout << "iniciando solve ida " << inicios[i] << endl;
            solve(inicios[i], true, true, true);
        }
        //cout << "iniciando solve volta " << inicios[i] << endl;
        if(!mat_adj[inicios[i]].empty()) {
            //cout << "iniciando solve ida " << inicios[i] << endl;
            solve(inicios[i], true, false, true);
        }
        // volta
        // cout << "solve com sucesso" << i << endl;
    }
    sort(verdadeiros.begin(), verdadeiros.end());

    for(int i=0; i<verdadeiros.size();i++){
        if(i != 0){
            if(verdadeiros[i] == verdadeiros[i-1]){
                continue;
            }
        }
        cout << verdadeiros[i] << " ";
        // se estiver saindo duplicado temos um problema, duas opções:
        // Resolver no codigo do solve o bug,
        // Simplesmente chekar se o ultimo mostrado é igual a i;
    }
    cout << endl;

    

    // DP - DAG



    // Saida -> conjunto de todos os eventos que ocorreram com certeza
    // Unica linha, em ordem crescente, separados por um espaço

}

// Ordem problemas:

/*
16 minutos para ler e entender todos os problemas.
1- Detetive
2- Super
3- Matrix
*/

// Perdi, 1 hora aqui aaaa! Colocar time limit de 20 min para cada, assim eu termino com certeza os mais rápidos primeiro

// E não consegui resolver
// Achei a solução, mas não sei s da tempo para refazer!

// por ser um DAG e um Dp, eu tenho que fazer um bottom-up;

// Vou refazer depois do teste acabar

// vou refazer amanhã, parei no meio
// faltam 20 min nn da tempo nem de terminar o super.cpp;
// iniciarei o tempo com 1h10m; para ser "justo". Assim não perco o simulado a toa; preciso melhorar;

// -------------

// Passo a passo de estratégia de prova
// 1° - identificar dificuldade de cada questão (Não ler elas todas - so inicio saida e estrutura) (5-10 minutos, máximo!)
// Loop até acabar questões:
    // 2° - Selecionar duas mais fáceis e ler ambas (instantaneo). Escrevendo logica dessas duas questões -> Rapidamente! (5 minutos)
    // Loop até acabar set:
        // 4° - Desenhar solução primeira questão do set, no papel mesmo (5 minutos)
        // 5° - Terminar questão (15 minutos) - se não terminar nesse tempo ir para próxima

// Seguindo esse passo a passo, da para acabar em 2h exatas.
// Ideal garimpar tempo. acelerar!

// Na volta das que não foram possíveis terminar
// 6° - Rever solução, avaliar: Debugar X Criar nova (5 min)
// 7° - Fazer acontecer :)