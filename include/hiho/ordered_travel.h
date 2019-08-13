//
// Created by yuanhao on 2019-8-12.
//

#ifndef ALGORITHMS_ORDERED_TRAVEL_H
#define ALGORITHMS_ORDERED_TRAVEL_H

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;

void travel_depth(vector<int> *road, int *depth, int *father, bool *cover, int current_city, int i_depth);

bool is_ancient(const int *father, const int *depth, int node, int ancient);

int find_common_ancient(int *father, int *depth, int node, int node2);

/**
 * 描述
 * 小Hi和小Ho准备国庆期间去A国旅游。A国的城际交通比较有特色：它共有n座城市(编号1-n)；城市之间恰好有n-1条公路相连，形成一个树形公路网。
 * 小Hi计划从A国首都(1号城市)出发，自驾遍历所有城市，并且经过每一条公路恰好两次——来回各一次——这样公路两旁的景色都不会错过。
 * 令小Hi苦恼的是他的小伙伴小Ho希望能以某种特定的顺序游历其中m个城市。例如按3-2-5的顺序游历这3座城市。
 * (具体来讲是要求：第一次到达3号城市比第一次到达2号城市早，并且第一次到达2号城市比第一次到达5号城市早)。
 * 小Hi想知道是否有一种自驾顺序满足小Ho的要求。
 * 输入
 * 输入第一行是一个整数T(1<=T<=20)，代表测试数据的数量。
 * 每组数据第一行是一个整数n(1 <= n <= 100)，代表城市数目。
 * 之后n-1行每行两个整数a和b (1 <= a, b <= n)，表示ab之间有公路相连。
 * 之后一行包含一个整数m (1 <= m <= n)
 * 最后一行包含m个整数，表示小Ho希望的游历顺序。
 * 输出
 * YES或者NO，表示是否有一种自驾顺序满足小Ho的要求。
 * 样例输入
 * 2
 * 7
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 6
 * 3 7
 * 3
 * 3 7 2
 * 7
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 6
 * 3 7
 * 3
 * 3 2 7
 * 样例输出
 * YES
 * NO
 */
void ordered_travel() {
    int n;//城市数量
    cin >> n;
    int father[n + 1];//父子关系
    vector<int> roads[n + 1];//城市公路网
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    int m;
    cin >> m;
    int city;
    vector<int> city_list;//游览顺序
    for (int i = 0; i < m; ++i) {
        cin >> city;
        city_list.push_back(city);
    }

    // 前面都是在输入

    int depth[n + 1]; //节点深度
    bool cover[n + 1];//遍历标识
    memset(cover, 0, (n + 1) * sizeof(*cover));
    travel_depth(roads, depth, father, cover, 1, 0);

    for (int i = 0; i < city_list.size() - 1; ++i) {
        for (int j = i + 1; j < city_list.size(); ++j) {
            // 对城市顺序中的任意两个城市进行判断，这样做可能会产生多余的判断
            int city_i = city_list[i];
            int city_j = city_list[j];
            if (is_ancient(father, depth, city_i, city_j)) {
                //如果city_i是city_j的子节点，这显然是不行的，因为要先访问city_i后访问city_j
                cout << "NO" << endl;
                return;
            }
            int common_ancient = find_common_ancient(father, depth, city_i, city_j);//找到公共祖先节点
            if (common_ancient != city_i) {
                int d_depth = depth[city_i] - depth[common_ancient] - 1;
                int branch_ancient = city_list[i];//公共祖先节点的某一个分支，即city_i所在分支
                for (int d = 0; d < d_depth; ++d) {
                    branch_ancient = father[branch_ancient];
                }
                //当访问lcity_i之后再访问city_j，那么city_i与city_j的公共祖先节点的city_i所在的分支应该都已经访问过了，如果后面再有，那么顺序就不对
                for (int c = j + 1; c < city_list.size(); ++c) {
                    if (is_ancient(father, depth, city_list[c], branch_ancient)) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
}

/**
 * 返回公共祖先节点
 * @param father
 * @param depth
 * @param node
 * @param node2
 * @return
 */
int find_common_ancient(int *father, int *depth, int node, int node2) {
    int ancient = node;
    int ancient2 = node2;
    if (depth[node] >= depth[node2]) {
        int d_depth = depth[node] - depth[node2];
        for (int i = 0; i < d_depth; ++i) {
            ancient = father[ancient];
        }
    } else {
        int d_depth = depth[node2] - depth[node];
        for (int i = 0; i < d_depth; ++i) {
            ancient2 = father[ancient2];
        }
    }
    while (ancient != ancient2) {
        ancient = father[ancient];
        ancient2 = father[ancient2];
    }
    return ancient;
}

/**
 * 判断ancient_node是否是node的祖先节点
 * @param father
 * @param depth
 * @param node
 * @param ancient_node
 */
bool is_ancient(const int *father, const int *depth, int node, int ancient_node) {
    if (depth[node] >= depth[ancient_node]) {
        int d_depth = depth[node] - depth[ancient_node];
        int real_ancient = node;
        for (int f = 0; f < d_depth; ++f) {
            real_ancient = father[real_ancient];
        }
        if (real_ancient == ancient_node) {
            return true;
        }
    }
    return false;
}


/**
 * 遍历并计算每个节点相对于1号城市的树深度，计算父子节点关系
 * @param road
 * @param depth
 * @param current_city 当前节点
 * @param i_depth 当前深度
 */
void travel_depth(vector<int> *road, int *depth, int *father, bool *cover, int current_city, int i_depth) {
    cover[current_city] = true;
    depth[current_city] = i_depth;
    for (int &next_city:road[current_city]) {
        if (!cover[next_city]) {
            father[next_city] = current_city;
            travel_depth(road, depth, father, cover, next_city, i_depth + 1);
        }
    }
}


#endif //ALGORITHMS_ORDERED_TRAVEL_H
