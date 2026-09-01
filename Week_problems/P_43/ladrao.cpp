#include <bits/stdc++.h>
using namespace std;

/*
- Pedro 

- N nós, cada nó com fruta de valor V1
- Caminho simples

Arvore magica -> muda valor dependendo do caminho
Val = u1 até um, sum (-1)^i+1 x Vui
i par -> * -1
i impar -> * 1
*/

/*
Caminho diferente: se vertice inicial != ou vertice final !=

*/

vector<int> valor_vertices;
vector<vector<int>> mat_adj_verti;

long long sum_val = 0;

int val(vector<int> path){

    // calculo valor:
    long long valor = 0;
    
    for(int n=0; n<path.size(); n++){
        int mult = (n%2 == 0) ? -1:1;

        valor += mult * valor_vertices[path[n]];
    }
    // sum_valor: 

    sum_val += valor;

    cout << sum_val << endl << "valor adicionado = " << valor << endl;
    return 0;
}

vector<int> mat_vis;

// int a = vertice inicial
void DFS(int a, vector<int> vis, vector<int> path){
    cout << "iniciando DFS em " << a << endl;
    vis[a] = 1;

    for(int i : mat_adj_verti[a]){
        if(vis[i] == 0){
            // inexplorado
            cout << "adicionando no path o " << i << endl;
            path.push_back(i);
            cout << "fazendo val do path_at, sum_valor at = " << endl;
            val(path);
            DFS(i, vis, path);
        }
    }

    vis[a] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    valor_vertices.assign(N,0);
    mat_adj_verti.assign(N, {});
    mat_vis.assign(N,0);

    for(int i=0; i< N; i++){
        cin >> valor_vertices[i];
    }

    for(int i=0; i<N-1;i++){

        int u, v; cin >> u >> v;
        u--; v--;

        // matrix bidirecionada
        mat_adj_verti[u].push_back(v);
        mat_adj_verti[v].push_back(u);

    }

    for(int i=0;i<N;i++){
        vector<int> path_ini;
        path_ini.push_back(i);
        cout << "começando novo caminho em: " << i << endl;
        val(path_ini);
        DFS(i, mat_vis, path_ini);
    }

    cout << sum_val << endl;
}

// Ta dando algum erro que não to conseguindo resolver

