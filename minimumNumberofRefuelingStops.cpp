#include <vector>
#include <queue>

class Solution {
public:

    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
        
        if(startFuel >= target) return 0;

        int size = stations.size();
        std::priority_queue<int> pq;
        int prev;
        int count = 0;

        for(int i = 0; i < size; ++i) {

            startFuel -= (stations[i][0]-prev);
            prev = stations[i][0];

            while(startFuel < 0 && !pq.empty()) {

                startFuel += pq.top();
                pq.pop();
                count++;

            }

            if(startFuel < 0) return -1;

            pq.push(stations[i][1]);

        }

        startFuel -= target - prev;
        while(startFuel < 0 && !pq.empty()) {

            startFuel += pq.top();
            pq.pop();
            count++;

        }

        if(startFuel < 0) return -1;

        return count;

    }

};
