//  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//  
//  For example,
//  "A man, a plan, a canal: Panama" is a palindrome.
//  "race a car" is not a palindrome.
//  
//  Note:
//  Have you consider that the string might be empty ? This is a good question to ask during an interview.
//  
//  For the purpose of this problem, we define empty string as valid palindrome.

#include <string>
#include <vector>
class Solution {
public:
    bool isPalindrome(std::string s) {
        int stringSize = s.size();
        if (stringSize == 0){
            return true;
        }

        // first, get only character and avoid the speaces
        // 0x30 ~ 0x39 = 0 ~ 9
        // 0x41 ~ 0x5A = A ~ Z
        // 0x61 ~ 0x7A = a ~ z

        std::vector<char> alphanumericString;
        for (unsigned int i = 0; i < stringSize; ++i){
            if ((s[i] >= 0x30) && (s[i] <= 0x39)){
                alphanumericString.push_back(s[i]);
            }
            else if (((s[i] >= 0x41) && (s[i] <= 0x5A)) || //  A ~ Z
                ((s[i] >= 0x61) && (s[i] <= 0x7A)))  //  a ~ z
            {
                alphanumericString.push_back((s[i] | 0x20)); // make them all lower case
            }
        }

        const int alphanumericSize = alphanumericString.size();
        const int middlePoint = (alphanumericSize >> 1);
        const bool isEvenSized = (alphanumericSize == (middlePoint << 1));
        // if stringSize = 10, then middlePoint = 5, isEvenSized = true, need compare 0 ~ 4 to 9 ~ 5
        // if stringSize = 9, then middlePoint = 4, isEvenSized = false, need to compare 0 ~ 3 to 8 ~ 5.  4 is ignored
        // so, need to compare 0 ~ (middlePoint - 1) to (alphanumericSize - 1) ~ (middlePoint or middlePoint + 1) 
        // in both cases, the # of comparison are both middlePoint.

        for (int i = 0; i < middlePoint; ++i){
            if (alphanumericString[i] != alphanumericString[alphanumericSize - 1 - i]){
                return false;
            }
        }

        return true;
    }
};