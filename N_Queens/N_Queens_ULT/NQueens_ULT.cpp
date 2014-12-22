#include "gtest/gtest.h"  // access test macro
#include "NQueens.h"


TEST(Backtracking, 5Queens){
    Solution_Backtracking sol;
    sol.solveNQueens(5);
}

TEST(Backtracking, 4Queens){
    Solution_Backtracking sol;
    sol.solveNQueens(4);
}

//TEST(NQueens, Basic_6Queens){
//    Solution sol;
//    sol.solveNQueens(6);
//}



//TEST(NQueens, Basic_8Queens){
//    Solution sol;
//    sol.solveNQueens(8);
//}
//
//
//
//TEST(NQueens, Basic_7Queens){
//    Solution sol;
//    sol.solveNQueens(7);
//}
//







