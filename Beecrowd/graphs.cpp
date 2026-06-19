#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// graphs problems.




// p_1053 - Vamos receber uma lista de pontos e suas conexões - Inacabada -> mto longa
// A-E, 1-5 matrix de pontos
// objetivo: desenhar segmentos e computar custo
/*
constraints:
1] Start from the end point of any line segment.
2] Do not lift your pen off the paper.
3] You can go over a line more than once.
4] Do not draw any line other than the ones mentioned.
5] You can only change direction at integer coordinates of x & y.
6] Use the least amount of ink needed.
*/
int p_1053(){
    int T = 0;
    cin >> T;
    int N = 0;
    
    vector<vector<int>> matrix;
    int 0_list[20] = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    // filling matrix
    for(int i =0; i <20; i++){
        matrix.push_back(0_list);
    }
    struct position{int x; int y;};

    struct edge{int end_point; int ink;};
    cin >> N;
    pair<string,string> pos_intersec;
    position pos_at, las_pos;
    int ink_edge;
    set<int> list_end;
    set<int> list;
    
    for(int i =0; i< N; i++){
        cin >> pos_intersec.first;
        cin >> pos_intersec.second;
        // conversão para gráfico: a - e = coluna = 0 a 4; int(pos_intersec.first) - int('A')
        int colum_1, colum_2, row_1, row_2;
        pos_at.x = int(pos_intersec.first[0]) - int('A');
        pos_at.y = int(pos_intersec.first[1]);
        las_pos.x = int(pos_intersec.first[0]) - int('A');
        las_pos.y = int(pos_intersec.first[1]);
        ink = sqrt(power(pos_at.x - las_pos.x,2) + power(pos_at.y - las_pos.y,2));
        matrix[pos_at.x][las_pos.x] = ink;
        matrix[las_pos.x][pos_at.x] = ink;
        if (list_end.count(pos_at.x) == 0){
            list_end.insert(pos_at.x);
        } else {
            list_end.erase(pos_at.x);
        }
        if (list_end.count(las_pos.x) == 0){
        list_end.insert(las_pos.x);
        }
        
        list.insert(pos_at.x);
        list.insert(las_pos.x);
    }

    int min_ink = 999999999;

    // BFS
    for(int i =0; i< list_end.size(); i++){
        set<int> list_copy = list;
        int ink_at = 0;
        list_copy.erase(list_end[i]);
        int ponto_at = list_end[i];
        while(list_copy.size() != 0){

            for(int j =0; j < matrix[i].size(); j++) {
                edge next_pon;
                next_pon.ink = 9999999999999;
                if(j != las_point){
                    if(matrix[i][j] != 0){
                        // caminho available
                        // Algoritimo guloso, menor caminho ink first.
                        if(next_pon.ink > matrix[i][j]){
                            next_pon.end_point = j;
                            next_pon.ink = matrix[i][j];
                        }
                    }
                }
            }
        
            ink_at += next_pon.ink;
            las_point = ponto_at;
            ponto_at = next_pon.end_point;


        }

    }
    // BFS

    // ink = sqrt(power(pos_at.x - las_pos.x,2) + power(pos_at.y - las_pos.y,2));
    return 0;
}

int main(){
    return 0;
}