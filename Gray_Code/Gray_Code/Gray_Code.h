// The gray code is a binary numeral system where two successive values differ in only one bit.
// 
// Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
// 
// For example, given n = 2, return[0, 1, 3, 2].Its gray code sequence is :
// 
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
// Note :
//      For a given n, a gray code sequence is not uniquely defined.
// 
//      For example, [0, 2, 3, 1] is also a valid gray code sequence according to the above definition.
// 
//      For now, the judge is able to judge based on one instance of gray code sequence.Sorry about that.
#include <vector>
using namespace std;

class Solution_copy {
public:
    vector<int> grayCode(int n) {
        vector<int> output(1 << n);
        vector<int> buffer;
        output[0] = 0; // seed
        if (n > 0){
            buffer.reserve(1 << (n - 1));
            output[1] = 1; // seed
            for (int lv = 2; lv <= n; ++lv){
                buffer.clear();
                for (int i = 0; i < (1 << (lv - 1)); ++i){
                    buffer.insert(buffer.begin(), output[i] | (1 << (lv - 1)));
                }
                copy(buffer.begin(), buffer.end(), output.begin() + (1 << (lv - 1)));
            }
        }
        return output;
    }
};

class Solution_insert {
public:
    vector<int> grayCode(int n) {
        vector<int> output;
        vector<int> buffer;
        output.push_back(0); // seed
        if (n > 0){
            output.reserve(1 << n);
            buffer.reserve(1 << (n - 1));
            output.push_back(1); // seed
            for (int lv = 2; lv <= n; ++lv){
                buffer.clear();
                for (auto& i : output){
                    buffer.insert(buffer.begin(), i | (1 << (lv - 1)));
                }
                output.insert(output.end(), buffer.begin(), buffer.end());
            }
        }
        return output;
    }
};