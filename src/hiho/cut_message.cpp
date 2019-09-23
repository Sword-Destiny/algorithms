//
// Created by yuanhao on 2019-9-16.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;
#define bracket_slash_len 3 // 括号和斜线占据的长度

int cut_message(list<string> &message, int k, int &num, int default_extlen = 1) {
    int left = k;
    left -= default_extlen + bracket_slash_len + 1;
    for (auto it = message.begin(); it != message.end(); it++) {
        string str = *it;
        int sl = str.length();
        if (sl > left) {
            num++;
            int extlen = bracket_slash_len + default_extlen + to_string(num).length();
            if (left == -1) {
                left = k - extlen - 1;
            } else {
                left = k - extlen;
            }
            it--;
        } else {
            left -= sl + 1;
        }
    }
    return to_string(num).length();
}

/**
 * *** *** *** *** *** *** *** ***
 * 输出
 * *** *** *** *** *** *** *** ***
 */
void output(list<string> &message, int k, int total_num, int final_extlen) {
    int num = 1;
    int left = k;
    left -= final_extlen + bracket_slash_len + 1;
    for (auto it = message.begin(); it != message.end(); it++) {
        string str = *it;
        int sl = str.length();
        if (sl > left) {
            if (left == -1) {
                cout << '(' << num << '/' << total_num << ')' << endl << " ";
                num++;
                int extlen = bracket_slash_len + final_extlen + to_string(num).length();
                left = k - extlen - 1;
            } else {
                cout << '(' << num << '/' << total_num << ')' << endl;
                num++;
                int extlen = bracket_slash_len + final_extlen + to_string(num).length();
                left = k - extlen;
            }
            it--;
        } else {
            left -= (int) str.length() + 1;
            if (left == -1) {
                cout << str;
            } else {
                cout << str;
                auto itcopy = it;
                itcopy++;
                if (itcopy != message.end()) {
                    cout << " ";
                }
            }
        }
    }
    cout << '(' << num << '/' << total_num << ')';
}


void split_str(const std::string &s, std::list<std::string> &v, const char c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + 1;
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) {
        v.push_back(s.substr(pos1));
    }
}


int main() {
    char s[10000];
    int k;
    cin.getline(s, 10);
    k = (int) strtol(s, nullptr, 10);

    list<string> message;

    cin.getline(s, 10000);

    split_str(s, message, ' ');

    int num = 1;
    int default_extlen = 1;
    int final_extlen = cut_message(message, k, num, default_extlen);
    while (final_extlen != default_extlen) {
        default_extlen = final_extlen;
        final_extlen = cut_message(message, k, num, default_extlen);
    }
    if (num <= 10) {
        unsigned long total_len = 0;
        for (string &str:message) {
            total_len += str.length();
        }
        total_len += message.size() - 1;
        if (total_len <= k) {
            for (auto it = message.begin(); it != message.end(); it++) {
                auto itcopy = it;
                itcopy++;
                if (itcopy == message.end()) {
                    cout << (*it);
                } else {
                    cout << (*it) << " ";
                }
            }
            return 0;
        }
    }
    output(message, k, num, final_extlen);
    return 0;
}