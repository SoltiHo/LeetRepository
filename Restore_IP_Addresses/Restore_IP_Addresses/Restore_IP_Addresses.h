//  Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//  
//  For example :
//  Given "25525511135",
//  
//  return["255.255.11.135", "255.255.111.35"]. (Order does not matter)
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string outputBuffer(s);
        backTracking(outputBuffer, -1, 0);
        return this->output;
    }

    void backTracking(string& buffer, int lastDotIdx, int numDotIncluded){
        if (reject(buffer, lastDotIdx, numDotIncluded)){
            return;
        }
        if (accept(buffer, lastDotIdx, numDotIncluded)){
            return;
        }

        // recursive
        // try 1 number
        const int bufferSize = buffer.size();
        const int countNumber = bufferSize - 1 - lastDotIdx;
        if (countNumber >= 2){
            buffer.insert(buffer.begin() + (lastDotIdx + 2), '.');
            backTracking(buffer, lastDotIdx + 2, numDotIncluded + 1);
            buffer.erase(buffer.begin() + (lastDotIdx + 2));
        }
        // try 2 numbers
        if ((countNumber >= 3) && (buffer[lastDotIdx + 1] - 0x30 > 0)){
            buffer.insert(buffer.begin() + (lastDotIdx + 3), '.');
            backTracking(buffer, lastDotIdx + 3, numDotIncluded + 1);
            buffer.erase(buffer.begin() + (lastDotIdx + 3));
        }
        // try 3 numbers
        if ((countNumber >= 4) && 
            (buffer[lastDotIdx + 1] - 0x30 > 0) && (buffer[lastDotIdx + 1] - 0x30 <= 2) && // 2 >= 1st digit > 0
            ((buffer[lastDotIdx + 1] - 0x30 < 2) || (buffer[lastDotIdx + 2] - 0x30 <= 5))){ // if 1st digit is 2, then 2nd digit <= 5
            buffer.insert(buffer.begin() + (lastDotIdx + 4), '.');
            backTracking(buffer, lastDotIdx + 4, numDotIncluded + 1);
            buffer.erase(buffer.begin() + (lastDotIdx + 4));
        }
    }

    bool reject(string& buffer, int lastDotIdx, int numDotIncluded){
        const int bufferSize = buffer.size();
        const int countNumber = bufferSize - 1 - lastDotIdx;
        if ((lastDotIdx > -1) && (lastDotIdx == bufferSize - 1)){
            // dot at the end
            return true;
        }
        if (countNumber <= 3 - numDotIncluded){
            // too few numbers to accomondate those dots
            return true;
        }

        // check the least number of dots needed
        int leastDotNeeded = 0;
        int cursor = lastDotIdx + 1;
        int temp = 0;
        int numDigits = 0;
        while (cursor < bufferSize){
            temp = temp * 10 + (buffer[cursor] - 0x30);
            if (temp > 255){
                leastDotNeeded++;
                temp = (buffer[cursor] - 0x30);
                numDigits = 0;
            }
            
            numDigits++;
            if (numDigits == 4){
                numDigits = 1;
                temp = 0;
                leastDotNeeded++;
            }
            cursor++;
        }

        if (leastDotNeeded > 3 - numDotIncluded){
            return true;
        }

        return false;
    }

    bool accept(string& buffer, int lastDotIdx, int numDotIncluded){
        if (numDotIncluded == 3){
            const int bufferSize = buffer.size();
            const int countNumber = bufferSize - 1 - lastDotIdx;
            if (countNumber == 1){
                this->output.push_back(buffer);
                return true;
            }
            else if ((countNumber == 2) && (buffer[lastDotIdx + 1] - 0x30 > 0)){
                this->output.push_back(buffer);
                return true;
            }
            else if ((countNumber == 3) &&
                (buffer[lastDotIdx + 1] - 0x30 > 0) && (buffer[lastDotIdx + 1] - 0x30 <= 2) && // 2 >= 1st digit > 0
                ((buffer[lastDotIdx + 1] - 0x30 < 2) || (buffer[lastDotIdx + 2] - 0x30 <= 5))) // if 1st digit is 2, then 2nd digit <= 5
            {
                this->output.push_back(buffer);
                return true;
            }
            return true;
        }

        return false;
    }
    vector<string> output;
};