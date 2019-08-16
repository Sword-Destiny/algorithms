//
// Created by yuanhao on 2019-8-16.
//

#ifndef ALGORITHMS_QUAD_TREE_H
#define ALGORITHMS_QUAD_TREE_H

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define small 0.000000001

/**
 * 描述
 * 小Ho：下个周末我们打算去隔壁城市玩吧？
 * 小Hi：反正来回也挺近的，好啊。
 * 小Ho：那么我先来规划一下游玩路线吧。
 * 小Ho打开了手机中的地图APP，把坐标移动到了隔壁的城市。各种各样的店铺显示在了街道的地图上。
 * 小Hi：小Ho，你知道地图APP是怎么计算出你周围的店铺么？
 * 小Ho：哎？没有想过哎。
 * 小Hi：其实这也是个很有意思的问题呢。我们先把模型简化一下，假设有一张平面图，上面分布了N个点，第i个点的坐标为(x[i],y[i])。
 * 小Ho：用点来代表店铺么？
 * 小Hi：是的，然后假如我们所在的坐标为(a,b)，那么以我们为中心半径为r的范围内(包含边上)，有多少个点呢？
 * 小Ho：感觉是个很有意思的问题呢，让我想一想。
 * 提示：四叉树(Quadtree)
 * 输入
 * 第1行：2个整数N,M。1≤N≤50,000,0≤M≤5,000。
 * 第2..N+1行：每行2个整数x,y，第i+1行表示第i个点的坐标，保证没有重复的点。0≤x,y≤30,000
 * 第N+2..N+M+1行：每行3个整数a,b,r，表示询问的中心坐标(a,b)，以及半径r。0≤a,b,r≤30,000
 * 输出
 * 第1..M行：每行1个整数，第i行表示以第i个询问的(x,y)为中心所包含的点数。
 * 样例输入
 * 2 2
 * 1 1
 * 2 2
 * 2 2 1
 * 2 2 2
 * 样例输出
 * 1
 * 2
 * @param points
 * @param a
 * @param b
 * @param r
 * @return
 */
int quad_tree(vector<pair<int, int>> &points, int a, int b, int r) {
    int ans = 0;
    for (auto p:points) {
        double pr = sqrt((p.first - a) * (p.first - a) + (p.second - b) * (p.second - b));
        if (pr + small <= r) {
            ans++;
        }
    }
    return ans;
}

#endif //ALGORITHMS_QUAD_TREE_H
