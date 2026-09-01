#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> lista_letra_maiscula(26,0);
vector<int> lista_letra_minuscula(26,0);
vector<int> lista_digitos(9,0);
vector<int> simbolos_especiais(6,0);

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    // 26 letras maisculas, 26 minusculas, 10 digitos, 4 operadores, 1 hashtag e 1 ponto(!)

    // Dois alienigenas se comunicam usando um alfabeto diferente
    
    // input: caracteres permitidos no alfabeto deles
    
    // Possivel estratégia: Usar o sistema de valores para letras e fazer um binary search para quando for uma letra.

    // Pegando os valores
    //cout << int('1') << endl;
    //cout << int('9') << endl;
    
    int K, N;
    cin >> K >> N;

    for(int i=0; i<K; i++){
        char char_at; cin >> char_at;
        int valor_char_at = int(char_at);
        if(97 <= valor_char_at && valor_char_at <= 122){    
            // Letra minuscula 
            valor_char_at -= int('a');
            lista_letra_minuscula[valor_char_at] = (lista_letra_minuscula[valor_char_at] != 1) ? 1:0;
            continue; 
        }
        else if(65 <= valor_char_at && valor_char_at <= 90){
            // Letra maiscula 
            valor_char_at -= int('A');
            lista_letra_maiscula[valor_char_at] = (lista_letra_maiscula[valor_char_at] != 1) ? 1:0;     
            continue; 
        }
        else if(49 <= valor_char_at && valor_char_at <= 57){
            valor_char_at -= int('1');
            lista_digitos[valor_char_at] = (lista_digitos[valor_char_at] != 1) ? 1:0; 
            continue;   
        }
        // Simbolos especiais
        else if(valor_char_at == int('+')){
            simbolos_especiais[0] = (simbolos_especiais[0] != 1) ? 1:0; 
            continue; 
        } else if(valor_char_at == int('-')){
            simbolos_especiais[1] = (simbolos_especiais[1] != 1) ? 1:0; 
            continue; 
        }  else if(valor_char_at == int('*')){
            simbolos_especiais[2] = (simbolos_especiais[2] != 1) ? 1:0; 
            continue; 
        } else if(valor_char_at == int('/')){
            simbolos_especiais[3] = (simbolos_especiais[3] != 1) ? 1:0; 
            continue; 
        } else if(valor_char_at == int('#')){
            simbolos_especiais[4] = (simbolos_especiais[4] != 1) ? 1:0; 
            continue; 
        } else if(valor_char_at == int('!')){
            simbolos_especiais[5] = (simbolos_especiais[5] != 1) ? 1:0; 
            continue; 
        }
    }

    // loop testando letra a letra, um vector que lembra se tal letra é permitida, 
    // 3 casos:
    // 1 - Letra

    // 2 - Hashtag ou ponto

    // 3 - Digito/numero

    string mensagem; cin >> mensagem;
    for(int i=0; i<N;i++){
        int valor_char_mes = int(mensagem[i]);
        // testando os casos
        if(97 <= valor_char_mes && valor_char_mes <= 122){
            if(lista_letra_minuscula[valor_char_mes - int('a')] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }
        }
        else if(65 <= valor_char_mes && valor_char_mes <= 90){
            if(lista_letra_maiscula[valor_char_mes - int('A')] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }
        }
        else if(49 <= valor_char_mes && valor_char_mes <= 57){
            if(lista_digitos[valor_char_mes - int('1')] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }   
        }
        // Simbolos especiais
        else if(valor_char_mes == int('+')){
            if(simbolos_especiais[0] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }  
        } else if(valor_char_mes == int('-')){
            if(simbolos_especiais[1] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            } 
        }  else if(valor_char_mes == int('*')){
            if(simbolos_especiais[2] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            } 
        } else if(valor_char_mes == int('/')){
            if(simbolos_especiais[3] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }
        } else if(valor_char_mes == int('#')){
            if(simbolos_especiais[4] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }
        } else if(valor_char_mes == int('!')){
            if(simbolos_especiais[5] == 1) continue; else{
                cout << 'N' << endl;
                return 0;
            }
        }
    }

    cout << 'S' << endl;
    return 0;

    

    // output: sim ou não

    
}

// Bem easy também

// Seguir ordem da prova, demorei 50 minutos para abstrair todas as soluções sendo 20 somente na ultima

// 100% nos exemplos