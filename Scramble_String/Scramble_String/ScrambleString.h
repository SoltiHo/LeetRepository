//   Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//   
//   Below is one possible representation of s1 = "great":
//   
//   great
//   / \
//   gr    eat
//   / \ / \
//   g   r  e   at
//   / \
//   a   t
//   To scramble the string, we may choose any non - leaf node and swap its two children.
//   
//   For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//   
//   rgeat
//   / \
//   rg    eat
//   / \ / \
//   r   g  e   at
//   / \
//   a   t
//   We say that "rgeat" is a scrambled string of "great".
//   
//   Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//   
//   rgtae
//   / \
//   rg    tae
//   / \ / \
//   r   g  ta  e
//   / \
//   t   a
//   We say that "rgtae" is a scrambled string of "great".
//   
//   Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

#include <string>
using namespace std;

#define NUM_CHARS 26
int* histogram_original = NULL;
int* histogram_scramble = NULL;
const char* pOriginalString = NULL;
const char* pScrambledString = NULL;
int stringSize = 0;

inline void calculateHistogrm(const char* s, const int startIndex, const int length, int* hist){
    // initialize
    memset(hist, 0, sizeof(int)* NUM_CHARS);

    // debugging only
    //cout << "\"";
    //for (int i = 1; i <= length; ++i){
    //    cout << s[startIndex + i - 1];
    //}
    //cout << "\"" << endl << endl;

    // start calculating
    // 'a' ~ 'z' = 0x61 ~ 6x7A
    for (int i = length; i; --i){
        hist[s[startIndex + i - 1] - 0x61]++;
    }
}

inline bool isHistogramIdentical(int* hist1, int* hist2){
    return (memcmp(hist1, hist2, sizeof(int)* NUM_CHARS) == 0);
}

enum MatchPattern {
    NONE,
    FROM_HEAD,
    FROM_TAIL,
    BOTH
};
bool reject(const int startIndex, const int entireIntervalSize, const int cutSize, const int startIndexScramble, MatchPattern& headMatched){
    // startIndex = 0 ... stringSize - 1
    // startIndexScramble = 0 ... stringSize - 1
    // cutSize = 1 ..... entireIntervalSize - 1
    // entireIntervalSize apply for both original string and scramble string

    bool histCompareResult_fromHead_Left = false;
    bool histCompareResult_fromTail_Left = false;
    bool histCompareResult_fromHead_Right = false;
    bool histCompareResult_fromTail_Right = false;
    headMatched = NONE;
    // check the smaller part first
    if (cutSize <= (entireIntervalSize >> 1)){
        // left is smaller
        calculateHistogrm(pOriginalString, startIndex, cutSize, histogram_original);
        calculateHistogrm(pScrambledString, startIndexScramble, cutSize, histogram_scramble); // to match the head
        histCompareResult_fromHead_Left = isHistogramIdentical(histogram_original, histogram_scramble);

        calculateHistogrm(pScrambledString, startIndexScramble + entireIntervalSize - cutSize, cutSize, histogram_scramble); // or, to match the tail
        histCompareResult_fromTail_Left = isHistogramIdentical(histogram_original, histogram_scramble);

        // one of them must be true
        if ((histCompareResult_fromHead_Left == false) && (histCompareResult_fromTail_Left == false)){
            // neither of them are possible, so no need to explore more, reject this candidate
            return true;
        }

        // then compare the right
        calculateHistogrm(pOriginalString, startIndex + cutSize, entireIntervalSize - cutSize, histogram_original);
        calculateHistogrm(pScrambledString, startIndexScramble, entireIntervalSize - cutSize, histogram_scramble); // to match the head
        histCompareResult_fromHead_Right = isHistogramIdentical(histogram_original, histogram_scramble);

        calculateHistogrm(pScrambledString, startIndexScramble + cutSize, entireIntervalSize - cutSize, histogram_scramble); // or, to match the tail
        histCompareResult_fromTail_Right = isHistogramIdentical(histogram_original, histogram_scramble);

        // one of them must be true
        if ((histCompareResult_fromHead_Right == false) && (histCompareResult_fromTail_Right == false)){
            // neither of them are possible, so no need to explore more, reject this candidate
            return true;
        }
    }
    else{
        // the right is smaller
        calculateHistogrm(pOriginalString, startIndex + cutSize, entireIntervalSize - cutSize, histogram_original);
        calculateHistogrm(pScrambledString, startIndexScramble, entireIntervalSize - cutSize, histogram_scramble); // to match the head
        histCompareResult_fromHead_Right = isHistogramIdentical(histogram_original, histogram_scramble);

        calculateHistogrm(pScrambledString, startIndexScramble + cutSize, entireIntervalSize - cutSize, histogram_scramble); // or, to match the tail
        histCompareResult_fromTail_Right = isHistogramIdentical(histogram_original, histogram_scramble);

        // one of them must be true
        if ((histCompareResult_fromHead_Right == false) && (histCompareResult_fromTail_Right == false)){
            // neither of them are possible, so no need to explore more, reject this candidate
            return true;
        }

        // then compare the left
        calculateHistogrm(pOriginalString, startIndex, cutSize, histogram_original);
        calculateHistogrm(pScrambledString, startIndexScramble, cutSize, histogram_scramble); // to match the head
        histCompareResult_fromHead_Left = isHistogramIdentical(histogram_original, histogram_scramble);

        calculateHistogrm(pScrambledString, startIndexScramble + entireIntervalSize - cutSize, cutSize, histogram_scramble); // or, to match the tail
        histCompareResult_fromTail_Left = isHistogramIdentical(histogram_original, histogram_scramble);

        // one of them must be true
        if ((histCompareResult_fromHead_Left == false) && (histCompareResult_fromTail_Left == false)){
            // neither of them are possible, so no need to explore more, reject this candidate
            return true;
        }
    }

    if ((histCompareResult_fromHead_Left) && (histCompareResult_fromTail_Right) && (histCompareResult_fromTail_Left) && (histCompareResult_fromHead_Right)){
        headMatched = BOTH;
    }
    else if ((histCompareResult_fromHead_Left) && (histCompareResult_fromTail_Right)){
        headMatched = FROM_HEAD;
    }
    else if ((histCompareResult_fromTail_Left) && (histCompareResult_fromHead_Right)){
        headMatched = FROM_TAIL;
    }
    else{
        headMatched = NONE;
        return true;
    }
    return false;
}


bool solveByBackTracking(const int startIndex, const int entireIntervalSize, const int cutSize, const int startIndexScramble){
    // filter out basic cases
    if (entireIntervalSize <= 1){
        return true;
    }

    if (memcmp(pOriginalString + startIndex, pScrambledString + startIndexScramble, sizeof(char)* entireIntervalSize) == 0){
        return true;
    }


    // reject
    MatchPattern match;
    if (reject(startIndex, entireIntervalSize, cutSize, startIndexScramble, match)){
        return false;
    }

    // accept
    if (entireIntervalSize <= 2){
        return true;
    }

    // recursive
    int subintervalSizeLeft = 0;
    int subintervalSizeRight = 0;
    bool leftSubintervalPassed = false;
    bool rightSubintervalPassed = false;
    switch (match){
    case NONE:
        return false;
        break;
    case FROM_HEAD:
        subintervalSizeLeft = cutSize;
        subintervalSizeRight = entireIntervalSize - cutSize;

        if (subintervalSizeLeft == 1){
            leftSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeLeft; ++i){
            if (solveByBackTracking(startIndex, subintervalSizeLeft, i, startIndexScramble)){
                leftSubintervalPassed = true;
                break;
            }
        }

        if (subintervalSizeRight == 1){
            rightSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeRight; ++i){
            if (solveByBackTracking(startIndex + cutSize, subintervalSizeRight, i, startIndexScramble + cutSize)){
                rightSubintervalPassed = true;
                break;
            }
        }

        if ((leftSubintervalPassed) && (rightSubintervalPassed)){
            return true;
        }
        else{
            return false;
        }
        break;
    case FROM_TAIL:
        subintervalSizeLeft = cutSize; 
        subintervalSizeRight = entireIntervalSize - cutSize;

        if (subintervalSizeLeft == 1){
            leftSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeLeft; ++i){
            if (solveByBackTracking(startIndex, subintervalSizeLeft, i, startIndexScramble + entireIntervalSize - cutSize)){
                leftSubintervalPassed = true;
                break;
            }
        }

        if (subintervalSizeRight == 1){
            rightSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeRight; ++i){
            if (solveByBackTracking(startIndex + cutSize, subintervalSizeRight, i, startIndexScramble)){
                rightSubintervalPassed = true;
                break;
            }
        }

        if ((leftSubintervalPassed) && (rightSubintervalPassed)){
            return true;
        }
        else{
            return false;
        }
        break;
    case BOTH:
        // try from head
        subintervalSizeLeft = cutSize;
        subintervalSizeRight = entireIntervalSize - cutSize;

        if (subintervalSizeLeft == 1){
            leftSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeLeft; ++i){
            if (solveByBackTracking(startIndex, subintervalSizeLeft, i, startIndexScramble)){
                leftSubintervalPassed = true;
                break;
            }
        }

        if (subintervalSizeRight == 1){
            rightSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeRight; ++i){
            if (solveByBackTracking(startIndex + cutSize, subintervalSizeRight, i, startIndexScramble + cutSize)){
                rightSubintervalPassed = true;
                break;
            }
        }

        if ((leftSubintervalPassed) && (rightSubintervalPassed)){
            return true;
        }

        // try from tail
        leftSubintervalPassed = false;
        rightSubintervalPassed = false;

        if (subintervalSizeLeft == 1){
            leftSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeLeft; ++i){
            if (solveByBackTracking(startIndex, subintervalSizeLeft, i, startIndexScramble + entireIntervalSize - cutSize)){
                leftSubintervalPassed = true;
                break;
            }
        }

        if (subintervalSizeRight == 1){
            rightSubintervalPassed = true;
        }
        for (int i = 1; i < subintervalSizeRight; ++i){
            if (solveByBackTracking(startIndex + cutSize, subintervalSizeRight, i, startIndexScramble)){
                rightSubintervalPassed = true;
                break;
            }
        }

        if ((leftSubintervalPassed) && (rightSubintervalPassed)){
            return true;
        }
        else{
            return false;
        }

        break;
    default:
        return false;
        break;
    }
}



class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int s1Size = s1.size();
        const int s2Size = s2.size();
        if (s1Size != s2Size){
            return false;
        }
        else if (s1Size == 1){
            return (s1[0] == s2[0]);
        }
        else if (s1Size == 2){
            if (((s1[0] == s2[0]) && (s1[1] == s2[1])) ||
                ((s1[0] == s2[1]) && (s1[1] == s2[0])))
            {
                return true;
            }
            else{
                return false;
            }

        }


        histogram_original = new int[NUM_CHARS];
        histogram_scramble = new int[NUM_CHARS];
        pOriginalString = s1.c_str();
        pScrambledString = s2.c_str();

        bool result = false;
        // loop throught first cut, any of them succeed then pass
        for (int i = 1; i < s1Size; ++i){
            if (solveByBackTracking(0, s1Size, i, 0)){
                result = true;
                break;
            }
        }


        delete[] histogram_original;
        delete[] histogram_scramble;
        return result;
    }
};


