//
// Created by yuanhao on 2019-7-12.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

/*
 *破解密码：
 *将有序的数字密码转为英文单词，随后调整顺序，改变大小写：
 *比如1233，变为onetwothreethree或者EnoOwTtthhrreeee
 *现在输入onetwothreethree或者EnoOwTtthhrreeee，要求破解出原密码
 */
int main() {
    string s;
    cin >> s;
    int count[26+'a'];
    for (int & i : count) {
        i = 0;
    }
    for (char & i : s) {
        if (i <= 'Z' && i >= 'A') {
            i = 'a' + i - 'A';
        }
        if (i <= 'z' && i >= 'a') {
            count[i]++;
        }
    }
    int num[10];
    for (int & i : num) {
        i = 0;
    }
    num[0] = count['z'];
    count['z'] -= num[0]; count['e'] -= num[0]; count['r'] -= num[0]; count['o'] -= num[0];
    num[4] = count['u'];
    count['f'] -= num[4]; count['o'] -= num[4]; count['u'] -= num[4]; count['r'] -= num[4];
    num[5] = count['f'];
    count['f'] -= num[5]; count['i'] -= num[5]; count['v'] -= num[5]; count['e'] -= num[5];
    num[7] = count['v'];
    count['s'] -= num[7]; count['e'] -= num[7]; count['v'] -= num[7]; count['e'] -= num[7]; count['n'] -= num[7];
    num[6] = count['s'];
    count['s'] -= num[6]; count['i'] -= num[6]; count['x'] -= num[6];
    num[8] = count['g'];
    count['e'] -= num[8]; count['i'] -= num[8]; count['g'] -= num[8]; count['h'] -= num[8]; count['t'] -= num[8];
    num[9] = count['i'];
    count['n'] -= num[9]; count['i'] -= num[9]; count['n'] -= num[9]; count['e'] -= num[9];
    num[3] = count['r'];
    count['t'] -= num[3]; count['h'] -= num[3]; count['r'] -= num[3]; count['e'] -= num[3]; count['e'] -= num[3];
    num[2] = count['t'];
    count['t'] -= num[2]; count['w'] -= num[2]; count['o'] -= num[2];
    num[1] = count['n'];
    count['o'] -= num[1]; count['n'] -= num[1]; count['e'] -= num[1];
    for (int i = 0; i < 10; i++) {
        if (num[i] > 0) {
            for (int j = 0; j < num[i]; j++) {
                cout << i;
            }
        }
    }
    cout << endl;
    return 0;
}