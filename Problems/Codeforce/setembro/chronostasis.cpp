#include <bits/stdc++.h>
using namespace std;

// Problema: https://codeforces.com/problemset/problem/2254/E

// Solução: Não estudei a solução - https://chatgpt.com/c/6aa17053-c520-83e9-87fe-e0a5687a894a

// Não consegui resolver

/*
array a, lenth n. só positivo
*/

// criaram array b:
/* b1 = a1; para cada i de 2 a n. bi = a_i - a_i-1;
b_i + a_i-1 = a_i
b_2 + 0 = a_2
*/
/* - apartir de b, descubra a

b só pode começar a ser negativo se
b_2 + b_1 > 0 
*/

bool comp(int a, int b){
    // Não pode ter negativo, no começo
    if(a<0) {
        if(b<a) return false;
        else return true;
    }
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int t_i=0; t_i<t;t++){
        int N; cin >> N; 
        bool tem_pos = false;
        vector<int> arr(N,0);

        for(int i=0; i<N;i++){
            cin >> arr[i];
            if(arr[i] > 0) tem_pos=true;
        }

        if(!tem_pos) {
            cout << -1 << endl; continue;
        }
        sort(arr.begin(), arr.end(), comp);

        vector<int> arr_a(N,0);
        cout << "check first number: " << endl;
        arr_a[0] = arr[0];
        cout << arr[0];

        for(int i = 1; i<N; i++){
            arr_a[i] = arr_a[i-1] + arr[i];
            /*if (arr_a[i]<1){
                cout << -1 << endl;
                continue;
            }*/
        }
        cout << "answer: " << endl;
        
        for(int i=0; i<N; i++){
            cout << arr_a[i] << " ";
        }
        cout << endl;
    }

}