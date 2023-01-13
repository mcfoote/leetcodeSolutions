#include<string>
#include<map>
#include<cmath>

using std::string;
using std::map;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, maxL=0, j=0;
        map<char, int> m;
        
        for(int i=0; i<s.size(); i++) {

            m[s[i]]++;
            l++;

            while(m[s[i]]>1) {
                m[s[j++]]--;
                l--;
            }

            maxL = max(maxL, l);

        }

        return maxL;

    }
};