#include<vector>

using std::vector;

class Solution {
public:
    int a;

    void dfSearch(vector<vector<int>>& stones, int index, vector<bool>& visited){
        visited[index] = true;

        for(int i = 0; i < a; i++){
            if(!visited[i] && ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                dfSearch(stones, i, visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        a = stones.size();

        vector<bool> visited(a, false);
        
        int count = 0;
        for(int i = 0; i<a; i++) {
            if(visited[i])
                continue;
            dfSearch(stones, i, visited);
            count++;
        }
        
        return a - count;
    }
};