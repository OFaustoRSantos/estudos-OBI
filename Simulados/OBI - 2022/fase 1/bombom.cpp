#include <iostream>
#include <vector>
#include <string>
using namespace std;
// maybe ideal seria usar pair, ou vector, mas usarei struct

struct carta{string figura; string naipe;};
vector<carta> cartas;

int main(){
    string vencedor;
    carta carta_at;
    int Sum_v_l =0;
    int Sum_v_e =0;

    string answer;
    for(int i =0; i<7;i++){
        cin >> answer;
        carta_at.figura = answer[0];
        carta_at.naipe = answer[1];
        cartas.push_back(carta_at);
    } 
    // 1 = naipe dominante
    // 2,3,4 = Luana
    // 5,6,7 = cartas Edu


    string naipe_d = cartas[0].naipe;
    // cout << naipe_d;
    // somatório valores de Luana
    for(int i =0; i<3; i++){
        if (cartas[i+1].figura == "A"){
            Sum_v_l +=10;
        } else if (cartas[i+1].figura == "J"){
            Sum_v_l +=11;
        } else if (cartas[i+1].figura == "Q"){
            Sum_v_l +=12;
        } else {
            Sum_v_l +=13;
        }
        if(cartas[i+1].naipe == naipe_d){
            Sum_v_l += 4;
        }
    }
    // cout << " Valor Total: " << Sum_v_l;
    // Sum_V, Edu

    for(int i =0; i<3; i++){
        if (cartas[i+4].figura == "A"){
            Sum_v_e +=10;
        } else if (cartas[i+4].figura == "J"){
            Sum_v_e +=11;
        } else if (cartas[i+4].figura == "Q"){
            Sum_v_e +=12;
        } else {
            Sum_v_e +=13;
        }
        if(cartas[i+4].naipe == naipe_d){
            Sum_v_e += 4;
        }
    }
    // cout << " Valor Total: " << Sum_v_e;

    if(Sum_v_e > Sum_v_l){
        vencedor = "Edu";
    } else if (Sum_v_e < Sum_v_l){
        vencedor = "Luana";
    } else{
        vencedor = "empate";
    }

    cout << vencedor;
    return 0;
}
// 100% de acerto nos exemplos