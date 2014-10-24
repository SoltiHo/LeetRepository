// Problem: https://oj.leetcode.com/problems/n-queens/
#include <vector>
#include <string>
#include <algorithm>

void mirrow(std::vector<std::vector<std::string>>& solSet){
    std::vector<std::vector<std::string>>::iterator solSetIt = solSet.begin();
    std::vector<std::vector<std::string>> toBeAddedSolutionSet;
    std::vector<std::string> mirrowedSolution;
    std::string temp;
    for (; solSetIt != solSet.end(); solSetIt++){
        for (std::vector<std::string>::iterator it = solSetIt->begin(); it != solSetIt->end(); it++){
            temp = *it;
            std::reverse(temp.begin(), temp.end());
            mirrowedSolution.push_back(temp);
        }
        toBeAddedSolutionSet.push_back(mirrowedSolution);
        mirrowedSolution.clear();
    }
    solSet.insert(solSet.end(), toBeAddedSolutionSet.begin(), toBeAddedSolutionSet.end());
}

bool isIdentical(std::vector<std::string>& left, std::vector<std::string> right){
    if (left.size() != right.size()){
        return false;
    }
    for (int i = 0; i < left.size(); ++i){
        if (left[i] != right[i]){
            return false;
        }
    }
    return true;
}
class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutionSet;
        if (n < 4){
            // empty solution if n < 4
            return solutionSet;
        }

        // push the two solution seeds
        std::vector<std::string> solution;
        solution.push_back(".Q..");
        solution.push_back("...Q");
        solution.push_back("Q...");
        solution.push_back("..Q.");
        solutionSet.push_back(solution);

        // the other seed is just a mirrow-ed version, no need to push.
        //solution.clear();
        //solution.push_back("..Q.");
        //solution.push_back("...Q");
        //solution.push_back("Q...");
        //solution.push_back("..Q.");
        //solutionSet.push_back(solution);

        unsigned int solutionCountBeforeExpansion = 0;
        for (int dimension = 4; dimension < n; ++dimension){
            solutionCountBeforeExpansion = solutionSet.size();
            for (unsigned int sol = 0; sol < solutionCountBeforeExpansion; ++sol){
                // for each current solution, need to examine all possible positions to insert
                // there are (dimension + 1) * (dimension + 1) candidates
                for (int y_new = 0; y_new < (dimension + 1); ++y_new){
                    for (int x_new = 0; x_new < (dimension + 1); ++x_new){
                        // some (x_new, y_new) is not worthy a check if there is already a Queen nearby.
                        // The four corners could have a queen: 
                        //               (x_new - 1, y_new - 1), (x_new + 1, y_new + 1), (x_new + 1, y_new - 1), (x_new - 1, y_new + 1)
                        if ((x_new < dimension) && (y_new < dimension)){
                            if ((x_new > 0) && (y_new > 0)){
                                // check all 4 possibilities
                                if ((solutionSet[sol][y_new - 1][x_new - 1] == 'Q') ||  // (x_new - 1, y_new - 1)
                                    (solutionSet[sol][y_new][x_new] == 'Q') ||  // (x_new + 1, y_new + 1)
                                    (solutionSet[sol][y_new - 1][x_new] == 'Q') ||  // (x_new + 1, y_new - 1)
                                    (solutionSet[sol][y_new][x_new - 1] == 'Q')){   // (x_new - 1, y_new + 1)
                                    continue;
                                }
                            }
                            else if ((x_new == 0) && (y_new != 0)){
                                if ((solutionSet[sol][y_new][x_new] == 'Q') ||  // (x_new + 1, y_new + 1)
                                    (solutionSet[sol][y_new - 1][x_new] == 'Q')){  // (x_new + 1, y_new - 1)
                                    continue;
                                }
                            }
                            else if ((x_new != 0) && (y_new == 0)){
                                if ((solutionSet[sol][y_new][x_new] == 'Q') ||  // (x_new + 1, y_new + 1)
                                    (solutionSet[sol][y_new][x_new - 1] == 'Q')){   // (x_new - 1, y_new + 1)
                                    continue;
                                }
                            }
                            else{
                                // x_new and y_new are both 0
                                if (solutionSet[sol][y_new][x_new] == 'Q'){  // (x_new + 1, y_new + 1)
                                    continue;
                                }
                            }
                        }
                        else if ((x_new == dimension) && (y_new < dimension)){
                            if ((x_new > 0) && (y_new > 0)){
                                // check all 4 possibilities
                                if ((solutionSet[sol][y_new - 1][x_new - 1] == 'Q') ||  // (x_new - 1, y_new - 1)
                                    (solutionSet[sol][y_new][x_new - 1] == 'Q')){   // (x_new - 1, y_new + 1)
                                    continue;
                                }
                            }
                            else if ((x_new != 0) && (y_new == 0)){
                                if (solutionSet[sol][y_new][x_new - 1] == 'Q'){   // (x_new - 1, y_new + 1)
                                    continue;
                                }
                            }
                        }
                        else if ((x_new < dimension) && (y_new == dimension)){
                            if ((x_new > 0) && (y_new > 0)){
                                // check all 4 possibilities
                                if ((solutionSet[sol][y_new - 1][x_new - 1] == 'Q') ||  // (x_new - 1, y_new - 1)
                                    (solutionSet[sol][y_new - 1][x_new] == 'Q')){  // (x_new + 1, y_new - 1)
                                    continue;
                                }
                            }
                            else if ((x_new == 0) && (y_new != 0)){
                                if (solutionSet[sol][y_new - 1][x_new] == 'Q'){  // (x_new + 1, y_new - 1)
                                    continue;
                                }
                            }
                        }
                        else{
                            // both at max
                            if ((x_new > 0) && (y_new > 0)){
                                // check all 4 possibilities
                                if (solutionSet[sol][y_new - 1][x_new - 1] == 'Q'){  // (x_new - 1, y_new - 1)
                                    continue;
                                }
                            }
                        }



                        bool isXNewYNewOk = true;
                        // checking solution solutionSet[sol]
                        // (x_new, y_new) is the coord in the expanded grid
                        // need to make sure no Q on the diagonals:  for a given (x_new,y_new), no Q at (x_new + i, y_new + i), (x_new + i, y_new - i)
                        // for the TopRight <--> BottomLeft diagonal
                        //     0 <= x_new + i < dimension + 1 --> -x_new <= i < dimension + 1 - x_new
                        //     0 <= y_new + i < dimension + 1 --> -y_new <= i < dimension + 1 - y_new
                        int i_LowerBound = std::max(-1 * x_new, -1 * y_new);
                        int i_UpperBound = std::min(dimension + 1 - x_new - 1, dimension + 1 - y_new - 1);
                        for (int i = i_LowerBound; i <= i_UpperBound; ++i){
                            // doesn't need to check (x_new, y_new) since it's the candidate
                            if (i == 0){
                                continue;
                            }

                            // let (x', y') be the check point in the expanded grid, then its corresponding position before expansion (x_old, y_old) is
                            //    if x_old >= x_new, x' = x_old + 1;
                            //    if x_old < x_new, x' = x_old;
                            //    if y_old >= y_new, y' = y_old + 1;
                            //    if y_old < y_new, y' = y_old;
                            // (x_new + i, y_new + i) = (x', y')
                            int x_old = (x_new + i < x_new) ? (x_new + i) : (x_new + i - 1);
                            int y_old = (y_new + i < y_new) ? (y_new + i) : (y_new + i - 1);
                            if (solutionSet[sol][y_old][x_old] == 'Q'){
                                isXNewYNewOk = false;
                                break;
                            }
                        }

                        // for the TopLeft <--> BottomRight diagonal
                        //     0 <= x_new + i < dimension + 1 --> -x_new <= i < dimension + 1 - x_new
                        //     0 <= y_new - i < dimension + 1 --> y_new - dimension - 1 < i <=  y_new
                        if (isXNewYNewOk) {
                            // only check this direction if this solution is still valid
                            i_LowerBound = std::max(-1 * x_new, y_new - dimension - 1 + 1);
                            i_UpperBound = std::min(dimension + 1 - x_new - 1, y_new);
                            for (int i = i_LowerBound; i <= i_UpperBound; ++i){
                                // doesn't need to check (x_new, y_new) since it's the candidate
                                if (i == 0){
                                    continue;
                                }

                                // the same raleasion as aboeve but now (x', y') = (x_new + i, y_new - i)
                                int x_old = (x_new + i < x_new) ? (x_new + i) : (x_new + i - 1);
                                int y_old = (y_new - i < y_new) ? (y_new - i) : (y_new - i - 1);
                                if (solutionSet[sol][y_old][x_old] == 'Q'){
                                    isXNewYNewOk = false;
                                    break;
                                }
                            }

                            if (isXNewYNewOk){
                                // if this candidate survives, then add the new solution with a new queen at (x_new, y_new)
                                std::vector<std::string> newExpandedSolution;
                                std::string temp;
                                for (int i = 0; i < dimension + 1; ++i){
                                    if (i == y_new){
                                        // add the new row with the new Queen
                                        temp.insert(temp.begin(), dimension + 1, '.');
                                        temp[x_new] = 'Q';
                                    }
                                    else{
                                        // add the original rows but expand by 1 column
                                        if (i < y_new){
                                            temp = solutionSet[sol][i];
                                        }
                                        else{
                                            // i > y_new
                                            temp = solutionSet[sol][i - 1];
                                        }
                                        temp.insert(temp.begin() + x_new, '.');
                                    }
                                    newExpandedSolution.push_back(temp);
                                    temp.clear();
                                }
                                // new expanded solution construction done, add to solution set
                                solutionSet.push_back(newExpandedSolution);
                                newExpandedSolution.clear();
                            }
                        } // end the 2nd diagonal check
                    } // end x_new
                } // end y_new


                // if no more seeds, then pointless to continue the loop
                if (solutionSet.size() == 0){
                    break;
                }
            } // end iterating existing solutions
            // this expansion is done, need to remove the before-expanded solutions, 
            // which is the first solutionCountBeforeExpansion solutions of solutionSet
            solutionSet.erase(solutionSet.begin(), solutionSet.begin() + solutionCountBeforeExpansion);
        } // end expansion
        // remove duplication solution
        for (int i = 0; i < solutionSet.size(); ++i){
            for (int j = i + 1; j < solutionSet.size(); ++j){
                if (isIdentical(solutionSet[i], solutionSet[j])){
                    // delete j
                    solutionSet.erase(solutionSet.begin() + j);
                    --j;
                }
            }
        }

        // mirrow the solution to get the other half from the skipped seed
        mirrow(solutionSet);



        //debugging only
        std::vector<std::vector<std::string>>::iterator solSetIt;
        std::vector<std::string>::iterator solIt;
        for (solSetIt = solutionSet.begin(); solSetIt != solutionSet.end(); ++solSetIt){
            for (solIt = solSetIt->begin(); solIt != solSetIt->end(); solIt++){
                std::cout << *solIt << std::endl;
            }
            std::cout << std::endl << std::endl;
        }

        return solutionSet;
    }
};
