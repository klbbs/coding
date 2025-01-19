#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;
//题目链接:https://www.acwing.com/problem/content/description/93/
const int N = 22;
int g[N][N];

//i表示状态,已经走了哪些点, j表示当前点
//状态表示,从第k点转移到j点,走过的点为 i - (1 << j),k 这里是指还没有走过j点,并且当前点为k

int dp[1 << 20][N];

void solve()
{
    int n;cin>>n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin>>g[i][j];
    memset(dp,0x3f,sizeof dp);
    
    dp[1][0] = 0;//1 >> 0 = 1,第0个点距离0
    
    for(int i = 0; i < 1 << n; i ++)//枚举所有状态
    {
        for(int j = 0; j < n; j ++)//枚举所有当前点
        {
            if(i >> j & 1)//状态合法:走过状态中有j点
                for(int k = 0; k < n; k ++)//枚举所有点
                    if(i >> k & 1)//状态合法:状态中包含j点前一个点:k点
                        dp[i][j] = min(dp[i][j],dp[i - (1 << j)][k] + g[j][k]);//转移,属性min
        }
    }
    cout << dp[(1 << n) - 1][n - 1];//走过了所有点(每一位都是1),当前点位n - 1
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