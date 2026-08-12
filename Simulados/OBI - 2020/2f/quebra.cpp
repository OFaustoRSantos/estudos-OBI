#include <bits/stdc++.h>
using namespace std;

/*
    
*/

vector<vector<int>> matrix;

// soma das multiplicações
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    matrix.assign(2, vector<int>(N,0));

    vector<vector<int>> fil;

    for(int i=0; i<2;i++){
        int M; // Numero de fichas na linha
        cin >> M;
        vector<int> fil_at;
        for(int j=0; j<M; j++){
            int N_at;
            cin >> N_at;
            fil_at.push_back(N_at);
            matrix[i][j] = N_at;
        }
        fil.push_back(fil_at);
    }   

    // o ultimo elemento de A fique com o ultimo elemento positivo
    for(int j=0; j<fil.size();j++){
        // Negativo
        if(fil[0][j] < 0){

        }
        // Positivo
        if(fil[0][j] > 0){

        }
    }
    

}


// farei fora de ordem farei estrada primeiro, esse parece demorar;
// Não consegui fazer em 10 min, focarei na formiga para tentar subir a nota;

/*

Aqui está o problema que mais revela uma lacuna sua.

Isso mostra que você estava tentando construir uma configuração ótima diretamente.

Esse é justamente o caminho que eu quero que você pare de seguir.

A descrição diz que as fichas podem deslizar, mas não podem mudar de ordem.
*/

/*
"Se a ordem não muda, o problema provavelmente é de alinhamento entre duas sequências."
Quais fichas de cima serão emparelhadas com quais fichas de baixo?

Não precisamos simular movimentos.
*/

/* - Programação Dinamica
Quando temos duas sequências preservando ordem:

A[0...M1-1]
B[0...M2-1]

e precisamos decidir como alinhá-las, pense:

dp[i][j] = melhor resultado usando as primeiras i fichas de A e as primeiras j fichas de B.

3° opções:
A partir daí existem decisões como:
- A[i] emparelha com B[j]
ou:
- A[i] fica sozinha
ou:
- B[j] fica sozinha
*/
/* - Forma de pensar:
ordem não pode mudar
↓
sequência
↓
alinhamento
↓
decisões entre elementos
↓
DP
*/

/* - Saber qual das 3 soluções melhor aumenta o dp:

dp[i][j] =
max(
    dp[i-1][j],
    dp[i][j-1],
    dp[i-1][j-1] + A[i-1] * B[j-1]
)

*/

/* - Resolução:
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M1;
    cin >> M1;

    vector<int> A(M1);

    for (int i = 0; i < M1; i++) {
        cin >> A[i];
    }

    int M2;
    cin >> M2;

    vector<int> B(M2);

    for (int i = 0; i < M2; i++) {
        cin >> B[i];
    }

    // dp[i][j] =
    // melhor valor usando as primeiras i fichas de A
    // e as primeiras j fichas de B

    vector<vector<int>> dp(M1 + 1, vector<int>(M2 + 1, 0));

    for (int i = 1; i <= M1; i++) {
        for (int j = 1; j <= M2; j++) {

            // A[i-1] fica sozinha
            dp[i][j] = dp[i-1][j];

            // B[j-1] fica sozinha
            dp[i][j] = max(dp[i][j], dp[i][j-1]);

            // A[i-1] e B[j-1] ficam na mesma coluna
            dp[i][j] = max(
                dp[i][j],
                dp[i-1][j-1] + A[i-1] * B[j-1]
            );
        }
    }

    cout << dp[M1][M2] << '\n';

    return 0;
}

*/