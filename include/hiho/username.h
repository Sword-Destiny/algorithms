//
// Created by yuanhao on 2019-8-6.
//

#ifndef ALGORITHMS_USERNAME_H
#define ALGORITHMS_USERNAME_H

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

/**
 * 描述
 * H站的系统的用户名允许任意小写字母和数字的组合，但是要求不能有重名用户。当用户注册时填写的用户名已经存在时，系统会自动在填写的用户名之后拼接上一个整数X。
 * 其中X从1开始，系统会依次尝试1, 2, 3, 4, ..., 直到拼接成的新用户名不存在为止。
 * 假设用户填写的是alice，如果alice, alice1, alice2都存在而alice3不存在的话，新的用户名会是alice3。
 * 一开始系统中没有任何用户，之后依次有N名用户注册。给出他们填写的用户名，请你输出系统生成的用户名。
 * 输入
 * 第一行包含一个整数N。
 * 以下N行每行包含一个字符串S，代表用户填写的用户名。S只包含小写字母和数字。
 * 对于70%的数据: 1 ≤ N ≤ 1000
 * 对于100%的数据: 1 ≤ N ≤ 100000  1 ≤ |S| ≤ 10
 * 输出
 * 输出N行，代表系统生成的用户名
 * 样例输入
 * 15
 * a2
 * a
 * a
 * a
 * a0
 * a0
 * a0
 * a01
 * a01
 * a01
 * alice
 * bob
 * bob
 * alice
 * bob
 * 样例输出
 * a2
 * a
 * a1
 * a3
 * a0
 * a01
 * a02
 * a011
 * a012
 * a013
 * alice
 * bob
 * bob1
 * alice1
 * bob2
 */
void username() {
    map<string, set<string>> used_tails_map; // 保存已经使用过的数字后缀
    map<string, int> last_num_cache; // 上次尝试的数字后缀，这个是用来节约时间的，不然会超时
    int n;
    cin >> n;
    string name;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        int last_letter_index = name.length() - 1; // 用户名最后一个字母（非数字）的位置
        for (; last_letter_index >= 0; --last_letter_index) {
            if (name[last_letter_index] > '9' || name[last_letter_index] < '0') {
                break;
            }
        }
        if (last_letter_index == name.length() - 1) { // 输入用户名不含数字后缀的情况
            set<string> &tails_used = used_tails_map[name];
            if (tails_used.empty()) { // 用户名没有被占用，可以不使用数字后缀
                cout << name << endl;
                tails_used.insert("");
                continue;
            }
            if (tails_used.find("") == tails_used.end()) { // 用户名没有被占用，可以不使用数字后缀
                cout << name << endl;
                tails_used.insert("");
                continue;
            }
            for (int num = last_num_cache[name] + 1; num < 100001; ++num) { // 查找可用的数字后缀
                if (tails_used.find(to_string(num)) == tails_used.end()) {
                    cout << name << num << endl;
                    tails_used.insert(to_string(num));
                    last_num_cache[name] = num;
                    break;
                }
            }

        } else { // 输入用户名本身含有数字后缀的情况
            string letter_name = name.substr(0, last_letter_index + 1); // 用户名字母部分
            set<string> &tails_used = used_tails_map[letter_name];
            string t = name.substr(last_letter_index + 1);
            if (tails_used.find(t) != tails_used.end()) { // 用户本身输入的用户名的数字后缀已经被使用
                for (int num2 = last_num_cache[name] + 1; num2 < 100001; ++num2) { // 查找可用的数字后缀
                    string tail = t;
                    tail.append(to_string(num2));
                    if (tails_used.find(tail) == tails_used.end()) {
                        cout << letter_name << tail << endl;
                        tails_used.insert(tail);
                        last_num_cache[name] = num2;
                        break;
                    }
                }
            } else {
                cout << letter_name << t << endl;
                tails_used.insert(t);
            }
        }
    }
}

#endif //ALGORITHMS_USERNAME_H
