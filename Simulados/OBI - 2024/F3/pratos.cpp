#include <bits/stdc++.h>
using namespace std;

/*
obter max qntd pratos

efeito = par (a,b)
a*pratos_atuais +b;

dois efeitos: 
feitições - S/ limite por feitiço, mas mana total gasta a cada feitiço
e 
refeições - Um uso cada, pode escolher ordem
*/



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K; cin >> N >> M >> K;

    vector<pair<int,int>> par_feitico(N,{0,0});
    vector<pair<int,int>> par_refeicao(M,{0,0});
    for(int i=0;i<N;i++){
        cin >> par_feitico[i].first;   
    }
    for(int i=0;i<N;i++){
        cin >> par_feitico[i].second;   
    }
    for(int i=0;i<M;i++){
        cin >> par_refeicao[i].first;   
    }
    for(int i=0;i<M;i++){
        cin >> par_refeicao[i].second;   
    }

    sort(par_feitico.begin(), par_feitico.end());
    sort(par_refeicao.begin(), par_refeicao.end());
    int Q; cin >> Q;

    for(int ops=0; ops<Q; ops++){
        int qtd_ini; cin >> qtd_ini;
        long long resultado = 0;

        long long pratos_at =qtd_ini;
        

        // valor_final, feitiço usado
        vector<pair<int,int>> turnos;
        int id_melhor_fe;

        for(int t=0; t<3; t++){
        // achar melhor turno 1,2,3 
            int id_melhor_fe;
            int valor_ini = qtd_ini;
            int max_valor_=0;
            for(int n_fe=0; n_fe<N; n_fe++){
                int valor_ = valor_ini*par_feitico[n_fe]. first + par_feitico[n_fe].second;

                if(max_valor_ < valor_){
                    max_valor_=valor_;
                    id_melhor_fe=n_fe;
                }
            }
            valor_ini = max_valor_;
            turnos.push_back({max_valor_, id_melhor_fe});
        }

        while(turnos[turnos.size()-1].second != turnos[turnos.size()-2].second && turnos[turnos.size()-2].second != turnos[turnos.size()-3].second){
            int id_melhor_fe;
            int max_valor_=turnos[turnos.size()-2].first;
            for(int n_fe=0; n_fe<N; n_fe++){
                int valor_ = turnos[turnos.size()-2].first*par_feitico[n_fe].first + par_feitico[n_fe].second;

                if(max_valor_ < valor_){
                    max_valor_=valor_;
                    id_melhor_fe=n_fe;
                }
            }
            turnos.push_back({max_valor_, id_melhor_fe});
        }
        int max_valor_ = turnos[turnos.size()-1].first;
        for(int ui=turnos.size(); ui<K;ui++){
            max_valor_ = max_valor_*par_feitico[id_melhor_fe]. first + par_feitico[id_melhor_fe].second;
        }

        // começando refeições

        // dp[n_primeiras_refeições][refeições usadas];

    }
    /* cout << (resultado) % (1e9+7) << end*/
}

// difícil