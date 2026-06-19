#include <iostream>
#include <vector>
using namespace std;

int p_1_gincana(){
    // times
    // cada aluno está somente em um time
    // se aluno amigo de outro ambos estão no mesmo time.

    // grafo onde cada parte dele é um time

    struct amigos{int ref; set<int> amigos;};

    vector<amigos> adjacencia;
    int N,M; 
    // N -> numero de alunos ; M -> listas de amizades
    int times = 0; // 1° coisa adicionar os que ficarão sozinhos - aqueles que não tenham uma amizade

    cin >> N >> M;
    
    for(int x=0; x < N; x++){
        int i, j;
        bool i, j = false;
        amigos new_amigo;
        cin >> i >> j;
        for(int y=0; y < adjacencia.size(); y++){
            if(adjacencia[y].ref == i){
                adjacencia[y].amigos.insert(j);
                i = true;
            }
            if(adjacencia[y].ref == j){
                adjacencia[y].amigos.insert(i);
                j = true;
            }
        }
        if(i == false){
            new_amigo.ref = i;
            new_amigo.amigos.insert(j);
            adjacencia.push_back(new_amigo);
        } else if (j == false){
            new_amigo.ref = j;
            new_amigo.amigos.insert(i);
            adjacencia.push_back(new_amigo);
        }
    }
    times += N - adjacencia.size(); // numero de times com pessoas sozinhas

    // calculo partes grafo
    vector<amigos> adjacencia_copy = adjacencia;
    while (adjacencia_copy.size() != 0){
        set<int> grupo_at;
        grupo_at.insert(adjacencia_copy[0].ref);
        search(pos_at, grupo_at, adjacencia_copy);
        times++;
    }

    return 0;
}

int search(int pos_at, set<int> &grupo_at, vector<amigos> &adjacencia_copy){
    int posi_vert = -1;
    for(int i=0; i < adjacencia_copy.size(); i++){
        if(adjacencia_copy[i].ref == pos_at){
            posi_vert = i;
            break;
        }
    }
    
    if(posi_vert == -1){
        return 0;
    }

    for(int j =0; j < adjacencia_copy[posi_vert].amigos.size(); j++){
        search(adjacencia_copy[posi_vert].amigos[j], grupo_at, adjacencia_copy);
        adjacencia_copy[posi_vert].amigos.delete(adjacencia_copy[posi_vert].amigos[j]); // apagando os vistos da lista de amigos
    }
    adjacencia_copy.erase(adjacencia_copy.begin() + posi_vert);
    return 0;
}

int main(){
    
    return 0;
}