#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N tarefas para automatizar nessa ordem; K = turnos/ n° funcionários
    int N, K; cin >> N >> K;

    vector<int> tempo_tarefas(N,0);
    for(int i =0;i<N;i++){
        cin >> tempo_tarefas[i];
    }

    // saida: menor numero possível para maior turno.
    // ideia 3:
    /*
    temos K turnos, vamos andar nos N digitos e faremos o seguintes:
    iremos colocar o numero no ultimo K colocado,
    iremos fazer uma verificação para o K maior se faz sentido passar um numero dele para fila antes

    Usando exemplo 1
    7 2 5 10 8
    No segundo turno ->
    1 - 7
    2 - 2
    (maior não tem para quem dar numero pula)
    No terceiro ->
    1 - 7
    2 - 2, 5
    (maior não tem para quem dar numero pula)
    
    No quarto turno ->
    1 - 7
    2 - 2, 5, 10 
    (2 é o maior e pode dar um numero para 1 sem que 1 se torne maior)
    logo
    1 - 7, 2
    2 - 5, 10
    : Se passarmos de novo 1 ficaria maior que o maior (2), por isso não passaremos
    quinto turno
    1 - 7, 2
    2 - 5, 10, 8
    (2 é o maior e pode dar um numero para 1 sem que 1 se torne maior)
    logo
    1 - 7, 2, 5
    2 - 10, 8
    teoricamente posso fazer essa operação durante criação do vetor, mas farei por fora para deixar organizado por enquanto
    */
    vector<vector<int>> grupos(K,vector<int>());
    
    /* tamanho_grupos
    first - valor do tamanho
    second - quando começa o vetor (para não ter que ficar dando delete)
    */
    vector<pair<int,int>> tamanho_grupos(K,{0,0});
    
    // priority_queue que guarda: Maior tamanho, id maior tamanho
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    // , greater<pair<int,int>>
    int ultimo_k_add = 0;
    for (int i =0; i<N; i++){
        int novo_numero = tempo_tarefas[i];
        // adicionamos o tamanho
        grupos[ultimo_k_add].push_back(novo_numero);
        tamanho_grupos[ultimo_k_add].first += novo_numero;
        
        // colocando na fila o ultimo grupo com adesão de K
        pq.push({tamanho_grupos[ultimo_k_add].first, ultimo_k_add});
        // adicionamos um novo num turno vazio
        if(ultimo_k_add != K-1)
            ultimo_k_add++;
        // temos um todos os turnos preenchidos    
        else{
            // fazemos as operações para reduzir o valor do maior:

            // teste se maior tem para quem dar
            auto maior_atual = pq.top(); pq.pop();
            
            // maior_atual tem que estar atualizado
            if(tamanho_grupos[maior_atual.second].first == maior_atual.second){
            // tem que ter indice maior que 0, e
            // jogando o primeiro item do grupo do maior no menor, não pode ser maior que o maior atual
            if(maior_atual.second > 0 && grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second] + tamanho_grupos[maior_atual.second-1].first < maior_atual.first){
                // passamos
                tamanho_grupos[maior_atual.second].first -= grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second];
                tamanho_grupos[maior_atual.second-1].first += grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second];

                // atualizando ponteiro
                tamanho_grupos[maior_atual.second].second++;
                
                // Colocando de volta na fila o grupo com maior atual.
                pq.push({tamanho_grupos[maior_atual.second].first, maior_atual.second});
                
            }
            // adicionamos o valor do maior atualmente, caso

            // adicionar maior atual de novo:
        }
        }
    }  
    int maior_grupo_real=0;
    
    while(!pq.empty()){
        auto maior_atual = pq.top(); pq.pop();
        //valores desatualizados
        if(tamanho_grupos[maior_atual.second].first != maior_atual.second)
           continue;
        
        // vendo se é possível passar
        if(maior_atual.second > 0 && grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second] + tamanho_grupos[maior_atual.second-1].first < maior_atual.first){
            // passamos
            tamanho_grupos[maior_atual.second].first -= grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second];
            tamanho_grupos[maior_atual.second-1].first += grupos[maior_atual.second][tamanho_grupos[maior_atual.second].second];

            // atualizando ponteiro
            tamanho_grupos[maior_atual.second].second++;
            
            // Colocando de volta na fila o grupo com maior atual.
            pq.push({tamanho_grupos[maior_atual.second].first, maior_atual.second});
            
        }

        // encontramos o maior numero com valor atualizado. logo podemos parar o sistema
        maior_grupo_real = tamanho_grupos[maior_atual.second].first;
        break; 
    }

    cout << maior_grupo_real << endl;
}  

// tipo assim temos uma fila de numeros vamos escolher onde colocar pontos de separação. de forma em que o grupo com maior valor entre pontos tenha o mínimo.
    // N = até 20.000

    // ideia é fazer uma soma de prefixo primeiro:
    /*// assim eu tenho uma lista de N+1 prefixos
    vector<int> prefix (N+1,0);
    for(int i=0; i<N;i++){
        prefix[i+1] = prefix[i] + tempo_tarefas[i]; 
    } 
    // Não vejo em que ma ajude
    */  
    // não podemos reordenar então no máximo mudaremos nos pontos do prefixo
    // ideia 1:
    /*
    // algo tipo um dp, mas não é um dp
    vector<int> pontos({0, N-1}); // dois pontos claros, no ultimo e no primeiro
    
    for(int i=1; i<=K; i++){
        // vamos adicionar pontos, de separação, e fazeremos um binary search para adicionar o ponto
        // Adicionando novo ponto:
        int l1 =0;
        int d1 = N-1;
        // se maior numero reduz 
    }
    */
    // Não acho que vai dar certo, farei algo como um Dp mesmo

    // ideia 2:
    /* farei um dp para dp[N][K] -> Maior grupo nos N primeiros numeros com K grupos
    for(int i=0;i<N;i++){

        for(int j=0;j<K;j++){

        }
    }
    // saber só o maior grupo não me ajuda
    // parece mais complicado fazendo o dp
    */

    
    // tenho t turnos, ideia a cada


// fiz de uma forma MUITO mais dificil
