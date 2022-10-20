#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<queue>

using std::string;
using std::vector;
using std::unordered_map;
using std::priority_queue;
using std::pair;
using std::sort;
using std::min;

class Solution {

private:

    struct Compare {
        Compare() {}
        ~Compare() {}

        bool operator()(const pair<string,int>& p1, const pair<string,int>& p2) {

            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);

        }

    };

public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> um;

        for(const string& s:words) um[s]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

        for(const auto& a : um) {

            pq.push(a);
            if(pq.size() > k) pq.pop();

        }

        vector<string> result;
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        reverse(result.begin(), result.end());

        return result;

    }
};