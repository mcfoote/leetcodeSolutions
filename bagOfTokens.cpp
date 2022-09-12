#include<vector>
#include<algorithm>
#include<cmath>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int l = 0;
        int r = tokens.size() - 1;
        int currentScore = 0;
        int maxScore = 0;

        while(l <= r) {

            if(tokens[l] <= power) {
                power -= tokens[l];
                currentScore += 1;
                maxScore = std::max(maxScore, currentScore);
                l +=1;
            } else if(currentScore >= 1) {
                power += tokens[r];
                currentScore -= 1;
                r -= 1;
            } else {
                break;
            }
        }

        return maxScore;

    }
};