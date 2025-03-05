#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;


void solve()
{
    int r,c;
    while(cin>>r>>c)
    {
        if(r == 0 && c == 0)
            break;
        PII st;
        vector<vector<char>>g(c + 1,vector<char>(r + 1));
        for(int i = 1; i <= c; i ++)
            for(int j = 1; j <= r; j ++)
            {
                cin>>g[i][j];
                if(g[i][j] == '@')
                    st = {i,j};
            }
        // for(int i = 1; i <= c; i ++)
        // {
        //     for(int j = 1; j <= r; j ++)
        //         cout << g[i][j];
        //     cout << endl;
        // }
        queue<PII>q;
        q.push({st.first,st.second});
        bool visd[c + 1][r + 1];
        memset(visd,0,sizeof visd);
        int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
        visd[st.first][st.second] = 1;
        int cnt = 1;
        while(q.size())
        {
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++)
            {
                int tx = dx[i] + x,ty = dy[i] + y;
                if(tx >= 1 && tx <= c && ty >= 1 && ty <= r && !visd[tx][ty] && g[tx][ty] != '#')
                {
                    q.push({tx,ty});
                    visd[tx][ty] = 1;
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }

}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    // cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}