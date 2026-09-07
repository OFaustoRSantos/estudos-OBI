
#include <vector>
#include <iostream>
using namespace std;

// Class 0 
void hey_neps(){
    cout << "Olá Neps" << endl;
};

int avrg(){

    int val_1 = 0;
    int val_2 = 0;

    cin >> val_1 >> val_2;
    
    cout << (val_1 + val_2)/2 << endl;
    return (val_1 + val_2)/2;
}

int avrg_median(){
    // avrg = median
    int val_1 = 0;
    int val_2 = 0;
    // menor C possivel
    cin >> val_1 >> val_2;

    int val_3 = 0;
    // val_1, val_2 or val_3 = (val_1 + val_2 + val_3)/3

    if (val_1 > val_2){
        val_3 = 2 * val_2 - val_1;
    } else{
        val_3 = 2 * val_1 - val_2;
    }

    cout << val_3 << endl;
    return val_3;
}

int treasure(){

    int money = 0;  
    int n_mar = 0;

    cin >> money >> n_mar;

    int M_per_mar = money/(n_mar + 2);
    cout << M_per_mar*2 << endl;
    return M_per_mar*2;
}

int siblings(){
    // Oscar, Otavio, Orlando
    int Osc = 0;
    int Ot = 0;
    cin >> Osc >> Ot;

    cout << 2*Ot-Osc << endl;       

    return 2*Ot-Osc;
}

int part_accelera(){
    // 3 km = emissor always
    // 8 km in circle
    // D total
    int D = 0;
    cin >> D;

    int R = (D-3)%8 - 2;
    cout << R << endl;

    return R;
}

// Aula 1 - Estruturas condicionais
char Flip(){
    // A B C
    int R1, R2 = 0;
    cin >> R1 >> R2;
    string N;
    if (R1 == 0) {
        N = "C";
    }
    else {
        if(R2 == 0){
            N = "A";
        }
        else {
            N = "B";
        }
    }

    
    return N[0];
}
string Pos_N_0(){
    int X;
    cin >> X;
    if(X > 0){
        return "positivo";
    }
    else if (X < 0 ){
        return "negativo";
    }
    else{
        return "nulo";
    }
}
char bondinho(){
    int M, A = 0;
    cin >> M >> A;

    if ((A+M) <= 50){
        return 'S';
    } else{
        return 'N';
    }
}
string Par_Impar(){
    int A,B = 0;
    cin >> A >> B;
    if ((A+B)%2 == 0){
        return "Bino";
    }
    else{
        return "Cino";
    }
}

// Aula 2 - Loops

// farei somente dois exercicios da OBI antigassos
// 2007
int chocolate(){
    // sucessivas divisões
    // barra de 100g -> 3kg,divide no meio, e depois em 5 partes iguais e depois em 3 partes iguais
    
    int n_d = 0;
    cin >> n_d;
    int n_choco = 0;
    while (n_d!= 0){
        int corte;
        cin >> corte;
        n_choco += corte - 1;
        n_d--;
    }
    return n_choco;
}
// OBI 2015
int code(){
    int n_se = 0;
    cin >> n_se;

    if(n_se < 0){
        cout << "n_se needs to be positive" << endl;
        n_se = 0;
    }
    
    vector<int> seq(n_se);
    int at_pos = 0;
    int n_hun = 0;
    while (n_se != 0){
        cin >> seq[at_pos];

        if (at_pos >= 2){
            if(seq[at_pos-2] == 1 && seq[at_pos-1] == 0 && seq[at_pos] == 0){
                n_hun++;
            }
        }
        n_se--;
        at_pos++;
    }

    // or with for structure:
    /*
    for (int i = 0; i < n_se; i++) {
        cin >> seq[i];

        if (i >= 2 &&
            seq[i-2] == 1 &&
            seq[i-1] == 0 &&
            seq[i] == 0) {
            n_hun++;
        }
    }   
    */
    return n_hun;

}
// Aula 3 - Vetor

int campo_minado(){
    int tamanho = 0;
    cin >> tamanho;

    vector<int> tabuleiro(tamanho);
    for(int i = 0; i <tamanho; i++){
        cin >> tabuleiro[i]; 
    }
    vector<int> answer(tamanho);

    for(int i = 0; i < tamanho; i++){ 
        if (i==0){ // primeiro
            answer[i] = tabuleiro[i];

            if (tamanho > 1) {
                answer[i] += tabuleiro[i + 1];
            }
        }
        else if (i == tamanho - 1) { // ultimo
            answer[i] = tabuleiro[i] + tabuleiro[i - 1];
        }
        else{ // geral
            answer[i] = tabuleiro[i-1] + tabuleiro[i] + tabuleiro[i+1];
        }
        cout << answer[i] << endl;
    }
    return 0;
    
}
// bubble sort
// Carregar o ultimo elemento
void bubble_sort(vector<int> &list){
    int len_list = list.size();
    int temp = 0;
    // ponteiro 1 - mede quantos elementos estão 100% certos e ordenados no final
    for(int i = 0; i< len_list - 1; i++){
        // ponteiro 2 - vai carregando elementos até posição len_list - i - 1 (começando do 0)
        for (int j = 0; j < len_list - i - 1; j++){
            if(list[j] > list[j+1]){
                temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
                // usando #include <algorithm> podemos usar a função swap que faz o que as tres linhas acima fazem  swap(list[j], list[j + 1]); Mas o sort do stl tem O (n log n)
            }
        }
    }
    
}

// Usando função comp
bool comp_1(string a, string b){
    return (a.size() < b.size());
}
// forma mais eficiente, usando const string garantimos que não alteraremos o valor, mas aumentamos velocidade e reduzimos memoria por trabalhar com o original
bool comp_1(const string& a, const string& b){
    return a.size() < b.size();
    # ordem crescente
    // Fatorando para caso a seja == b
    if(a.size() != b.size())
        return a.size() < b.size();
    // Ordem alfabética
    return a < b;
}
// comp retorna true CASO o 1° apareça antes do segundo.
int large_value(vector<int> list){
    sort(list.begin(), list.end());
    return list[list.size() - 1];
}


int main(){
    // Aula 0:
    /*
    hey_neps();
    cout << "Média system: " << endl;
    avrg();
    cout << "treasure System: " << endl;
    treasure();
    cout << "siblings System: " << endl;
    siblings();
    */
    
    // Aula 1: 
    /*
    cout << Flip() << endl;
    
    cout << Pos_N_0() << endl;

    cout << bondinho() << endl;

    cout << Par_Impar() << endl;

    */
    // Aula 2:
    /*
    cout << chocolate() << endl;
    */
    
    return 0;
}