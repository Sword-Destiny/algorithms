//
// Created by yuanhao on 2019-8-22.
//

#ifndef ALGORITHMS_MIN_SHOP_DISTANCE_GOOGLE_H
#define ALGORITHMS_MIN_SHOP_DISTANCE_GOOGLE_H

#pragma comment(linker, "/STACK:102400000,102400000")
#ifndef ONLINE_JUDGE
#   ifdef __WINDOWS_
#       include "stdafx.h"
#   else
#       include<bits/stdc++.h>
#   endif
#endif

#pragma region
using std::vector;
using std::pair;
using std::queue;
using std::map;
using std::set;
using std::multiset;
using std::stack;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::sort;
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define per(i, a, b) for (int i=(a);i>=(b);i--)
#define trav(a, x) for (auto &a:x)
#define mp(a, b) std::make_pair(a,b)
#define all(x) x.begin(),x.end()
#define fill(x, c) memset(x,c,sizeof(x))
#define write(x) cout<<(x)<<' '
#define writeln(x) cout<<(x)<<endl
#define ADDMOD(x, a, m) x=(((x)+(a)%m)%(m)+m)%m
#define MLTMOD(x, a, m) x=(((x)*((a)%m))%(m)+m)%m
typedef long long lnt;
typedef vector<int> VI;
typedef vector<lnt> VL;
typedef pair<int, int> PII;
typedef pair<lnt, lnt> PLL;
typedef vector<pair<int, int>> VPI;
typedef vector<pair<lnt, lnt>> VPL;
typedef queue<int> QI;
typedef queue<lnt> QL;
typedef map<int, int> MII;
typedef map<lnt, lnt> MLL;
typedef map<pair<int, int>, int> MPI;
typedef map<pair<lnt, lnt>, lnt> MPL;
typedef map<vector<int>, int> MVI;
typedef map<vector<lnt>, lnt> MVL;
typedef set<int> SI;
typedef set<lnt> SL;
typedef set<pair<int, int>> SPI;
typedef set<pair<lnt, lnt>> SPL;
const double eps = 1e-6;

inline lnt pow(lnt a, lnt b, lnt p) {
    lnt rtn = 1;
    while (b) {
        if (b & 1) rtn = rtn * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return rtn;
}

lnt inv(lnt a, lnt p) {
    return pow(a, p - 2, p);
}

long long gcd(long long a, long long b) {
    long long k;
    while (b != 0) {
        k = b;
        b = a % b;
        a = k;
    }
    return a;
}

void makedata() {
    freopen("input.txt", "w", stdout);
    cout << 70000 << endl;
    rep(i, 1, 50000) cout << "alice" << i << endl;
    rep(i, 1, 10000) cout << "alice" << endl;
    rep(i, 1, 10000) cout << "alice10000" << endl;
    fclose(stdout);
}

void TLE() {
    for (unsigned long long i = 0; i >= 0; i++) {
        if (i % 8475354556 == 0) cout << i << endl;
    }
}

void MLE(string s = "") {
    MLE(s + ' ');
}

#pragma endregion
#pragma region

template<typename T>
class SegmentTree {
public:
    T merge(T a, T b) {
        /*how to merge the answer when queried*/
        //-----sum-----
        //return a + b;
        //-------------
        //
        //---------max---------
        //return a < b ? b : a;
        //---------------------
        //
        //---------min---------
        return a < b ? a : b;
        //---------------------
    }

    T *data, *lazy;
    int ll, rr;

    inline void pushup(int rt) {
        /*how to merge the data on sub-nodes*/
        //-----------------------sum-----------------------
        //data[rt] = data[rt << 1] + data[((rt << 1) | 1)];
        //-------------------------------------------------
        //
        //-----------------------max---------------------------
        //data[rt] = max(data[rt << 1], data[((rt << 1) | 1)]);
        //-----------------------------------------------------
        //
        //-----------------------min---------------------------
        data[rt] = min(data[rt << 1], data[((rt << 1) | 1)]);
        //-----------------------------------------------------
    }

    inline void addLazy(int rt, int m, T v) {
        /*
        * how to merge the newly added lazy mark with the existing one
        * lazy mark mean the update has been implemented on the very current node but not on its sub-node yet
        * m is the length of the segment
        */
        //-----------straight add-----------
        lazy[rt] += v;
        //----------------------------------
        //#####################################################
        //sub-nodes' data
        //-------------------sum-------------------
        //data[rt] += v * m;
        //-----------------------------------------
        //
        //-----------------max/min-----------------
        data[rt] += v;
        //-----------------------------------------
    }

    inline void pushdown(int rt, int m) {
        if (lazy[rt] == 0) return;
        addLazy(rt << 1, m - (m >> 1), lazy[rt]);
        addLazy((rt << 1) | 1, (m >> 1), lazy[rt]);
        lazy[rt] = (T) (0);
    }

    void build(T *base, int l, int r, int rt) {
        lazy[rt] = 0;
        if (l == r) data[rt] = base[l];
        else {
            int mid = (l + r) >> 1;
            build(base, l, mid, rt << 1);
            build(base, mid + 1, r, ((rt << 1) | 1));
            pushup(rt);
        }
    }

    void modify(int l, int r, int rt, int L, int R, T v) {
        if (L <= l && r <= R) {
            addLazy(rt, r - l + 1, v);
            return;
        }
        pushdown(rt, r - l + 1);
        int mid = (l + r) >> 1;
        if (L <= mid) modify(l, mid, rt << 1, L, R, v);
        if (R > mid) modify(mid + 1, r, ((rt << 1) | 1), L, R, v);
        pushup(rt);
    }

    T query(int l, int r, int rt, int val) {
        if (l == r) return data[rt];
        pushdown(rt, r - l + 1);
        int mid = (l + r) >> 1;
        T ret = 0;
        if (val <= mid) ret = query(l, mid, rt << 1, val);
        else ret = query(mid + 1, r, ((rt << 1) | 1), val);
        pushup(rt);
        return ret;
    }

    T query(int l, int r, int rt, int L, int R) {
        pushdown(rt, r - l + 1);
        if (L == l && R == r) return data[rt];
        int mid = (l + r) >> 1;
        if (R <= mid) return query(l, mid, rt << 1, L, R);
        if (mid < L) return query(mid + 1, r, ((rt << 1) | 1), L, R);
        return merge(query(l, mid, rt << 1, L, mid), query(mid + 1, r, ((rt << 1) | 1), mid + 1, R));
    }

    SegmentTree(int n) : data(new T[n << 3]), lazy(new T[n << 3]) {}

    void build(T *base, int l, int r) {
        ll = l, rr = r;
        build(base, ll, rr, 1);
    }

    void modify(int l, int r, T v) {
        if (l > r || l < ll || rr < r) return;
        modify(ll, rr, 1, l, r, v);
    }

    void modify(int p, T v) {
        if (p < ll || rr < p) return;
        modify(ll, rr, 1, p, p, v);
    }

    T query(int l, int r) {
        if (l > r || l < ll || rr < r) return (T) (0);
        return query(ll, rr, 1, l, r);
    }

    T query(int p) {
        if (p < ll || rr < p) return (T) (0);
        return query(ll, rr, 1, p);
    }

    ~SegmentTree() {
        delete[] data, delete[] lazy;
    }
};

#pragma endregion

#endif //ALGORITHMS_MIN_SHOP_DISTANCE_GOOGLE_H
