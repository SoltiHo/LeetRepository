//  Given an array of words and a length L, format the text such that each line has exactly L characters and is fully(left and right) justified.
//  
//  You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
//  Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//  
//  Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//  
//  For the last line of text, it should be left justified and no extra space is inserted between words.
//  
//  For example,
//  words:["This", "is", "an", "example", "of", "text", "justification."]
//    L : 16.
//  
//        Return the formatted lines as :
//  [
//      "This    is    an",
//      "example  of text",
//      "justification.  "
//  ]
//  Note : Each word is guaranteed not to exceed L in length.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        while ((words.size() > 0) && (words[0].size() > 0)){
            int currLineLength = words[0].size();
            int currWordIdx = 1;
            while ((currWordIdx < words.size()) && (currLineLength + 1 + words[currWordIdx].size() <= maxWidth)){
                currLineLength += (1 + words[currWordIdx].size());
                currWordIdx++;
            }

            int extraSpaceCount = maxWidth - currLineLength;  // could be distributed evenly or attach to the end if last line
            int minSpacesInserted = 1;
            int bonusSpaceCount = 0;
            string temp = words[0];
            if ((currWordIdx != words.size()) && (currWordIdx != 1)){
                // not the last line
                // modify the parameters for regular lines
                minSpacesInserted += extraSpaceCount / (currWordIdx - 1);
                bonusSpaceCount = extraSpaceCount - ((extraSpaceCount / (currWordIdx - 1)) * (currWordIdx - 1));
            }
            else if (currWordIdx == 1){
                // 1 word line
                temp.insert(temp.size(), string(extraSpaceCount, ' '));
            }
            else{
                // the last line
                if (extraSpaceCount > 0){
                    words.push_back(string(extraSpaceCount - 1, ' '));
                    currWordIdx++;
                }
            }

            for (int i = 1; i < currWordIdx; ++i){
                temp.insert(temp.size(), string(minSpacesInserted, ' '));
                if (bonusSpaceCount){
                    temp.push_back(' ');
                    bonusSpaceCount--;
                }
                temp.insert(temp.size(), words[i]);
            }
            output.push_back(temp);
            words.erase(words.begin(), words.begin() + currWordIdx);
        }

        if (output.size() == 0){
            output.push_back(string(maxWidth, ' '));
        }
        return output;
    }
};


class Solution_OLD {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> output;

        int numCharAccumulated = 0;
        int nextStringStart = 0;
        int extraSpacesToDistribute = 0;
        int numSpaceEvenly = 0;
        int numSpaceRemaining = 0;
        string temp;
        while (words.size() > 0){
            // reset counters
            numCharAccumulated = 0;
            nextStringStart = 0;
            extraSpacesToDistribute = 0; 
            numSpaceEvenly = 0;
            numSpaceRemaining = 0;

            // collect words to be in the line
            numCharAccumulated = words[0].size(); // anyway the first word is always included
            nextStringStart = 1;
            while (words.size() > nextStringStart){
                if (numCharAccumulated + words[nextStringStart].size() + 1 <= L){
                    // the +1 is the space BEFORE the latest word just added in
                    numCharAccumulated += words[nextStringStart].size() + 1;
                    nextStringStart++;
                }
                else{
                    break;
                }
            }

            // check if this is the last line
            if (nextStringStart == words.size()){
                // the last line
                // creat the line
                temp.clear();
                temp += words[0];
                words.erase(words.begin());
                while (words.size() > 0){
                    temp += ' ';
                    temp += words[0];
                    words.erase(words.begin());
                }
                // append the remain spaces
                numSpaceRemaining = L - temp.size();
                for (int i = 0; i < numSpaceRemaining; ++i){
                    temp += ' ';
                }
            
                output.push_back(temp);
            }
            else{
                // normal lines
                // nextStringStart is the first word that cannot be contained in the current line
                // nextStringStart is the num of words that can be contained in the current line, (0, 1,... nextStringStart - 1 --> nextStringStart words)

                // calculate the spaces
                extraSpacesToDistribute = L - numCharAccumulated;  // the +1 is the last space added in the loop, which is not needed

                // there are (nextStringStart - 1) gaps in between nextStringStart words
                // plus the original one single space added in the loop
                numSpaceEvenly = ((nextStringStart == 1) ? 0 : extraSpacesToDistribute / (nextStringStart - 1) + 1);
                numSpaceRemaining = ((nextStringStart == 1) ? 0 : extraSpacesToDistribute % (nextStringStart - 1));

                // creat the line
                temp.clear();
                temp += words[0];
                for (int i = 1; i < nextStringStart; ++i){
                    // append spaces first
                    for (int j = 0; j < numSpaceEvenly; j++){
                        temp += ' ';
                    }
                    if (i <= numSpaceRemaining){
                        temp += ' ';
                    }

                    // append the word
                    temp += words[i];
                }

                // append the remain spaces
                numSpaceRemaining = L - temp.size();
                for (int i = 0; i < numSpaceRemaining; ++i){
                    temp += ' ';
                }

                output.push_back(temp);
                words.erase(words.begin(), words.begin() + nextStringStart);
            }
        } // finish a line

        return output;
    }
};