#include <iostream>
using namespace std;

const int N = 20;
char q[N][N];
int n;
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if(n == u)
    {
        for(int i = 0; i < n; i ++)puts(q[i]);
        puts("");
        return ;
    }
    
    for(int i = 0; i < n; i ++) 
    {
        if(!col[i] && !dg[i + u] && !udg[n + u - i])//注意这里,对角线编号
        {
            q[u][i] = 'Q';
            col[i] = dg[i + u] = udg[n + u - i] = true;
            dfs(u + 1);
            q[u][i] = '.';
            col[i] = dg[i + u] = udg[n + u - i] = false;
        }
    }
}


int main()
{
    cin>>n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)q[i][j] = '.';
    dfs(0);
}