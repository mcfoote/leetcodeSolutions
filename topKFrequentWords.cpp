#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

using std::string;
using std::vector;
using std::map;
using std::pair;
using std::sort;
using std::min;

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();
        map<string, int> frequency;

        for(int i = 0; i < n; i++) {
            frequency[words[i]]++;
        }

        vector<pair<string, int>> result;
        vector<string> answer;

        for(auto iter : frequency) {
            result.push_back({iter.first, iter.second});
        }

        sort(result.begin(), result.end());

        for(int i = 0; i < min(k, n); i++) {
            answer.push_back(result[i].first);
        }
        
        return answer;
        
    }
};