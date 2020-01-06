//
// Created by yuanhao on 2020-1-6.
//
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// 大数乘以个位数
void big_mul(char *a, int alen, int b, char *c, int &clen) {
    int m = alen - 1;
    int carry = 0;
    int len = m + 2;
    for (int i = len - 1; i >= 0; --i) {
        int sum = 0;
        if (m >= 0) {
            sum += a[m] * b;
        }
        c[i] = sum + carry;
        if (c[i] >= 10) {
            carry = c[i] / 10;
            c[i] %= 10;
        } else {
            carry = 0;
        }
        m--;
    }
    c[len] = '\0';
    if (c[0] == 0) {
        for (int k = 0; k < len; ++k) {
            c[k] = c[k + 1];
        }
        clen = len - 1;
    } else {
        clen = len;
    }
}

// 大数加上大数
void big_add(char *a, int alen, char *b, int blen, char *c, int &clen) {
    int m = alen - 1;
    int n = blen - 1;
    int carry = 0;
    int len = max(m, n) + 2;
    for (int i = len - 1; i >= 0; --i) {
        int sum = 0;
        if (m >= 0) {
            sum += a[m];
        }
        if (n >= 0) {
            sum += b[n];
        }
        c[i] = sum + carry;
        if (c[i] >= 10) {
            c[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        m--;
        n--;
    }
    c[len] = '\0';
    if (c[0] == 0) {
        for (int k = 0; k < len; ++k) {
            c[k] = c[k + 1];
        }
        clen = len - 1;
    } else {
        clen = len;
    }
}

// 大数乘以大数
void big_mul(char *a, int alen, char *b, int blen, char *c, int &clen) {
    int j;
    long sum, t = 0;
    int m = alen - 1;
    int n = blen - 1;
    for (int i = m + n; i >= 0; i--) {
        sum = t;
        if ((j = (i - m)) < 0)
            j = 0;
        for (; j <= i && j <= n; j++)
            sum += (a[i - j] * b[j]);
        c[i + 1] = sum % 10;
        t = sum / 10;
    }
    c[m + n + 2] = '\0';
    if (t > 0) {
        c[0] = t;
        clen = m + n + 2;
    } else {
        int len = m + n + 2;
        for (int k = 0; k < len; ++k) {
            c[k] = c[k + 1];
        }
        clen = m + n + 1;
    }
}

// 大数比较
bool bigger_than(char *a, int alen, char *b, int blen) {
    if (alen > blen) {
        return true;
    }
    if (alen < blen) {
        return false;
    }
    for (int i = 0; i < alen; ++i) {
        if (a[i] > b[i]) {
            return true;
        }
        if (a[i] < b[i]) {
            return false;
        }
    }
    return false;
}

/**
 * 夹逼法
 */
int main() {
    char number[100];
    cin >> number;
    int len = strlen(number);

    char n[100];
    for (int i = 0; i < len; ++i) {
        n[i] = number[i] - '0';
    }
    int nlen = len;

    /**
     * 使用夹逼法，从高位到低位，分别用0-9进行测试。
     * 举个例子，如果输入是1130，那么，nlen = 4，test_len = 2,
     * 先测试高位，f(00) < 1130, f(10) == 1130, f(20) > 1130, 那么第一位就是1。
     * 再测试第二位，f(10) == 1130, f(11) > 1130, 那么第二位就是0。
     * 因此最终的结果就是10。
     */
    char test[100];
    int test_len = len / 3 + 1;
    char f[100]; // 临时存放3x
    int flen = 0;
    char f2[100]; // 临时存放x^2
    int flen2 = 0;
    char f3[100]; // 临时存放x^3
    int flen3 = 0;
    char sum[100]; // 临时存放x^2 + 3x
    int sum_len = 0;
    char tmp[100]; // 临时存放x^3 + x^2 + 3x
    int tmp_len = 0;
    for (int i = 0; i < test_len; ++i) {
        test[i] = 0;
    }
    for (int test_index = 0; test_index < test_len; ++test_index) {
        int test_num = 0;
        bool find_bigger = false;
        for (; test_num <= 9; ++test_num) {
            // 计算 x^3 + x^2 + 3x，其中x就是test
            test[test_index] = test_num;
            big_mul(test, test_len, 3, f, flen);
            big_mul(test, test_len, test, test_len, f2, flen2);
            big_mul(test, test_len, f2, flen2, f3, flen3);
            big_add(f, flen, f2, flen2, sum, sum_len);
            big_add(sum, sum_len, f3, flen3, tmp, tmp_len);
            if (bigger_than(tmp, tmp_len, n, nlen)) {
                find_bigger = true;
                break;
            }
        }
        if (find_bigger) {
            test[test_index] = test_num - 1;
        } else {
            test[test_index] = 9;
        }
    }

    // 输出结果，注意这里要忽略掉test前面的0
    bool output = false;
    for (int i = 0; i < test_len; ++i) {
        if (test[i] != 0) {
            for (int j = i; j < test_len; ++j) {
                cout << (char) (test[j] + '0');
            }
            cout << endl;
            output = true;
            return 0;
        }
    }
    if (!output) {
        cout << 0 << endl;
    }
    return 0;
}