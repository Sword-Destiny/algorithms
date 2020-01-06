//
// Created by yuanhao on 2019-8-30.
//

#include <iostream>

using namespace std;

//题目描述
//给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。
//输入描述:
//第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。
//以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
//最后一行为节点 o1 和 o2。
//输出描述:
//输出一个整数表示答案。
//
//示例1
//输入
//8 1
//1 2 3
//2 4 5
//4 0 0
//5 0 0
//3 6 7
//6 0 0
//7 8 0
//8 0 0
//4 5
//输出
//2
int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    int father[n + 1];// 保存父节点信息
    int f, l, r;
    for (int i = 0; i < n; i++) {
        cin >> f >> l >> r;
        if (l != 0) {
            father[l] = f;
        }
        if (r != 0) {
            father[r] = f;
        }
    }

    int ln = 0, rn = 0;
    cin >> ln >> rn;

    int ld = 0, rd = 0; // 节点深度
    l = ln, r = rn;
    while (l != root) {
        ld++;
        l = father[l];
    } // 这个while循环用于计算左节点深度
    while (r != root) {
        rd++;
        r = father[r];
    }//这个while循环用于计算右节点深度
    l = ln;
    r = rn;
    // 下面这个if-else会将深度更低的节点上移，抹平两个节点的深度差距
    if (ld > rd) {
        int bd = ld - rd;
        for (int i = 0; i < bd; i++) {
            l = father[l];
        }
    } else {
        int bd = rd - ld;
        for (int i = 0; i < bd; i++) {
            r = father[r];
        }
    }
    // 然后一起上移，直到找到公共祖先节点
    while (l != r) {
        l = father[l];
        r = father[r];
    }
    cout << l << endl; // 或者 cout << r << endl; 都是一样的
}