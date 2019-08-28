//
// Created by yuanhao on 2019-8-28.
//

#include "../../include/now_coder/max_happy_value.h"

int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    int happy_value[n + 1];
    vector<int> tree[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> happy_value[i];
    }
    int ui = 0, vi = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> ui >> vi;
        tree[ui].push_back(vi);
    }

    int root_exists_max = 0;
    int root_not_exists_max = 0;
    max_happy_value(root, happy_value, tree, root_exists_max, root_not_exists_max);
    cout << max(root_exists_max, root_not_exists_max) << endl;
}