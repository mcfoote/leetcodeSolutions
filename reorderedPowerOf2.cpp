#include<vector>
#include<map>
#include<string>

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        std::vector<std::string> temp;
        int numb = n;
        int length = std::to_string(n).size();
        int i =1;

        while(std::to_string(i).size() <= length) {
            std::string str = std::to_string(i);

            if(length == str.size()) {
                temp.push_back(str);
            }

            i *= 2;
        }

        std::string strTwo = std::to_string(n);
        std::map<char, int> m;

        for(auto c:strTwo) {
            m[c]++;
        }

        for(auto s:temp) {
            std::map<char, int> h;
            for(auto c:s) {
                h[c]++;
            }
            if(m == h) {
                return true;
            }
        }
        return false;
    }

    

};