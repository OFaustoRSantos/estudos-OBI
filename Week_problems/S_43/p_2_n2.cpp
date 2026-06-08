#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Ladrão de frutas - N nós, cada nó possue fruta valor Vi
// Topico - grafo

// Caminho simples de Val(u1,um)
// preciso colocar o vertice, mas acredito que nn será tão necessário

vector<vector<int>> matrix; // já inicia tirando os garbage correto?
vector<int> vertices; // poderia por um par no vertice ou fazer de três dimensões, mas acredito muito trabalho

int val(vector<vector<int>> lista);


int main(){
    int N; cin >> N; // numero nós
    int V;
    for(int i=0; i<N; i++){ // setando valores dos vertices
        cin >> V;
        vertices.push_back(V);
    }

    for(int n=1; n<N;n++){ // criando tabela vizinhos
        int i,j;
        cin >> i >> j;
        matrix[i].push_back(j);
        matrix[j].push_back(i);
    }

    for(int n=0; n<matrix.size(); n++){

    }


    return 0;
}

int caminhos(){ // BFS
    

}

// val vai receber uma lista com pares vetor inicial vetor final!
int val(vector<vector<int>> lista){
    int sum; // pode ser double

    for(int i =1; i<=lista.size(); i++){
        sum += pow(-1,i+1) * matrix[lista[i][0]][lista[i][1]];
    }
    return sum;
}
// caminhos são diferentes caso começo for diferente, faz sentido pela formula acima
