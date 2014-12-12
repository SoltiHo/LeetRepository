// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed ?
// 
// Would this affect the run - time complexity ? How and why ?
// 
// Write a function to determine if a given target is in the array.

class Solution {
public:
    bool search(int A[], int n, int target) {
        this->target = target;
        this->input = A;
        return binarySearch(0, n - 1);
    }

    bool binarySearch(int startIdx, int endIdx){
        // base cases
        if (input[startIdx] == target){
            return true;
        }
        else if (input[endIdx] == target){
            return true;
        }

        const int currSize = endIdx - startIdx + 1;
        if (currSize <= 2){
            return false;
        }

        // recursive
        const int middleIdx = (startIdx + endIdx) >> 1;
        if (input[middleIdx] == target){
            return middleIdx;
        }
        else{
            if (target > input[middleIdx]){
                if (input[startIdx] < input[endIdx]){
                    // normal array, not rotated
                    return binarySearch(middleIdx + 1, endIdx - 1);
                }
                else if ((input[middleIdx] >= input[startIdx]) && (input[middleIdx] > input[endIdx])){
                    // min is at the right of middle point
                    return binarySearch(middleIdx + 1, endIdx - 1);
                }
                else if ((input[middleIdx] == input[startIdx]) && (input[middleIdx] == input[endIdx])){
                    // handle "equal" situation
                    bool cutIsAtRight = false;
                    for (int i = middleIdx + 1; i < endIdx; ++i){
                        if (input[i] != input[middleIdx]){
                            cutIsAtRight = true;
                            break;
                        }
                    }

                    if (cutIsAtRight){
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                    else{
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                }
                else{
                    // min is at the left of middle point
                    if (target > input[startIdx]){
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                    else{
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                }
            }
            else{
                // target < input[middleIdx]
                if (input[startIdx] < input[endIdx]){
                    // normal array, not rotated
                    return binarySearch(startIdx + 1, middleIdx - 1);
                }
                else if ((input[middleIdx] >= input[startIdx]) && (input[middleIdx] > input[endIdx])){
                    // min is at the right of middle point
                    if (target < input[endIdx]){
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                    else{
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                }
                else if ((input[middleIdx] == input[startIdx]) && (input[middleIdx] == input[endIdx])){
                    // handle "equal" situation
                    bool cutIsAtRight = false;
                    for (int i = middleIdx + 1; i < endIdx; ++i){
                        if (input[i] != input[middleIdx]){
                            cutIsAtRight = true;
                            break;
                        }
                    }

                    if (cutIsAtRight){
                        return binarySearch(middleIdx + 1, endIdx - 1);
                    }
                    else{
                        return binarySearch(startIdx + 1, middleIdx - 1);
                    }
                }
                else{
                    // min is at the left of middle point
                    return binarySearch(startIdx + 1, middleIdx - 1);
                }
            }
        }
    }

    int target;
    int* input;
};
