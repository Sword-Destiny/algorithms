//
// Created by yuanhao on 2019-8-20.
//

#ifndef ALGORITHMS_MIN_SHOPPING_DISTANCE_H
#define ALGORITHMS_MIN_SHOPPING_DISTANCE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define maxn 100001
using namespace std;

int shops[maxn];
int ans[maxn];
int bounds[maxn];
int locations[maxn];

int nk;
int k1;
int n = 0, m = 0, k = 0;

int **min_distances = nullptr;

/**
 * 二分计算min_distance
 * min_distance中的数据的含义是：
 * 第一个下标i代表连续i个长度为k1的区间的路程的最小值
 * 第二个下表j代表初始商店索引
 * @param min_k
 */
void compute(int min_k) {
    if (min_distances[min_k][0] != 0) {
        return;
    }
    int len = n - k1 - min_k + 1;
    int sub_k = min_k / 2;
    int sub_k2 = min_k - sub_k;
    compute(sub_k);
    compute(sub_k2);
    for (int i = 0; i < len; ++i) {
        min_distances[min_k][i] = min(min_distances[sub_k][i], min_distances[sub_k2][i + sub_k]);
    }
}

void compute_min_distances() {
    min_distances = new int *[k];
    for (int i = 0; i < n; ++i) {
        min_distances[i] = new int[n];
        memset(min_distances[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < n - k1; ++i) {
        min_distances[1][i] = 2 * (shops[i + k1] - shops[i]);
    }

    compute(k1);
}

void output_min_distances(int ok){
    for (int i = 1; i <= ok; ++i) {
        for (int j = 0; j < n - k1 - i + 1; ++j) {
            cout << min_distances[i][j] << " ";
        }
        cout << endl;
    }
}


/**
 * 计算住宅位于哪两个商店之间，这里记录的是住宅右边的第一个商店，或者住宅同位置的商店
 * 复杂度O(n + m)
 */
void count_bounds() {
    int ni = 0;
    int mi = 0;
    while (mi < m && ni < n) {
        if (shops[ni] > locations[mi]) {
            bounds[mi] = ni;
            mi++;
        } else {
            ni++;
        }
    }
    if (ni == n) {
        for (int i = mi; i < m; ++i) {
            bounds[i] = n;
        }
    }
}

/**
 * 描述
 * 在一条笔直的大道上坐落着N家连锁店和M栋住宅。不妨将大道看作数轴，则N家连锁店的坐标是A1, A2, ... AN，M栋住宅的坐标是B1, B2, ... BM。
 * 现在连锁店在搞圣诞活动，只要收集K家不同连锁店的贴纸，就可以获得年终优惠。小Hi想知道对于每一住宅的居民，如果他们从自家住宅出发，收集至少K家不同连锁店的贴纸，再回到自己住宅，途经的总距离最少是多少。
 * 输入
 * 第一行包含两个整数N、M和K。
 * 第二行包含N个整数A1, A2, ... AN。
 * 第三行包含M个整数B1, B2, ... BM。
 * 对于50%的数据，1 <= N, M <= 10000
 * 对于100%的数据，1 <= K <= N <= 100000 1 <= M <= 100000 0 <= Ai, Bi <= 1000000
 * 输出
 * 输出M行。其中第i行包含一个整数，代表从坐标Bi的住宅出发，收集K家的贴纸再回到Bi，途经的最少的总距离。
 * 样例输入
 * 5 3 2
 * 1 3 4 5 10
 * 2 5 6
 * 样例输出
 * 4
 * 2
 * 4
 *
 * 复杂度O(k)
 */
int min_shopping_distance(int mi) {
    int location = locations[mi];
    int right_index = bounds[mi];
    int left_index;
    // 左边界和右边界差不多相差k
    if (shops[right_index] == location) {
        left_index = right_index - k1;
    } else {
        left_index = right_index - k;
    }
    left_index = max(0, left_index);

    // start和end是循环的边界，肯定是必须要大于等于0小于等于n-k的，否则会溢出
    int start = min(left_index, nk);
    int end = min(right_index, nk);

    int min_distance = 2000001;
    for (int i = start; i <= end; ++i) {
        // 最小的情况下必是相连的k家商店
        int shop_begin = shops[i];
        int shop_end = shops[i + k1];
        int distance;
        if ((shop_begin - location) * (location - shop_end) >= 0) {
            distance = 2 * abs(shop_begin - shop_end);
        } else {
            distance = 2 * max(abs(shop_begin - location), abs(location - shop_end));
        }
        if (distance < min_distance) {
            min_distance = distance;
        }
    }
    return min_distance;
}

#endif //ALGORITHMS_MIN_SHOPPING_DISTANCE_H