//
// Created by yuanh on 2018/6/7.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/blocks.h"

int main() {
    int mod = 10007;
    for (unsigned int i = 1; i <= 10; ++i) {
        cout << "blocks " << i << " : " << blocks(i, mod) << endl;
    }
    return 0;
}