#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;


void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<char>>q(n + 1,vector<char>(m + 1));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin>>q[i][j];
    int h = -1;
    int mx = 0;
    for(int i = 1; i <= n; i ++)
    {
        int t = 0;
        int zero = 0,one = 0;
        for(int j = 1; j <= m; j ++)
            if(q[i][j] == '0')
                zero ++;
            else one ++;
        t = max(zero,one);
        if(t > mx)
        {
            h = i;
            mx = t;
        }
    }
    int zero = 0,one = 0;
    for(int i = 1; i <= m; i ++)
    {
        if(q[h][i] == '1')
            one ++;
        else zero ++;
    }
    if(zero > one)
        for(int i = 1; i <= m; i ++)
            if(q[h][i] == '1')
                q[h][i] = '0';
            else q[h][i] = '1';

    for(int i = 1; i <= n; i ++)    
    {
        if(i == h)
            continue;
        int com = 0;
        for(int j = 1; j <= m; j ++)
            if(q[i][j] == q[h][j]) 
                com ++;
        if(com < m - com)
            for(int j = 1; j <= m; j ++)
                if(q[i][j] == '1')
                    q[i][j] = '0';
                else q[i][j] = '1';
    }

    int ans = 0;
    for(int i = 1; i <= m; i ++)
    {
        int flag = 0;
        for(int j = 1; j <= n; j ++)
            if(q[j][i] != '1')
            {
                flag = 1;
                break;
            }
        if(!flag)
            ans ++;
    }

    cout << ans << endl;
    return;

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