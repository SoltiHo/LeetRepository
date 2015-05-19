// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? 
// Find all unique quadruplets in the array which gives the sum of target.
// 
// Note :
//    - Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ? b ? c ? d)
//    - The solution set must not contain duplicate quadruplets.
//      
//      For example, given array S = { 1 0 -1 0 -2 2 }, and target = 0.
//      A solution set is :
//           (-1,  0, 0, 1)
//           (-2, -1, 1, 2)
//           (-2,  0, 0, 2)
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> output;
        if (num.size() >= 4){
            sort(num.begin(), num.end());
            vector<int> buffer(4, 0);
            int lastLeft = -1;
            int lastRight = -1;
            for (int left = 0; left < num.size() - 2; ++left){
                if ((lastLeft != -1) && (num[left] == num[lastLeft])){
                    // repeat
                    continue;
                }
                for (int right = num.size() - 1; right > left + 2; --right){
                    if ((lastRight != -1) && (num[right] == num[lastRight])){
                        // repeat
                        continue;
                    }
                    if (num[left + 1] + num[left + 2] > target - num[left] - num[right]){
                        // not possible
                        continue;
                    }
                    if (num[right - 1] + num[right - 2] < target - num[left] - num[right]){
                        // not possible
                        break;
                    }
                    buffer[0] = num[left];
                    buffer[3] = num[right];
                    TwoSum(output, buffer, num, left + 1, right - 1, target - num[left] - num[right]);
                    lastRight = right;
                } // right for loop
                lastRight = -1;
                lastLeft = left;
            } // left for loop
        }
        return output;
    }

    void TwoSum(vector<vector<int>>& output, vector<int>& buffer, vector<int>& num, int startIdx, int endIdx, int target){
        // buffer is alway of size 4
        int lastStart = -1;
        int lastEnd = -1;
        while (startIdx < endIdx){
            if ((lastStart != -1) && (num[lastStart] == num[startIdx])){
                lastStart = startIdx;
                startIdx++;
            }
            else if ((lastEnd != -1) && (num[lastEnd] == num[endIdx])){
                lastEnd = endIdx;
                endIdx--;
            }
            else{
                if (target == num[startIdx] + num[endIdx]){
                    buffer[1] = num[startIdx];
                    buffer[2] = num[endIdx];
                    output.push_back(buffer);
                    lastStart = startIdx;
                    lastEnd = endIdx;
                    startIdx++;
                    endIdx--;
                }
                else if (target > num[startIdx] + num[endIdx]){
                    lastStart = startIdx;
                    startIdx++;
                }
                else{
                    lastEnd = endIdx;
                    endIdx--;
                }
            }
        }
    }
};

class Solution_DP{
public:
    struct Pair {
        int Idx1;
        int Idx2;
    };
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        pNum = &num;

        const int numSize = num.size();
        unordered_map<int, int> twoSum;
        unordered_map<int, int>::iterator it;
        vector<vector<Pair>> pairs;
        int sum;
        for (int i = 1; i < numSize; ++i){
            if (num[i - 1] == num[i]){
                sum = num[i] + num[i - 1];
                if ((it = twoSum.find(sum)) == twoSum.end()){
                    // a new 2 sum
                    twoSum.insert({ sum, pairs.size() });
                    pairs.push_back({ { i - 1, i } });
                }
                else{
                    // existed
                    pairs[it->second].push_back({ i - 1, i });
                }
            }
            else{
                for (int j = 0; j < i; j++){
                    sum = num[i] + num[j];
                    if ((it = twoSum.find(sum)) == twoSum.end()){
                        // a new 2 sum
                        twoSum.insert({ sum, pairs.size() });
                        pairs.push_back({ { j, i } });
                    }
                    else{
                        // existed
                        pairs[it->second].push_back({ j, i });
                    }
                }
            }
        }

        const int num2Sum = pairs.size();
        int complement = 0;
        for (int i = 0; i < num2Sum; ++i){
            complement = target - num[pairs[i][0].Idx1] - num[pairs[i][0].Idx2];
            if ((it = twoSum.find(complement)) != twoSum.end()){
                // found
                if (i <= it->second){
                    generateSolutions(pairs, pairs[i], pairs[it->second]);
                }
            }

        }

        return this->output;

    }

    void generateSolutions(vector<vector<Pair>>& pairs, vector<Pair>& bucket1, vector<Pair>& bucket2){
        vector<int> buffer;
        const int bucketSize1 = bucket1.size();
        const int bucketSize2 = bucket2.size();
        Pair lastP1;
        Pair lastP2;
        lastP1.Idx1 = -1;
        lastP1.Idx2 = -1;
        lastP2.Idx1 = -1;
        lastP2.Idx2 = -1;
        for (auto& p1 : bucket1){
            if ((lastP1.Idx1 != -1) && (this->pNum->at(lastP1.Idx1) == this->pNum->at(p1.Idx1)) && (this->pNum->at(lastP1.Idx2) == this->pNum->at(p1.Idx2))){
                continue;
            }
            for (auto& p2 : bucket2){
                if ((lastP2.Idx1 != -1) && (this->pNum->at(lastP2.Idx1) == this->pNum->at(p2.Idx1)) && (this->pNum->at(lastP2.Idx2) == this->pNum->at(p2.Idx2))){
                    continue;
                }
                if (p1.Idx2 < p2.Idx1){
                    this->output.push_back({ pNum->at(p1.Idx1), pNum->at(p1.Idx2), pNum->at(p2.Idx1), pNum->at(p2.Idx2) });
                    lastP2 = p2;
                }
            }
            lastP2.Idx1 = -1;
            lastP2.Idx2 = -1;
            lastP1 = p1;
        }
    }

    vector<vector<int>> output;
    vector<int>* pNum;
};

class Solution_Permutation {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        this->target = target;
        // calculate histogram
        for (auto& i : num){
            if (hist.find(i) == hist.end()){
                hist.insert(make_pair(i, 1));
            }
            else{
                hist[i]++;
            }
        }

        // permutation
        vector<vector<int>> output;
        vector<int> buffer;
        int sum = 0;
        permutation(output, buffer, sum);

        return output;
    }

    void permutation(vector<vector<int>>& output, vector<int>& buffer, int& sum){
        if ((buffer.size() == 4) && (sum == this->target)){
            output.push_back(buffer);
        }

        for (auto& choice : this->hist){
            if ((choice.second > 0) &&
                ((buffer.size() == 0) || (buffer.back() <= choice.first)))
            {
                choice.second--;
                buffer.push_back(choice.first);
                sum += choice.first;
                permutation(output, buffer, sum);
                sum -= choice.first;
                buffer.pop_back();
                choice.second++;
            }
        }
    }

    unordered_map<int, unsigned int> hist;
    int target;
};

class Solution_Permutation_Sorted {
public:
    struct HistNode {
        int key;
        unsigned int counter;
        HistNode(int k) : key(k), counter(1){};
    };

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        this->target = target;
        sort(num.begin(), num.end());

        // calculate histogram
        for (auto& i : num){
            if ((this->hist.size() > 0) && (i == this->hist.back().key)){
                this->hist.back().counter++;
            }
            else{
                this->hist.push_back({ i });
            }
        }
        this->numberCount = this->hist.size();

        // permutation
        vector<vector<int>> output;
        vector<int> buffer;
        int sum = 0;
        permutation(output, buffer, 0, sum);

        return output;
    }

    void permutation(vector<vector<int>>& output, vector<int>& buffer, int firstPossibleIdx, int& sum){
        if ((buffer.size() == 4) && (sum == this->target)){
            output.push_back(buffer);
        }

        for (int i = firstPossibleIdx; i < this->numberCount; ++i){
            if (this->hist[i].counter > 0){
                this->hist[i].counter--;
                buffer.push_back(this->hist[i].key);
                sum += this->hist[i].key;


                permutation(output, buffer, i, sum);

                sum -= this->hist[i].key;
                buffer.pop_back();
                this->hist[i].counter++;
            }
        }
    }

    vector<HistNode> hist;
    int numberCount;
    int target;
};

