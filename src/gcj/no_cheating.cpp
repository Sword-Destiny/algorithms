//
// Created by yuanhao on 18-9-28.
//

#include "../../include/gcj/no_cheating.h"

#include <iostream>

using std::endl;
using std::cout;

int main(){
    int M = 2;
    int N = 3;

    char **seats = new char*[M]{
        new char[N]{'.','.','.'},
        new char[N]{'.','.','.'}
    };
    int n = no_cheating(M,N,seats);
    cout << "seats:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << seats[i][j];
        }
        cout << endl;
        delete[] seats[i];
    }
    delete[] seats;
    cout <<"no_cheating res : " << n << endl << endl;

    seats = new char*[M]{
            new char[N]{'x','.','x'},
            new char[N]{'x','x','x'}
    };
    n = no_cheating(M,N,seats);
    cout << "seats:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << seats[i][j];
        }
        cout << endl;
        delete[] seats[i];
    }
    delete[] seats;
    cout <<"no_cheating res : " << n << endl << endl;

    seats = new char*[M]{
            new char[N]{'x','.','x'},
            new char[N]{'x','.','x'}
    };
    n = no_cheating(M,N,seats);
    cout << "seats:" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << seats[i][j];
        }
        cout << endl;
        delete[] seats[i];
    }
    delete[] seats;
    cout <<"no_cheating res : " << n << endl << endl;

    return 0;
}