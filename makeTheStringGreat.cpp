#include<string>

using std::string;

class Solution {
public:
    string makeGood(string s) {
        
        string answer;

        for(int i = 0; i < s.size(); i++) {
            answer.push_back(s[i]);

            while(answer.size() && (answer.back()==s[i+1]+32 || answer.back()==s[i+1]-32)) {
                answer.pop_back();
                i++;
            }
        }

        return answer;

    }
};