#include <iostream>
#include <set>

#define int long long

using namespace std;

signed main() {
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> se;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        se.insert(x);
    }

    int ans = 0;
    while (se.size() > 1) {
        int mx1 = *(se.begin());
        se.erase(se.begin());
        int mx2 = *(se.begin());
        se.erase((se.begin()));
        ans += mx1 + mx2;
        se.insert(mx1 + mx2);
    }

    cout << ans;
    return 0;
}