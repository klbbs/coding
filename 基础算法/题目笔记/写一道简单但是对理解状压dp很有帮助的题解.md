#### 写一道~~简单~~但是对理解状压dp很有帮助的题解

#### 如果你是从上一题小国王(洛谷题名为:互补侵犯)来的,那应该已经差不多熟悉基本上状压在干什么

#### 我认为动态规划并非是模板,而是一种很重要的算法思想,这类题目的解决办法.

#### 动态规划有两个非常重要的东西:状态定义和状态转移,如果没定义好状态,可能空间就会爆,如果没处理好状态转移或者编码时可行的优化,那么时间可能就会爆



#### 目前,状压dp我看到两种写法(i,j状态定义为第i行状态为j)

1. #### 把所有合法状态和合法的转移枚举出来,也就是预处理

2. #### 直接转移,转移中枚举所有合法状态,通常时间复杂度会高很多

#### 此外,状压dp不应该只局限于在模板,互不侵犯定义轮廓线状态压缩也是一种很好的方式

#### 回到这道题:

#### 这题和上题相比只多了一个条件,那就是提前给了你地图,地图中出现1才能种玉米,既然是约束条件,枚举合法状态的时候只需要加上这层约束就可以了. 先贴代码,我们采取的是在转移过程中枚举状态

### 时间复杂度为$O(2*n*2^m*m)$

```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;
const int mod = 1e8;

void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n+1,vector<int>(m,0));
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    auto check=[&](int rows,int st)->bool
    {
        for(int i=0,j=m-1;i<m,j>=0;i++,j--)
            if((i+1<m && (st>>i)&1 && (st>>(i+1))&1) || ((st>>j)&1 && !g[rows][i]))//加上新约束
                return false;
        return true;
    };
    vector<vector<int>>f(n+1,vector<int>(1<<m,0));
    f[0][0]=1;//0层不放任何东西是1个方案
    for(int i=1;i<=n;i++)
    {
        for(int u=0;u<1<<m;u++)//上一个状态
        {
            for(int v=0;v<1<<m;v++)//此状态
                if((u&v)==0&&check(i,v)&&check(i-1,u))//均合法
                    f[i][v]=(f[i][v]+f[i-1][u])%mod;//可以转移过来
        }
    }
    LL ans=0;
    //加上所有最后一行所有状态
    for(int i=0;i<1<<m;i++)
        ans=(ans+f[n][i])%mod;
    cout<<ans<<endl;
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
```
#### 如果你想预处理,可以仿照小国王那题,这题麻烦的一点是不同层可以转移状态是不一样的(加了不等价的限制)

