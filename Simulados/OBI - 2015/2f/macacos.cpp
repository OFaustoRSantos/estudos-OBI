#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// errado não sei porque.

struct tree{int position; int height;};
vector<tree> trees;

bool comp(tree a, tree b){ 
    return a.position < b.position;
}
// retorna true se a é antes de b, logo acima está correto.

int main(){
    int N; // arvores alinhadas
    cin >> N;
    tree new_tree;  
    for(int i = 0; i< N; i++){
        cin >> new_tree.position;
        cin >> new_tree.height;
        
        trees.push_back(new_tree);
   }
    // sort
    sort(trees.begin(), trees.end(), comp);
    // sort está correto
    // menor quantidade de pulos que OBI deve dar para ir da primeira até a ultima arvore
    int actual_tree = 0;
    int jumps = 0;
    int jump_dist=1;
    int max_jump = 0;
    bool pulavel = true;
    bool reach_end = false;
    while(!reach_end){
        cout << "At: " << actual_tree << "Jump_dist_at= " << jump_dist << endl;
        if(actual_tree == (trees.size()-1)){
            reach_end = true;
        } else if (actual_tree + jump_dist > (trees.size()-1)){
            jumps++;
            reach_end = true;
            break;
        }
        for(int i=1; i < jump_dist; i++){
            cout << "teste usando i = " << i << endl;
            cout << trees[actual_tree].height << trees[actual_tree+i].height;

            if(trees[actual_tree].height <= trees[actual_tree+jump_dist].height){
                if((trees[actual_tree+i].height - trees[actual_tree].height)/i <= (trees[actual_tree+jump_dist].height - trees[actual_tree].height)/jump_dist){
                    
                } else {
                    pulavel = false;
                    break;
                }
            } else{
                if((trees[actual_tree+i].height - trees[actual_tree].height)/i >= (trees[actual_tree].height - trees[actual_tree+jump_dist].height)/jump_dist){
                    
                } else {
                    pulavel = false;
                    break;
                }
            }
        }
        
        if (pulavel == true){
            jump_dist++;
        }
        else {
            max_jump = jump_dist--;
            actual_tree += max_jump;
            jump_dist = 1;
            jumps++;
            pulavel = true;
        }

    }

    cout << jumps;
    // enquanto cos de todos x até o i for menor que que cos 0 arvore até < x; ele consegue pular para X+1
    
    // quando x+1 > x, temos dois pulos -> para x e depois para x+1 e recomeçamos em x+1
    // int jump_dist = 0;

    

    return 0;
}

/*
Passo 1: Restrição para ação pulo

Identifiquei bem, mas o ideal em competições de informatica é não dividir, logo o ideal seria fazer a multiplicação matemática

Passo 2: Entender se fazer um algoritimo guloso vale a pena e resolve o problema:

Você consegue construir um exemplo onde:

o maior pulo possível leva a uma solução pior;
mas um pulo menor leva ao número mínimo de pulos?

===
Quando você não consegue construir um contraexemplo, normalmente existem duas possibilidades:

O algoritmo guloso realmente está correto.
O contraexemplo é muito difícil de enxergar.

Um competidor experiente faz exatamente o que você fez: tenta quebrar a própria ideia.
===

Diagnóstico:
1- Errei ao ter dividido
2- Errei no calculo da inclinação:
o que importa não é o indice, mas o delta posição
- eu fiz: Δaltura / índice
- Correto é: Δaltura / Δposição

logo, deveria ser:

dy = trees[j].height - trees[i].height;

dx = trees[j].position - trees[i].position;

*/

/*
==========================
Passo a passo
==========================
1. Ordenar as árvores pela posição.

↓

2. Como verifico se um salto é possível?

↓

3. Como comparar duas inclinações sem usar divisão?

↓

4. A estratégia gulosa é válida?

↓

5. Só então implementar.

*/


/*
Graças a Deus guloso funciona se não seria mais complicado, precisariamos de DP ou Grafo, ou outra ferramenta + complexa

*/