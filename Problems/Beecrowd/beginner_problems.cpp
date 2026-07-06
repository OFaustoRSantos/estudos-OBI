#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// 1000
int p_1000(){
    cout << "Hello World!" << endl;
    return 0;
}
int p_1001(){

    int Y, X = 0;
    cin >> Y >> X;
    cout << "X = " << X+Y << endl;
    return 0;
}
// 1002
int p_1002(){
    float n = 3.14159;
    float R = 0;
    cin >> R;
    float A = n * R * R ;
    
    cout << "A=" << fixed << setprecision(4) << A << endl;
    //setprecision is to set number of decimal houses
    return 0;
}
// 1003
int p_1003(){
    return 0;
}

// 1021
// to fix the decimal house we will need to include iomanip.
// Always include iostream, vector, algorithm, cmath, iomanip + using namespace std
void p_1021(){
    float N = 0;
    cin >> N;
    N = round(N * 100);
    // to control the number of decimal places we insert a 0 in both 100.0f , 1000.0f (3 digits), and we use one multiplying inside the paranthesis and other dividing
    int notas[6] = {0}; // começando 100 até 2
    int moedas[6] = {0}; // começando 1 até 0.05
    int resto = N;
    int n[6] = {10000,5000,2000,1000,500,200};
    int m[6] = {100, 50, 25, 10, 5, 1};
    
    cout << "NOTAS:\n";
    cout << fixed << setprecision(2);
    for (int i =0; i < 6; i++){
        notas[i] = resto/n[i];
        resto = resto%n[i];
        cout << notas[i] << " nota(s) de R$" << n[i]/100 << ".00\n";
    }
    
    cout << "MOEDAS:\n";
    for (int i =0; i < 6; i++){
        moedas[i] = resto/m[i];
        resto = resto%m[i];
        cout << moedas[i] << " moeda(s) de R$" << float(m[i])/100 << "\n";
    }


}

// 1042 - runtime error???
// use of & modifies the original value, without it we make a copy
void base_sort_1042(vector<int>& l){
    for(int j=0; j<l.size();j++){
        for(int i = 0; i < l.size() -1; i++){
            
            if( l[i] > l[i+1]){
                int temp = l[i+1];
                l[i+1] = l[i];
                l[i] = temp;
            }
            
        }
    }
    for(int i =0; i< l.size(); i++){
    cout << l[i]<< endl;}
    // or we could use the sort function from <algorithm> sort(list.begin(), list.end());
}

int p_1042(){
    int list_len = 3;
    vector<int> list(list_len);
    for(int i = 0; i < list_len; i++){
        cin >> list[i];
        cout << list[i] << endl;
    } // or I could used the push_back function

    cout << endl;

    base_sort_1042(list);

    return 0;
}
// p_1044

void p_1044(){
    int A,B = 0;
    cin >> A >> B;

    if (A > B){
        if( A%B == 0){
            cout << "Sao Multiplos" << endl;
        }
        else{ cout << "Nao sao Multiplos" << endl;}
    } else {
        if( B%A == 0){
            cout << "Sao Multiplos" << endl;
        }
        else{ cout << "Nao sao Multiplos" << endl;}
    }
}

// 1244

bool cmp_stable_1244(const string& a, const string& b) {
    return a.size() < b.size(); // ascending by length
}

int p_1244() {
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        // Split line into words
        // entender isso aqui
        vector<string> words;
        istringstream iss(line);
        string w;
        while (iss >> w) {
            words.push_back(w);
        }

        // Stable sort preserves original order for equal-length strings
        stable_sort(words.begin(), words.end(), cmp_stable_1244);

        // Print with spaces BETWEEN words (no trailing space)
        for (int j = 0; j < words.size(); j++) {
            if (j > 0) cout << " ";
            cout << words[j];
        }
        cout << "\n";
    }

    return 0;
}

// p_1661_err -> pois achei que distancia cada casa fosse igual 1
int p_1661_err(){
    vector<int> s_b;
    // each house is close one with other and one wine transport cost one work token
    int n; // # of inhabitants
    cin >> n;
    for (int i = 0; i < n; i++){
        int a = 0;
        cin >> a;
        s_b.push_back(a)

    }
    sort(s_b.begin(), s_b.end());
    int work = 0;
    int l_emp_pos = n - 1;
    for(int i =0; i < n; i++){
        if(s_b[i] != 0) {
            for(int j=l_emp_pos; j>0; j--){
                if(s_b[i] == s_b[j]) {
                    l_emp_pos = j;
                    work++;
                    s_b[i] = 0;
                    s_b[j] = 0;
                    break;
                } else if (s_b[i] < s_b[j]){
                    work++;
                    s_b[j]-= s_b[i];
                    s_b[i] = 0;
                    break;
                } else{
                    work++;
                    s_b[i] -= s_b[j];
                    s_b[j] = 0;
                    l_emp_pos = j;
                    continue;
                }

            }
        }
        if (i == l_emp_pos){
            break;
        }
    }
    return 0;
}

// That can be easier using balance and the module of each one after a house we add to work

int main() {

    return 0;
}
