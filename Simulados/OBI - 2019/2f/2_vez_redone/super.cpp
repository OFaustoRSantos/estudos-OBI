#include <bits/stdc++.h>
using namespace std;


struct mercado{int gramas; double custo;};

vector<mercado> mercados;

int const target_gramas = 1000;

bool comp(mercado a, mercado b){
    return a.gramas/a.custo < b.gramas/a.custo;
}


// matrix: indice mercado comprado, quantidade
vector<pair<int,int>> mercado_compra;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    for(int i =0; i<N; i++){
        mercado mer_at;
        cin >> mer_at.custo >> mer_at.gramas;
        mercados.push_back(mer_at);
    }

    // Ordenando por menor preço
    sort(mercados.begin(), mercados.end(), comp);

    bool continuar_n_mercados = true;
    int mercado_at = 0;

    // [indice_mercado][0 = preço total; 1 = quantidade total]
    vector<vector<double>> dp;

    dp.assign(N,{99999999999,999999999});
    int menor_dp = 0;
    while(continuar_n_mercados){
        if(mercado_at == mercados.size()-1) continuar_n_mercados = false;
        // ultima operação será essa
        // definindo dp[0]
        if(mercado_at==0){
            pair<int,int> merc_ini; merc_ini.first = 0; merc_ini.second = 1 + target_gramas/mercados[mercado_at].gramas;
            mercado_compra.push_back(merc_ini);
            dp[0] = {(1 + target_gramas/mercados[mercado_at].gramas) * mercados[mercado_at].custo, double(int(1 + target_gramas/mercados[mercado_at].gramas))};

            mercado_at++;
            continue;
        }
        
        
        // após ele passar de um iremos fazer um min
        int custo_at = dp[mercado_at-1][0];
        
        
        int pedidos_mer_at = 0;
        int preco_dp = dp[mercado_at-1][0];
        int gramas_dp = dp[mercado_at-1][0];

        while (true)
        {   
            int n_custo_at = preco_dp - 
                // pedido que estamos tirando do ultimo mercado
                (mercados[mercado_compra[mercado_compra.size()-1].first].custo * 1)
                +
                // pedido que estamos adicionando ao mercado atual
                (1+ (target_gramas - 
                    // quantidade de gramas tiras
                    (dp[mercado_at-1][1] - mercados[mercado_compra[mercado_compra.size()-1].first].gramas * 1))/mercados[mercado_at].gramas) * mercados[mercado_at].custo > dp[dp.size() -1][0]; 

            
            // preço antigo > preço do antigo - o tirado do antigo + o novo -> temos novo menor 
            if(preco_dp > n_custo_at){
                // atualiza custo
                preco_dp = n_custo_at;
                // atualizar pedidos mer_at
                pedidos_mer_at++;
                mercado_compra[mercado_compra.size()-1].first--;
                //gramas_dp=;
            } else{
                break;
            }
            if(mercado_compra[mercado_compra.size()-1].first == 0){
                mercado_compra.pop_back();
                // tirar ele da lista
                break;
            }
            if(mercado_compra.size() == 0){
                // já tiramos todos os outros
                break;
            }
        }

        if(preco_dp < dp[mercado_at-1][0]){
            mercado_compra.push_back({mercado_at,pedidos_mer_at});
            dp[mercado_at][0] = preco_dp;
            dp[mercado_at][1] = gramas_dp;
        }
        
        // do ultimo mercado é maior que o novo mercado
        if(dp[mercado_at-1][0] < dp[mercado_at][0]){
            break;
        }
    }

    // dp[i] -> Melhor preço com i mercados;



}


// To apanhando, não posso guardar só o preço

//tenho que 