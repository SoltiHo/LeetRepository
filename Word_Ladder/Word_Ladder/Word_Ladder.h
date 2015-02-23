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
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
using namespace std;


class Solution_Dijkstra {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // convert dict to a vector
        this->dict.push_back(start);
        this->dict.push_back(end);
        while (dict.size() > 0){
            if ((*dict.begin() != start) && (*dict.begin() != end)){
                this->dict.push_back(*dict.begin());
            }
            dict.erase(dict.begin());
        }

        // init word location table
        const unsigned int wordCount = this->dict.size();
        this->wordLocationTable.insert(this->wordLocationTable.begin(), wordCount, 0);

        // build node heap
        unsigned int currDistance;
        for (unsigned int i = 1; i < wordCount; ++i){
            currDistance = calculateWordDistance(start, this->dict[i]);
            if (currDistance == 1){
                // there is an edge
                insertHeap(i, 1);
            }
            else{
                // more than one char differs. since only 1 char change is allowed, this is a node with infinite cost
                insertHeap(i, UINT_MAX);
            }
        }

        // init node sets for Dijkstra
        unordered_map<unsigned int, unsigned int> V; // not yet processed
        unordered_map<unsigned int, unsigned int> X; // processed
        for (unsigned int i = 1; i < wordCount; ++i){
            V.insert({ i, 0 });
        }
        X.insert({ 0, 0 }); // 0 is the start
        
        // Dijkstra
        unsigned int d = 0;
        unsigned int latestWordId = 0;
        while (X.count(1) == 0) {
            if (this->heap[0].cost == UINT_MAX){
                // can't proceed.
                d = 0;
                break;
            }
            d = this->heap[0].cost;
            latestWordId = this->heap[0].wordId;
            X.insert({ latestWordId, d });
            V.erase(this->heap[0].wordId);
            deleteHeap(latestWordId, 0);
            for (auto& remainingNode : V){
                if ((calculateWordDistance(this->dict[latestWordId], this->dict[remainingNode.first]) == 1) &&
                    (d + 1 < this->heap[this->wordLocationTable[remainingNode.first]].cost)){
                    // update heap
                    if (this->heap[this->wordLocationTable[remainingNode.first]].cost > d + 1){
                        this->heap[this->wordLocationTable[remainingNode.first]].cost = d + 1;
                        swapToRightHeapLocation(this->wordLocationTable[remainingNode.first]);
                    }
                }
            }
        }        
        return (X[1] == UINT_MAX ? 0 : X[1] + 1);
    }


    // heap realted implementation
    struct HeapNode {
        unsigned int wordId;
        unsigned int cost;
        HeapNode(unsigned int wID, int c) : wordId(wID), cost(c) {};
    };

    // input
    //   id: the word id, the index in the dict array
    //   cost: the heap key value, which is the distance to the processed set
    // output
    //   the vector idx where the node finally lands on
    void insertHeap(unsigned int id, int cost){
        HeapNode newNode(id, cost);
        this->heap.push_back(newNode);
        this->wordLocationTable[id] = this->heap.size() - 1;
        this->wordLocationTable[id] = swapToRightHeapLocation(this->heap.size() - 1);
    };

    // input
    //   id: the word id, the index in the dict array
    //   locationIdx: the vector idx of the node to be deleted
    // output
    //   return true if deletion completes correctly, otherwise false.
    bool deleteHeap(unsigned int id, unsigned int locationIdx){
        const unsigned int heapSize = this->heap.size();
        if (locationIdx >= heapSize){
            return false;
        }
        if (this->heap[locationIdx].wordId != id){
            return false;
        }
        swap(this->wordLocationTable[this->heap[locationIdx].wordId], this->wordLocationTable[this->heap[heapSize - 1].wordId]);
        swap(this->heap[locationIdx], this->heap[heapSize - 1]);
        this->heap.pop_back();
        swapToRightHeapLocation(locationIdx);
        return true;
    }


    // for node idx i, parents --> (i - 1)/2,  children --> 2i + 1, 2i + 2
    //              0, no parents, children 1, 2
    //              1, parent 0  , children 3, 4
    //              2, parent 0  , children 5, 6
    unsigned int swapToRightHeapLocation(unsigned int newNodeIdx){
        const unsigned int heapSize = this->heap.size();
        if ((heapSize == 0) || (heapSize == 1)){
            return 0;
        }
        unsigned int parentIdx = (newNodeIdx > 0) ? ((newNodeIdx - 1) >> 1) : 0;
        unsigned int currNode = newNodeIdx;
        if (this->heap[newNodeIdx].cost < this->heap[parentIdx].cost){
            // smaller than parent, needs to go up
            while (this->heap[currNode].cost < this->heap[parentIdx].cost){
                // before swapping, need to take care of location array
                swap(this->wordLocationTable[this->heap[parentIdx].wordId], this->wordLocationTable[this->heap[currNode].wordId]);

                // swap the node
                swap(this->heap[currNode], this->heap[parentIdx]);
                currNode = parentIdx;
                parentIdx = parentIdx > 0 ? ((parentIdx - 1) >> 1) : 0;
            }
        }
        else if ((this->heap[newNodeIdx].cost > this->heap[parentIdx].cost) || (newNodeIdx == parentIdx)){
            // compare to children if any            
            unsigned int childIdx1 = ((newNodeIdx << 1) + 1) >= heapSize ? heapSize - 1 : ((newNodeIdx << 1) + 1); // be the last one if no child
            unsigned int childIdx2 = ((newNodeIdx << 1) + 2) >= heapSize ? heapSize - 1 : ((newNodeIdx << 1) + 2); // be the last one if only 1 child or no child
            unsigned int smallerChild = (this->heap[childIdx1].cost > this->heap[childIdx2].cost) ? childIdx2 : childIdx1;

            while ((((currNode << 1) + 1) < heapSize) &&  // guarantee at least one child
                (this->heap[currNode].cost > this->heap[smallerChild].cost))
            {
                // before swapping, need to take care of location array
                swap(this->wordLocationTable[this->heap[currNode].wordId], this->wordLocationTable[this->heap[smallerChild].wordId]);

                // swap the node
                swap(this->heap[currNode], this->heap[smallerChild]);
                currNode = smallerChild;
                childIdx1 = ((currNode << 1) + 1) >= this->heap.size() ? this->heap.size() - 1 : ((currNode << 1) + 1);
                childIdx2 = ((currNode << 1) + 2) >= this->heap.size() ? this->heap.size() - 1 : ((currNode << 1) + 2);
                smallerChild = (this->heap[childIdx1].cost > this->heap[childIdx2].cost) ? childIdx2 : childIdx1;
            }
        }

        return currNode;
    }

    unsigned int calculateWordDistance(const string& a, const string& b){
        const int size = a.size();
        unsigned int distance = 0;
        for (int i = 0; i < size; ++i){
            if (a[i] != b[i]){
                distance++;
            }
        }
        return distance;
    }


    // Data members
    vector<HeapNode> heap;
    vector<string> dict; // the 1st is start, the 2nd is end, followed by others
    vector<int> wordLocationTable;
};

class Solution_Dijkstra_Steve : public Solution_Dijkstra {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // convert dict to a vector
        this->dict.push_back(start);
        this->dict.push_back(end);
        while (dict.size() > 0){
            if ((*dict.begin() != start) && (*dict.begin() != end)){
                this->dict.push_back(*dict.begin());
            }
            dict.erase(dict.begin());
        }

        // init word location table
        const unsigned int wordCount = this->dict.size();
        this->wordLocationTable.insert(this->wordLocationTable.begin(), wordCount, 0);

        // build relevant maps
        unordered_map<string, unordered_set<unsigned int>> wordKeys;
        unordered_map<string, unordered_set<unsigned int>>::iterator wordKeysIt;
        string key;
        for (unsigned int wordId = 0; wordId < wordCount; ++wordId){
            for (unsigned int i = 0; i < this->dict[wordId].size(); ++i){
                key = this->dict[wordId];
                key.erase(i, 1);
                wordKeysIt = wordKeys.find(key);
                if (wordKeysIt == wordKeys.end()){
                    // first time
                    wordKeys.insert({ key, { wordId } });
                }
                else{
                    wordKeys[key].insert(wordId);
                }
            }
        }

        unordered_map<unsigned int, unordered_set<unsigned int>> releveantWordMap;
        for (unsigned int wordId = 0; wordId < wordCount; ++wordId){
            for (unsigned int i = 0; i < this->dict[wordId].size(); ++i){
                key = this->dict[wordId];
                key.erase(i, 1);
                wordKeysIt = wordKeys.find(key);
                if (releveantWordMap.find(wordId) == releveantWordMap.end()){
                    // first time
                    releveantWordMap.insert({ wordId, wordKeysIt->second });
                }
                else{
                    releveantWordMap[wordId].insert(wordKeysIt->second.begin(), wordKeysIt->second.end());
                }
            }

            releveantWordMap[wordId].erase(wordId);
        }

        wordKeys.clear();
        validateRelevantNodeMap(releveantWordMap);

        // build node heap
        for (unsigned int i = 1; i < wordCount; ++i){
            if (releveantWordMap[0].find(i) != releveantWordMap[0].end()){
                // there is an edge
                insertHeap(i, 1);
            }
            else{
                // more than one char differs. since only 1 char change is allowed, this is a node with infinite cost
                insertHeap(i, UINT_MAX);
            }
        }

        // init node sets for Dijkstra
        unordered_map<unsigned int, unsigned int> V; // not yet processed
        unordered_map<unsigned int, unsigned int> X; // processed
        for (unsigned int i = 1; i < wordCount; ++i){
            V.insert({ i, 0 });
        }
        X.insert({ 0, 0 }); // 0 is the start

        // Dijkstra
        unsigned int d = 0;
        unsigned int latestWordId = 0;
        while (X.count(1) == 0) {
            if (this->heap[0].cost == UINT_MAX){
                // can't proceed.
                d = 0;
                break;
            }
            d = this->heap[0].cost;
            latestWordId = this->heap[0].wordId;
            X.insert({ latestWordId, d });
            V.erase(this->heap[0].wordId);
            deleteHeap(latestWordId, 0);

            for (auto& relevantIdx : releveantWordMap[latestWordId]){
                if (V.find(relevantIdx) != V.end()){
                    // latestWordId is still in V
                    if (d + 1 < this->heap[this->wordLocationTable[relevantIdx]].cost){
                        // worth update
                        this->heap[this->wordLocationTable[relevantIdx]].cost = d + 1;
                        swapToRightHeapLocation(this->wordLocationTable[relevantIdx]);
                    }
                }
            }
        }
        return (X[1] == UINT_MAX ? 0 : X[1] + 1);
    }

    bool validateRelevantNodeMap(unordered_map<unsigned int, unordered_set<unsigned int>>& releveantWordMap){
        // from map to words
        for (unsigned int i = 0; i < releveantWordMap.size(); ++i){
            for (auto& relevantIdx : releveantWordMap[i]){
                if (calculateWordDistance(this->dict[i], this->dict[relevantIdx]) != 1){
                    return false;
                }
            }
        }

        // from words to map
        for (unsigned int i = 0; i < this->dict.size(); ++i){
            for (unsigned int j = 0; j < i; ++j){
                if (calculateWordDistance(this->dict[i], this->dict[j]) == 1){
                    // i must have j, and j must have i
                    if ((releveantWordMap[i].find(j) == releveantWordMap[i].end()) ||
                        (releveantWordMap[j].find(i) == releveantWordMap[j].end())){
                        // not found
                        return false;
                    }
                }
            }
        }

        return true;
    }
};




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
