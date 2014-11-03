//  Write a program to solve a Sudoku puzzle by filling the empty cells.
//  
//  Empty cells are indicated by the character '.'.

#include <vector>
#include <iostream>
using namespace std;


int** table = NULL;

void printTable(){

    for (unsigned int x = 0; x < 9; ++x){
        for (unsigned int y = 0; y < 9; ++y){
            cout << table[x][y] << ", ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void initTable(){
    table = new int*[9];
    memset(table, 0, sizeof(int*)* 9);
    for (int i = 9; i; --i){
        table[i - 1] = new int[9];
        memset(table[i - 1], 0, sizeof(int)* 9);
    }
}

void deleteTable(){
    for (int i = 9; i; --i){
        delete[] table[i - 1];
    }
    delete[] table;
    table = NULL;
}

void fillInTable(vector<vector<char> > &board){
    for (unsigned int y = 9; y; --y){
        for (unsigned int x = 9; x; --x){
            table[x - 1][y - 1] = (board[x - 1][y - 1] != '.' ? board[x - 1][y - 1] - 0x30 : 0);
        }
    }
}


void updateCharVectorsFromTable(vector<vector<char> > &board){
    for (unsigned int y = 9; y; --y){
        for (unsigned int x = 9; x; --x){
            if (board[x - 1][y - 1] == '.'){
                board[x - 1][y - 1] = table[x - 1][y - 1] + 0x30;
            }
        }
    }
}



bool reject(const int center_x, const int center_y){
    int value = table[center_x][center_y];
    // check the same column
    for (int i = 9; i; --i){
        if (((i - 1) != center_y) && (table[center_x][i - 1] == value)){
            // conflict
            return true;
        }
    }

    // check the same column
    for (int i = 9; i; --i){
        if (((i - 1) != center_x) && (table[i - 1][center_y] == value)){
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
            if (table[sameZoneXLowerBound + x_offset - 1][sameZoneYLowerBound + y_offset - 1] == value){
                return true;
            }
        }
    }
    return false;
}

bool accept(int x_justFilled, int y_justFilled){
    int nextStart_x = 0;
    int nextStart_y = 0;

    nextStart_x = (x_justFilled + 1) % 9;
    nextStart_y = (x_justFilled == 8 ? y_justFilled + 1 : y_justFilled);


    for (int y = nextStart_y; y < 9; ++y){
        for (int x = nextStart_x; x < 9; ++x){
            if (table[x][y] == 0){
                return false;
            }
        }
        nextStart_x = 0;
    }
    return true;
}

bool solveByBackTracking(const int x_justFilled, const int y_justFilled, bool fromFirst = false){
    // (x, y) is the cell just filled
    if (reject(x_justFilled, y_justFilled)){
        // conflict detected
        return false;
    }

    // check if any remaining cell to be filled
    if (accept(x_justFilled, y_justFilled)){
        // last cell filled and passed
        return true;
    }

    // recursive
    int nextStart_x = 0;
    int nextStart_y = 0;
    if (!fromFirst){
        nextStart_x = (x_justFilled + 1) % 9;
        nextStart_y = (x_justFilled == 8 ? y_justFilled + 1 : y_justFilled);
    }

    for (int y = nextStart_y; y < 9; ++y){
        for (int x = nextStart_x; x < 9; ++x){
            // next, fill in the next cell
            if (table[x][y] == 0){
                for (int i = 9; i; --i){
                    table[x][y] = i;
                    if (solveByBackTracking(x, y) == true){
                        return true;
                    }
                    else{
                        table[x][y] = 0;
                    }
                }
                return false;
            }
        }
        nextStart_x = 0;
    }

    return false;
}
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        initTable();
        fillInTable(board);

        int firstCellX = 0;
        int firstCellY = 0;

        bool found = false;
        for (int y = 0; (y < 9) && (!found); ++y){
            for (int x = 0; x < 9; ++x){
                if (table[x][y] != 0){
                    found = true;
                    firstCellX = x;
                    firstCellY = y;
                    break;
                }
            }
        }

        solveByBackTracking(firstCellX, firstCellY, ((firstCellX != 0) || (firstCellY != 0)));
        updateCharVectorsFromTable(board);
        deleteTable();
    }
};
