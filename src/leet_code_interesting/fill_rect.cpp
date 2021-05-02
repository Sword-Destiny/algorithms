#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    unordered_set<long> pset;
public:
    inline void insert(int x, int y) {
        long point = ((long) x << 32) + y;
        if (pset.find(point) != pset.end()) {
            pset.erase(point);
        } else {
            pset.insert(point);
        }
    }

    bool isRectangleCover(vector<vector<int>> &rectangles) {
        pset.clear();
        int minx = INT32_MAX;
        int miny = INT32_MAX;
        int maxx = 0;
        int maxy = 0;
        long sub_sum_area = 0;
        for (vector<int> &rect:rectangles) {
            sub_sum_area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            if (rect[0] < minx)
                minx = rect[0];
            if (rect[1] < miny)
                miny = rect[1];
            if (rect[2] > maxx)
                maxx = rect[2];
            if (rect[3] > maxy)
                maxy = rect[3];
            insert(rect[0], rect[1]);
            insert(rect[0], rect[3]);
            insert(rect[2], rect[1]);
            insert(rect[2], rect[3]);
        }

        if (sub_sum_area != (maxx - minx) * (maxy - miny))
            return false;

        insert(minx, miny);
        insert(minx, maxy);
        insert(maxx, miny);
        insert(maxx, maxy);

        return pset.empty();
    }
};

int main() {
    vector<vector<int>> rects = {{1, 1, 3, 3},
                                 {3, 1, 4, 2},
                                 {3, 2, 4, 4},
                                 {1, 3, 2, 4},
                                 {2, 3, 3, 4}};
    Solution s = {};
    cout << s.isRectangleCover(rects) << endl;
    return 0;
}