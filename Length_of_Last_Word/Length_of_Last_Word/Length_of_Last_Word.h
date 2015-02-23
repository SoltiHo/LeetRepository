// Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
// 
// If the last word does not exist, return 0.
// 
// Note: A word is defined as a character sequence consists of non - space characters only.
// 
//       For example,
//       Given s = "Hello World",
//       return 5.


// case 1: " " --> 0
// case 2: "abc" --> 3
// case 3: "abc " --> 3
// case 4: "  1  " --> 1
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        int lastLength = 0;
        while (*s != '\0'){
            if (*s == ' '){
                lastLength = length > 0 ? length : lastLength;
                length = 0;
            }
            else{
                length++;
            }
            s++;
        }
        return  length > 0 ? length : lastLength;
    }
};

