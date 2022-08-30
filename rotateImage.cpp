#include<vector>
#include<algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {

        int n = matrix.size();

        for(int i = 0; i <= n/2; ++i) {
            for(int j = i; j <= n - 2 - i; ++j) {

                int x = matrix[i][j];
                int d = j - i;
                std::swap(x, matrix[j][n-1-i]);
                std::swap(x, matrix[n-1-i][n-1-j]);
                std::swap(x, matrix[n-1-j][i]);
                std::swap(x, matrix[i][j]);

            }
        }
        
    }
};