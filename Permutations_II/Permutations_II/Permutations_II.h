//  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//  
//  For example,
//  [1, 1, 2] have the following unique permutations :
//  [1, 1, 2], [1, 2, 1], and[2, 1, 1].

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution_LatestTrial {
public:
    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<vector<int>> output;
        const int numSize = num.size();
        if (numSize > 0){
            permu(num, numSize, 0, output);
        }
        return output;
    }

    void permu(vector<int>& num, const int numSize, const int currIdx, vector<vector<int>>& output){
        if (currIdx == numSize - 1){
            output.push_back(num);
        }
        else{
            unordered_set<int> swapped;
            for (int i = currIdx; i < numSize; ++i){
                if (swapped.count(num[i]) == 0){
                    // first time
                    swapped.insert(num[i]);
                    swap(num[currIdx], num[i]);
                    permu(num, numSize, currIdx + 1, output);
                    swap(num[currIdx], num[i]);
                }
            }
        }
    }
};
class Solution {
public:

    struct ListNode {
        vector<int> set;
        ListNode* next;
        ListNode(vector<int> s) : set(s), next(NULL){};
    };

    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<int> selected;
        unordered_map<int, void*>* pRootTable = new unordered_map<int, void*>;
        this->testedSetTable = new unordered_map<int, ListNode*>[num.size()];
        solveByRecursive(selected, num, 0, pRootTable, false);

        // clean up is a whole mess
        // skip...
        return this->output;
    }

    void solveByRecursive(vector<int> selected, vector<int> candidates, int layer, void* pHashTable, bool atLeastOneNumDifferent){
        if (candidates.size() == 0){
            if (atLeastOneNumDifferent){
                this->output.push_back(selected);
            }
        }
        else{
            if (!atLeastOneNumDifferent){
                // check if current set was tested before or not
                unordered_map<int, ListNode*>::iterator it_set;
                int key = generateSetKey(candidates);
                it_set = this->testedSetTable[layer].find(key);
                if (it_set == this->testedSetTable[layer].end()){
                    // new set, never tested before
                    ListNode* pNewNode = new ListNode(candidates);
                    this->testedSetTable[layer].insert({ key, pNewNode });
                }
                else{
                    // key hit, but not necessary tested before.  
                    // it could be two sets generating the same key
                    if (testedBefore(candidates, it_set->second)){
                        // tested before, no need to continue
                        return;
                    }
                    // just a duplicated key, so append the new node and continue trying
                }
            }

            unordered_map<int, void*>* pHash = (unordered_map<int, void*>*)pHashTable;
            unordered_map<int, void*>::iterator it;
            void* pNextLevelHash = NULL;
            int toBeTested = 0;

            for (int i = 0; i < candidates.size(); ++i){
                atLeastOneNumDifferent = false;
                toBeTested = candidates[i];

                it = pHash->find(toBeTested);
                if (it == pHash->end()){
                    // at least one thing new
                    atLeastOneNumDifferent = true;;
                    pNextLevelHash = new unordered_map<int, void*>;
                    pHash->insert({ toBeTested, pNextLevelHash });
                }
                else{
                    pNextLevelHash = it->second;
                }

                selected.push_back(toBeTested);
                candidates.erase(candidates.begin() + i);
                solveByRecursive(selected, candidates, layer + 1, pNextLevelHash, atLeastOneNumDifferent);

                // restore
                selected.pop_back();
                candidates.insert(candidates.begin() + i, toBeTested);
            }
        }
    }

    inline int generateSetKey(const vector<int> set){
        int output = 0;
        const int setSize = set.size();
        for (int i = 0; i < setSize; ++i){
            output ^= set[i];
        }
        return output;
    }

    bool testedBefore(const vector<int>& newSet, ListNode* pHead){
        ListNode* pCurrNode = pHead;
        ListNode* pPrevNode = NULL;
        while (pCurrNode){
            if (setEqual(pCurrNode->set, newSet)){
                // the same, really tested before
                return true;
            }
            pPrevNode = pCurrNode;
            pCurrNode = pCurrNode->next;
        }

        pPrevNode->next = new ListNode(newSet);
        return false;
    }

    bool setEqual(vector<int> a, vector<int> b){
        if (a.size() != b.size()){
            return false;
        }

        bool matchFound = false;
        while (a.size() > 0){
            matchFound = false;
            for (int j = 0; j < b.size(); ++j){
                if (a[0] == b[j]){
                    matchFound = true;
                    b.erase(b.begin() + j);
                    a.erase(a.begin());
                    break;
                }
            }
            if (!matchFound){
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> output;
    unordered_map<int, ListNode*>* testedSetTable;
    int maxLayer;
};

class Solution_ByMasterSteve {
public:


    vector<vector<int>> permuteUnique(vector<int> &num) {
        const int numSize = num.size();
        unordered_map<int, int> histogram;
        unordered_map<int, int>::iterator it;

        vector<int> candidates;
        vector<int> countArray;
        for (int i = 0; i < numSize; ++i){
            it = histogram.find(num[i]);
            if (it == histogram.end()){
                // not found, insert new
                histogram.insert({ num[i], 1 });
                candidates.push_back(num[i]);
            }
            else{
                // previously exist, increment counter
                it->second++;
            }
        }
        for (vector<int>::iterator it_cand = candidates.begin(); it_cand != candidates.end(); it_cand++){
            countArray.push_back(histogram[*it_cand]);
        }
        vector<int> buf;
        perm(candidates.data(), countArray.data(), buf, candidates.size(), numSize, 0);


        return this->output;
    }

    void perm(int *a, int *count, vector<int>& buf, int n, int len, int idx) {
        if (idx == len) {
            this->output.push_back(buf);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (count[i] > 0) {
                buf.push_back(a[i]);
                --count[i];
                perm(a, count, buf, n, len, idx + 1);
                buf.pop_back();
                ++count[i];
            }
        }
    }

    vector<vector<int>> output;

};
