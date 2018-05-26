//
// Created by yuanh on 2018/5/26.
//
#include "../include/conscription.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
    int n = 5;
    int m = 5;
    int r = 8;
    auto **relations = new int *[8]{new int[3]{4, 3, 6831},
                                    new int[3]{1, 3, 4583},
                                    new int[3]{0, 0, 6592},
                                    new int[3]{0, 1, 3063},
                                    new int[3]{3, 3, 4975},
                                    new int[3]{1, 2, 2049},
                                    new int[3]{4, 2, 2104},
                                    new int[3]{2, 2, 781}};



    cout << "conscription cost : " << conscription(n, m, r, relations) << endl;
    for (int i = 0; i < 8; ++i) {
        delete[] relations[i];
    }
    delete[] relations;
    return 0;
}
