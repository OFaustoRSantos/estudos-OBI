#include <bits/stdc++.h>
using namespace std;

// Codigo interativo: uso do cout.flush
// Tutoria no caderno de codigo

/*
- win outros p/ escapar

- jogo começa com n
cada turno ocorre:
- jogador com p quebra em p1, e p2; onde nenhum dos dois é igual a zero e p1 (+) p2 = p ; onde (+) é a operação de XOR bitwise

- Se não existir p1, p2 valido, o jogador perde. (ou seja, p1,p2 maior que 0 e menor que p)

- Caso exista, o oponente escolhe p1 ou p2, e é o turno dele

*/

/*
- o jogo da a permissão para escolhermos se queremos começar ou não
- Sistema vai agir como Ortsac, temos 63 operações/lances.
*/

/*
- Tendo n:
-> XOR n: vai dar dois valores: p1 e p2;
se p1 ou p2 for invalido -> escolher second

-> se não escolher first:
enzo vai escolher p1 ou p2 que ao fazer o XOR seja valido
*/


/*
Lógica: Olhar o maior bit do P, definirmos como p1 e fazermos P ^ p1

// Se P tem somente um bit 1, então a solução não funciona

// Cada uma rodada tiramos um numero X de bit um do numero pois dividimos o numero de bits, então a ideia é ir selecionando ou o p que tem 

*/

int calculo_n_bits_1(int n){
    int n_bits_1 = 0;

    while (n != 0){
        if(n%2 ==1) n_bits_1++;
        n /=2;
    } 
    // outra forma usando bitwise
    /*
    while (n !=){
        if(n & 1) n_bits_1++;
        n>>=1; // Deslocar todos os bits em um
    
    }
    // Operadores legais:
    n & 1; // retorna 0 se 1° bit  == 0, e 1 se 1° bit == 1;
    n>>=1; // Deslocar todos os bits em um para direita, logo tira 1 bit;
    n<<=1; // Desloca todos os bits para esquerda, logo adiciona 1 bit 0;
    n=~n; // inverte todos os bits do tipo inteiro!
    | logo ~n = -n -1;
    */


    return n_bits_1;
}

pair<int,int> quebrar_n(int n_at){
    // caso numero tenha somente dois troços
    // escolher maior bit de n_at;


}

bool log_select(int n_ini){
    // true = primeiro; false = segundo
    // Caso um: XOR do primeiro já quebre regra; escolher segundo ( mais fácil )
    
    if(calculo_n_bits_1(n_ini) < 2){
        return false;
    }
    if(calculo_n_bits_1(n_ini) == 2){
        return true;
    }

}

void turno(int p_1, int p_2, int jogador_at){

    int n_p1, n_p2;
    if (jogador_at == 0){
        // Enzo;
        // calcular p com mais bits e escolher esse;
        // uma forma de sempre ganhar é dando dois valores que tenham somente um bit

        // if n° de bits de um dos p for = 2; escolher esse p

        int n_bits_1_p_1 = calculo_n_bits_1(p_1);
        int n_bits_1_p_2 = calculo_n_bits_1(p_2);
        
        if(n_bits_1_p_1 == 2) {
            // escolher esse
            // dividir em dois
        }
        if(n_bits_1_p_2 == 2) {

        }

        // Se n de bits for par:
    }
    else{
        // Osmar outro sistema

    }

    turno(n_p1, n_p2, (jogador_at++)%2);

}

void partidas(int n_ini, bool selecionado){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; // o numero de casos de teste

    for(int i=0; i<t; i++){
        int n; cin >> n; // numero que começa

        // logica seleção: começar em primeiro ou em segundo;
        bool selecionado = log_select(n);

        string escolha = (selecionado) ? "primeiro":"segundo";
        cout << escolha << endl;
        cout.flush();
    }

}


// Esse desafio é muito avançado para mim ainda, não faz sentido faze-lo para fase 3, eu acho, verificarei ;