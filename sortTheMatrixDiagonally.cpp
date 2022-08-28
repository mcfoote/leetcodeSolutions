#include<vector>
#include<algorithm>
#include<cmath>

class Solution {
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat) {

        int m = mat.size();
        int n =  mat[0].size();
        int diag = (m-1) + 1 + (n-1);

        for(int k = 0; k < diag; k++) {
            std::vector<int> tmp;

            for(int i = std::max(m - 1 - k, 0), j = std::max(k - m + 1, 0); i < m && j < n; i++, j++) {
                tmp.push_back(mat[i][j]);
            }

            sort(tmp.begin(), tmp.end());
            for(int i = std::max(m-1-k, 0), j = std::max(k-m+1, 0), t = 0; i < m && j < n; i++, j++, t++) {
                mat[i][j] = tmp[t];
            }

        }

        return mat;

    }
};