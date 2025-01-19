#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int>q(n + 1);  // 每只猪要求的天数
    for(int i = 1; i <= n; i++)
        cin >> q[i];
    vector<int>E(n + 1), val(n + 1);  // 精力和补偿值
    for(int i = 1; i <= n; i++)
        cin >> E[i] >> val[i];
        
    // 按天分组，记录每天要求陪伴的猪
    int max_day = *max_element(q.begin(), q.end());
    vector<vector<pair<int,int>>> groups(max_day + 1);  // {精力,补偿}
    for(int i = 1; i <= n; i++) {
        groups[q[i]].push_back({E[i], val[i]});
    }

    vector<LL> dp(max_day + 1, 0x3f3f3f3f3f3f3f3fLL);
    dp[0] = 0;

    // 对每一天
    for(int i = 1; i <= max_day; i++) {
        // 如果这天没有猪要求陪伴
        if(groups[i].empty()) {
            dp[i] = dp[i-1];
            continue;
        }

        // 计算这天所有猪的补偿总和
        LL total_val = 0;
        for(auto [e, v] : groups[i]) {
            total_val += v;
        }

        // 不陪任何猪
        dp[i] = dp[i-1] + total_val;

        // 尝试陪其中一只猪
        if(i >= m) {
            for(auto [e, v] : groups[i]) {
                // 陪这只猪：花费精力e，其他猪需要补偿(total_val - v)
                dp[i] = min(dp[i], dp[i-m] + e + (total_val - v));
            }
        }
    }

    cout << dp[max_day] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}