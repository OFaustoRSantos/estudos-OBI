#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ideia de grupos:
/*
se retangulo pertence a um outro retangulo, então ambos podem ser impactados por uma antena, logo precisamos ver o numero de grupos individuais de retangulos que temos
*/
/*
struct retangulo{ 
    int x1; int x2; int y1; int y2; int index_parent; 

    // Reaprender a fazer alteração no operator
    bool operator<=(
        (retangulo.x1-retangulo.x2)*(retangulo.x1-retangulo.x2) *(retangulo.y1-retangulo.y2)*(retangulo.y1-retangulo.y2) <=(x1-x2)*(x1-x2) *(y1-y2)*(y1-y2)
    );

}; // index_parent = imediatamente acima

// ideia:
/*
    Pintar uma matrix,
    // muito ineficiente; pense na ideia de flood fill


*/


// quero tipo desenhar um grafo direcionado maior para o menor, e o numero de antenas é igual o numero de caminhos
/*
int N; // Numero de salas
vector<vector<int>> matrix_adj;

int criar_tab_adj(){
    
    matrix_adj.assign(N,{});

    for(int i =0; i<retangulos.size(); i++){        
        for(int j=0; j<retangulos.size(); j++){

        }
    }
}
*/
/*
int main(){
    cin >> N;

    for(int i=0; i<N;i++){ 
        retangulo ret_at;
        cin >> ret_at.x1 >> ret_at.y1 >> ret_at.x2 >> ret_at.y2;
        //tenho as dimensões,
        retangulos.push_back(ret_at);
    }

    
}
*/

// Muito complexo meu raciocinio, ta errado, tentar pensar mais simples desde o começo. Refazendo:

// lógica atual
/*
Testar todos os retangulos se retangulo contem um retangulo então ignorar ele;
*/

struct retangulo{ 
    int x1; int x2; int y1; int y2; bool contem=false; 
};

int N;

vector<retangulo> retangulos;

bool check_se_retan_contem(retangulo ret_at, retangulo ret_obs){
    
    // Não precisava da variável contem

    if(!(min(ret_at.x1,ret_at.x2) <= min(ret_obs.x1,ret_obs.x2)))
        return false; 
    if(!(max(ret_at.x1,ret_at.x2) >= max(ret_obs.x1,ret_obs.x2)))
        return false; 
    if(!(min(ret_at.y1,ret_at.y2) <= min(ret_obs.y1,ret_obs.y2)))
        return false; 
    if(!(max(ret_at.y1,ret_at.y2) >= max(ret_obs.y1,ret_obs.y2)))
        return false; 
    
    return true;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int antenas=0;
    cin >> N;
    
    for(int i=0; i<N;i++){ 
        retangulo ret_at;
        cin >> ret_at.x1 >> ret_at.y1 >> ret_at.x2 >> ret_at.y2;
        //tenho as dimensões,
        retangulos.push_back(ret_at);
    }

    if(N == 1){
        cout << "1" << endl;
    }
    for(int i =0; i<retangulos.size(); i++){
        if(retangulos[i].contem){
            continue;
        }
        for(int j=0; j<retangulos.size(); j++){
            if(i == j){
                continue;
            }
            //cout << "testando ret " << i << "e ret " << j << endl;
            if(check_se_retan_contem(retangulos[j],retangulos[i])){
                retangulos[j].contem = true;
                
            }
            if(check_se_retan_contem(retangulos[i],retangulos[j])){
                retangulos[i].contem = true;
                break;
            }
        }
        if(!retangulos[i].contem){
            antenas++;
        }
    }

    cout << antenas << endl;
}

// Apanhei primeiro, mas depois de pensar mais simples

// dá certo, mas está estourando limite de tempo.

// terei de estudar solução

/*
Limite de tempo permitido	0,4 s
Limite de memória permitido	64.0 MB
Máximo tempo usado	0,195 s
Máxima memória usada	2.92 MB
Detalhes da correção
Execução dos testes
Subtarefa 10 / 20
#	Resultado	Detalhes	Tempo de execução	Memória usada
1	Correto	A saída está correta	0,001 seg	504.0 KB
2	Incorreto	A saída está errada	0,001 seg	504.0 KB
3	Correto	A saída está correta	0,001 seg	504.0 KB
4	Correto	A saída está correta	0,001 seg	504.0 KB
5	Correto	A saída está correta	0,001 seg	324.0 KB
6	Correto	A saída está correta	0,01 seg	504.0 KB
7	Correto	A saída está correta	0,01 seg	324.0 KB
8	Correto	A saída está correta	0,01 seg	324.0 KB
9	Incorreto	Excedeu o tempo limite de execução	0,195 seg	796.0 KB
10	Incorreto	Excedeu o tempo limite de execução	0,188 seg	796.0 KB
11	Correto	A saída está correta	0,007 seg	324.0 KB
Subtarefa 20 / 20
#	Resultado	Detalhes	Tempo de execução	Memória usada
1	Incorreto	Excedeu o tempo limite de execução	0,192 seg	1.12 MB
2	Incorreto	Excedeu o tempo limite de execução	0,19 seg	1.08 MB
3	Incorreto	Excedeu o tempo limite de execução	0,191 seg	1.29 MB
4	Incorreto	Excedeu o tempo limite de execução	0,194 seg	1.8 MB
5	Incorreto	Excedeu o tempo limite de execução	0,189 seg	1.11 MB
*/

/* Comentários chat*/

/*
Primeira tentativa

Você começou pensando em

grafo

Depois

árvore

Depois

flood fill

Depois

matriz

Isso é um sintoma clássico.

Você estava tentando encaixar um algoritmo conhecido.

Isso quase nunca funciona.

Primeiro vem a matemática.

Depois o algoritmo.


O segundo raciocínio foi MUITO melhor

Você escreveu:

"Vamos pensar mais simples"

Isso foi exatamente o que deveria fazer.

Depois chegou em

se um retângulo contém outro

Excelente.

A modelagem ficou correta.

PENSE PRIMEIRO EM COMO RESOLVER O PROBLEMA DEPOIS NO ALGORITIMO
*/

/*
A grande sacada do problema

Sem dar spoiler completo da solução.

Pergunte-se:

Você realmente precisa comparar

todo mundo

com

todo mundo?

Ou existe alguma forma de ordenar os retângulos?

Quando vejo

retângulos

na OBI imediatamente penso em

ordenar pelas bordas

ou

sweep line

ou

ordenar pela área

Não significa que a resposta seja exatamente essa.

Mas significa que provavelmente existe uma propriedade que elimina muitas comparações.

O que estudar depois desse problema

Esse problema mostra exatamente quais assuntos vão fazer diferença para você.

Muito importante

✅ Ordenação com múltiplas chaves

sort(v.begin(), v.end(), cmp);
Muito importante

Comparator customizado

bool cmp(...)
Muito importante

Sweep Line

Esse é provavelmente o assunto que mais aparece quando existem retângulos.

Muito importante

Intervalos

Principalmente:

contains
overlap
merge intervals
Muito importante

Greedy

Você ainda tenta usar grafos muito cedo.

Greedy resolve MUITOS problemas da Fase 2.

Minha avaliação da sua evolução

Comparando com as conversas que tivemos sobre BFS, Dijkstra e histogramas, vejo uma mudança clara.

Antes, você pensava quase exclusivamente em estruturas de dados:

"Será que isso é BFS?"

Agora você começa pela modelagem:

"Qual propriedade do problema posso explorar?"
*/