// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};




#define MAX_m ((float(INT_MAX) - float(INT_MIN)))
#define MAX_b (double(INT_MAX))
#define delta 0.001

class Solution {
public:
    struct LineRecord {
        float m;
        float b;
        unordered_map<int, bool>* set;
        int totalCount;
    };

    struct PointRecord {
        int x;
        int y;
        int count;
        PointRecord(int xx, int yy, int cc) : x(xx), y(yy), count(cc){};
    };

    int maxPoints(vector<Point> &points) {
        const int size = points.size();
        if (size == 0){
            return 0;
        }
        else if (size == 1){
            return 1;
        }
        else if (size == 2){
            return 2;
        }

        // preprocess the points to get a unique array
        unordered_map<unsigned long long, PointRecord*> pointCount;
        unordered_map<unsigned long long, PointRecord*>::iterator it_point_count;
        unsigned long long key;
        for (int i = 0; i < points.size(); ++i){
            key = makeKey(points[i].x, points[i].y);
            it_point_count = pointCount.find(key);
            if (it_point_count == pointCount.end()){
                // not found
                pointCount.insert({ key, new PointRecord(points[i].x, points[i].y, 1) });
            }
            else{
                // found
                it_point_count->second->count++;
            }
        }

        // reset the point array and get only the unique points
        points.clear();
        for (it_point_count = pointCount.begin(); it_point_count != pointCount.end(); it_point_count++){
            points.push_back({ it_point_count->second->x, it_point_count->second->y });
        }


        vector<LineRecord> lines;
        LineRecord temp;
        unordered_map<int, bool>::iterator it;
        unordered_map<int, bool> pointsAlreadyChecked;
        int uniquePointCount = points.size();
        
        float x1, x2, y1, y2;
        float m = 0, b = 0;  // y = mx + b
        for (int i = 0; i < uniquePointCount; ++i){
            pointsAlreadyChecked.clear();
            x1 = points[i].x;
            y1 = points[i].y;
            for (int j = 0; j < lines.size(); ++j){
                if (fallOnTheLine(lines[j].m, lines[j].b, x1, y1)){
                    lines[j].set->insert({ i, true });
                    lines[j].totalCount += pointCount[makeKey(x1,y1)]->count;
                    pointsAlreadyChecked.insert(lines[j].set->begin(), lines[j].set->end());
                }
            }

            for (int j = 0; j < i; ++j){
                it = pointsAlreadyChecked.find(j);
                if (it != pointsAlreadyChecked.end()){
                    // already processed
                    continue;
                }
                x2 = points[j].x;
                y2 = points[j].y;

                if (x1 == x2){
                    // vertical line, max slope
                    m = MAX_m;
                    b = float(x1); // where it intercept x-axis
                }
                else{
                    // normal line
                    m = (y1 - y2) / (x1 - x2);
                    b = (x1*y2 - x2*y1) / (x1 - x2);
                }

                temp.m = m;
                temp.b = b;
                temp.set = new unordered_map<int, bool>;
                temp.set->insert({ i, true });
                temp.set->insert({ j, true });
                temp.totalCount = pointCount[makeKey(x1, y1)]->count;
                temp.totalCount += pointCount[makeKey(x2, y2)]->count;
                lines.push_back(temp);
            }
        }

        unsigned int max = 0;
        if (lines.size() == 0){
            max = pointCount[makeKey(points[0].x, points[0].y)]->count;
        }
        else{
            for (int k = 0; k < lines.size(); ++k){
                if (max < lines[k].totalCount){
                    max = lines[k].totalCount;
                }
            }

        }
        return max;
    }

    inline bool fallOnTheLine(const float m, const float b, const float x, const float y){
        if (m == MAX_m){
            return (abs(x - b) < delta);
        }

        if (abs(y - m * x - b) < delta){
            return true;
        }
        
        return false;
    }

    inline unsigned long long makeKey(int i, int j){
        unsigned long long key;
        char* p = (char*)&key;
        memcpy(p, &i, sizeof(int));
        memcpy(p + sizeof(int), &j, sizeof(int));
        return key;
    }
};

