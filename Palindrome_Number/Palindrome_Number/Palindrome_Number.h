//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool output = false;
        if (x > 0){
            const int numDigits = log10(x) + 1;

            if (numDigits > 1){
                const int half = numDigits >> 1;

                int reversedLowerDigits = 0;
                int factor = 1;
                for (int i = 0; i < half; ++i){
                    reversedLowerDigits = reversedLowerDigits * 10 + ((x / factor) % 10);
                    factor *= 10;
                }

                output = ((int)(x / pow(10, numDigits - half)) == reversedLowerDigits);

            }
            else{
                // single digit
                output = true;
            }
        }
        else if (x == 0){
            output = true;
        }
        return output;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        bool output = false;
        if (x >= 0){
            const int numDigits = log10(x) + 1;
            int factor = pow(10, numDigits - 1);
            bool mismatchFound = false;
            while (factor >= 10){
                if (((x / factor) % 10) != x % 10){
                    // not equal
                    mismatchFound = true;
                    break;
                }
                else{
                    x /= 10;
                    factor /= 100;
                }
            }
            output = !mismatchFound;
        }


        return output;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x > 0){
            // find the MSD
            int factor = 1;
            int digitCount = 1;
            while (x / factor >= 10){
                factor *= 10;
                digitCount++;
            }

            int digitsToCheck = digitCount >> 1;
            int comparee = 0;
            int tenPower = 0;
            while (digitsToCheck){
                comparee += (((x / factor)) * pow(10, tenPower));
                x = x % factor;
                tenPower++;
                factor /= 10;
                digitsToCheck--;
            }

            if (digitCount % 2 == 1){
                // odd counts
                x = x % factor;
            }

            return x == comparee;
        }
        else if (x == 0){
            return true;
        }

        return false;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if (x > 0){
            int factor = 1;
            int digitCountOfX = 1;
            while (x / factor >= 10){
                factor *= 10;
                digitCountOfX++;
            }

            int comparee = 0;
            int digitCountOfComparee = (digitCountOfX >> 1);
            while (digitCountOfComparee){
                comparee = comparee * 10 + (x % 10);
                x /= 10;
                digitCountOfComparee--;
            }

            if (digitCountOfX % 2 == 1){
                x /= 10;
            }

            return (x == comparee);
        }
        else if (x == 0){
            return true;
        }

        return false;
    }
};