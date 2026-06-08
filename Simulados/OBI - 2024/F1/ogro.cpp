#include <iostream>
#include <vector>
using namespace std;

int main(){
    int e;
    int d;
    cin >> e;
    cin >> d;
    // se o número de dedos na mão esquerda é maior do que o número de dedos na mão direita (ou seja E > D) então o resultado é a soma dos dois números (ou seja E + D);
    if (e>d){
        cout << e+d << endl;
    } else{
        cout << 2*(d-e) << endl;
    }

    return 0;
    // caso contrário, o resultado é o dobro da diferença entre o número de dedos na mão direita e o número de dedos na mão esquerda (ou seja, 2 × (D − E)).


}