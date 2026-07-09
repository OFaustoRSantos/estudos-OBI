#include <iostream>
#include <vector>
using namespace std;
vector<int> fila;

// erro não sei oque deu;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i< N; i++){
        int A_n;
        cin >> A_n;
        fila.push_back(A_n);
    }

    /*
    // Operação T=0, 
    Novo competidor, de altura X, atrás do competidor i
    // Operação T=1,
    Determinar a pessoa na posição mais proxima a frente de P com altura maior H_P + D
    */
    int Q;
    cin >> Q;
    for(int i =0; i<Q; i++){
        int T, I, X; // Onde X = altura na op 0, e D na opt 1;
        cin >> T >> I >> X;
        if (T==0){
            fila.insert(fila.begin()+I-1,X);

        } else if(T==1){
            int pos;
            for(int i=I-1; i>=0;i--){
                if(fila[i] >= X + fila[I-1]){
                    pos=i;
                    break;
                }
            }
            cout << pos << endl;
        }
    }
    return 0;
}