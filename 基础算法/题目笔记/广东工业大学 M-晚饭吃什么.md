# 2025年华为杯广东工业大学程序设计竞赛

##### [官方题解](https://ac.nowcoder.com/discuss/1481277)

# M.晚饭吃什么?

### 题目描述:

![m1](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\M1.png)

![M2](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\M2.png)

#### 长期不会组合数学,这次借助AI工具完整的学完了这道题:

#### 题目可以简化为如下: 在n个格子中,选择k个格子,给这k个格子涂上颜色,颜色的种类为m种,同时,要求相邻颜色不能相同(除了未涂色的格子外)

#### 分析:

#### 	首先直接分析太复杂了,我们考虑一个连续的被涂色格子的块,块的定义为:一段连续的格子,这些格子都被涂色了.

#### 第一个格子可以选择的颜色有m种,第二个只能选m-1种,因为必须和相邻的不一样,第三个格子同理为m-1种.假设这个块含有y个格子,计算这些方案数可以简化为式子

$$
一个块中的方案数=m*(m-1)^{y-1}
$$

#### 但是,我们需要思考能分多少个块.首先,我们能分配的格子是k个,也就是说,最大可以分配k个块,这些块都只有一个被涂色格子,此外,最小就是k个格子拼成的一整个块.我们要计算这些块的所有方案,设每个块的格子为$y_1,y_2,\dots,y_x$,有:

$$
\sum_{i=1}^{x}y_i=k
$$

#### 计算所有块的方案数,就要把它们乘起来(独立计算乘法原则)

$$
\prod_{i=1}^xm*(m-1)^{yi-1}\\
简化得:m^x*(m-1)^{k-x}
$$

#### 块中问题解决了,我们现在要选择块的放置,放几个块?很明显会影响到上面的公式,因为x就是块的数量,关于这个可以选择枚举放的块的数量,从1到k,现在我们要想:要怎么放块呢?

#### 除去要选择的格子,剩下的空格子为n-k个,这n-k个格子有n-k+1个空隙(包含最左边和最右边的),要在这些缝隙中选择放块,很明显的$C(n-k+1,x)$,同时,假设k个涂色格子连成一块,我们要把他们分成x个块,那么,k个涂色格子中有k-1个空隙,我们要分成x个块就需要选择其中x-1个空隙中切,方案数为$C(k-1,x-1)$

#### 每个部分用乘法原理联系起来,对于分x个块的答案为

$$
m^x*(m-1)^{k-x}*C(n-k+1,x)*C(k-1,x-1)\\
对于所有可能的块的数量,则为\\
\sum_{x=1}^k{C(n-k+1,x)*C(k-1,x-1)*m^x(m-1)^{k-x}} \mod 1e9+7
$$



#### 注意这里求组合数含有除法,所以需要逆元	

#### 至此分析基本上就结束了,下面会贴AC代码,所有逻辑源于上述分析:

```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;
const int mod = 1e9+7;
const int N = 1e6+10;
LL fac[N];
LL rev[N];

LL get_C(int a,int b)
{
    if(b<0||b>a)return 0;
    return fac[a]*rev[b]%mod*rev[a-b]%mod;
}

LL qmi(LL a,LL b,LL p)
{
    a%=p,b%=p;
    LL res=a;
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*res)%mod;
        res=(res*res)%mod;
        b>>=1;
    }
    return ans;
}
void pre()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=(fac[i-1]*i)%mod;
    rev[N-1]=qmi(fac[N-1],mod-2,mod); 
    for(int i=N-1;i>=1;i--)
        rev[i-1]=(rev[i]*i)%mod;
    rev[0]=1;
};

void solve()
{
    int n,m,k;cin>>n>>m>>k;
    LL ans=0;
    for(int i=1;i<=k;i++)
    {
        LL tmp=get_C(n-k+1,i)*get_C(k-1,i-1)%mod;
        ans=(ans+tmp*qmi(m,i,mod)%mod*qmi(m-1,k-i,mod)%mod)%mod;
    }
    cout<<ans<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    pre();
    cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}
```

# L.字符串匹配太多了!

### 题目描述:

![](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\L1.png)

![L2](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\L2.png)

![L3](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\L3.png)

#### 这题有几个很重要的点:

1. ##### 字符串中的字符只有'a','b','c'

2. ##### 要求的T字符串长度限制为1-n

#### 官方题解通过观察并证明了,如果存在一个长度大于1的T符合要求,那么长度为1的T1(表示字符串T的第一个字符)一定也满足要求,这部分我认为grok证明的很详细,当然,仔细想也可以想明白

![](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\L4.png)

#### 这个结论非常符合我们简化题目的目的,我们肯定希望T越简单越好,1个字符当然是最简单的了,数组A中也不会出现大于1的字符,又由于字符串只有三种字符,枚举每个字符,如果有答案就输出,没有就真的是没有了(通过结论),这个结论非常重要,也导致了代码非常简单

```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;


void solve()
{
    int n;string a,b;
    cin>>n>>a>>b;

    char ans='?';
    for(char i='a';i<='c';i++)
    {
        ans=i;
        for(int j=0;j<n;j++)
        {
            if(a[j]!=b[j]&&(a[j]==i||b[j]==i))
            {
                ans='?';
                break;
            }
        }
        if(ans!='?')
            break;
    }
    if(ans!='?')
    {
        cout<<"YES"<<endl<<1<<endl<<ans<<endl;
    }
    else cout<<"NO"<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}
```

# K-橘猫的后缀问题

**[官方题解](https://ac.nowcoder.com/discuss/1481277)**

#### 题目描述

![](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\广东K.png)

![广东K2](C:\Users\kendas\Desktop\for_code_skill\基础算法\photos\广东K2.png)

#### 分析来源官方题解及AI,仅整理:

#### 题目加粗的部分谈到`初始字符串和修改操作中的字符是从 1<=x<=n,{a,b,…,z}中均匀随机抽取的`

#### 假设只比较每个后缀字符串前L个字符,那么比较出现相同的概率为$\frac{n}{26^L}$(总共是n个后缀字符串,每个字符串前L位可能性有$26^L$)

#### 也就是说我们完全可以用暴力的方法,要比较两个字符串字典序大小,直接按位比较就完事了.

#### 但是要确定一个字符串的排名,就需要对所有的字符串进行排序,怎么排序呢?如果没有统一的比较标准,即不方便存储,也不方便逻辑书写.我们假设每个字符串都只比较前2个(自定),那么要排序,我们可以来个27进制(最后一个后缀字符串只有一个字符,需要0来补充),这样我们统计完就可以进行排序了,但是这并不是十全十美的,如果发生冲突了,即两个后缀字符串的前两个字符相等,那就需要根据实际情况再往后面比较,但是我们说了,这种情况很少(Q是随机的).

#### 当我们修改一个字符,那么我们实际只修改了2个字符串(L=2),即$S_xS_{x+1}\dots S_n$和$S_{x-1}S_x\dots S_n$这两个字符串,要消去原来的权值影响,再添加上新的,我们可以采用树状数组来写,在原来的权值那减去,再算出新的权值后加上.根据原字符串我们很轻松就能知道要修改的字符.

#### 现在假设发生了1个冲突,那么我们怎么知道那个冲突在字符串的什么位置呢?(因为我们需要比较当前字符和冲突字符)我们需要再维护一个二维数组,统计每个权值所对应的下标,这样清楚了冲突字符串位置.

#### 代码请看[官方题解](https://ac.nowcoder.com/discuss/1481277)
