#include <vector>
#include <cmath>
//using namespace std;
class Solution {
public:

    int minCostClimbingStairs(std::vector<int>& cost) {

        int n = cost.size();
        int dynamic1 = 0, dynamic2 = 0;

        for(int i =n-1; i >=0; i--){

            int dynamicI= cost[i] + std::min(dynamic1, dynamic2);
            dynamic2 = dynamic1;
            dynamic1 = dynamicI;

        }

        return std::min(dynamic1, dynamic2);

     }

};