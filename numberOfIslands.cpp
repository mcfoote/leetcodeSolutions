#include<vector>
// DFS solution.
class Solution {
public:

    int numIslands(std::vector<std::vector<char>>& grid) {

        int row = grid.size();

        if(row == 0) return 0;

        int col = grid[0].size();
        int resolution = 0;

        std::vector<std::vector<bool>> mark(row, std::vector<bool>(col, true));

          for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == '1' && mark[i][j] == true){

                    search(i, j, grid, mark);
                    resolution+=1;

                }
            }
        }
        
        return resolution;
    }

     void search(int i, int j, std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& mark){
        
        mark[i][j] = false;
        
        if (i+1<grid.size() && grid[i+1][j]=='1' && mark[i+1][j]==true){
            search(i+1,j,grid,mark);
        }

        if (j+1<grid[0].size() && grid[i][j+1]=='1' && mark[i][j+1]==true){
            search(i,j+1,grid,mark);
        }

        if (i-1>=0 && grid[i-1][j]=='1' && mark[i-1][j]==true){
            search(i-1,j,grid,mark);
        }

        if (j-1>=0 && grid[i][j-1]=='1' && mark[i][j-1]==true){
            search(i,j-1,grid,mark);
        }

    }  

};