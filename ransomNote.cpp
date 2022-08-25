#include<unordered_map>
#include<string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> m;
        
        for(int i = 0; i < magazine.size(); i++) {
            
            m[magazine[i]]++;
            
        }
        
        for(int i = 0; i < ransomNote.size(); i++ ) {
            
            char c = ransomNote[i];
            if(m[c] <= 0) return false;
            m[c]--;
        }
        
        return true;
        
    }
};