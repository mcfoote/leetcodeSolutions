#include<stack>

using std::stack;

class Solution {
public:
    bool isPalindrome(int x) {
        stack<int> s;

        if(x < 0) {
            return false;
        }

        int y = x;

        while(x) {
            s.push(x % 10);
            x /= 10;
        }

        while(y) {
            if(s.top() != (y % 10)) {
                return false;
            }
            s.pop();
                y /= 10;
        }

        return true;
    }
};