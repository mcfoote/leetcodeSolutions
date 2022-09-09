#include<vector>
#include<algorithm>

class Solution {
public:
    static bool compare(std::vector<int> &c1, std::vector<int> &c2) {

        if(c1[0] == c2[0]) {
            return c1[1] < c2[1];
        }

        return c1[0] > c2[0];

    }

    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
        
        std::sort(properties.begin(), properties.end(), compare);

        int answer = 0;
        int defenseMax = 0;

        for(auto iter: properties) {
            if(iter[1] < defenseMax) answer++;
            else defenseMax = iter[1];
        }

        return answer;

    }
};