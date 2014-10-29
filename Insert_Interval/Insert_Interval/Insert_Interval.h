//  Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//  
//  You may assume that the intervals were initially sorted according to their start times.
//  
//  Example 1:
//  Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//  
//  Example 2 :
//  Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//  
//  This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].


#include <vector>
using namespace std;

#include <algorithm>

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

        // a few easy cases
        if (intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        else if (intervals[0].start > newInterval.end){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        else if (intervals[intervals.size() - 1].end < newInterval.start){
            intervals.push_back(newInterval);
            return intervals;
        }

        // after this, the job involves deleting.

        int firstIntervalIndexToMerge = INT_MIN;
        int lastIntervalIndexToMerge = INT_MIN;
        bool startOverlapWithPrevInterval = false;

        for (unsigned int i = 0; i < intervals.size(); ++i){
            if (firstIntervalIndexToMerge == INT_MIN){
                // only check when never been checked before
                if (intervals[i].start < newInterval.start){
                    if (i == intervals.size() - 1){
                        // all is about the last entry.
                        lastIntervalIndexToMerge = firstIntervalIndexToMerge = i;
                        startOverlapWithPrevInterval = true;
                        break;
                    }
                    else{
                        continue;
                    }
                }

                // find the 1st interval started after the new interval.
                if (intervals[i].start == newInterval.start){
                    // new interval right start with current;
                    firstIntervalIndexToMerge = i;
                    startOverlapWithPrevInterval = true;
                }
                else{
                    if (i == 0){
                        firstIntervalIndexToMerge = 0;
                        startOverlapWithPrevInterval = true;
                    }
                    else{
                        firstIntervalIndexToMerge = i - 1;
                        if (intervals[i - 1].end >= newInterval.start){
                            startOverlapWithPrevInterval = true;
                        }
                    }
                }
            }

            //
            if (intervals[i].start < newInterval.end){
                if (i == intervals.size() - 1){
                    lastIntervalIndexToMerge = i;
                    break;
                }
                else{
                    continue;
                }
            }

            // reach the first interval totally irrelevant with the new interval
            if (i == 0){
                lastIntervalIndexToMerge = 0;
            }
            else{
                if (intervals[i].start == newInterval.end){
                    lastIntervalIndexToMerge = i;
                }
                else{
                    lastIntervalIndexToMerge = i - 1;
                }
            }
            break;

        }

        // 
        Interval temp = { 0, 0 };
        if (startOverlapWithPrevInterval){
            temp.start = min(intervals[firstIntervalIndexToMerge].start, newInterval.start);
        }
        else{
            temp.start = newInterval.start;
        }

        if (intervals[lastIntervalIndexToMerge].end > newInterval.end){
            temp.end = intervals[lastIntervalIndexToMerge].end;
        }
        else{
            temp.end = newInterval.end;
        }

        //
        int firstToBeDeleted = (startOverlapWithPrevInterval ? firstIntervalIndexToMerge : firstIntervalIndexToMerge + 1);
        int lastToBeDeleted = lastIntervalIndexToMerge;
        if (firstToBeDeleted == lastToBeDeleted){
            intervals.erase(intervals.begin() + firstToBeDeleted);
        }
        else{
            intervals.erase(intervals.begin() + firstToBeDeleted, intervals.begin() + lastToBeDeleted + 1);
        }
        intervals.insert(intervals.begin() + firstToBeDeleted, temp);

        return intervals;
    }
};


