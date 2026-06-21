#include <iostream>
#include <vector>
using namespace std;

struct tree{int position; int height;};
vector<tree> trees;

bool comp(tree a, tree b){
    return a.postion < b.position
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
    // menor quantidade de pulos que OBI deve dar para ir da primeira até a ultima arvore
    int actual_tree = 0;
    int jumps = 0;
    int jump_dist=1;
    int max_jump = 0;
    bool pulavel = true;
    while(actual_tree < trees.size()-1){
        // 
        for(int i =0; i < jump_dist; i++){
            if((tree[actual_tree+i].height - tree[actual_tree].height)/i <= (tree[actual_tree+jump_dist].height - tree[actual_tree].height)/jump_dist){
                
            } else{
                pulavel = false;
            }
        }
        
        if (pulavel == true){
            jump_dist++;
        }
        else {
            max_jump = jump_dist--;
            actual_tree += max_jump;
            jump_dust = 1;
            jumps++;
        }

    }

    cout << jumps;
    // enquanto cos de todos x até o i for menor que que cos 0 arvore até < x; ele consegue pular para X+1
    
    // quando x+1 > x, temos dois pulos -> para x e depois para x+1 e recomeçamos em x+1
    // int jump_dist = 0;

    

    return 0;
}

