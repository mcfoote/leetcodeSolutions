#include<vector>

using std::vector;

class Solution {
public:
    static bool comparison(vector<int> &vectA, vector<int> &vectB) {

        return vectA[1] < vectB[1];

    }

    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), comparison);

        int prev = 0; int res = 1;

        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[prev] < pairs[i]) {
                prev = i;
                res++;
            }

        }

        return res;

    }
};