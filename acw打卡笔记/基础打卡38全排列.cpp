//hello算法学过一点点,虽然模板都一样但是y总写代码真的很简洁,最重要的是:总算让我在打卡也算水一题了! 
#include <iostream>

using namespace std;

bool status[8]{false};
int path[8];//这里是因为题目最大值只有7
int n;
void dfs(int u)
{
    if(u == n)
    {
        for(int i = 1; i <= n; i ++)
            printf("%d ",path[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(!status[i])
        {
            status[i] = true;
            path[u+1] = i;
            dfs(u+1);
            status[i] = false;
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
}