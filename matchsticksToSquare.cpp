#include <vector>
#include <algorithm>


class Solution {
public:

    bool backtrack(std::vector<int> &sides, std::vector<int> &matchsticks, int index, int sideLength) {

        if(index == matchsticks.size())
            return true;

        for(int i = 0; i < 4; ++i) {

            if(sides[i] + matchsticks[index] <= sideLength){

                sides[i] += matchsticks[index];
                if(backtrack(sides, matchsticks, index + 1, sideLength)) return true;   
                sides[i] -= matchsticks[index];
            }
        }

        return false;

    }

    bool makesquare(std::vector<int>& matchsticks) {

        int perimeter = 0;
        for(int val: matchsticks) 
            perimeter += val;

        if(perimeter % 4 != 0) return false;

        std::vector<int> sides(4, 0);
        int sideLength = perimeter/4;

        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());

        return backtrack(sides, matchsticks, 0, sideLength);
        
        
    }

};