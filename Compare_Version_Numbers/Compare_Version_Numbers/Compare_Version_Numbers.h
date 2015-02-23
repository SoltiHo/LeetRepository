// Compare two version numbers version1 and version2.
// If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
// 
// You may assume that the version strings are non - empty and contain only digits and the.character.
// The.character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second - level revision of the second first - level revision.
// 
// Here is an example of version numbers ordering :
// 
// 0.1 < 1.1 < 1.2 < 13.37
#include <string>
using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
        while ((version1.size() > 0) && (version2.size() > 0)){
            int v1 = getNumber(version1);
            int v2 = getNumber(version2);
            if (v1 > v2){
                return 1;
            }
            else if (v1 < v2){
                return -1;
            }
        }
        if (version1.size() > version2.size()){
            int v1 = getNumber(version1);
            if (v1 == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (version1.size() < version2.size()){
            int v2 = getNumber(version2);
            if (v2 == 0){
                return 0;
            }
            else{
                return -1;
            }
        }
        else{
            return 0;
        }
    }

    int getNumber(string& s){
        int output = 0;
        while ((s.size() > 0) && (s[0] != '.')){
            output = output * 10 + (s[0] - '0');
            s.erase(0, 1);
        }
        if (s[0] == '.'){
            s.erase(0, 1);
        }
        return output;
    }
};