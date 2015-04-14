// Given a non - negative number represented as an array of digits, plus one to the number.
// 
// The digits are stored such that the most significant digit is at the head of the list.
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0;
        digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
        for (int i = digits.size() - 2; i >= 0; --i){
            if (digits[i + 1] == 0){
                digits[i] = (digits[i] + (digits[i + 1] == 0 ? 1 : 0)) % 10;
            }
            else{
                break;
            }
        }
        if (digits[0] == 0){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};