#include "gtest/gtest.h"  // access test macro
#include "Permutations_II.h"

bool matched(vector<vector<int>> a, vector<vector<int>> b){
    if (a.size() != b.size()){
        return false;
    }

    bool matchFound = false;
    while (a.size() > 0){
        matchFound = false;
        for (int i = 0; i < b.size(); ++i){
            for (int j = 0; j < a[0].size(); ++j){
                if (a[0][j] != b[i][j]){
                    break;
                }
                if (j == a[0].size() - 1){
                    // match found
                    matchFound = true;
                }
            }
            if (matchFound) {
                a.erase(a.begin());
                b.erase(b.begin() + i);
                break;
            }
        }
        if (!matchFound){
            // current a[0] has no match
            return false;
        }
    }
    return true;
}


TEST(LeetCode, Timeout01){
    vector<int> input = { 3, 3, 0, 0, 2, 3, 2 };

    Solution sol;
    vector<vector<int>> output = sol.permuteUnique(input);
    vector<vector<int>> expected = { { 1 } };
    ASSERT_TRUE(matched(output, expected));

}

TEST(LeetCode, Example01){
    vector<int> input = { 1, 1, 2 };

    Solution sol;
    vector<vector<int>> output = sol.permuteUnique(input);
    vector<vector<int>> expected = { { 1, 1, 2 }, { 1, 2, 1 }, { 2, 1, 1 } };
    ASSERT_TRUE(matched(output, expected));

}


TEST(LeetCode, Fail01){
    vector<int> input = { 1 };

    Solution sol;
    vector<vector<int>> output = sol.permuteUnique(input);
    vector<vector<int>> expected = { { 1 } };
    ASSERT_TRUE(matched(output, expected));

}



