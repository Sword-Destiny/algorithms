#include <cstring>

using std::memcpy;
using std::memset;

#include <iostream>

using std::ostream;
using std::endl;

template<typename T>
/**
 * 矩阵类
 * @tparam T 类型参数
 */
class matrix {
public:
    int row;//行
    int column;//列
    T **data;//数据

public:
    matrix(int r, int c) : row(r), column(c) {
        data = new T *[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new T[c];
            memset(data[i], 0, column * sizeof(*data[i]));
        }
    }

    matrix(const matrix &m) : row(m.row), column(m.column) {
        data = new T *[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[column];
            memcpy(data[i], m.data[i], column * sizeof(*data[i]));
        }
    }

    matrix(int r, int c, T **m) : row(r), column(c) {
        data = new T *[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[column];
            memcpy(data[i], m[i], column * sizeof(*data[i]));
        }
    }

    matrix &operator=(const matrix &m) {
        if (&m == this) {
            return *this;
        }
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
        row = m.row;
        column = m.column;
        data = new T *[row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[column];
            memcpy(data[i], m.data[i], column * sizeof(*data[i]));
        }
        return *this;
    }

    bool operator==(const matrix &m) const {
        if (row != m.row || column != m.column) {
            return false;
        }
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (m[r][c] != data[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }

    inline bool operator!=(const matrix &m) const {
        return !operator==(m);
    }

    inline matrix operator*(const matrix &m) {
        return multiply(m);
    }

    inline matrix &operator*=(const matrix &m) {
        *this = multiply(m);
        return *this;
    }

    /**
     * 矩阵乘法
     * @param m 被乘数
     * @return 结果
     */
    matrix multiply(const matrix &m) {
        matrix<T> c(row, m.column);
        for (int i = 0; i < row; ++i) {
            for (int k = 0; k < m.row; ++k) {
                for (int j = 0; j < m.column; ++j) {
                    c[i][j] = (c[i][j] + data[i][k] * m[k][j]);
                }
            }
        }
        return c;
    }

    /**
     * 矩阵乘法
     * @param m 被乘数
     * @param mod 结果太大的时候求mod
     * @return 结果
     */
    matrix multiply(const matrix &m, T mod) {
        matrix<T> c(row, m.column);
        for (int i = 0; i < row; ++i) {
            for (int k = 0; k < m.row; ++k) {
                for (int j = 0; j < m.column; ++j) {
                    c[i][j] = (c[i][j] + data[i][k] * m[k][j]) % mod;
                }
            }
        }
        return c;
    }

    /**
     * 求矩阵m的n次幂
     * 注意m.row == m.column
     * @param n n次幂
     * @return 结果
     */
    matrix pow(unsigned long long n) {
        matrix<T> m = *this;
        matrix<T> res(m.row, m.row);
        for (int i = 0; i < m.row; ++i) {
            res[i][i] = 1;
        }
        while (n > 0) {
            if (n & (unsigned) 1) {
                res = res.multiply(m);
            }
            m = m.multiply(m);
            n >>= (unsigned)1;
        }
        return res;
    }

    /**
     * 求矩阵m的n次幂
     * 注意m.row == m.column
     * @param n n次幂
     * @param mod 结果太大的时候求mod
     * @return 结果
     */
    matrix pow(unsigned long long n, T mod) {
        matrix<T> m = *this;
        matrix<T> res(m.row, m.row);
        for (int i = 0; i < m.row; ++i) {
            res[i][i] = 1;
        }
        while (n > 0) {
            if (n & (unsigned) 1) {
                res = res.multiply(m, mod);
            }
            m = m.multiply(m, mod);
            n >>= (unsigned)1;
        }
        return res;
    }

    ~matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    T *&operator[](int r) const {
        return data[r];
    }

    friend ostream &operator<<(ostream &os, const matrix &m) {
        os << "matrix : ";
        for (int i = 0; i < m.row; ++i) {
            if (i != 0) {
                os << "         ";
            }
            for (int j = 0; j < m.column; ++j) {
                os << m[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

template<typename T>
T fast_fibonacci(unsigned long long n, T mod) {
    matrix<T> m(3, 3);
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
    m[1][2] = 0;
    m[2][0] = 0;
    m[2][1] = 1;
    m[2][2] = 0;
    m = m.pow(n, mod);
    return m[0][0];
}

using std::cout;
using std::cin;

unsigned long long m = 1e9 + 7;

int main() {
    unsigned long long n = 50;
    for (unsigned long long i = 0; i < n; ++i) {
        cout << i << "," << fast_fibonacci(i+1, m) << endl;
    }
}