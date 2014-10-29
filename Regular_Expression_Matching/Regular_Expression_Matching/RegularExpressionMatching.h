//  Implement regular expression matching with support for '.' and '*'.
//  
//  '.' Matches any single character.
//  '*' Matches zero or more of the preceding element.
//  
//  The matching should cover the entire input string(not partial).
//  
//  The function prototype should be :
//  bool isMatch(const char *s, const char *p)
//  
//  Some examples :
//  isMatch("aa", "a") --> false
//  isMatch("aa", "aa") --> true
//  isMatch("aaa", "aa") --> false
//  isMatch("aa", "a*") --> true
//  isMatch("aa", ".*") --> true
//  isMatch("ab", ".*") --> true
//  isMatch("aab", "c*a*b") --> true




class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if ((*p == *(p + 2)) && (*(p + 1) == '*') && (*(p + 3) == '*')){
            // repeated pattern detected
            const char* pRepeatedPattern = p;
            while (true){
                if ((*(pRepeatedPattern + 1) == '*') && 
                    (*(pRepeatedPattern + 3) == '*') &&
                    (*(pRepeatedPattern + 2) == *pRepeatedPattern))
                {
                    pRepeatedPattern = pRepeatedPattern + 2;
                }
                else
                {
                    break;
                }
            }
            return isMatch(s, pRepeatedPattern);
        }

        bool result = false;
        // base cases
        if (*s == '\0'){
            if (*p == '\0'){
                return true;
            }
            else if (*(p+1) == '*'){
                return isMatch(s, p + 2);
            }
            else{
                return false;
            }
            
        }
        else if (*p == '\0'){
            // empty pattern, but non empty string
            return false;
        }

        // recursive calls
        if ((*s == *p) || (*p == '.')){
            if (*(p + 1) == '*'){
                result |= isMatch(s, p + 2);
                result |= isMatch(s + 1, p);
                result |= isMatch(s + 1, p + 2);
            }
            else{
                result |= isMatch(s + 1, p + 1);
            }
        }
        else if (*(p + 1) == '*'){
            result |= isMatch(s, p + 2);
        }
        else{
            // current char doesn't match, and the next char isn't * either
            return false;
        }

        return result;
    }
};

