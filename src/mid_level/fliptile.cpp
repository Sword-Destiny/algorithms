//
// Created by yuanh on 2018/6/3.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/fliptile.h"
#include <fstream>
using std::fstream;

int main(int argc, char *argv[]) {
    unsigned int rows = 0;
    unsigned int columns = 0;
    fliptile_color **puzzle = nullptr;
    int **flip = nullptr;
    if(argc>1){
        char color;
        fstream input(argv[1]);
        if(input){
            input >> rows >> columns;
            puzzle = new fliptile_color*[rows];
            for (int r = 0; r < rows; ++r) {
                puzzle[r] = new fliptile_color[columns];
                for (int c = 0; c < columns; ++c) {
                    input >> color;
                    if (color == 'b'){
                        puzzle[r][c] = black;
                    } else{
                        puzzle[r][c] = white;
                    }
                }
            }
            flip = new int *[rows];
            for (int r = 0; r < rows; ++r) {
                flip[r] = new int[columns];
            }
        } else{
            return -1;
        }
    }else {
        rows = 4;
        columns = 4;
        puzzle = new fliptile_color *[rows]{
                new fliptile_color[columns]{black, white, white, black},
                new fliptile_color[columns]{white, black, black, white},
                new fliptile_color[columns]{white, black, black, white},
                new fliptile_color[columns]{black, white, white, black}};
        flip = new int *[rows]{new int[columns], new int[columns], new int[columns], new int[columns]};
    }
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