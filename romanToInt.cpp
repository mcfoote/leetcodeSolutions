#include<string>

using std::string;

class Solution {
public:
    string intToRoman(int num) {
        
        int integer[] = {
            1000,
            900,
            500,
            400,
            100,
            90,
            50,
            40,
            10,
            9,
            5,
            4,
            1
        };

        string roman[] = {
            "M",
            "CM",
            "D",
            "CD",
            "C",
            "XC",
            "L",
            "XL",
            "X",
            "IX",
            "V",
            "IV",
            "I"
        };

        string answer;

        for(int i = 0; i < 13; i++) {
            while(num >= integer[i]) {
                answer.append(roman[i]);
                num -= integer[i];
            }
        }

        return answer;

    }
};