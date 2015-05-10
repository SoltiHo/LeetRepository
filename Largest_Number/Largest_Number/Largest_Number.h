// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

class SolutionWrong {
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


class Solution {
public:
    string largestNumber(vector<int> &num) {
        string output = countingSort(num, 0);
        while (output.size() > 0 && output[0] == '0'){
            output.erase(output.begin());
        }
        if (output.size() == 0){
            output.push_back('0');
        }
        return output;
    }

    string countingSort(vector<int> n, int level){
        if (n.size() == 1){
            // convert the number to string
            return to_string(n[0]);
        }
        else if (level > 10){
            // the order of these doesn't matter
            stringstream ss;
            for (auto w : n){
                ss << to_string(w);
            }
            return ss.str();
        }
        else if (n.size() == 0){
            return "";
        }

        vector<vector<int>> buckets(10, vector<int>()); // for 0 ~ 9
        for (auto i : n){
            int numDigits = i == 0 ? 1 : (int)log10(i) + 1;
            int digitIdx = level % numDigits;
            int sortingKey = (i / (int)pow(10, numDigits - digitIdx - 1)) % 10;
            buckets[9 - sortingKey].push_back(i); // put in reverse order, because 9 should come first
        }

        stringstream ss;
        for (auto b : buckets){
            ss << countingSort(b, level + 1);
        }

        return ss.str();
    }
};
class Solution_Old {
public:
    struct indirectNode{
        int key;
        int idx;
    };

    string largestNumber(vector<int> &num) {
        const int size = num.size();
        string output;
        if (size > 0){
            int maxNum = num[0];  // O(n)
            for (int i = 1; i < size; ++i){
                maxNum = max(maxNum, num[i]);
            }

            int maxDigitCount = calculateDigitCount(maxNum); // the # of digits of the max number
            int requiredKeyDigitCount = maxDigitCount + 1; // required digits to break tie in sorting
            vector<indirectNode> sortee;
            indirectNode temp;
            // create the indirect sort nodes
            for (int i = 0; i < size; ++i){  // O(n * m), m is the max num of digits
                temp.key = generateKey(num[i], requiredKeyDigitCount);
                temp.idx = i;
                sortee.push_back(temp);
            }

            // radix sort the indirect nodes
            int exp = 1;
            for (int i = 0; i < requiredKeyDigitCount; ++i){
                countingSort(sortee, size, exp);
                exp *= 10;
            }

            // covert the indirect nodes back to string
            stringstream ss;
            bool leadingNonzero = false;
            for (int i = size - 1; i >= 0; --i){  // O(n)
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

    int calculateDigitCount(int n){
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }

    int generateKey(int originalNum, int requiredKeyLength){
        if (originalNum == 0){
            return 0;
        }

        vector<int> digits;
        int oriDigitCount = 0;
        int cursor = originalNum;
        while (cursor > 0){
            digits.insert(digits.begin(), cursor % 10);
            cursor /= 10;
            oriDigitCount++;
        }

        int output = originalNum;
        for (int i = 0; i < requiredKeyLength - oriDigitCount; ++i){
            output = output * 10 + (digits[i % oriDigitCount]);
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