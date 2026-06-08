#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> contas;

    // receber valor de joão
    // valor de açougue, farmácia, padaria
    int money;
    int valor;
    cin >> money;
    
    for(int i = 0; i <3; i++){
        cin >> valor;
        contas.push_back(valor);
    }
    sort(contas.begin(), contas.end());
    // primeira solução faria sem interar, para ver se é mais rápido 
    int contas_pagas = 0;
    if(money > contas[0]){
        contas_pagas = 1;
        money -= contas[0];
        if(money > contas[1]){
            contas_pagas = 2;
            money -= contas[1];
            if(money > contas[2]){
                contas_pagas = 3;
                money -= contas[2];
            }
        }
    }
    // Solução 1.1 seria sem << endl e a 1.2 com o << end, pois não sei como ele corrigiria
    cout << contas_pagas;
    return 0;


    // mapa de soluções que devo fazer:
    // com sort do algorith:
    // 1- apresentada - feito
    // 2- com endl
    // 3 - sem endl + interação
    // 4 - com endl + interação
    // 5 - sem endl + sem vetor
    // 6- com endl + sem vetor
    // 7 - sem endl + interação + sem vetor
    // 8 - com endl + interação + sem vetor

    // com sort próprio
    // 9- apresentada
    // 10- com endl
    // 11- sem endl + interação
    // 12- com endl + interação
    // 13- sem endl + sem vetor
    // 14- com endl + sem vetor
    // 15- sem endl + interação + sem vetor
    // 16- com endl + interação + sem vetor
}
