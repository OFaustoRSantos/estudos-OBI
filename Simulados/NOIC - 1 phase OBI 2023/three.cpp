#include <iostream>
#include <vector>
#include <string>
using namespace std;

// violão piano bateria,
int main(){
    string Luca, Le, Luc;
    cin >> Luca >> Le >> Luc;

    if(Luca == Le || Le == Luc || Luca == Luc){
        cout << "N" << endl;
    } else{
        cout << "S" << endl;
    }
    return 0;
}