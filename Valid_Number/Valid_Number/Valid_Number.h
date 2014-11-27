// Validate if a given string is numeric.
// 
// Some examples :
// "0" = > true
// " 0.1 " = > true
// "abc" = > false
// "1 a" = > false
// "2e10" = > true
// Note: It is intended for the problem statement to be ambiguous.You should gather all requirements up front before implementing one.

// allowed char: [0~9] . e space -
// '.' can be only followed by [0~9] (at least one), can be only proceeded by [0~9]
// 'e' can be only followed by [0~9] (at least one), can be only proceeded by [0~9]
// ' ' can be only followed by [0~9] and ' ', can be only proceeded by [0~9]

// .3 is allowed
// 3. is allowed

class Solution {
public:
    bool isNumber(const char *s) {
        if (*s == '\0'){
            return false;
        }

        unsigned char lastOne = 0xFF;
        const char* p = s;
        bool atLeastOneDigit = false;
        bool digitZoneCompleted = false;
        bool inDotMode = false;
        bool inExpMode = false;
        while (*p != '\0'){
            if ((*p >= 0x30) && (*p <= 0x39)){
                // [0 ~ 9]
                atLeastOneDigit = true;

                if (digitZoneCompleted){
                    return false;
                }
            }
            else if (*p == ' '){
                if (lastOne == 'e'){
                    return false;
                }
                if ((lastOne == '.') || (atLeastOneDigit)){
                    digitZoneCompleted = true;
                }

                if (inDotMode){
                    inDotMode = false;
                }
                if (inExpMode){
                    inExpMode = false;
                }
            }
            else if (*p == 'e'){
                if (((lastOne < 0x30) || (lastOne > 0x39)) && (lastOne != '.')){
                    return false;
                }

                if (digitZoneCompleted){
                    return false;
                }

                if (inDotMode){
                    inDotMode = false;
                }

                if (inExpMode){
                    return false;
                }
                else{
                    inExpMode = true;
                }
                
            }
            else if (*p == '.'){
                if (((lastOne < 0x30) || (lastOne > 0x39)) && 
                    ((lastOne != 0xFF) && (lastOne != ' ') && (lastOne != '+') && (lastOne != '-')))
                {
                    return false;
                }
                if ((inDotMode) || (inExpMode)){
                    return false;
                }
                else{
                    inDotMode = true;
                }

                if (((lastOne < 0x30) || (lastOne > 0x39)) && ((*(p + 1) < 0x30) || (*(p + 1) > 0x39))){
                    // . must have digit before or after 
                    return false;
                }
                if (digitZoneCompleted){
                    return false;
                }
            }
            else if ((*p == '-') || (*p == '+')){
                if (((lastOne != 0xFF) && (lastOne != ' ') && (lastOne != 'e')) || (digitZoneCompleted) || (inDotMode)){
                    return false;
                }
                if (((*(p + 1) < 0x30) || (*(p+1) > 0x39)) &&
                    ((*(p + 1) != '.'))){
                    return false;
                }
            }
            else{
                // other chars are not allowed
                return false;
            }
            lastOne = *p;
            p++;
        }

        if ((!atLeastOneDigit) || (lastOne == 'e')){
            return false;
        }
        else{
            return true;
        }
    }
};