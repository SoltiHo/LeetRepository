// Given a collection of intervals, merge all overlapping intervals.
// 
// For example,
// Given[1, 3], [2, 6], [8, 10], [15, 18],
// return[1, 6], [8, 10], [15, 18].

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};



class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        const int count = intervals.size();
        vector<Interval> output = mergeSort(intervals, count);

        return output;
    }


    // not in place
    vector<Interval> mergeSort(vector<Interval> interval, const int size){
        vector<Interval> output;
        Interval temp;
        do{
            if (size == 0){
                break;
            }
            if (size == 1){
                output.push_back(interval[0]);
                break;
            }
            else if (size == 2){
                // 2 intervals, 
                if (interval[0].start <= interval[1].start){
                    // interval[startIdx + 0] should go first
                    if (interval[0].end >= interval[1].start){
                        // need to merge
                        temp.start = interval[0].start;
                        temp.end = max(interval[0].end, interval[1].end);
                        output.push_back(temp);
                        break;
                    }
                    else{
                        // no need to merge, the same order as original
                        output.push_back(interval[0]);
                        output.push_back(interval[1]);
                        break;
                    }
                }
                else{
                    // interval[1] should go first
                    if (interval[1].end >= interval[0].start){
                        // need to merge
                        temp.start = interval[1].start;
                        temp.end = max(interval[0].end, interval[1].end);
                        output.push_back(temp);
                        break;
                    }
                    else{
                        // no need to merge, the reversed order as original
                        output.push_back(interval[1]);
                        output.push_back(interval[0]);
                        break;
                    }
                }
            }

            // recursive call
            const int leftHalfSize = (size >> 1);
            const int rightHalfSize = size - leftHalfSize;
            vector<Interval> leftHalf(interval.begin(), interval.begin() + leftHalfSize);
            vector<Interval> rightHalf(interval.begin() + leftHalfSize, interval.begin() + size);
            vector<Interval> sortedLeft = mergeSort(leftHalf, leftHalfSize);
            vector<Interval> sortedRight = mergeSort(rightHalf, rightHalfSize);

            // merge
            while ((sortedLeft.size() > 0) || (sortedRight.size() > 0)){
                if ((sortedLeft.size() > 0) && (sortedRight.size() > 0)){
                    // both have remaining
                    if (sortedLeft[0].start <= sortedRight[0].start){
                        // left go first
                        temp.start = sortedLeft[0].start;
                        temp.end = sortedLeft[0].end;
                        sortedLeft.erase(sortedLeft.begin());
                        mergeIntervals(temp, sortedLeft, sortedRight, false);
                    }
                    else{
                        // right go first
                        temp.start = sortedRight[0].start;
                        temp.end = sortedRight[0].end;
                        sortedRight.erase(sortedRight.begin());
                        mergeIntervals(temp, sortedLeft, sortedRight, true);
                    }
                    output.push_back(temp);
                }
                else if (sortedLeft.size() > 0){
                    // only left has remaining
                    // insert all remaining
                    while (sortedLeft.size() > 0){
                        output.push_back(sortedLeft[0]);
                        sortedLeft.erase(sortedLeft.begin());
                    }
                }
                else{
                    // only right has remaining.
                    // insert all remaining
                    while (sortedRight.size() > 0){
                        output.push_back(sortedRight[0]);
                        sortedRight.erase(sortedRight.begin());
                    }
                }
            }

        } while (false);


        return output;
        
    }

    void mergeIntervals(Interval& temp, vector<Interval>& sortedLeft, vector<Interval>& sortedRight, bool compareLeft){
        while (true){
            if (compareLeft){
                // check if merge the interval at left is needed or not
                if (sortedLeft.size() > 0){
                    if (temp.end >= sortedLeft[0].start){
                        // merge this interval is required
                        while ((sortedLeft.size() > 0) && (sortedLeft[0].end <= temp.end)){
                            sortedLeft.erase(sortedLeft.begin());
                        }
                        if (sortedLeft.size() > 0){
                            if (temp.end >= sortedLeft[0].start){
                                temp.end = sortedLeft[0].end;
                                sortedLeft.erase(sortedLeft.begin());
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                        compareLeft = false;
                    }
                    else{
                        // no need to merge
                        break;
                    }
                }
                else{
                    // there is no more intervals at left, done
                    break;
                }
            }
            else{
                // check if merge the interval at right is needed or not
                if (sortedRight.size() > 0){
                    if (temp.end >= sortedRight[0].start){
                        // merge this interval is required
                        while ((sortedRight.size() > 0) && (sortedRight[0].end <= temp.end)){
                            sortedRight.erase(sortedRight.begin());
                        }
                        if (sortedRight.size() > 0){
                            if (temp.end >= sortedRight[0].start){
                                temp.end = sortedRight[0].end;
                                sortedRight.erase(sortedRight.begin());
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                        compareLeft = true;
                    }
                    else{
                        // no need to merge
                        break;
                    }
                }
                else{
                    // there is no more intervals at right, done
                    break;
                }
            }
        }
    }

};