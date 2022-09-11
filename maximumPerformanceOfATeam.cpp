#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cmath>

class Solution {
public:
    int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k) {

        int mod = 1e9 + 7;

        std::vector<std::pair<int, int>> candidates(n);

        for(int i = 0; i < n; i++) candidates[i] ={efficiency[i], speed[i]};

        sort(candidates.rbegin(), candidates.rend());

        long speedSum = 0;
        long answer = 0;

        std::priority_queue<int, std::vector<int>, std::greater<int>> pQ;

        for(auto&[e, s] : candidates) {
            pQ.push(s);
            speedSum += s;

            if(pQ.size() > k) {
                speedSum -= pQ.top();
                pQ.pop();
            }
            answer = std::max(answer, speedSum * e);
        }

        return answer % mod;

    }
};