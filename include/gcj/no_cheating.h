//
// Created by yuanhao on 18-9-28.
//
#ifndef ALGORITHMS_NO_CHEATING_H

#include "../mid_level/binary_partite_matching.h"

int no_cheating(int M, int N, char **seats) {

    int num = 0;//正常座位数量
    int dx[4] = {-1, 0, -1, 0};
    int dy[4] = {-1, -1, 1, 1};
    int V = M * N;//总数量
    int odd;//列为奇数的座位数量
    int even;//列为偶数的座位数量
    if (N % 2 == 0) {
        odd = even = V / 2;
    } else {
        odd = M * (N / 2);
        even = V - odd;
    }
    bool **can = new bool *[odd];
    for (int o = 0; o < odd; ++o) {
        can[o] = new bool[even];
        memset(can[o], 0, even * sizeof(bool));
    }
    for (int row = 0; row < M; ++row) {
        for (int column = 0; column < N; ++column) {
            if (seats[row][column] == '.') {
                num++;
                for (int k = 0; k < 4; ++k) {
                    int row2 = row + dx[k];
                    int column2 = column + dy[k];

                    if (row2 >= 0 && row2 < M && column2 >= 0 && column2 < N) {
                        if (seats[row2][column2] == '.') {
                            if (column % 2 == 0) {//如果index的列为奇数则index2必为偶数列,反之亦然
                                can[(N / 2) * row2 + column2 / 2][((N + 1) / 2) * row + column / 2] = true;
                            } else {
                                can[(N / 2) * row + column / 2][((N + 1) / 2) * row2 + column2 / 2] = true;
                            }

                        }
                    }
                }

            }
        }
    }

    int flow = binary_partite_matching(odd, even, can);

    for (int o = 0; o < odd; ++o) {
        delete[] can[o];
    }
    delete[] can;

    return num - flow;
}

#define ALGORITHMS_NO_CHEATING_H

#endif //ALGORITHMS_NO_CHEATING_H
