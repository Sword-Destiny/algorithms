//
// Created by yuanhao on 2019-9-3.
//
#include <iostream>

using namespace std;

class Solution {
    long long n;     //n个皇后
    long long total; //总共的解法
    int *c;
public:

    explicit Solution(long long n) : n(n), total(0), c(new int[n]) {

    }

    ~Solution() {
        delete[] c;
    }

    long long getTotal() {
        maxQueen(0);
        return total;
    }

    //八皇后问题共有92种解法(回溯法、递归实现)
    void maxQueen(int row) {
        if (row == n) {
            total++;
        } else {
            for (int col = 0; col != n; col++) {
                c[row] = col;
                if (isOk(row)) {
                    maxQueen(row + 1); //递归调用，进行下一行的安排
                }
            }
        }
    }

    //判断一个位置是否可以放置皇后
    bool isOk(int row) {
        for (int j = 0; j != row; j++) {
            if ((c[row] == c[j]) || (row - c[row] == j - c[j]) || (row + c[row] == j + c[j]))
                return false;
        }
        return true;
    }
};

//八皇后问题，是一个古老而著名的问题。该问题是国际西洋棋棋手马克斯·贝瑟尔于1848年提出：在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。利用回溯算法我们能很快的得到共有92种互不相同的解（独立解有12种）。当棋盘变成n行，n列，且皇后也有n个的时候（n<=20），问有多少种不同的解？
//
//输入描述:
//一行，一个正整数n(1<=n<=20)
//
//
//输出描述:
//输出一个整数，代表解的个数。
//示例1
//输入
//8
//输出
//92
//示例2
//输入
//20
//输出
//39029188884
int main() {
    long long n = 0;
    cin >> n;
    // Solution s(n);
    // cout << s.getTotal() << endl;
    // 普通的解法肯定超时，最牛的大牛求解16皇后都要十几秒时间，更别说一秒钟之内求解20皇后问题了
    // 所以，下面是唯一的办法了。。。
    // 查表法，先全部算好，直接查表就行
    // ^(^.^)^
    long long a[20] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184, 14772512, 95815104,
                       666090624, 4968057848, 39029188884};
    cout << a[n - 1] << endl;
}