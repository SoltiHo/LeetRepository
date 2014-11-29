// Given a string S, find the longest palindromic substring in S.You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

#include <string>
#include <unordered_set>
#include <iostream>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution_Hash_UnorderedMap {
public:
    string longestPalindrome(string s) {
        time_t timer_find = 0;
        time_t timer_insert = 0;
        time_t flag = 0;
        vector<time_t> insertTimes;
        time_t maxTime = 0;
        time_t temp = 0;
        unsigned int insertCount = 0;
        const unsigned int sSize = s.size();

        string dummy;
        if (sSize == 0){
            return dummy;
        }
        else if (sSize == 1){
            return s;
        }

        unordered_map<unsigned long long, bool> impossibleMap;
        impossibleMap.reserve( 1 << 20); // 1 million buckets
        unsigned int length = 0;
        unsigned int randomIdx = 0;
        bool mismatchFound = false;
        bool palindromeFound = false;

        // if a certain L doesn't have palindrome, meaning:
        //    - all L + 2, L + 4, ...  are not possible  // 25% removed
        // if a certain L finds a palindrome, meanning:
        //    - all 2, ... L - 1 are not worthy a try    // 50% removed
        vector<unsigned int> lengthsToBeTested(sSize - 1);
        for (unsigned int i = 2; i <= sSize; ++i){
            lengthsToBeTested[i - 2] = i;
        }

        unsigned int lastStart = 0;
        unsigned int lastLength = 1;
        unsigned int lengthIdx = 0;

        while (lengthsToBeTested.size() > 0){
            lengthIdx = lengthsToBeTested.size() >> 1;  // always test the middle
            length = lengthsToBeTested[lengthIdx];
            for (unsigned int startIdx = 0; startIdx + length - 1 < sSize; ++startIdx){
                mismatchFound = false;
                // check if possible or not
                flag = clock();
                if (impossibleMap.find(makeKey(startIdx, length)) != impossibleMap.end()){
                    timer_find += clock() - flag;
                    // already pre-determined impossible, skip
                    continue;
                }
                timer_find += clock() - flag;

                // search from inside out to achieve max info when mismatch found
                unsigned int leftCursor = ((length >> 1) - 1);
                unsigned int rightCursor = ((length + 1) >> 1);
                while (leftCursor != UINT_MAX){
                    if (s[startIdx + leftCursor] != s[startIdx + rightCursor]){
                        // add the impossible combination
                        unsigned int impossibleStart = startIdx + leftCursor;
                        unsigned int impossibleLength = rightCursor - leftCursor + 1;
                        while (impossibleStart != UINT_MAX){
                            flag = clock();
                            insertCount++;
                            impossibleMap.insert({ makeKey(impossibleStart, impossibleLength), true });
                            temp = clock() - flag;
                            if (temp > 0){
                                insertTimes.push_back(temp);
                            }
                            timer_insert += temp;
                            impossibleStart--;
                            impossibleLength += 2;
                        }
                        mismatchFound = true;
                        break; // break the outter while loop
                    }
                    leftCursor--;
                    rightCursor++;
                }

                if (mismatchFound){
                    // meaning current startIdx doesn't work, but other startIdx might work with current length
                    // so this sholud be a continue, not break
                    continue;
                }

                // reaching here means a palindrome found, no need to continue testing this length
                // so this is a break;
                // each found can only go longer, so can directly updating the record
                lastStart = startIdx;
                lastLength = length;
                palindromeFound = true;
                break;
            }

            // prepare for next trial
            if (palindromeFound){
                // meanning shorter lengths are not worthy trying
                lengthsToBeTested.erase(lengthsToBeTested.begin(), lengthsToBeTested.begin() + lengthIdx + 1);
            }
            else {
                // meanning L + 2, L + 4, .... are not worthy trying
                for (unsigned int i = lengthIdx; i < lengthsToBeTested.size();){
                    if ((lengthsToBeTested[i] - length) % 2 == 0){
                        // L + 2N, erase it. and i stay
                        lengthsToBeTested.erase(lengthsToBeTested.begin() + i);
                    }
                    else{
                        // move i
                        i++;
                    }
                }
            }

            palindromeFound = false;
        }

        cout << "insert time: " << timer_insert << endl;
        cout << "find time: " << timer_find << endl;

        for (unsigned int i = 0; i < insertTimes.size(); ++i){
            cout << insertTimes[i] << ", ";
        }
        cout << endl;

        return s.substr(lastStart, lastLength);
    }

    inline unsigned long long makeKey(unsigned int& startIdx, unsigned int& length){
        unsigned long long output = (((unsigned long long)startIdx) << (sizeof(unsigned int) << 3));
        output += length;
        return output;
    }

};

class Solution_BinarySearchLengthRemoval {
public:
    string longestPalindrome(string s) {
        const unsigned int sSize = s.size();

        string dummy;
        if (sSize == 0){
            return dummy;
        }
        else if (sSize == 1){
            return s;
        }

        // unordered_set<unsigned long long> impossibleMap;
        unsigned int length = 0;
        unsigned int randomIdx = 0;
        bool mismatchFound = false;
        bool palindromeFound = false;

        // if a certain L doesn't have palindrome, meaning:
        //    - all L + 2, L + 4, ...  are not possible  // 25% removed
        // if a certain L finds a palindrome, meanning:
        //    - all 2, ... L - 1 are not worthy a try    // 50% removed
        vector<unsigned int> lengthsToBeTested(sSize - 1);
        for (unsigned int i = 2; i <= sSize; ++i){
            lengthsToBeTested[i - 2] = i;
        }

        unsigned int lastStart = 0;
        unsigned int lastLength = 1;
        unsigned int lengthIdx = 0;
        while (lengthsToBeTested.size() > 0){
            lengthIdx = lengthsToBeTested.size() >> 1;  // always test the middle
            length = lengthsToBeTested[lengthIdx];
            for (unsigned int startIdx = 0; startIdx + length - 1 < sSize; ++startIdx){
                mismatchFound = false;
                unsigned int leftCursor = ((length >> 1) - 1);
                unsigned int rightCursor = ((length + 1) >> 1);
                while (leftCursor != UINT_MAX){
                    if (s[startIdx + leftCursor] != s[startIdx + rightCursor]){
                        mismatchFound = true;
                        break; // break the outter while loop
                    }
                    leftCursor--;
                    rightCursor++;
                }

                if (mismatchFound){
                    // meaning current startIdx doesn't work, but other startIdx might work with current length
                    // so this sholud be a continue, not break
                    continue;
                }

                // reaching here means a palindrome found, no need to continue testing this length
                // so this is a break;
                // each found can only go longer, so can directly updating the record
                lastStart = startIdx;
                lastLength = length;
                palindromeFound = true;
                break;
            }

            // prepare for next trial
            if (palindromeFound){
                // meanning shorter lengths are not worthy trying
                lengthsToBeTested.erase(lengthsToBeTested.begin(), lengthsToBeTested.begin() + lengthIdx + 1);
            }
            else {
                // meanning L + 2, L + 4, .... are not worthy trying
                for (unsigned int i = lengthIdx; i < lengthsToBeTested.size();){
                    if ((lengthsToBeTested[i] - length) % 2 == 0){
                        // L + 2N, erase it. and i stay
                        lengthsToBeTested.erase(lengthsToBeTested.begin() + i);
                    }
                    else{
                        // move i
                        i++;
                    }
                }
            }

            palindromeFound = false;
        }

        return s.substr(lastStart, lastLength);
    }
};

class Solution_Hash {
public:
    string longestPalindrome(string s) {
        time_t timer_find = 0;
        time_t timer_insert = 0;
        time_t flag = 0;

        const unsigned int sSize = s.size();

        string dummy;
        if (sSize == 0){
            return dummy;
        }
        else if (sSize == 1){
            return s;
        }

        unordered_set<unsigned long long> impossibleMap;
        unsigned int length = 0;
        unsigned int randomIdx = 0;
        bool mismatchFound = false;
        bool palindromeFound = false;

        // if a certain L doesn't have palindrome, meaning:
        //    - all L + 2, L + 4, ...  are not possible  // 25% removed
        // if a certain L finds a palindrome, meanning:
        //    - all 2, ... L - 1 are not worthy a try    // 50% removed
        vector<unsigned int> lengthsToBeTested(sSize - 1);
        for (unsigned int i = 2; i <= sSize; ++i){
            lengthsToBeTested[i - 2] = i;
        }

        unsigned int lastStart = 0;
        unsigned int lastLength = 1;
        unsigned int lengthIdx = 0;
        while (lengthsToBeTested.size() > 0){
            lengthIdx = lengthsToBeTested.size() >> 1;  // always test the middle
            length = lengthsToBeTested[lengthIdx];
            for (unsigned int startIdx = 0; startIdx + length - 1 < sSize; ++startIdx){
                mismatchFound = false;
                // check if possible or not
                flag = clock();
                if (impossibleMap.find(makeKey(startIdx, length)) != impossibleMap.end()){
                    timer_find += clock() - flag;
                    // already pre-determined impossible, skip
                    continue;
                }
                timer_find += clock() - flag;

                // search from inside out to achieve max info when mismatch found
                unsigned int leftCursor = ((length >> 1) - 1);
                unsigned int rightCursor = ((length + 1) >> 1);
                while (leftCursor != UINT_MAX){
                    if (s[startIdx + leftCursor] != s[startIdx + rightCursor]){
                        // add the impossible combination
                        unsigned int impossibleStart = startIdx + leftCursor;
                        unsigned int impossibleLength = rightCursor - leftCursor + 1;
                        while (impossibleStart != UINT_MAX){
                            flag = clock();
                            impossibleMap.insert(makeKey(impossibleStart, impossibleLength));
                            timer_insert += clock() - flag;
                            impossibleStart--;
                            impossibleLength += 2;
                        }
                        mismatchFound = true;
                        break; // break the outter while loop
                    }
                    leftCursor--;
                    rightCursor++;
                }

                if (mismatchFound){
                    // meaning current startIdx doesn't work, but other startIdx might work with current length
                    // so this sholud be a continue, not break
                    continue;
                }

                // reaching here means a palindrome found, no need to continue testing this length
                // so this is a break;
                // each found can only go longer, so can directly updating the record
                lastStart = startIdx;
                lastLength = length;
                palindromeFound = true;
                break;
            }

            // prepare for next trial
            if (palindromeFound){
                // meanning shorter lengths are not worthy trying
                lengthsToBeTested.erase(lengthsToBeTested.begin(), lengthsToBeTested.begin() + lengthIdx + 1);
            }
            else {
                // meanning L + 2, L + 4, .... are not worthy trying
                for (unsigned int i = lengthIdx; i < lengthsToBeTested.size();){
                    if ((lengthsToBeTested[i] - length) % 2 == 0){
                        // L + 2N, erase it. and i stay
                        lengthsToBeTested.erase(lengthsToBeTested.begin() + i);
                    }
                    else{
                        // move i
                        i++;
                    }
                }
            }

            palindromeFound = false;
        }
        
        cout << "insert time: " << timer_insert << endl;
        cout << "find time: " << timer_find<< endl;

        return s.substr(lastStart, lastLength);
    }

    inline unsigned long long makeKey(unsigned int& startIdx, unsigned int& length){
        unsigned long long output = (((unsigned long long)startIdx) << (sizeof(unsigned int) << 3));
        output += length;
        return output;
    }
};

class Solution_DP {
public:
    string longestPalindrome(string s) {
        const unsigned int sSize = s.size();

        string dummy;
        if (sSize == 0){
            return dummy;
        }
        else if (sSize == 1){
            return s;
        }

        unsigned int maxStart = 0;
        unsigned int maxLength = 1;
        unsigned int currLength = 0;
        unsigned int currStart = 0;

        bool mismatchFound = false;
        for (unsigned int i = 0; i < sSize; ++i){
            for (currStart = 0; currStart < i; ++currStart){
                currLength = i - currStart + 1;
                if (currLength <= maxLength) {
                    // no need to continue exploring
                    break;
                }

                unsigned int leftCursor = currStart;
                unsigned int rightCursor = i;
                mismatchFound = false;
                while (leftCursor < rightCursor){
                    if (s[leftCursor] != s[rightCursor]){
                        // mismatch
                        mismatchFound = true;
                        break;
                    }
                    leftCursor++;
                    rightCursor--;
                }

                if (!mismatchFound){
                    // palindrome found
                    if (maxLength < currLength){
                        maxLength = currLength;
                        maxStart = currStart;
                    }
                }
            }

        }

        return s.substr(maxStart, maxLength);
    }
};