#include<math.h>

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0xaaaaaaaa) == 0);
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        double value = log(n) / log(4);
        double resolve = value - (int)value;
        return resolve == 0.0;
    }
};