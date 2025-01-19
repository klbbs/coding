#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;

const int N = 22;
int g[N][N];

int dp[1 << 20][N];

void solve()
{
    int n;cin>>n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin>>g[i][j];
    memset(dp,0x3f,sizeof dp);
    dp[1][0] = 0;

    for(int i = 0; i < 1 << n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(i >> j & 1)
                for(int k = 0; k < n; k ++)
                    if(i >> k & 1)
                        dp[i][j] = min(dp[i][j],dp[i - (1 << j)][k] + g[j][k]);
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}