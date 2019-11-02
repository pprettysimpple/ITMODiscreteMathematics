//
// Created by kirill on 02.11.2019.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

#define int long long

using namespace std;

signed main() {
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    string ans;

    map<string, int> mp;
    for (char i = 'a'; i <= 'z'; i++) {
        mp[string(1, i)] = i - 'a';
    }
    int min_code = 26;
    string t;
    for (int i = 0; i < n; i++) {
        if (mp.count(t + s[i])) {
            t += s[i];
            continue;
        }
        ans += to_string(mp[t]) + " ";
        mp[t + s[i]] = min_code++;
        t = s[i];
    }
    ans += to_string(mp[t]);

    cout << ans;
//    cerr << ans;
    return 0;
}