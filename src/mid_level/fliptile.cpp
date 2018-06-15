//
// Created by yuanh on 2018/6/3.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/fliptile.h"

int main() {
    unsigned int rows = 4;
    unsigned int columns = 4;
    auto **puzzle = new fliptile_color *[rows]{
            new fliptile_color[columns]{black, white, white, black},
            new fliptile_color[columns]{white, black, black, white},
            new fliptile_color[columns]{white, black, black, white},
            new fliptile_color[columns]{black, white, white, black}};
    auto **flip = new int *[rows]{new int[columns], new int[columns], new int[columns], new int[columns]};
    int res = fliptile(rows, columns, puzzle, flip);
    cout << "puzzle :" << endl;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            cout << puzzle[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "fliptile res : " << res << endl;
    cout << "flip :" << endl;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            cout << flip[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        delete[] puzzle[i];
        delete[] flip[i];
    }
    delete[] puzzle;
    delete[] flip;
    return 0;
}