#include<vector>
#include<queue> 

class Solution {
public:
    std::vector<int> numsSameConsecDiff(int n, int k) {

        std::queue<int> q;

        for(int s = 1; s < 10; s++) q.push(s);

        for(int i =1; i < n; i++) {
            int qSize = q.size();

            for(int j = 0; j < qSize; j++) {

                int currentNum = q.front(); 
                q.pop();
                int rightNum = currentNum % 10;

                if(rightNum + k < 10) q.push(currentNum * 10 + rightNum + k);

                if(k != 0 && rightNum - k >= 0) q.push(currentNum * 10 + rightNum - k);

            }
        }

        std::vector<int> resolution;

        while(!q.empty()) {
            resolution.push_back(q.front());
            q.pop();
        } 

        return resolution;
        
    }
};