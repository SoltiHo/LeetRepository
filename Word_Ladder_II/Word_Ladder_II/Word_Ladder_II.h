// Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :
// 
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
// 
// Given :
//       start = "hit"
//       end = "cog"
//       dict = ["hot", "dot", "dog", "lot", "log"]
//       Return
//       [
//           ["hit", "hot", "dot", "dog", "cog"],
//           ["hit", "hot", "lot", "log", "cog"]
//       ]
// Note:
// All words have the same length.
// All words contain only lowercase alphabetic characters.
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> output;
        // basic cases
        if (start == end){
            output.push_back({ start });
            return output;
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
        for (unsigned int i = 0; i < dictVector.size(); ++i){
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
        bool stepRefresh = false;
        vector<int>* parentNodeVector;
        bool targetReached = false;
        parentNodeVector = new vector<int>[dictVector.size()]();
        while (true){
            distance++;
            for (int i = srcIdxStart; i < srcFrontSize; ++i){
                for (int j = 0; j < candSize; ++j){
                    distSrc = calculateWordDistance(dictVector[SrcFront[i]], dictVector[candidates[j]]);
                    if (distSrc == 1){
                        parentNodeVector[j].push_back(SrcFront[i]);
                        if (candidates[candidates[j]] == endInDict){
                            // reach
                            targetReached = true;
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
            if (targetReached){
                break;
            }
        }

        // recycle some memory
        candidates.clear();
        SrcFront.clear();

        // reconstruct the paths
        vector<string> currSolution;
        reconstructSolution(output, dictVector, currSolution, parentNodeVector, endInDict, startInDict);

        return output;
    }

    void reconstructSolution(vector<vector<string>>& output, vector<string>& dictVector, vector<string>& currSolution, vector<int>* parentNodeVector, int currIdx, int startIdx){
        const int choiceCount = parentNodeVector[currIdx].size();
        for (int i = 0; i < choiceCount; ++i){
            currSolution.insert(currSolution.begin(), dictVector[currIdx]);
            if (currIdx == startIdx){
                output.push_back(currSolution);
            }
            else{
                reconstructSolution(output, dictVector, currSolution, parentNodeVector, parentNodeVector[currIdx][i], startIdx);
            }
            currSolution.erase(currSolution.begin());

        }
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

class Solution_LatestTrial_ {
public:
    struct SolutionNode {
        int wordIdx;
        int prevSolutionNodeIdx;
    };
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // preprocessing
        dict.erase(start);
        dict.erase(end);
        vector<string> words;
        vector<int> candidateIdx;
        words.push_back(start);
        words.push_back(end);
        for (auto& w : dict){
            candidateIdx.push_back(words.size());
            words.push_back(w);
        }

        // building solution
        vector<SolutionNode> pathBook;
        pathBook.push_back({0, -1});  // root.  every solution should start from this node

        int stepCount = 0;
        int currStepStartIdx = 0;
        int currStepEndIdx = 0;
        int nextStepStartIdx;
        int nextStepEndIdx;
        while (dict.size() > 0){
            for (int i = currStepStartIdx; i <= currStepEndIdx; ++i){
                // expand
                for (int ci = 0; ci < candidateIdx.size(); ++ci){
                    if (reachable(words[pathBook[i].wordIdx], words[candidateIdx[ci]])){
                        pathBook.push_back({ candidateIdx[ci], i });

                    }
                }
            }
        }


    }

    bool reachable(string& a, string& b){
        int i = a.size() - 1;
        bool diffFound = false;
        while (i >= 0){
            if (a[i] != b[i]){
                if (diffFound){
                    return false;
                }
                diffFound = true;
            }
            i--;
        }
        return true;
    }
};