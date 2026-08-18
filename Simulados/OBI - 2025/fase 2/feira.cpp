#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
- meta ver lucro;
- T objetos -> 1 a T, 
- N estoque,
- Nem todos
*/

struct mais_b {int first; int second; 
    /*int operator<(mais_b& cont other){
        if(other.second == b.second) return other.first < b.first;
        return other.second < b.second; // retorna true se preço de a menos que de b

    }; // Não consegui configurar o operator */
};

vector<vector<int>> objetos; // [objeto][estoques (preço)] - 2° -> preço
vector<long long> sorted;

vector<mais_b> mais_baratos; // indice, preço. Para clientes indecisos

int comp(mais_b other, mais_b b){
    if(other.second == b.second) return other.first < b.first;
    return other.second < b.second;
}
vector<int> clientes;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Populando quantidade de objetos
    int T, N;
    cin >> N >> T;

    objetos.assign(T+1, {}); // vazio no começo
    sorted.assign(T+1,-1); // -1 = não sorted, 0 = sorted nenhum comprado, 1 quer dizer primeiro comprado

    vector<int> tipos(N,0); vector<int> precos(N,0);
    for(int i=0; i<N;i++){
        int t_at; cin >> t_at;
        tipos[i] = t_at;
    }
    for(int i=0; i<N;i++){
        int p_at; cin >> p_at;
        precos[i] = p_at;
    }
    
    
    int C; cin >> C; // compra no max 1 objeto

    long long primeiro_mais_barato = 0;
    long long total_gasto = 0;

    for(int i=0; i<C; i++){
        int cliente_at; cin >> cliente_at;
        clientes.push_back(cliente_at);
    }
    //cout << "montando matrix e lista mais baratos" << endl;
    for(int i=0; i<tipos.size(); i++){
        mais_b elemento;
        elemento.first=tipos[i];
        elemento.second=precos[i];
        //cout << "printando elemento " << i << " Tipo e preço " << elemento.first << " " << elemento.second << endl;
        mais_baratos.push_back(elemento);
        objetos[tipos[i]].push_back(precos[i]);
    }

    //cout << "matrix e lista mais baratos montados " << endl;


    // podia ter usado uma priority_queue, também
   
    sort(mais_baratos.begin(),mais_baratos.end(), comp);
    //cout << "começando sort matrix "<< endl;
    for(int i=1; i<T+1; i++){
        // se não estiver vazio
        if(objetos.empty()) continue;
        if(1 < objetos[i].size()) {
            sort(objetos[i].begin(), objetos[i].end()); 
        } 
        sorted[i] = 0;
    }
    //cout << "sort mais_baratos e matrix" << endl;


    for(int cliente_at : clientes){
        // Se decidido -> Já sabe o tipo desejado, se não tiver no estoque vai embora. Se tiver compra o mais barato - fazer um sort,
        if(cliente_at != 0 ){
            // Se tiver o objeto e não tiverem comprado ele
            cout << "iniciando cliente deciso " << endl;
            if(!objetos[cliente_at].empty() && sorted[cliente_at] < objetos[cliente_at].size()){
                total_gasto+= objetos[cliente_at][sorted[cliente_at]];
                sorted[cliente_at]++;
                cout << "comprou item " << cliente_at << " total gasto= " << total_gasto << endl;
                continue;
            }
            continue;
        }
        // Se indeciso; Ao visitar a loja compra + barato - não preciso do if(cliente_at == 0)

        cout << "iniciando cliente indeciso " << endl;

        if(primeiro_mais_barato >= mais_baratos.size()) break;
        int indice_obj_mais_b = mais_baratos[primeiro_mais_barato].first;
        int preco_obj_mais_b =  mais_baratos[primeiro_mais_barato].second;

        // enquanto lista de mais barato estiver desatualizada
        while(
            // Verificar se ainda tem na matrix, se não pop na posição e dar outro
            objetos[indice_obj_mais_b][sorted[indice_obj_mais_b]] != preco_obj_mais_b){
                if(primeiro_mais_barato >= mais_baratos.size()) break;
                primeiro_mais_barato++;
                indice_obj_mais_b = mais_baratos[primeiro_mais_barato].first;
                preco_obj_mais_b = mais_baratos[primeiro_mais_barato].second;
            }
        // Passou logo achou o novo mais barato;
        if(primeiro_mais_barato >= mais_baratos.size()) break;
        total_gasto+= preco_obj_mais_b;
        sorted[indice_obj_mais_b]++;
        primeiro_mais_barato++;

        cout << "comprou item " << indice_obj_mais_b << " total gasto= " << total_gasto << endl;
    }
    

    cout << total_gasto << endl;

    
}

// Gastei bastante tempo já aqui 30 minutos, vou
// não terminei ta dando erro