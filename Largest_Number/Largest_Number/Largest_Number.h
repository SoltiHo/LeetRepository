// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    struct indirectNode{
        int key;
        int idx;
    };

    string largestNumber(vector<int> &num) {
        const int size = num.size();
        string output;
        if (size > 0){
            int maxNum = num[0];
            for (int i = 1; i < size; ++i){
                maxNum = max(maxNum, num[i]);
            }

            int exp = 1;
            while (maxNum / exp >= 10){
                exp *= 10;
            }

            vector<indirectNode> sortee;
            for (int i = 0; i < size; ++i){
                int leadingDigit = num[i];
                while (leadingDigit >= 10){
                    leadingDigit /= 10;
                }
                indirectNode temp;
                temp.idx = i;
                temp.key = num[i];
                if (temp.key > 0){
                    while (temp.key / exp == 0){
                        temp.key = temp.key * 10 + leadingDigit;
                    }
                }
                sortee.push_back(temp);
            }

            // radix sort the indirect nodes
            int expCur = 1;
            while (exp >= expCur){
                countingSort(sortee, size, expCur);
                expCur *= 10;
            }

            stringstream ss;
            bool leadingNonzero = false;
            for (int i = size - 1; i >= 0; --i){
                if ((num[sortee[i].idx] > 0) || leadingNonzero){
                    ss << num[sortee[i].idx];
                    leadingNonzero = true;
                }
            }
            if (ss.str().size() > 0){
                output = ss.str();
            }
            else{
                output = "0";
            }
            
        }
        return output;
    }

    void countingSort(vector<indirectNode>& sortee, const int size, const int exp){
        vector<int> count(10, 0);
        for (int i = 0; i < size; ++i){
            count[(sortee[i].key / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i){
            count[i] += count[i - 1];
        }

        vector<indirectNode> buffer(size, { 0, 0 });
        for (int i = size - 1; i >= 0; --i){
            buffer[count[(sortee[i].key / exp) % 10] - 1] = sortee[i];
            count[(sortee[i].key / exp) % 10]--;
        }
        sortee = buffer;
    }
};

