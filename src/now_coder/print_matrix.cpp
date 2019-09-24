//
// Created by yuanhao on 2019-9-23.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int num = n * m;
        bool **printed = new bool *[m];
        for (int i = 0; i < m; ++i) {
            printed[i] = new bool[n];
            for (int j = 0; j < n; ++j) {
                printed[i][j] = false;
            }
        }
        const int right = 0, down = 1, left = 2, up = 3;
        int direction = right;
        int printed_num = 0;
        for (int i = 0, j = 0; printed_num < num;) {
            res.push_back(matrix[i][j]);
            printed_num++;
            printed[i][j] = true;

            switch (direction) {
                case right:
                    if (j == n - 1 || printed[i][j + 1]) {
                        direction = down;
                    }
                    break;
                case down:
                    if (i == m - 1 || printed[i + 1][j]) {
                        direction = left;
                    }
                    break;
                case left:
                    if (j == 0 || printed[i][j - 1]) {
                        direction = up;
                    }
                    break;
                case up:
                    if (i == 0 || printed[i - 1][j]) {
                        direction = right;
                    }
                    break;
                default:
                    break;

            }

            switch (direction) {
                case right:
                    j++;
                    break;
                case down:
                    i++;
                    break;
                case left:
                    j--;
                    break;
                case up:
                    i--;
                    break;
                default:
                    break;
            }
        }
        for (int i = 0; i < m; i++) {
            delete[] printed[i];
        }
        delete[] printed;
        return res;
    }
};

int main() {
    vector<vector<int>> matrix;
    // matrix.push_back({1,2,3,4});
    matrix.push_back({1, 2, 3, 4});
    matrix.push_back({5, 6, 7, 8});
    matrix.push_back({9, 10, 11, 12});
    matrix.push_back({13, 14, 15, 16});
    Solution s;
    s.printMatrix(matrix);
}