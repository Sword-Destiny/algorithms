//
// Created by yuanh on 2018/6/19.
//

#ifndef ALGORITHMS_ARRAY_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template<typename T>
/*数组*/
class data_array {
protected:
    T *a;
public:
    const int length;

    data_array() : length(0) {
        this->a = nullptr;
    }

    data_array(const int &len) : length(len) {
        this->a = new T[len];
    }

    ~data_array() {
        delete[] this->a;
    }

    data_array(const data_array<T> &arr) : length(arr.length) {
        this->a = new T[arr.length];
        for (int i = 0; i < arr.length; i++) {
            this->a[i] = arr.a[i];
        }
    }

    data_array(const T *arr, int size) : length(size) {
        this->a = new T[size];
        for (int i = 0; i < size; i++) {
            this->a[i] = arr[i];
        }
    }

    /*赋值*/
    data_array<T> &operator=(const data_array<T> &arr) {
        if (this == &arr) {
            return *this;
        }
        delete[] this->a;
        this->a = new T[arr.length];
        *(const_cast<int *>(&this->length)) = arr.length;
        for (int i = 0; i < arr.length; i++) {
            this->a[i] = arr.a[i];
        }
        return *this;
    }

    inline T &operator[](int index) {
        return this->a[index];
    }

    inline T operator[](int index) const {
        return this->a[index];
    }

    /*返回数据data的索引位置*/
    /*有序时有用*/
    int index_of(const T &data) {
        return index_of(data, 0, length);
    }
    
    /*返回数据data的索引位置*/
    /*有序时有用*/
    int index_of(const T &data, int low, int high) {
        int mid = -1;
        while (high >= low) {
            mid = (low + high) / 2;
            if (a[mid] == data) {
                break;
            }
            if (a[mid] < data) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low <= high ? mid : -1;
    }

    /*相等性判断*/
    bool operator==(const data_array<T> &arr) const {
        if (this->length != arr.length) {
            return false;
        }
        for (int i = 0; i < this->length; i++) {
            if (this->a[i] != arr.a[i]) {
                return false;
            }
        }
        return true;
    }

    /*不等性判断*/
    inline bool operator!=(const data_array<T> &arr) const {
        return !this->operator==(arr);
    }

    /*输出*/
    ostream &print(ostream &os = cout) const {
        os << "data_array:<";
        for (int i = 0; i < this->length - 1; i++) {
            os << this->a[i] << ",";
        }
        if (this->length > 0) {
            os << this->a[this->length - 1];
        }
        os << ">" << endl;
        return os;
    }

    /*输出*/
    inline friend ostream &operator<<(ostream &os, const data_array<T> &arr) {
        return arr.print(os);
    }
};

template<typename T>
using darray = data_array<T>;

#define ALGORITHMS_ARRAY_H

#endif //ALGORITHMS_ARRAY_H
