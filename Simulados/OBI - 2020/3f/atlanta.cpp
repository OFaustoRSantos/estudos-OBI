#include <bits/stdc++.h>
using namespace std;

/*
Ladrilhos de 20x20cm
duas cores: brancos (centro), uma fileira de ladrilhos azuils em cada lateral;

dada quantidade de ladrilhos determinar proporção dimensões sala
*/

int A,B;
/*
void teste_multiplor(int meio, int par_minimo){
    //sabemos que 
    int area_interna=(par_minimo+1+meio)*(par_minimo-meio);
    // = a B
    int area_externa=(par_minimo+2)*(par_minimo+2);
    int qntd_A_expect= -area_interna;
    // logo temos que testar todos os multiplos dos pares;

}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // A = ladrilhos azuis, B = ladrilhos brancos
    cin >> A >> B;

    // azuis => dimensão branco + 2 cada - total ladrilhos brancos

    // Numero total de ladrilhos = A + B
    
    // 1° - achar dois numeros que multiplicados dão o numero B de ladrilhos

    // pares possíveis

    // Uma ideia que quero testar é um binary_search com um guloso.

    // se eu tenho B ladrilhos brancos, então calculamos numero de pares que dão B: se não houver pulamos;

    vector<int> pares;

    // a ideia de raiz de B vezes raiz de B = B, 
    int par_minimo = sqrt(B);

    //cout << par_minimo << endl;
    // exemplo com B = 12; raiz de 12 ~ 3
    // Testar variações entre par_minimo e o par_imediatamente acima
    // Se par minimo for = certo

    int par_acima = par_minimo+1;
    int area_interna;
    int area_externa;
    //cout << par_acima << endl;
    if(par_minimo*par_minimo==B){
        // econtramos já
        area_interna=par_minimo*par_minimo;
        area_externa=(par_minimo+2)*(par_minimo+2);
        if(area_externa - area_interna == A){
            // dois iguais
            cout << par_acima+1 << " " << par_acima+1 << endl;
            return 0;
        }
    }

    // no caso do 12, tem o 3*3 -Par minimo, e o 4*4 - par máximo;
    // teste um par_minimo * par_acima;

    if(par_minimo*par_acima == B){
        area_interna=par_minimo*par_acima;
        area_externa=(par_minimo+2)*(par_acima+2);
        if(area_externa - area_interna == A){
            // dois iguais
            cout << par_minimo+2  << " " << par_acima+2 << endl;
            return 0;
        }
    }

    // outros testes: (par_minimo+1+i)*(par_minimo-i);
    // ou seja 5x2, 6x1
    
    // Colocarei como binary search

    int esq=1;
    int dir=par_minimo-1;

    while(esq<dir){
        int meio = (esq+dir)/2;

        area_interna=(par_minimo+1+meio)*(par_minimo-meio);
        area_externa=(par_minimo+3+meio)*(par_minimo-meio+2);
        
        if(area_interna==B){
            if(
                area_externa - area_interna == A){
                // dois iguais
                cout << (par_minimo-meio+2) << " "  << (par_minimo+3+meio) << endl;
                return 0;
            }
            // é igual a B, mas não tem A certo
            //test_multiplos(meio,par_minimo);
            //break;

        }   
        if(area_interna > B || area_externa - area_interna > A){
            esq=meio+1;
        } else if(area_interna<B || area_externa - area_interna < A){
            dir=meio;
        }
    }

    // logo se for 10 brancos:
    // par minimo 3*3, par_acim 4*4, testa 4*3 -> 5*2 (encontrou)
    cout << -1 << " " << -1 << endl; 


    // saida
    // cout << menor_dimensão << maior_dimensão << endl;

}

/* - Não parece dificil, mas não to com uma ideia clara vou pular 13 minutos aqui
Terminei depois com ideia em 16 minutos
| tempo total 29 min

Resultado - teste:
10/100
Excedeu tempo de resposta

agora:
20/100
-> Agora tem alguns que dão resposta incorreta, ou limite de tempo

Agora: 20/100. ,as nenhum time limit
*/

/* - amtigo
    for(int i=1; i<par_minimo; i--){
        // encontrou: fazer teste com o numero de azuis para ver se bate.

        

        if(area_interna == B){
            if(
                area_externa - area_interna == A){
                // dois iguais
                cout << (par_minimo-i+2) << " "  << (par_minimo+3+i) << endl;
                return 0;
            }
        }   
        
    }
*/