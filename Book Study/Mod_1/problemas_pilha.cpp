#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


// Problema Validar se parenteses estão balanceados
int val_par(string parenteses){
    /*
    0 - False
    1 - True

    Checkagem por pilha, complexidade O(N);
    Check por:
    - presença de ) sem par antes do termino da string;
    - Check de quantidade de ( vazio

    */
    stack<int> pilha;
    bool balanced = true;

    for(int i =0; i< parenteses.size(); i++){
        if(parenteses[i] == '('){
            pilha.push(1);
        } else if (parenteses[i] == ')'){
            if(pilha.empty() == 0){ // se ainda tiver ( na pilha
                pilha.pop();
            } else{
                balanced = false; 
                break;
            }
        }

    }
    if(balanced == false){
        // se tiver um ) sem ( respectivo antes
        return 0; // retornar falso

    } else{
        // caso não verificando pelo tamanho da fila
        if (pilha.empty() == 0){
            return 0;
        } // false
        else{
            return 1;
        }
    }

}

// Problema via Gemini:
// Descrição do mesmo no docs do book
/*
Um único ponto (.) refere-se ao diretório atual (não faz nada).

Dois pontos consecutivos (..) referem-se ao diretório pai (move um nível para cima).

Qualquer sequência de múltiplas barras consecutivas (como //) é tratada como uma única barra /.

Qualquer outra sequência de caracteres é considerada um nome de diretório ou arquivo válido.
*/

string simplify_path_dir(string original_path){

    string saida = "/"; // usar push_back para adicionar
    char last_char = '/';
    // acredito que seja a forma mais fácil usando esse "carry"
    
    //stack<string> path;
    // eu não consegui resolver por pilha então usei vetor, rever correção mais tarde, pois no final preciso repassar o path do começo ao fim para criar o string
    vector<string> path;

    string palavra_atual;

    for(int i =0; i<original_path.size();i++){
        if(original_path[i] == '/' && last_char == '/'){
            // Nada acontece, duas / seguidas ignora a /
        } else if(original_path[i] == '.' && last_char == '/'){
            last_char == '.';
            // Mão adiciona nada, pois ta no dir atual
        }
        else if(original_path[i] == '.' && last_char == '.'){
            // temos que voltar uma casa
            path.pop_back();
        } else if(original_path[i] == '/' && last_char != '.'){
            // terminar palavra at e colocar na stack
            path.push_back(palavra_atual);
            palavra_atual.clear();
        }
        else{
            palavra_atual.push_back(original_path[i]);
        }
    }

    for(int i = 0; i < path.size();i++){
        saida += path[i];
        if(i != path.size() -1){
            saida.push_back('/');
        }
    }

    return saida;
}

int maior_ret_histo(){
    // Não soube resolver

    int N; // n de terrenos

    cin >> N;
    
    // cada terreno tem 1 metro de largura
    int area_max = 0;
    vector<int> alturas;
    for(int i=0;i<N;i++){
        int alt_at;
        cin >> alt_at;
        // para cada altura precisamos saber até onde ela vai cescer para direita, e até quanto vai crescer para esquerda
        alturas.push_back(alt_at);
    }
    // para cada barra, calcular:
    // primeiro menor a esqueda, primeiro menor a direita
    // calculo área, atualiza resposta
    // força bruta
    for(int i=0; i<N;i++){
        int area_at;
        int right = 0;
        int left = 0;

        int r_at = i; int l_at = i;
        while(right == 0){
            if(r_at == N-1){
                right = r_at;
            }
            if(alturas[r_at] > alturas[i]){
                r_at++;
            } else{
                right = r_at;
            }
        } while(left == 0){
            if(l_at == 0){
                left = l_at;
            }
            if(alturas[l_at] > alturas[i]){
                l_at--;
            } else{
                left = l_at;
            }
        }

        int largura = right - left - 1;
        area_at = largura * alturas[i];
        if (area_at > area_max){
            area_max = area_at;
        }
    }
    /*
    Em vez de perguntar
    "Para esta barra, qual é a primeira menor?"

    fazemos a pergunta inversa.
    "Esta barra acabou de encontrar a primeira menor de quem?"
    */

    //pseudo código
    /*
    pilha vazia

para i = 0 até N-1

    enquanto a pilha não estiver vazia
          e altura[topo] >= altura[i]

          barra = topo
          pop()

          direita = i

          esquerda = topo da pilha
                     (ou -1 se vazia)

          calcula área

    push(i)
    */

    long long areaMax = 0;
    stack<int> pilha;

    for (int i = 0; i < N; i++) {

        // Enquanto a barra atual é menor que a do topo
        while (!pilha.empty() && alturas[pilha.top()] > alturas[i]) {

            int indice = pilha.top();
            pilha.pop();

            long long altura = alturas[indice];

           // A barra atual foi quem interrompeu
            // o crescimento.
            int direita = i;

            // Depois do pop:
            //
            // topo ---> primeira menor esquerda
            //
            int esquerda;

            if (pilha.empty())
                esquerda = -1;
            else
                esquerda = pilha.top();

            //-----------------------------------
            // Calcula largura
            //-----------------------------------

            int largura = direita - esquerda - 1;

            //-----------------------------------
            // Área
            //-----------------------------------

            long long area = altura * largura;

            areaMax = max(areaMax, area);
        }

        //-----------------------------------
        // Empilha a barra atual
        //-----------------------------------

        pilha.push(i);
    }

    //-----------------------------------
    // Barras que nunca encontraram uma
    // menor à direita.
    //-----------------------------------

    while (!pilha.empty()) {

        int indice = pilha.top();
        pilha.pop();

        long long altura = alturas[indice];

        int direita = N;

        int esquerda;

        if (pilha.empty())
            esquerda = -1;
        else
            esquerda = pilha.top();

        int largura = direita - esquerda - 1;

        long long area = altura * largura;

        areaMax = max(areaMax, area);
    }

    cout << areaMax << endl;
    
}
