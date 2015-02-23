//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string output = "1";
        for (int i = 0; i < n - 1; ++i){
            output = compile(output);
        }
        return output;
    }

    string compile(string input){
        string output;

        int currentNumber = -1;
        int counter = 0;
        while (input.size() > 0){
            if (counter == 0){
                // start a new number
                currentNumber = input[0] - '0';
                counter = 1;
            }
            else{
                if (currentNumber != input[0] - '0'){
                    // output what's accumulated so far
                    output.push_back('0' + counter);
                    output.push_back('0' + currentNumber);
                    currentNumber = input[0] - '0';
                    counter = 1;
                }
                else{
                    counter++;
                }
            }
            input.erase(0, 1);
        }
        output.push_back('0' + counter);
        output.push_back('0' + currentNumber);

        return output;
    }
};