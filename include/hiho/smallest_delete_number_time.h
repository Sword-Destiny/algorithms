//
// Created by yuanhao on 2019-8-19.
//

#ifndef ALGORITHMS_SMALLEST_DELETE_NUMBER_TIME_H
#define ALGORITHMS_SMALLEST_DELETE_NUMBER_TIME_H

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int smallest_delete_number_time(int *numbers, int n) {
    vector<int> times;
    int res = 0;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        counts[numbers[i]]++;
    }
    for (auto entry:counts) {
        if (entry.second != 0) {
            times.push_back(entry.second);
        }
    }
    sort(times.begin(), times.end(), std::greater<int>());
    int tmp = times[0];
    for (int i = 1; i < times.size(); ++i) {
        if (times[i] >= tmp) {
            int d = min(times[i], times[i] - tmp + 1);
            res += d;
            times[i] -= d;
            tmp = times[i];
        } else {
            tmp = times[i];
        }
    }
    return res;
}

#endif //ALGORITHMS_SMALLEST_DELETE_NUMBER_TIME_H
