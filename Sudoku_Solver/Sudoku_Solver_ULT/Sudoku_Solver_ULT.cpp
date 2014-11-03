#include "gtest/gtest.h"  // access test macro
#include "SudokuSolver.h"


bool reject(const int center_x, const int center_y, vector<vector<char>>& solution){
    char value = solution[center_x][center_y];
    if ((value < '1') || (value > '9')){
        return true;
    }
    // check the same column
    for (int i = 9; i; --i){
        if (((i - 1) != center_y) && (solution[center_x][i - 1] == value)){
            // conflict
            return true;
        }
    }

    // check the same column
    for (int i = 9; i; --i){
        if (((i - 1) != center_x) && (solution[i - 1][center_y] == value)){
            // conflict
            return true;
        }
    }

    // find its zone number
    const int zoneNumberX = center_x / 3;
    const int zoneNumberY = center_y / 3;
    const int sameZoneXLowerBound = zoneNumberX * 3;
    const int sameZoneYLowerBound = zoneNumberY * 3;
    // check the same zone
    for (int x_offset = 3; x_offset; --x_offset){
        for (int y_offset = 3; y_offset; --y_offset){
            if ((sameZoneXLowerBound + x_offset - 1 == center_x) && (sameZoneYLowerBound + y_offset - 1 == center_y)){
                continue;
            }
            if (solution[sameZoneXLowerBound + x_offset - 1][sameZoneYLowerBound + y_offset - 1] == value){
                return true;
            }
        }
    }

    // so far check no duplication, then check everything is between '1' ~ '9'
    return false;
}

bool solutionPassed(vector<vector<char>>& solution){
    for (int y = 9; y; --y){
        for (int x = 9; x; --x){
            if (reject(x - 1, y - 1, solution)){
                return false;
            }
        }
    }
    return true;
}


TEST(Online, Example01){
    vector<vector<char>> problem;
    vector<char> temp;
    // row 1
    temp.clear();
    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('7');
    temp.push_back('.');

    temp.push_back('6');
    temp.push_back('.');
    temp.push_back('5');
    problem.push_back(temp);

    // row 2
    temp.clear();
    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('4');

    temp.push_back('.');
    temp.push_back('8');
    temp.push_back('.');
    problem.push_back(temp);

    // row 3
    temp.clear();
    temp.push_back('2');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('6');

    temp.push_back('.');
    temp.push_back('7');
    temp.push_back('.');
    problem.push_back(temp);

    // row 4
    temp.clear();
    temp.push_back('.');
    temp.push_back('7');
    temp.push_back('3');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('2');
    temp.push_back('.');
    temp.push_back('.');
    problem.push_back(temp);

    // row 5
    temp.clear();
    temp.push_back('5');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('4');
    problem.push_back(temp);

    // row 6
    temp.clear();
    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('4');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('9');
    temp.push_back('6');
    temp.push_back('.');
    problem.push_back(temp);

    // row 7
    temp.clear();
    temp.push_back('.');
    temp.push_back('8');
    temp.push_back('.');

    temp.push_back('4');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('3');
    problem.push_back(temp);

    // row 8
    temp.clear();
    temp.push_back('.');
    temp.push_back('5');
    temp.push_back('.');

    temp.push_back('2');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');
    problem.push_back(temp);

    // row 9
    temp.clear();
    temp.push_back('7');
    temp.push_back('.');
    temp.push_back('6');

    temp.push_back('.');
    temp.push_back('8');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');
    problem.push_back(temp);


    Solution sol;
    sol.solveSudoku(problem);
    ASSERT_TRUE(solutionPassed(problem));
}


TEST(Basic, Example01){
    vector<vector<char>> problem;
    vector<char> temp;
    // row 1
    temp.clear();
    temp.push_back('5');
    temp.push_back('3');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('7');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');
    problem.push_back(temp);

    // row 2
    temp.clear();
    temp.push_back('6');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('1');
    temp.push_back('9');
    temp.push_back('5');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');
    problem.push_back(temp);

    // row 3
    temp.clear();
    temp.push_back('.');
    temp.push_back('9');
    temp.push_back('8');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('6');
    temp.push_back('.');
    problem.push_back(temp);

    // row 4
    temp.clear();
    temp.push_back('8');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('6');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('3');
    problem.push_back(temp);

    // row 5
    temp.clear();
    temp.push_back('4');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('8');
    temp.push_back('.');
    temp.push_back('3');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('1');
    problem.push_back(temp);

    // row 6
    temp.clear();
    temp.push_back('7');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('2');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('6');
    problem.push_back(temp);

    // row 7
    temp.clear();
    temp.push_back('.');
    temp.push_back('6');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('2');
    temp.push_back('8');
    temp.push_back('.');
    problem.push_back(temp);

    // row 8
    temp.clear();
    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('4');
    temp.push_back('1');
    temp.push_back('9');

    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('5');
    problem.push_back(temp);

    // row 9
    temp.clear();
    temp.push_back('.');
    temp.push_back('.');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('8');
    temp.push_back('.');

    temp.push_back('.');
    temp.push_back('7');
    temp.push_back('9');
    problem.push_back(temp);


    Solution sol;
    sol.solveSudoku(problem);
    ASSERT_TRUE(solutionPassed(problem));


}

