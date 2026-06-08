#include <iostream>
#include <vector>
using namespace std;

//https://neps.academy/br/competition/1574/exercise/2273


int main(){
    int N; // Amigos

    // Emprestou A, e pegou B;
    // Quer saber quantia total que ira pagar e total que ira receber

    cin >> N;
    int A,B;
    int sum_A;
    int sum_B;
    for(int i=0; i<N; i++){
        cin >> A;
        sum_A += A;
    }
    for(int i=0; i<N; i++){
        cin >> B;
        sum_B+= B;
    }

    cout << A << " " << B << endl;
    return 0;
}