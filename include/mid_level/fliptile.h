//
// Created by yuanh on 2018/6/3.
//

#ifndef ALGORITHMS_FLIPTILE_H

#include <cstring>

using std::memset;

enum fliptile_color {
    white = 0,
    black = 1
};

typedef struct _coordinate {
    int x;
    int y;
} coordinate;

#define D 5
coordinate xy[D] = {{-1, 0},
                    {0,  -1},
                    {0,  0},
                    {0,  1},
                    {1,  0}};

/**
 * 查询颜色
 * @param x x行
 * @param y y列
 * @param rows 行
 * @param columns 列
 * @param puzzle 初始状态
 * @param fliptile_times 翻转次数
 * @return 颜色
 */
fliptile_color get_color(int x, int y, unsigned int rows, unsigned int columns, fliptile_color **puzzle,
          int **fliptile_times) {
    int c = puzzle[x][y];
    for (auto &d : xy) {
        int x2 = x + d.x;
        int y2 = y + d.y;
        if (x2 >= 0 && x2 < rows && y2 >= 0 && y2 < columns) {
            c += fliptile_times[x2][y2];
        }
    }
    return static_cast<fliptile_color>(c % 2);
}

/**
 * 固定第一行求解
 * @param rows 行
 * @param columns 列
 * @param puzzle 初始状态
 * @param fliptile_times 翻转次数
 * @return 翻转总次数
 */
int fun_1(unsigned int rows, unsigned int columns, fliptile_color **puzzle, int **fliptile_times) {
    for (unsigned int row = 1; row < rows; ++row) {
        for (unsigned int column = 0; column < columns; ++column) {
            if (get_color(row - 1, column, rows, columns, puzzle, fliptile_times) == black) {
                // (row-1,column)为黑色,则必须翻转(row,column),因为上一行已经确定了
                fliptile_times[row][column] = 1;
            }
        }
    }
    //判断最后一行是否全白
    for (unsigned int column = 0; column < columns; ++column) {
        if (get_color(rows - 1, column, rows, columns, puzzle, fliptile_times) != white) {
            return -1;
        }
    }
    //统计翻转次数
    int res = 0;
    for (unsigned int row = 0; row < rows; ++row) {
        for (unsigned int column = 0; column < columns; ++column) {
            res += fliptile_times[row][column];
        }
    }
    return res;
}

/**
 * 开关灯游戏
 * POJ No.3279
 *
 * @param rows 行
 * @param columns 列,注意columns<32
 * @param puzzle 初始状态
 * @param fliptile_times 翻转次数
 * @return 全部翻转为白色需要的总翻转次数,如果为-1则代表无解
 */
int fliptile(unsigned int rows, unsigned int columns, fliptile_color **puzzle, int **fliptile_times) {
    int res = -1;
    unsigned int best_i = 0;
    // 遍历第一行的所有情况
    for (unsigned int i = 0; i < ((unsigned) 1 << columns); ++i) {
        for (int r = 0; r < rows; ++r) {
            memset(fliptile_times[r], 0, columns * sizeof(*fliptile_times[r]));
        }
        for (unsigned int column = 0; column < columns; ++column) {
            fliptile_times[0][columns - column - 1] = (i >> column) & (unsigned) 1;
        }
        int num = fun_1(rows, columns, puzzle, fliptile_times);
        if (num >= 0 && (res < 0 || num < res)) {
            res = num;
            best_i = i;//最优解
        }
    }
    if (res < 0) {
        return res;//无解
    }
    // 恢复最优解
    for (int r = 0; r < rows; ++r) {
        memset(fliptile_times[r], 0, columns * sizeof(*fliptile_times[r]));
    }
    for (unsigned int column = 0; column < columns; ++column) {
        fliptile_times[0][columns - column - 1] = (best_i >> column) & (unsigned) 1;
    }
    res = fun_1(rows, columns, puzzle, fliptile_times);
    return res;
}

#define ALGORITHMS_FLIPTILE_H

#endif //ALGORITHMS_FLIPTILE_H
