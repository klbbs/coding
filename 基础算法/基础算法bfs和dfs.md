# 基础算法:bfs和dfs

#### 这两个算法听名字就知道是在干什么,Depth First Search,深度优先搜索嘛,先深入,Breadth First Search,广度优先嘛,不先深入那干嘛?先搜这点一圈的嘛,广度一层一层的搜.

#### 这两个算法经常一起出现,不仅仅是因为都是搜索算法,也是因为它们都有暴力的思想,每个点都搜,直到找到答案.

### dfs  {#dfs}

#### dfs最经典的题就是全排列了,给定n,把1-n排成一排,把所有可能输出.通过dfs模板可以很轻松就写出这道题

```cpp
#include <iostream>
using namespace std;
bool status[8]{false};
int path[8];
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
```

#### 但是,我们最重要的不是dfs和bfs模板,而是理解这两个算法,很多题目不是让你直接套个模板就解出来了,我们需要通过程序在对题目进行dfs或bfs的时候进行一些操作,从而借助这两个算法来解决题目,例如下面这题

##### 给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。

##### 请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

##### 重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

##### 输入格式

###### 第一行包含整数 n，表示树的结点数。

###### 接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+10;

int e[N*2],ne[N*2],q[N],idx;
bool vised[N];
int n;
int ans = N;
void add(int a,int b)
{
    e[idx] = a,ne[idx] = q[b], q[b] = idx++;
}
int dfs(int u)
{
    vised[u] = true;
    int size = 0, sum = 0; 
    for(int i = q[u]; i != -1; i = ne[i])
    {
        if(!vised[e[i]])
        {
            int s = dfs(e[i]);
            size = max(size,s);
            sum += s;
        }
    }
    size = max(size,n - sum - 1);
    ans = min(ans,size);
    return sum + 1;
}

int main()
{
    memset(q,-1,sizeof q);
    cin>>n;
    int t = n - 1;
    while(t --)
    {
        int a,b;cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout << ans;
}
```

#### 在这题中,简单写个dfs模板可不行,需要通过dfs的机制,加上一些符合题目要求的操作才可以.这题中,我们需要size来记录这颗子树最大的连通块,然后再return上面,再取(这颗子树的最大连通块和整棵树去掉重心后除了)的最大值

#### 说了这么多,好像忘记说模板了,一般来说,dfs需要在最开始判断什么时候退出递归,在全排列中,是u == n的时候,这时候以及到达这条路最深的情况了,输出结果并return.但在上面这道题中,就没有写合适return,但如果我们仔细观察,发现vised只会不断被改成true,而不会改成false,而下面循环中的操作,只有在vised是false的情况下才会执行,也就是说,所有点都被算法走了一遍后,这个dfs也就结束了,因为它不会再调用在for循环中调用dfs了.

1. #### 我们发现,全排列和上面那道题中都需要一个bool数组来存是否走过一个点的状态

2. #### 一般情况下,我们需要判断何时退出递归

3. #### dfs里面调用dfs,传入的参数是有规律的,是从头到尾的

#### dfs有一道经典问题,就是n皇后问题,这时候,我们就需要更多bool数组来记录状态了(当然也有些情况也不一定是用bool数组记录状态),这里不妨贴出n皇后代码

```cpp
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
        if(!col[i] && !dg[i + u] && !udg[n + u - i])
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
```

#### dfs和回溯很像,回溯相当于是如果dfs走上了错误的深入,立马通过剪枝来让它不要走了,退回上一步换条路走,下面贴hello算法书例题一

##### 给定一棵二叉树，搜索并记录所有值为 7 的节点，请返回节点列表。

```cpp
/* 前序遍历：例题一 */
void preOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->val == 7) {
        // 记录解
        res.push_back(root);
    }
    preOrder(root->left);
    preOrder(root->right);
}
```

#### 再给来一道题

##### 在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径，**并要求路径中不包含值为 3 的节点**。

```cpp
/* 前序遍历：例题三 */
void preOrder(TreeNode *root) {
    // 剪枝
    if (root == nullptr || root->val == 3) {
        return;
    }
    // 尝试
    path.push_back(root);
    if (root->val == 7) {
        // 记录解
        res.push_back(path);
    }
    preOrder(root->left);
    preOrder(root->right);
    // 回退
    path.pop_back();
}
```

#### 这两道题一对比,剪枝操作一眼盯真了,既然dfs是暴力,那我加点剪枝,让它不那么暴力,变相减少了dfs所需的时间

> ###### 剪枝”是一个非常形象的名词。如图 13-3 所示，在搜索过程中，**我们“剪掉”了不满足约束条件的搜索分支**，避免许多无意义的尝试，从而提高了搜索效率。

#### 下面我们关注bfs,最经典的就是走迷宫吧,很多书上都是以走迷宫开始bfs的学习的

### `给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。`

### `最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。`

### `请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。`

### `数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。`

### `输入格式`

### `第一行包含两个整数 n 和 m。`

### `接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。`

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
queue<pair<int,int>>q;
int k[N][N];
int g[N][N];
int main()
{
    memset(g,-1,sizeof g);
    int n,m;cin>>n>>m;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin>>k[i][j];
    q.push({1,1});
    g[1][1] = 0;
    int ofx[]{-1,0,1,0},ofy[]{0,1,0,-1};
    while(q.size())
    {
        int tx = q.front().first, ty = q.front().second;
        for(int i = 0; i < 4; i ++)        
        {
            int kx = tx + ofx[i], ky = ty + ofy[i];
            if(kx <= n && ky <= m && kx>= 1 && ky >= 1 && k[kx][ky] == 0 && g[kx][ky] == -1)
            {
                g[kx][ky] = g[tx][ty] + 1;
                q.push({kx,ky});
            }
        }
        q.pop();
    }
    cout << g[n][m];
}
```

#### 在这题中,k来记录地图,g来记录地图上能走的点距离(1,1)的距离,队列来保证不会像递归那样,走了一条路另一条路就会放到走的那条路走到底之后才会走.保证只要走了一条路,我只扩展一步,然后再看看另外一条路

1. #### bfs中通过队列来实现,同样有记录状态的数组(上面那题是g\[][])

2. #### bfs结束的情况是队列中没有任何元素了

#### 来看看八数码题的bfs


```

 在一个 3×3 的网格中，1∼8 这 8 个数字和一个 `x` 恰好不重不漏地分布在这 3×3 的网格中。
 例如：

1 2 3
x 4 6
7 5 8


在游戏过程中，可以把 `x` 与其上、下、左、右四个方向之一的数字交换（如果存在）。
我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：


1 2 3
4 5 6
7 8 x


例如，示例中图形就可以通过让 `x` 先后与右、下、右三个方向的数字交换成功得到正确排列。
交换过程如下：


1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x


现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

```


```cpp
#include <bits/stdc++.h>
using namespace std;
string s = "";
const int N = 362880;
unordered_map<string,int> q;
string f[N];
int hh,tt = -1;
int bfs()
{
    q[s] = 0;
    f[++ tt] = s;
    while(hh <= tt)
    {
        string t = f[hh ++];
        if (t == "12345678x")return q[t];
        int k = t.find('x');
        if(k + 3 <= 8)
        {
            f[++ tt] = t;
            f[tt][k] = f[tt][k + 3];
            f[tt][k + 3] = 'x';
            if(!q.count(f[tt]))
                q[f[tt]] = q[t] + 1;
            else tt --;
        }
        if(k + 1 <= 8 && k != 2 && k != 5)
        {
            f[++ tt] = t;
            f[tt][k] = f[tt][k + 1];
            f[tt][k + 1] = 'x';
            if(!q.count(f[tt]))
            q[f[tt]] = q[t] + 1;
            else tt --;
        }
        if(k - 1 >= 0 && k != 3 && k != 6)
        {
            f[++ tt] = t;
            f[tt][k] = f[tt][k - 1];
            f[tt][k - 1] = 'x';
            if(!q.count(f[tt]))
            q[f[tt]] = q[t] + 1;
            else tt --;
        }
        if(k - 3 >= 0)
        {
            f[++ tt] = t;
            f[tt][k] = f[tt][k - 3];
            f[tt][k - 3] = 'x';
            if(!q.count(f[tt]))
            q[f[tt]] = q[t] + 1;
            else tt --;
        }
    }
    return -1;
}
int main()
{
    for(int i = 0; i < 9; i ++)
    {
        char a;cin>>a;
        s += a;
    }
    cout << bfs();
}
```

#### 这段代码是我自己写的,比y总的长得多,但是思路一样,y总实现得更巧妙

```cpp
//yxc代码
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;
    q.push(state);
    d[state] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    string end = "12345678x";
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == end) return d[t];

        int distance = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a * 3 + b], t[k]);
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
        }
    }
    return -1;
}
int main()
{
    char s[2];
    string state;
    for (int i = 0; i < 9; i ++ )
    {
        cin >> s;
        state += *s;
    }
    cout << bfs(state) << endl;
    return 0;
}
```

#### 没接触bfs之前确实想不到这种搜索能解决这样的问题,说很巧妙但是又是暴力,说暴力吧在这上面用又很巧妙.d来存步数,队列来存状态,还有防重机制`(!d.count)`,我第一次写这题是没有写任何防重的,结果直接爆了(当然也不知道爆在哪里,数组开了$9!$),这题里面还学到一个,string类里面的find方法远比for循环找一个字符快,我第一次写完是用for来找`x`字符的,比y总慢了1s多,但是实现来看,思路都一样,为什么会慢这么多呢?好家伙,就是因为这个for遍历找x

