//
// Created by yuanhao on 2019-8-22.
//
#include "../../include/hiho/min_shop_distance_google.h"

int l[110000], r[110000], a[110000], b[110000], ans[110000], f[110000], n, m, k;
SegmentTree<int> st(110000);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    //makedata();
    std::ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, m) cin >> b[i];
    sort(b + 1, b + m + 1);
    for (int i = 1, j = 1; i <= m; i++) {
        while (a[j + 1] <= b[i] && j < n) j++;
        if (a[j] <= b[i]) l[i] = j;
        else l[i] = -1;
    }
    for (int i = m, j = n; i >= 1; i--) {
        while (b[i] <= a[j - 1] && j > 1) j--;
        if (b[i] <= a[j]) r[i] = j;
        else r[i] = -1;
    }
    rep(i, 1, m) r[i] = max(l[i], r[i]);
    fill(ans, 0x3F);
    rep(i, 1, n) {
        if (i + k - 1 <= n) f[i] = (a[i + k - 1] - a[i]) * 2;
        else f[i] = INT_MAX;
    }
    st.build(f, 1, n);
    for (int i = 1; i <= m; i++) {
        if (l[i] >= k && l[i] != -1) ans[i] = min(ans[i], (b[i] - a[l[i] - k + 1]) * 2);
        if (r[i] <= n - k + 1 && r[i] != -1) ans[i] = min(ans[i], (a[r[i] + k - 1] - b[i]) * 2);
        if (k == 1) continue;
        int ll = l[i] - k + 2, rr = min(n - k + 1, l[i]);
        if (ll < 1) ll = 1;
        if (ll > rr) continue;
        ans[i] = min(ans[i], st.query(ll, rr));
    }
    rep(i, 1, m) writeln(ans[i]);
    return 0;
}