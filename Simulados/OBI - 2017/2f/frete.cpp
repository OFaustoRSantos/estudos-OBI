#include <bits/stdc++.h>
using namespace std;

// Dijkstra
// BFS com glutão


struct estrada{int destino; int custo;
    bool operator>(const estrada& other) const {
        return this->custo > other.custo;
    }    
    bool operator<(const estrada& other) const {
        return this->custo < other.custo;
    }    
};

priority_queue<estrada, vector<estrada>, greater<estrada>> pq;

vector<vector<estrada>> adj_mat;
vector<int> m_distancias;
vector<int> m_ultima_cidade;


void dijkstra(){
    

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        int ultima_city = m_ultima_cidade[];

        if(m_distancias[ultima_city] + temp.custo < m_distancias[temp.destino]){
            m_distancias[temp.destino] = m_distancias[ultima_city] + temp.custo;
        } else{
            continue;
        }

    }

}

int main(){
    int N; // cidades
    cin >> N;
    adj_mat.assign(N,vector<estrada>({}));
    m_distancias.assign(N,99999999999999999);
    m_ultima_cidade.assign(N,0);
    m_distancias[0] = 0;
    m_ultima_cidade[0] = 0;
    int M; // estradas

    for(int i =0; i<M; i++){
        int A, B, distancia;
        cin >> A >> B >> distancia;
        estrada estrada_at;
        estrada_at.destino = B; estrada_at.custo = distancia;
        adj_mat[A].push_back(estrada_at);
        estrada_at.destino = A;
        adj_mat[B].push_back(estrada_at);
    }

    // cidade 1 até cidade N; 0 -> N-1
    
    dijkstra();

    cout << m_distancias[N-1] << endl;
}

// Não consegui fazer, uma loucura que estava a cada da minha vo nn conseguindo pensar