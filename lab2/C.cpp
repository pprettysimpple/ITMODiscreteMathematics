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
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int m = 'z' - 'a' + 1;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        a[i] = i;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j] == s[i] - 'a') {
                ans += to_string(j + 1) + " ";
                int save = a[j];
                for (int k = j; k > 0; k--) {
                    swap(a[k], a[k - 1]);
                }
                a[0] = save;
            }
        }
    }

    cout << ans;
//    cerr << ans;
    return 0;
}