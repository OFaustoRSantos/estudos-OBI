#include <iostream>
#include <vector>
using namespace std;

vector<int> ml_prefix;
int main(){
    int N, D;
    // quantidade de copos + quantidade pode tomar sem passar mal
    int prefix_at;
    int limit_drunked;
    // usar prefixo, ideia
    for(int i = 0; i < N; i++){
        cin >> prefix_at
        if(ml_prefix.size() != 0){
            prefix_at += ml_prefix[ml_prefix.size()-1];
            
        } 
        ml_prefix.push_back(prefix_at);
        
        if (prefix_at >= D){
            if (ml_prefix.size() -2 >= 0){
            limit_drunked = ml_prefix.size() -1;}
            else{
                limit_drunked = 0;
            }
        }

    }

    cout << limit_drunked << endl;
    return 0;
}