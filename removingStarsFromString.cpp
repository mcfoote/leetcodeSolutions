#include<string>
#include<vector>

using std::string;
using std::vector;

class Solution {
public:
    string removeStars(string s) {

        vector<char> v;
        for (char c : s) {
            if (c != '*') {
                v.push_back(c);
            } else if (!v.empty()) {
                v.pop_back();
            }
        }

        string res(v.begin(), v.end());

        return res;

    }
};