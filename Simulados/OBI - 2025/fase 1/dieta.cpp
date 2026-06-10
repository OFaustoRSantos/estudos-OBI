#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// SBC
struct lasanha {int proteina;int carboidrato; int gordura;};
int cal_p[3] = {4,4,9};
vector<lasanha> lasanhas;

int main (){
    int M;
    int N;
    cin >> N >> M;
    int P,G,C;
    int calorias_consumidas;
    lasanha lasanha_at;
    for(int i = 0; i < N; i++){
        cin >> P >> G >> C;
        lasanha_at.proteina = P;
        lasanha_at.carboidrato = C;
        lasanha_at.gordura = G;
        lasanhas.push_back(lasanha_at);
        calorias_consumidas += P*cal_p[0] + C*cal_p[1] + G*cal_p[2];
    }

    cout << (M - calorias_consumidas);
    return 0;
}

// Não precisa nem do vetor, vou mandar um com vetor só para honrar meu esforço
// 100% com os exemplos;