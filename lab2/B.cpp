//
// Created by kirill on 02.11.2019.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main() {
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += s;
    int n = (int)s.size() / 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    auto cmp = [s] (int x, int y) {
        return s.substr(x) < s.substr(y);
    };

    sort(a.begin(), a.end(), cmp);

    string ans;
    for (int i = 0; i < n; i++) {
        ans += s[(a[i] - 1 + n) % n];
    }

//    cerr << ans;
    cout << ans;

    return 0;
}