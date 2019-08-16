//
// Created by yuanhao on 2019-8-16.
//

#include "../../include/hiho/quad_tree.h"

int main() {
    int n = 0, m = 0;
    cin >> n;
    cin >> m;
    vector<pair<int, int>> points;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        points.emplace_back(pair<int, int>(x, y));
    }
    int a, b, r;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> r;
        cout << quad_tree(points, a, b, r) << endl;
    }
}