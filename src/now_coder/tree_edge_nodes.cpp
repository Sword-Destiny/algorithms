//
// Created by yuanhao on 2019-9-2.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// 计算深度和访问顺序
void edge0(int root, const int *lch, const int *rch, vector<int> *visit_orders, int *depth, int dep) {
    depth[root] = dep;
    visit_orders[dep].push_back(root);
    if (lch[root] != 0) {
        edge0(lch[root], lch, rch, visit_orders, depth, dep + 1);
    }
    if (rch[root] != 0) {
        edge0(rch[root], lch, rch, visit_orders, depth, dep + 1);
    }
}

// 所有叶节点
void edge1(int root, int *lch, int *rch, bool *output, bool *is_right) {
    if (lch[root] != 0) {
        edge1(lch[root], lch, rch, output, is_right);
    }
    if (rch[root] != 0) {
        edge1(rch[root], lch, rch, output, is_right);
    }
    if (lch[root] == 0 && rch[root] == 0 && !output[root] && !is_right[root]) {
        cout << root << " ";
        output[root] = true;
    }
}

void edge2(int root, int *lch, int *rch, bool left, bool right, bool *output) {
    // 左路径
    if (left && !output[root]) {
        cout << root << " ";
        output[root] = true;
    }
    if (lch[root] != 0) {
        edge2(lch[root], lch, rch, left, right && rch[root] == 0, output);
    }
    if (rch[root] != 0) {
        edge2(rch[root], lch, rch, left && lch[root] == 0, right, output);
    }
    // 叶节点
    if (lch[root] == 0 && rch[root] == 0 && !output[root]) {
        cout << root << " ";
        output[root] = true;
    }
    //右路径
    if (!output[root] && right) {
        cout << root << " ";
        output[root] = true;
    }
}

//题目描述
//给定一颗二叉树的根节点 root，按照如下两种标准分别实现二叉树的边界节点的逆时针打印。
//标准一：
//1，根节点为边界节点。
//2，叶节点为边界节点。
//3，如果节点在其所在的层中是最左的或最右的，那么该节点也是边界节点。
//标准二：
//1，根节点为边界节点。
//2，叶节点为边界节点。
//3，树左边界延伸下去的路径为边界节点。
//4，树右边界延伸下去的路径为边界节点。
//ps:具体请对照样例
//输入描述:
//第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。
//以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
//输出描述:
//输出两行整数分别表示按两种标准的边界节点。
//示例1
//输入
//复制
//16 1
//1 2 3
//2 0 4
//4 7 8
//7 0 0
//8 0 11
//11 13 14
//13 0 0
//14 0 0
//3 5 6
//5 9 10
//10 0 0
//9 12 0
//12 15 16
//15 0 0
//16 0 0
//输出
//复制
//1 2 4 7 11 13 14 15 16 12 10 6 3
//1 2 4 7 13 14 15 16 10 6 3
int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    int lch[n + 1];
    int rch[n + 1];
    for (int i = 0; i < n; ++i) {
        int f, l, r;
        cin >> f >> l >> r;
        lch[f] = l;
        rch[f] = r;
    }
    // 前面是输入

    // 第一种情况，
    // 这种情况其实题目是有问题的，顺序的问题，并不是你所以为的逆时针顺序，而是下面的顺序，
    // 先输出每层最左节点，再输出既不是每层最左节点也不是每层最右节点的叶节点，最后从下往上输出每层最右节点
    // 我也是看了出错的用例才从里面看出来的，此题略坑

    bool output[n + 1]; // 是否已经输出了这个节点，一个节点可能既是每层最左节点，又是每层最右节点，又是子节点
    memset(output, 0, sizeof(bool) * (n + 1));
    int depth[n + 1]; // 节点深度
    vector<int> visit_orders[n + 1]; // 访问顺序
    memset(depth, 0, sizeof(int) * (n + 1));

    // 先序遍历，获取节点深度和访问顺序，每层最左节点是本层先被访问的，最右节点是本层最后被访问的
    edge0(root, lch, rch, visit_orders, depth, 0);

    bool is_right[n + 1]; // 是否本层最右节点
    memset(is_right, 0, sizeof(bool) * (n + 1));
    // 输出每层最左边节点
    for (int dep = 0; dep <= n; ++dep) {
        vector<int> level = visit_orders[dep];
        if (!level.empty()) {
            cout << level[0] << " ";
            output[level[0]] = true;
            is_right[level[level.size() - 1]] = true;
        }
    }
    // 第二次遍历，输出既不是每层最左节点，也不是每层最右节点的叶节点
    edge1(root, lch, rch, output, is_right);
    // 输出每层最右节点
    for (int dep = n; dep >= 0; --dep) {
        vector<int> level = visit_orders[dep];
        if (!level.empty() && !output[level[level.size() - 1]]) {
            cout << level[level.size() - 1] << " ";
            output[level[level.size() - 1]] = true;
        }
    }
    cout << endl;

    // 第二种情况
    memset(output, 0, sizeof(bool) * (n + 1));
    edge2(root, lch, rch, true, true, output);

    return 0;
}