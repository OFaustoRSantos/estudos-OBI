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

