//
// Created by yuanhao on 2019-8-20.
//

#include "../../include/hiho/min_shopping_distance.h"

int main() {
    cin >> n >> m >> k;
    nk = n - k;
    k1 = k - 1;
    for (int i = 0; i < n; ++i) {
        int shop;
        cin >> shop;
        shops[i] = shop;
    }
    //sort(shops, shops + n);
    for (int i = 0; i < m; ++i) {
        int location;
        cin >> location;
        locations[i] = location;
    }
    count_bounds();
    compute_min_distances();
    output_min_distances(k1);
    // 复杂度O(n * k)
    for (int i = 0; i < m; ++i) {
        ans[i] = min_shopping_distance(i);
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}