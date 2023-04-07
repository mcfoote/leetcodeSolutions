#include<vector>

using std::vector;

//depth-first search solution
class Solution {
public:
    int numEnclaves(vector<vector<int>>& field)  {

        int a = field.size();
        int b = field[0].size();
        
        for (int i = 0; i < a; i++) {
            dfs(field, i, 0);
            dfs(field, i, b-1);
        }
        for (int j = 0; j < b; j++) {
            dfs(field, 0, j);
            dfs(field, a-1, j);
        }
        
        int count = 0;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (field[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;

    }
    
private:
    void dfs(vector<vector<int>>& field, int i, int j) {

        if (i < 0 || i >= field.size() || j < 0 || j >= field[0].size() || field[i][j] != 1) {
            return;
        }

        field[i][j] = -1; 

        dfs(field, i+1, j);
        dfs(field, i-1, j);
        dfs(field, i, j+1);
        dfs(field, i, j-1);

    }
};