//
// Created by yuanh on 2018/6/14.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/dancing_links.h"

int main() {
    auto **can = new bool *[6]{
            new bool[7]{false, false, true, false, true, true, false},
            new bool[7]{true, false, false, true, false, false, true},
            new bool[7]{false, true, true, false, false, true, false},
            new bool[7]{true, false, false, true, false, false, false},
            new bool[7]{false, true, false, false, false, false, true},
            new bool[7]{false, false, false, true, true, false, true},
    };
    matrix<bool> m(6, 7, can);
    auto *selected = new bool[m.row];
    memset(selected, 0, sizeof(*selected) * m.row);
    int res = dancing_links(m, selected);
    cout << "dancing_links res : " << res << endl;
    cout << "selected rows : ";
    for (int r = 0; r < m.row; ++r) {
        cout << selected[r] << " ";
    }
    cout << endl;
    for (int i = 0; i < m.row; ++i) {
        delete[] can[i];
    }
    delete[] can;
    delete[] selected;
}