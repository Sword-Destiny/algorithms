//
// Created by yuanh on 2018/6/14.
//

#ifndef ALGORITHMS_DANCING_LINKS_H

#include "matrix.h"

/**
 * 求解精确覆盖问题的通用算法
 * dancing links
 * 舞蹈的链条算法
 * @param m 矩阵
 * @param selected 最后选择的行
 * @return 选择的行数
 */
int dancing_links(matrix<bool> &m, bool *selected) {
    if (m.row == 1) { //只有一行的情况
        for (int i = 0; i < m.column; ++i) {
            if (!m[0][i]) {
                return -1; //无解
            }
        }
        selected[0] = true;
        return 1; //有解
    }
    for (int i = 0; i < m.row; ++i) {
        selected[i] = true;
        int remove_row = 0;
        int remove_column = 0;
        bool *rr = new bool[m.row]; //要移除的行
        memset(rr, 0, sizeof(*rr) * m.row);
        bool *rc = new bool[m.column]; //要移除的列
        memset(rc, 0, sizeof(*rc) * m.column);
        rr[i] = 1;
        for (int c = 0; c < m.column; ++c) {
            if (m[i][c]) {
                remove_column++;
                rc[c] = 1;
                for (int r = 0; r < m.row; ++r) {
                    if (r != i && m[r][c]) {
                        remove_row++;
                        rr[r] = 1;
                    }
                }
            }
        }
        bool *sub_selected = new bool[m.row - remove_row]; //子问题参数
        memset(sub_selected, 0, sizeof(*sub_selected) * (m.row - remove_row));
        matrix<bool> new_m(m.row - remove_row, m.column - remove_column); //子问题参数
        int nr = 0;
        for (int r = 0; r < m.row; ++r) {
            if (!rr[r]) {
                int nc = 0;
                for (int c = 0; c < m.column; ++c) {
                    if (!rc[c]) {
                        new_m[nr][nc] = m[r][c];
                        nc++;
                    }
                }
                nr++;
            }
        }
        int sub_res = dancing_links(new_m, sub_selected); // 递归
        if (sub_res != -1) {
            // 有解
            int sr = 0;
            for (int r = 0; r < m.row; ++r) {
                if (!rr[r]) {
                    selected[r] = sub_selected[sr++];
                }
            }
            delete[] rr;
            delete[] rc;
            delete[] sub_selected;
            return sub_res + 1;
        }
        delete[] rr;
        delete[] rc;
        delete[] sub_selected;
        selected[i] = false;
    }
    return -1; //无解
}

#define ALGORITHMS_DANCING_LINKS_H

#endif //ALGORITHMS_DANCING_LINKS_H