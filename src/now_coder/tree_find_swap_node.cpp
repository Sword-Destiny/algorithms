//
// Created by yuanhao on 2019-9-2.
//
#include <iostream>
#include <cstring>

using namespace std;

/**
 * 对无序的几位进行排序 O(n)
 */
void sort(int *a, int n, int *wrong_index, int &wrong_index_len) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            if (wrong_index[wrong_index_len - 1] != i) {
                wrong_index[wrong_index_len++] = i;
            }
            if (wrong_index[wrong_index_len - 1] != i + 1) {
                wrong_index[wrong_index_len++] = i + 1;
            }
            if (wrong_index_len >= 4) {
                // 两个数字交换，最多只有四个可能的位置不对
                break;
            }
        }
    }

    // 对最多四个位置的数字进行排序，随便选排序算法，冒泡就行
    for (int i = 0; i < wrong_index_len - 1; ++i) {
        for (int j = 0; j < wrong_index_len - 1 - i; j++) {
            if (a[wrong_index[j]] > a[wrong_index[j + 1]]) {
                int tmp = a[wrong_index[j]];
                a[wrong_index[j]] = a[wrong_index[j + 1]];
                a[wrong_index[j + 1]] = tmp;
            }
        }
    }
}


/**
 * 中序遍历 O(n)
 */
void mid_visite(int root, int *lch, int *rch, int *arr, int &num) {
    if (lch[root] != 0) {
        mid_visite(lch[root], lch, rch, arr, num);
    }
    arr[num++] = root;
    if (rch[root] != 0) {
        mid_visite(rch[root], lch, rch, arr, num);
    }
}

//题目描述
//一棵二叉树原本是搜索二叉树，但是其中有两个节点调换了位置，使得这棵二叉树不再是搜索二叉树，请按升序输出这两个错误节点的值。(每个节点的值各不相同)
//
//输入描述:
//第一行输入两个整数 n 和 root，n 表示二叉树的总节点个数，root 表示二叉树的根节点。
//
//以下 n 行每行三个整数 fa，lch，rch，表示 fa 的左儿子为 lch，右儿子为 rch。(如果 lch 为 0 则表示 fa 没有左儿子，rch同理)
//
//ps:节点的编号就是该节点的值。
//输出描述:
//请按升序输出这两个错误节点的值。
//示例1
//输入
//复制
//3 1
//1 2 3
//2 0 0
//3 0 0
//输出
//复制
//1 2
int main() {
    int n = 0;
    int root = 0;
    cin >> n >> root;
    int lch[n];
    int rch[n];
    for (int i = 0; i < n; ++i) {
        int f, l, r;
        cin >> f >> l >> r;
        lch[f] = l;
        rch[f] = r;
    }
    // 前面都是输入

    int num = 0;
    int arr[n];
    int sorted_arr[n];
    mid_visite(root, lch, rch, arr, num); // 实际上这个num最后是等于n的
    memcpy(sorted_arr, arr, num * sizeof(int));

    // 搜索树中序遍历的结果应该是一个有序的数组，这里有两位被交换，会导致最多四个位置的数字无序，排序之后就知道是哪两位交换了
    // 不用完整的排序，那样会超时，自己写一个排序算法
    int wrong_index[4];
    int wrong_index_len = 0;
    sort(sorted_arr, num, wrong_index, wrong_index_len);

    // 输出结果
    for (int i = 0; i < wrong_index_len; ++i) {
        if (arr[wrong_index[i]] != sorted_arr[wrong_index[i]]) {
            cout << sorted_arr[wrong_index[i]] << " ";
        }
    }
}