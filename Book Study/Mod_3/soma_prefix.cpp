#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);

}

//Feito 100% sozinho
int construct_padrao_1d(){

    int N; cin >> N;
    vector<int> lista(N,0);

    for(int i=0;i<N; i++){
        cin >> lista[i];
    }

    // Praticamente um DP, usando os N elementos temos uma soma total de prefix[N]
    vector<int> prefix(N+1,0);

    for(int j=1; j<=N;j++){
        prefix[j] = prefix[j-1]+lista[j-1];
    }

    // Intervalo
    int R,L; cin >> R >> L;
    cout << "soma intervalo = " << prefix[R]-prefix[L] << endl;
}


// Nunca fiz antes
int construct_2d(){
    int n,m;
    vector<vector<int>> grid;
    vector<vector<long long>> prefix(n+1, vector<long long>(m+1,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i+1][j+1] = 
            grid[i][j] + prefix[i][j+1] + prefix[i+1][j] 
            - prefix[i][j];

            /*
            Prefixo do () é igual soma [] e - menos {}
            {-} [ ]
            [ ] ( )
            {-} é tanto o prefixo, como o valor da grid
            */
           
        }
    }
    
    // soma do retângulo com cantos (r1,c1) até (r2,c2), inclusivo:
           
    auto somaRetangulo = [&](int r1, int c1, int r2, int c2) -> long long {
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    };  
}

// Quantidade de subarrays com soma exata igual a K, usando prefix sum + hashmap (médio/difícil)
void sub_array_soma_K(){
    /*
    Não pensei em como fazer ...
    tem que ser subarray em sequencia
    a,b,c,d,e,f
    [ a, b, c] ou pode ser [a,d,f];
    caso precise podemos só fazer força bruta.

    fazer o prefixo:
    while(i<N){
        int soma_at;

        while(soma_at<valor_K){
            // teste dos dois casos colocando mais uma direita, colocando mais um a esquerda
        }
    }
    */
}

// solução sub_array_soma_k: https://chatgpt.com/c/6aa948ef-bd5c-83e9-8766-8a6dfca011ce

void sub_array_soma_K_solution(){

    
}