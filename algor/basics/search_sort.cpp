#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// base sort using algo
bool cmp(int a, int b){
    return (a < b);
    // retorne true se a for menor que b e tiver que vir antes.
}
// a melhor função: struct >>>

// A lista tem que estar sorted
void binary_search(vector<int> list, int n_to_search){
    bool found = false;
    int i = list.size()/2;
    int ref = list.size()/2;
    int half = i;
    while (found == false){
        if(list[i] == n_to_search){
            found = true;
        }
        else if (list[i] < n_to_search){
            i += (list.size() -i)/2;
        } else {
            
        }
        
    }

}

int main(){

}