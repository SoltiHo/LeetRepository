//  Given two words(start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that :
//  
//  Only one letter can be changed at a time
//  Each intermediate word must exist in the dictionary
//  For example,
//  
//  Given :
//        start = "hit"
//        end = "cog"
//        dict = ["hot", "dot", "dog", "lot", "log"]
//        As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//        return its length 5.
//  
//    Note :
//         Return 0 if there is no such transformation sequence.
//         All words have the same length.
//         All words contain only lowercase alphabetic characters.

#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // basic cases
        if (start == end){
            return 0;
        }

        vector<string> dictVector;
        vector<int> SrcFront;

        int idx = 0;
        int startInDict = -1;
        int endInDict = -1;
        while (dict.size() > 0){
            if (calculateWordDistance(*dict.begin(), start) == 0){
                startInDict = idx;
            }

            if (calculateWordDistance(*dict.begin(), end) == 0){
                endInDict = idx;
            }
            dictVector.push_back(*dict.begin());
            dict.erase(dict.begin());
            idx++;
        }


        if (endInDict == -1){
            dictVector.push_back(end);
            endInDict = dictVector.size() - 1;
        }

        if (startInDict == -1){
            dictVector.push_back(start);
            startInDict = dictVector.size() - 1;
        }

        vector<int> candidates;
        int distSrc = 0;
        int distDst = 0;
        bool singleJumpFound = false;
        for (int i = 0; i < dictVector.size(); ++i){
            if (dictVector[i] == start){
                SrcFront.push_back(i);
            }
            else{
                candidates.push_back(i);
            }
        }

        int candSize = candidates.size();;
        int srcFrontSize = SrcFront.size();
        int srcIdxStart = 0;
        int distance = 1;
        while (true){
            distance++;
            for (int i = srcIdxStart; i < srcFrontSize; ++i){
                for (int j = 0; j < candSize; ++j){
                    distSrc = calculateWordDistance(dictVector[SrcFront[i]], dictVector[candidates[j]]);
                    if (distSrc == 1){
                        if (candidates[j] == endInDict){
                            // reach
                            return distance;
                        }
                        else{
                            SrcFront.push_back(candidates[j]);
                            candidates.erase(candidates.begin() + j);
                            j--;
                            candSize--;
                        }
                    }
                }
            }
            if (SrcFront.size() == srcFrontSize){
                // src front did not expand in the last loop
                break;
            }
            srcIdxStart = srcFrontSize;
            srcFrontSize = SrcFront.size();
            candSize = candidates.size();
        }
        return 0;
    }

    inline int calculateWordDistance(const string& a, const string& b){
        const int size = a.size();
        int distance = 0;
        for (int i = 0; i < size; ++i){
            if (a[i] != b[i]){
                distance++;
            }
        }
        return distance;
    }
};
