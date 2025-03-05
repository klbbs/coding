#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int l = 0; l <= 9; l++) {
        string s = to_string(n - l);
        cout << s << endl;
        int md = 0;
        for (auto c: s) {
            if (c <= '7') {
                md = max(md, c - '0');
            }
        }
        if (l >= 7 - md) {
            cout << l << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}