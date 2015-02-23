//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB

#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string output;
        while (n > 0){
            output.insert(output.begin(), n % 26 == 0 ? 'Z' : 0x40 + (n % 26));
            n = (n - 1) / 26;
        }
        return output;
    }
};