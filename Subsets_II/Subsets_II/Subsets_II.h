// Given a collection of integers that might contain duplicates, S, return all possible subsets.
// 
// Note:
// Elements in a subset must be in non - descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1, 2, 2], a solution is :
// 
// [
//     [2],
//     [1],
//     [1, 2, 2],
//     [2, 2],
//     [1, 2],
//     []
// ]
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// http://stackoverflow.com/questions/14781264/how-to-self-copy-a-vector
// std::size_t size = myvec.size();
// myvec.resize(size * 3);  //resize must protects us from iterator invalidation
// vector<string>::iterator it = myvec.begin() + size;
// std::copy(myvec.begin(), it, it);
// std::copy(myvec.begin(), it, it + size);
class Solution_DP {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> output;
        const int SSize = S.size();
        if (SSize > 0){
            sort(S.begin(), S.end());
            vector<int> numbers;
            vector<int> counts;
            numbers.push_back(S[0]);
            counts.push_back(1);
            int numCount = 1;
            for (int i = 1; i < SSize; ++i){
                if (S[i] == S[i - 1]){
                    counts[numCount - 1]++;
                }
                else{
                    numCount++;
                    numbers.push_back(S[i]);
                    counts.push_back(1);
                }
            }

            vector<int> temp;
            int currIdx = 0;
            int originalSize = 0;
            //for (auto& n : numbers){
            for (int numIdx = 0; numIdx < numCount; ++ numIdx){
                originalSize = output.size();
                duplicateVector(output, counts[numIdx] + 1); // if only 1 then double twiec
                
                temp.clear();
                currIdx = originalSize;
                while (counts[numIdx] > 0){
                    temp.push_back(numbers[numIdx]);
                    output.push_back(temp);
                    for (int i = 0; i < originalSize; ++i){
                        output[currIdx + i].insert(output[currIdx + i].end(), temp.begin(), temp.end());
                    }
                    currIdx += originalSize;
                    counts[numIdx]--;
                }
            }
        }
        output.push_back({});
        return output;
    }

    void duplicateVector(vector<vector<int>>& vv, const int factor){
        if (vv.size() > 0){
            const int originalSize = vv.size();
            vv.resize(originalSize * factor);
            vector<vector<int>>::iterator it = vv.begin() + originalSize;
            for (int i = 1; i < factor; ++i){
                copy(vv.begin(), vv.begin() + originalSize, it);
                it += originalSize;
            }
        }
    }
};


class Solution_Permutation {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        unordered_map<int, int> hist;  // number -> counters idx -> counter
        unordered_map<int, int>::iterator it;
        int counterIdx = 0;
        for (auto& i : S){
            if ((it = hist.find(i)) == hist.end()){
                // new number
                hist.insert({ i, counterIdx });
                counterIdx++;
                this->counters.push_back(1);
                this->numbers.push_back(i);
            }
            else{
                // existed, increment the counter
                this->counters[it->second]++;
            }
        }
        
        for (int i = 0; i <= S.size(); ++i){
            selectOneToMiss(hist, i);
        }

        return this->output;
    }

    void selectOneToMiss(unordered_map<int, int>& hist, const int numMissNeeded){
        if (numMissNeeded == 0){
            constructSolution();
        }
        else{
            for (auto& k : hist){
                if (this->counters[k.second] > 0){
                    this->counters[k.second]--;
                    selectOneToMiss(hist, numMissNeeded - 1);
                    this->counters[k.second]++;
                }
            }
        }
    }

    void constructSolution(){
        vector<int> buffer;
        const int countNumbers = this->numbers.size();
        for (int i = 0; i < countNumbers; ++i){
            for (int j = 0; j < counters[i]; ++j){
                buffer.push_back(this->numbers[i]);
            }
        }
        this->output.push_back(buffer);
    }

    vector<vector<int>>output;
    vector<int> counters;
    vector<int> numbers;
};