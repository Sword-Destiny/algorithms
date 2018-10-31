//
// Created by yuanh on 2018/6/19.
//

#include "matrix.h"

#ifndef ALGORITHMS_ORTHOGONAL_LATIN_SQUARES_H

#include <vector>
#include "array.h"
#include "dancing_links.h"

using std::vector;

/**
 * 采用递归的方法,生成n个数全排列
 * @param selected 已选择的数
 * @param s 已选择的数量
 * @param unselected 未选择的数
 * @param u 未选择的数量
 */
void full_arrangement(bool *cover, int i, matrix<int> &m, vector<darray<int>> &transversal, int *selected, int s, const int *unselected, int u) {
    if (u == 0) {
        // selected[a] == b意味着,所求的矩阵的第b行第a列为i
        // 比如 <0,1,2,3,5,6,9,8,4,7> 意味着
        // [0, , , , , , , , , ]
        // [ ,0, , , , , , , , ]
        // [ , ,0, , , , , , , ]
        // [ , , ,0, , , , , , ]
        // [ , , , , , , , ,0, ]
        // [ , , , ,0, , , , , ]
        // [ , , , , ,0, , , , ]
        // [ , , , , , , , , ,0]
        // [ , , , , , , ,0, , ]
        // [ , , , , , ,0, , , ]
        //
        // 而 <1,2,0,6,7,3,5,4,8,9> 意味着
        // [ , ,1, , , , , , , ]
        // [1, , , , , , , , , ]
        // [ ,1, , , , , , , , ]
        // [ , , , , ,1, , , , ]
        // [ , , , , , , ,1, , ]
        // [ , , , , , ,1, , , ]
        // [ , , ,1, , , , , , ]
        // [ , , , ,1, , , , , ]
        // [ , , , , , , , ,1, ]
        // [ , , , , , , , , ,1]
        memset(cover, 0, s * sizeof(*cover));
        for (int index = 0; index < s; ++index) {
            cover[m[selected[index]][index]] = true;
        }
        for (int index = 0; index < s; ++index) {
            if (!cover[index]) {
                return;
            }
        }
        darray<int> arr(selected, s);
        transversal.emplace_back(arr);
    }
    for (int index = 0; index < u; ++index) {
        selected[s] = unselected[index];
        auto *sub_unselected = new int[u - 1];
        int sub_index = 0;
        for (int j = 0; j < u; ++j) {
            if (j != index) {
                sub_unselected[sub_index++] = unselected[j];
            }
        }
        full_arrangement(cover, i, m, transversal, selected, s + 1, sub_unselected, u - 1);
        delete[] sub_unselected;
    }
}

/**
 * 找到所有的transversals
 * @param transversals 用于dancing links算法的符合条件的数字分布
 * @param n 矩阵行列
 * @param m 矩阵
 */
void find_transversals(vector<darray<int>> *transversals, int n, matrix<int> &m) {
    auto *cover = new bool[n];
    for (int i = 0; i < n; ++i) {
        auto *selected = new int[n];
        selected[0] = m[i][0];
        auto *unselected = new int[n - 1];
        for (int index = 0; index < selected[0]; ++index) {
            unselected[index] = index;
        }
        for (int index = selected[0]; index < n - 1; ++index) {
            unselected[index] = index + 1;
        }
        full_arrangement(cover, i, m, transversals[i], selected, 1, unselected, n - 1);
        delete[] selected;
        delete[] unselected;
    }
    delete[] cover;
}


/**
 * 求正交拉丁矩阵
 * <<The Art Of Computer Programming>> 卷4A,第三页的问题
 * @param m 矩阵,确保row==column
 * @return 正交拉丁矩阵
 */
matrix<int> orthogonal_latin_squares(matrix<int> &m) {
    int n = m.row;
    matrix<int> res(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = -1;
        }
    }
    auto *transversals = new vector<darray<int>>[n];
    find_transversals(transversals, n, m);
    // 构造dancing links矩阵,如果按照案例中的输入,则矩阵一共808行
    // 矩阵一共有 n+n*n 列
    // 第0到n-1列代表数字0到n-1的出现,这n列只有一个1,其余为0
    // 第n到 n+n*n-1列代表数字出现在矩阵的[x,y]位置,其中列position = x*n + y + n ,除了position列为1,其他为0
    int M = 0;
    for (int i = 0; i < n; ++i) {
        M += transversals[i].size();
    }
    int N = n * n + n;
    matrix<bool> dancing_links_m(M, N);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        vector<darray<int> > &transversal = transversals[i];
        for (auto &arr : transversal) {
            bool *dancing_line = dancing_links_m[index++];
            for (int di = 0; di < n; ++di) {
                dancing_line[di] = di == m[i][0];
            }
            for (int di = n; di < N; ++di) {
                dancing_line[di] = false;
            }
            for (int ai = 0; ai < n; ++ai) {
                int position = ai + n * arr[ai] + n;
                dancing_line[position] = true;
            }
        }
    }
    auto *selected = new bool[M];
    dancing_links(dancing_links_m, selected);
    // dancing links算法结束后将结果构造出来
    for (int si = 0; si < M; ++si) {
        if (selected[si]) {
            bool *line = dancing_links_m[si];
            int number = -1;
            for (int i = 0; i < n; ++i) {
                if (line[i]) {
                    number = m[i][0];
                    break;
                }
            }
            for (int i = n; i < N; ++i) {
                if (line[i]) {
                    int position_shift = i - n;
                    int row = position_shift / n;
                    int column = position_shift % n;
                    res[row][column] = number;
                }
            }
        }
    }
    delete[] selected;
    delete[] transversals;
    return res;
}

#define ALGORITHMS_ORTHOGONAL_LATIN_SQUARES_H

#endif //ALGORITHMS_ORTHOGONAL_LATIN_SQUARES_H
