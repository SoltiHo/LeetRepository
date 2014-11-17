#include "gtest/gtest.h"  // access test macro
#include "Word_Ladder.h"

TEST(LeetCode, Fail03){
    unordered_set<string> dict = { "hot", "dog", "dot" };
    string start = "hot";
    string end = "dog";
    Solution sol;
    ASSERT_EQ(sol.ladderLength(start, end, dict), 3);

}

TEST(LeetCode, Fail02){
    unordered_set<string> dict = { "a", "b", "c" };
    string start = "a";
    string end = "c";
    Solution sol;
    ASSERT_EQ(sol.ladderLength(start, end, dict), 2);

}


TEST(LeetCode, Fail01){
    unordered_set<string> dict = { "ion", "rev", "che", "ind", "lie", "wis", "oct", "ham", "jag", "ray", "nun", "ref", "wig", "jul", "ken", "mit", "eel", "paw", "per", "ola", "pat", "old", "maj", "ell", "irk", "ivy", "beg", "fan", "rap", "sun", "yak", "sat", "fit", "tom", "fin", "bug", "can", "hes", "col", "pep", "tug", "ump", "arc", "fee", "lee", "ohs", "eli", "nay", "raw", "lot", "mat", "egg", "cat", "pol", "fat", "joe", "pis", "dot", "jaw", "hat", "roe", "ada", "mac" };
    string start = "cat";
    string end = "fin";
    Solution sol;
    ASSERT_EQ(sol.ladderLength(start, end, dict), 0);  // this is not a correct answer, just mock run

}
