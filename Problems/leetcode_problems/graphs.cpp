#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// Find a sage path through the grid - https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description
// f_1 try : 
/*
Time Limit Exceeded
510 / 691 testcases passed
submitted at Jul 02, 2026 11:28
----
Oops… Failure is the mother of success! You didn't pass on this first attempt, but you've built a solid foundation to learn from.
approach
Current: Depth-First Search + Recursion
Suggested: Breadth-First Search + Dijkstra's Algorithm
Key Idea: Find a path in a grid maximizing remaining health using shortest-path algorithms on weighted graphs.
----
Current complexity:
O(4∗(M∗N))
Suggested complexity:
O(M∗N)
Suggestions:
Replace DFS with BFS or Dijkstra to visit each cell once, avoiding exponential recursion.
----
Readability:Good
Structure: Good
Suggestions: Use consistent indentation and clearer variable names to improve logic flow visibility.
Since all cell values are non-negative, we can apply Dijkstra's algorithm to compute the minimum cost to reach every cell. If the minimum cost to reach the destination is less than the initial health value health, then the destination is reachable; otherwise, it is not.
*/
void p_3286_med(){
    class Solution {
    public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // logica, replicar a tabela, porém a ideia é que iremos fazer dfs com um grafo podendo ter valor zero ou -1,
        vector<vector<int>> n_grid = grid; //copia da grid por segurança, para aumentar speed pode tirar e usar só grid.
        vector<vector<int>> h_grid(n_grid.size(), vector<int>(n_grid[0].size(),-999));
        vector<vector<int>> visited_grid(n_grid.size(), vector<int>(n_grid[0].size(),0));
        // 0 = n_visited, 1 = visited
        
        // Dessa forma faremos uma atualização para cada posição se conseguirmos alcançar aquele mesmo ponto com um maior numero, se o numero alcançar 0 no final retorna-se falso. 
        // Fazer algo recursivo;
        // while end == true:
        // Se bloco existir investigar bloco, exceto, visiteds
        // if h_grid[i][j] < health_at:
        // h_grid[i][j] = health_at
        search_update(n_grid, h_grid, visited_grid, health, 0,0);
        if(h_grid[n_grid.size()-1][n_grid[0].size()-1] >= 1){
            return true;
        } else{
            return false;
        }
    }
    void search_update(vector<vector<int>>& n_grid, vector<vector<int>>& h_grid, vector<vector<int>> visited_grid, int health_at, int i, int j){
        if(visited_grid[i][j] == 1){

        }
        else {
            visited_grid[i][j] = 1;
            if(h_grid[i][j] < (health_at - n_grid[i][j])){
                h_grid[i][j] = (health_at - n_grid[i][j]);
            }
            if(h_grid[i][j] > (health_at - n_grid[i][j])){

            }
            else if(h_grid[i][j] < 1){

            } // Caso seja igual a zero nem precisa fazer nada com esse abençoado mais.
            else{
                health_at -= n_grid[i][j];
                // posições avaibles{}
                if(i +1 < n_grid.size()){
                    search_update(n_grid, h_grid,visited_grid, health_at, i +1, j);
                }
                if(j +1 < n_grid[0].size()){
                    search_update(n_grid, h_grid,visited_grid, health_at, i, j+1);
                }
                if(i -1 >= 0){
                    search_update(n_grid, h_grid,visited_grid, health_at, i-1, j);
                }
                if(j-1 >= 0){
                    search_update(n_grid, h_grid,visited_grid, health_at, i, j-1);
                }

            }
        }    
    }
};
}

void p_3286_med_sol(){
    class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            if (dis[cx][cy] >= 0) {
                continue;
            }
            dis[cx][cy] = val;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                    dis[nx][ny] >= 0) {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};
}