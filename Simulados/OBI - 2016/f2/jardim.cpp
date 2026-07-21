#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 100% - demorei bastante 1 hora e 8 minutos
/*
    Pinheiro;
    O ângulo 6 P2P1P3 é agudo (vértice em P1);
    Os segmentos P1P2 e P1P3 têm o mesmo comprimento;
• Os pontos P2, P3, P4 e P5 são colineares;
• Os pontos médios dos segmentos P2P3 e P4P5 são coincidentes;
• O segmento P2P3 tem comprimento maior que o segmento P4P5;
• Os segmentos P4P6 e P5P7 são perpendiculares ao segmento P2P3;
• Os segmentos P4P6 e P5P7 têm o mesmo comprimento;
• Os pontos P1 e P6 devem estar separados pela reta que contém o segmento P2P3. Formalmente,
o segmento P1P6 deve interceptar a reta que contém o segmento P2P3 em um único ponto.

*/

struct coord{int x;int y;};

bool tresPontosColineares(coord p1, coord p2, coord p3) {
    return (p1.x * (p2.y - p3.y) + 
            p2.x * (p3.y - p1.y) + 
            p3.x * (p1.y - p2.y)) == 0;
}

bool quatroPontosColineares(coord p1, coord p2, coord p3, coord p4) {
    // Caso a area dos quatro pontos seja == 0
    return tresPontosColineares(p1, p2, p3) && tresPontosColineares(p1, p2, p4);
}

int main(){
    vector<coord> pontos;
    char resposta = 'S';
    for(int i=0; i<7;i++){
        coord ponto_at;
        cin >> ponto_at.x >> ponto_at.y;

        pontos.push_back(ponto_at);
    }
    // cout << "cadastrados no vetor" << endl;
    // funciona
    // verificação se angulo P2P1P3 é agudo, agudo = menor que 90 graus

    vector<int> tam {6,0}; // 0 = P1P2, 1 = P1P3, 2 = P2P3, 3 = P4P5, 4 = P4P6, 5 = P5P7
    tam[0] = pow((pontos[0].x - pontos[1].x),2) + pow((pontos[0].y - pontos[1].y),2);
    tam[1] = pow((pontos[0].x - pontos[2].x),2) + pow((pontos[0].y - pontos[2].y),2);
    tam[2] = pow((pontos[1].x - pontos[2].x),2) + pow((pontos[1].y - pontos[2].y),2);
    tam[3]= pow((pontos[3].x - pontos[4].x),2) + pow((pontos[3].y - pontos[4].y),2);
    tam[4]= pow((pontos[3].x - pontos[5].x),2) + pow((pontos[3].y - pontos[5].y),2);

    //cout << "primeiras distancias cadastradas" << endl;
    
    // se pow(tam[2],2) > pow(tam[1]) + pow(tam[0])
    if(tam[2] >= tam[1] + tam[0]){
        // angulo em P1 n é agudo, pois P2P3 é maior ou igual ao que seria se angulo fosse 90° 
        //cout << "1" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    } 
    if (tam[0] != tam[1]){
        //cout << "2" << endl;
        // P1P2 != P1P3
        resposta = 'N';
        cout << resposta;
        return 0;
    }
    
    if((pontos[1].x + pontos[2].x)/2 != (pontos[1].x + pontos[2].x)/2 || (pontos[1].y + pontos[2].y)/2 != (pontos[1].y + pontos[2].y)/2){
        
        //cout << "4" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }

    if(tam[2] <= tam[3]){
        
        //cout << "5" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }
    int P2P4 = pow((pontos[1].x - pontos[3].x),2) + pow((pontos[1].y - pontos[3].y),2);
    int P5P3 = pow((pontos[4].x - pontos[2].x),2) + pow((pontos[4].y - pontos[2].y),2);
    int P4P6 = pow((pontos[3].x - pontos[5].x),2) + pow((pontos[3].y - pontos[5].y),2);
    int P5P7 = pow((pontos[4].x - pontos[6].x),2) + pow((pontos[4].y - pontos[6].y),2);
    //hipotenusas
    int P3P7 = pow((pontos[2].x - pontos[6].x),2) + pow((pontos[2].y - pontos[6].y),2);
    int P2P6 = pow((pontos[1].x - pontos[5].x),2) + pow((pontos[1].y - pontos[5].y),2);
    // P3P7 != && P2P6 !=
    if(P3P7 != P5P3 + P5P7 || P2P6 != P2P4 + P4P6){
        //cout << "6" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }

    if(P4P6 != P5P7){
        //cout << "7" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }

    if(!quatroPontosColineares(pontos[1], pontos[2], pontos[3],pontos[4])){
        //cout << "3" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }
    // Se todas as regras acimas forem aceitas, eu acho que a ultima regra é também
    int P1P6 = pow((pontos[0].x - pontos[5].x),2) + pow((pontos[0].y - pontos[5].y),2);
    int P1P4 = pow((pontos[0].x - pontos[3].x),2) + pow((pontos[0].y - pontos[3].y),2);
    // ultima regra impede que o pinheiro seja tipo uma ponta de flecha
    // P6P7 sempre deve estar mais distante que P4P5 do ponto 1
    if(P1P6 <= P1P4){
        //cout << "8" << endl;
        resposta = 'N';
        cout << resposta;
        return 0;
    }
    cout << resposta;
    return 0;
    
    
}

// Proxima vez criar funções