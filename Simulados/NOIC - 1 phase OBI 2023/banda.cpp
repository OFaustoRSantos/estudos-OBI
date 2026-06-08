#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct candidato{
    string instrumento;
    int habilidade;
}

vector<candidato> candidatos;

bool comp(candidato a, candidato b){
    if(a.instrumento == b.instrumento){    
        return a.habilidade < b.habilidade;
    }
    else{
        return a.instrumento < b.instrumento;
    }
}

int main(){
    int N,K;
    cin >> N >> K;

    int sum_skills;

    // para struct
    string inst;
    int i_N;
    candidato candidato_at;
    for(int i =0; i <  N; i++){
        cin >> inst >> i_N;
        candidato_at.instrumento = inst;
        candidato_at.habilidade = i_N;
        candidatos.push_back(candidato_at);
    }

    sort(candidatos.begin(), candidatos.end(), comp); // acredito que terei de fazer o sort duas vezes

    // teste usando cout, na prove deixar isso comentado
    for(int i =0; i <  N; i++){
        cout << "inst: " << candidatos[i].instrumento << "H: " << candidatos[i].habilidade << endl;
    }

    vector<int> pos_inst_diff;
    for(int i =0; i < N - 1; i++){
        if(candidatos[i].instrumento != candidatos[i+1].instrumento){
            pos_inst_diff.push_back(i+1);
        }
    }
    for(int j = 0; j < pos_inst_diff.size(); j++){
        for(int i =0; i<K; i++){
            if(i + pos_inst_diff[j] <= pos_inst_diff[j+1]){
                break;
            }
            else{
                sum_skills += candidatos[i + pos_inst_diff[j]].habilidade;
            }
        }
    }

    cout << sum_skills << endl;
    return 0;
}