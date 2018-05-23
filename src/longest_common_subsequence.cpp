//
// Created by sworddestiny on 17-12-16.
//

#include "../include/longest_common_subsequence.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    const char *s = "123456789";
    const char *t = "2346789";
    int sn = 9;
    int tm = 7;
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    int result = longest_common_subsequence(s, sn, t, tm);
    cout << "longest common subsequence: " << result << endl;
    return 0;
}

