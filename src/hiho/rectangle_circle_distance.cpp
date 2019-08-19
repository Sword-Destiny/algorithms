//
// Created by yuanhao on 2019-8-19.
//
#include "../../include/hiho/rectangle_circle_distance.h"

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        int y = 0;
        int r = 0;
        cin >> x >> y;
        point p1 = {x, y};
        cin >> x >> y;
        point p2 = {x, y};
        cin >> x >> y >> r;
        point circle = {x, y};
        cout << rectangle_circle_distance(p1, p2, circle, r) << endl;
    }
    return 0;
}
