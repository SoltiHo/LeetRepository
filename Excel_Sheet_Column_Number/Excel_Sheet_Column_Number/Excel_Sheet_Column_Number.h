//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int output = 0;
        for (auto& c : s){
            output = output * 26 + c - 0x40;
        }
        return output;
    }
};