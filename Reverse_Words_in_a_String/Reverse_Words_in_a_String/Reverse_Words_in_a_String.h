//  Given an input string, reverse the string word by word.
//  
//  For example,
//  Given s = "the sky is blue",
//  return "blue is sky the".
//  
//  click to show clarification.
//  
//  Clarification:
//  What constitutes a word ?
//      A sequence of non - space characters constitutes a word.
//
//  Could the input string contain leading or trailing spaces ?
//      Yes.However, your reversed string should not contain leading or trailing spaces.
//
//  How about multiple spaces between two words ?
//      Reduce them to a single space in the reversed string.
// 
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // preprocessing, remove duplicated space
        // and make sure no space at the beginning and the end
        int charCursor = 1;
        while (charCursor < s.size()){
            if ((s[charCursor] == ' ') && (s[charCursor - 1] == ' ')){
                s.erase(charCursor, 1);
            }
            else{
                charCursor++;
            }
            
        }

        if (s[0] == ' '){
            s.erase(0, 1);
        }

        if (s[s.size() - 1] == ' '){
            s.pop_back();
        }

        int lastSpaceIdx = 0;
        int currSpaceIdx = 0;
        int wordFirstCharIdx = 0;
        int wordLastCharIdx = 0;
        while (true){
            wordFirstCharIdx = s.find_first_not_of(" ", lastSpaceIdx);
            if (wordFirstCharIdx == string::npos){
                // no match, no more word
                break;
            }

            lastSpaceIdx = s.find_first_of(" ", wordFirstCharIdx + 1);
            if (lastSpaceIdx == string::npos){
                // the word last to the end
                wordLastCharIdx = s.size() - 1;
            }
            else{
                wordLastCharIdx = lastSpaceIdx - 1;
            }

            reverse(s, wordFirstCharIdx, wordLastCharIdx);
        }

        reverse(s, 0, s.size() - 1);
    }

    void reverse(string& s, int firstCharIdx, int lastCharIdx){
        while (firstCharIdx < lastCharIdx){
            swap(s[firstCharIdx], s[lastCharIdx]);
            firstCharIdx++;
            lastCharIdx--;
        }
    }
};