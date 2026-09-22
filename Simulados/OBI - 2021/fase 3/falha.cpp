#include <bits/stdc++.h>
using namespace std;

/*
Se usuario digitar uma cadeia de caracteres com um sub conjunto da senha correta, o sistema confunde acesso.

ou seja, enviando 
um senha xau
se tivermos ooxauoop; libera acesso
mas xa00u, não libera.
*/

/*
Quantos pares ordenados A,B de usuários distintos. onde A usando senha de A, consegue acesso a B
*/

bool comp (string a, string b){
    if(a.size() != b.size())
    return a.size() < b.size();
    else
    return a[0] < b[0];
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    /*
    Numero de usuários no sistema
    */
    int N; cin >> N; 


    /*
    senhas: contem apenas letras minusculas e digitos 0 a 9.
    */
    int n_pares=0;
    vector<string> usu_senhas(N, "");

    vector<int> pares_palavra(N,0);
    vector<int> memo(N,-1);
    // caso a palavra atual seja igual a uma palavra que passou antes, o numero de pares que a anterior pegou é igual o que essa pode também

    for(int i=0; i<N;i++){
        cin >> usu_senhas[i];
    }

    // um sort pelo tamanho da senha, pois as maiores só conseguiram acessar uma a outra se forem exatamente iguais.
    // acaba virando força bruta
    /*
    duas opções:
    1- ir do menor ao maior,
    2- ir do maior ao menor.
    a maior vai fazer um teste as menores que ela e se a menor estiver contida nela, ++ no valor 

    Queria fazer algo tipo
    t -> ta -> justa
    ou seja ta tem um, mas t tem dois pois t é ta + 1;
    */


    // Problema:
    sort(usu_senhas.begin(), usu_senhas.end(), comp);

    // cout << usu_senhas[0] << " " << usu_senhas[1]; - sort working
    // vou jogar força bruta, se não for eu vou adptar.

    for(int i=0; i<N; i++){
        // teste interativo:
        string palavra_at = usu_senhas[i];
        //cout << "testando palavra atual: " << palavra_at << endl;

        // memória, temos uma que já passou com valor igual - acelera muito
        if(memo[i] != -1){
            pares_palavra[i] = pares_palavra[memo[i]];
            n_pares+= pares_palavra[i];
            continue;
        }

        // Nunca vimos palavra antes
        for(int j=i+1; j<N;j++){
            
            string palavra_teste = usu_senhas[j];
            //cout << "| testando palavra teste: " << palavra_teste << endl;

            // se tamanho for igual: uma chance somente, ambas sendo iguais
            if(palavra_at.size() == palavra_teste.size()){
                if(palavra_at == palavra_teste){
                    // cout << "> Palavra teste = Palavra atual" << endl;
                    n_pares+=1; //pois i=>j vale e j=>i também
                    //cout << "-> n_pares: " << n_pares << endl;
                    pares_palavra[i]+=1;
                    memo[j]=i;
                }
                continue; // pula essa palavra
            }
            // tamanho de j nunca será > tamanho de i

            // loop dentro de J para ver o numero de digitos:
            int pont_em_p_teste=0;
            int pont_em_p_at=0;
            
            //cout << "| palavras diferentes testando se palavra at e contida em palavra teste " << endl;
            while(pont_em_p_teste<palavra_teste.size())
            {
                if(palavra_teste.size()-pont_em_p_teste +1 < palavra_at.size()-pont_em_p_at -1){
                    break;
                }
                // Stops adicionais = tentando resolver problema de memória na correção
                //if(pont_em_p_at == palavra_at.size()) break;
                //if(pont_em_p_teste == palavra_at.size()) break;

                char char_p_teste = palavra_teste[pont_em_p_teste];
                char char_p_at = palavra_at[pont_em_p_at];
                //cout << "testando caractere p_at com o p_teste" << char_p_at << " " << char_p_teste << endl;

                if(char_p_teste == char_p_at){
                    //cout << "| | caracteres sao iguais!" << endl;
                    if(pont_em_p_at == palavra_at.size()-1){
                        //cout << "acabou caracteres na p_at" << endl;
                        n_pares++; // i-> j funciona;
                        pares_palavra[i]++;
                        break;
                    }

                    // ainda temos caracteres

                    pont_em_p_at++; // testando proxima letra da p_at
                    pont_em_p_teste++; // testando proxima letra da p_teste

                    // Early stop, caso caracteres sobrando < caracteres faltando
                    //if(palavra_teste.size()-pont_em_p_teste+1 < palavra_at.size()-pont_em_p_at) break;
                    continue; // proxima letra
                }

                // Letra não bateu, voltar ponteiro caractere 1
                pont_em_p_at=0;
                char_p_at = palavra_at[pont_em_p_at];
                
                // caso da caractere que não bateu ser igual o 1° caractere da palavra at
                if(char_p_teste == char_p_at) pont_em_p_at++;

                pont_em_p_teste++;
                // early stop, numero caracteres sobrando < caracteres faltando
                //if(palavra_teste.size()-pont_em_p_teste +1 < palavra_at.size()-pont_em_p_at) break;
            }
        }
    }

    cout << n_pares << endl;
}

// começando exercício com 2h10 minutos de 4h30 de prova.
/*
- fiz 3 exercícios em 2h20, e tenho 2h10 ainda para os ultimos 2.
contando a meia hora a menos teria 2h40m na prova.

- levei 33 minutos para resolver - ainda dei um delay

Deu 100% nos exemplos, mas ta dando 0/100 no teste,
- compilação terminou um sucesso, mas a maioria está dando: Execução interrompida (provavelmente violação de limite de memória)

// to tentando mexer nela, mas nao ta indo direito.
O pior é que não esta dando time limite.
Agora ganhamos 10 pontos, nos outros não está mais dando limite de memória no máximo passa tempo limite

São 1h23; colocamos sistema de memória
Fui no banheiro e mexi em algumas coisas?
39 mins -> Pontuação atual 40/100

não temos mais erros tudo é agora exceção tempo limite.
porem está falando que o tempolimite permitido é 0.7 e o nosso tempo maximo usado é 0.194; Logo provvavelmente é um erro do site.
O limite real pelo que parece é 0.1 segundos;
Não acredito que consigo otimizar tudo para metade da complexidade;


*/

/* - forma de acelerar mas demoraria mais tempo:

em vez de olhar caracteres vamos literalmente procurar a palavra na outra:
se palavra A tem 2 caracteres e palavra b tem 3
dividir palavra b nos dois grupo de 2
b1b2, b2b3 e testar com a
ou seja dividir e testar.
Sem tempo agora - contando os 30 min a mais temos 1h 4 minutos.


*/