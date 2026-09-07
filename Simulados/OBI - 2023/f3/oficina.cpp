#include <bits/stdc++.h>
using namespace std;

/*
    - Distribuir os carros a serem consertados entre os mecânicos de modo a garantir alta satisfação dos clientes.

    tempo de conserto = T; 
    fator trabalho F - tempo demora para completar uma unidade de trabalho.

    logo para o mecanico j coserta o carro i em Ti * Fj
*/

priority_queue<int, vector<int>, greater<int>> t_carros;

/*
inicia vazia
*/

struct mecanico{
    // nem preciso do indice
    int indice_mec; int f_mecanico; 
    int tamanho_fila_at=0;

    bool operator<(const mecanico& other) const{
        if(other.tamanho_fila_at == tamanho_fila_at){
            return f_mecanico > other.f_mecanico;
        }else{
            return tamanho_fila_at < other.tamanho_fila_at;
        }
    }
    bool operator>(const mecanico& other) const{
        if(other.tamanho_fila_at == tamanho_fila_at){
            return f_mecanico < other.f_mecanico;
        }else{
            return tamanho_fila_at > other.tamanho_fila_at;
        }
    }
};

priority_queue<mecanico, vector<mecanico>, greater<mecanico>> pq_fila;


int sum_tempo_espera = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    N = Numero de carros na fila
    M = numero de mecanicos;
    */
    int N, M; cin >> N >> M;

    for(int i=0; i<N; i++){
        int car_at;
        cin >> car_at;
        t_carros.push(car_at);
    }
    for(int i=0; i<M;i++){
        mecanico mecanico_at; mecanico_at.indice_mec=i;
        cin >> mecanico_at.f_mecanico;
        pq_fila.push(mecanico_at);
    }

    // Os mais lentos ficaram por ultimo;

    // priority_queue() com indice do mecanico para seleção nova posição fila. 
    // priority_queue() com trabalho carro;

    for(int i=0; i<M; i++){
        //adicionando na fila os indices com os trabalhadores mais rápidos:


    }

    while(!t_carros.empty()){
        
        int carro_at = t_carros.top();t_carros.pop();
        // colocando novo carro na fila de um mecanico; somando tempo de espera dele atual; mudando tempo de espera dele proximo carro; recolocando ele na priority_queue;
        auto mecanico_at = pq_fila.top(); pq_fila.pop();

        sum_tempo_espera += mecanico_at.tamanho_fila_at;
        mecanico_at.tamanho_fila_at += carro_at * mecanico_at.f_mecanico;

        pq_fila.push(mecanico_at);

    }

    cout << sum_tempo_espera << endl;

}

/*
    Ficou excelente o código - 100% nos exemplos.
    foi uns ~25 minutos
*/