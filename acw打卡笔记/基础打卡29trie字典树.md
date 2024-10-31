## trie树重点是一定要理解tire[][]这二维代表什么，存的是什么。
- 第一维[]的含义是节点，第二维的含义是26个字母，存的是这个节点的编号
- 意思是：当 abc 插入到树中时，从0节点开始（根节点），发现tire[0][a](这里没有把a转成ASCLL - 'a')没有此节点，于是用idx分配一个节点在此处，同时节点编号被使用，idx ++
- 插入 b 即 tire[p][b](p已经变成了1,因为存a字符时使用了一个节点，编号为1)仍然不存在这个节点，以此类推
- 值得注意的是，编号p节点的子节点是tire[p][]，至于是否有子节点，看tire[p][]究竟有没有分配节点编号
- abc插入完成时，c结尾，此处c节点的编号通过cnt数组记录有abc这个字符串,至于几个，看cnt[节点编号]的值，所以cnt[abc字符串c结尾编号]++;
```
#include <iostream>
using namespace std;


const int N = 100005;
int trie[N][26];
int cnt[N];
int idx = 0;
void insert(string a)
{
    int p = 0;
    for(int i = 0; i < a.length(); i ++)
    {
        int u = a[i] - 'a';
        if(!trie[p][u]) trie[p][u] = ++ idx;
        p = trie[p][u];
    }
    cnt[p] ++;
}

void query(string a)
{
    int p = 0;
    for(int i = 0; i < a.length(); i ++)
    {
        int u = a[i] - 'a';
        if(!trie[p][u]) {cout << 0 << endl;return;}
        p = trie[p][u];
    }
    cout << cnt[p] << endl;
}


int main()
{
    int n;cin>>n;
    while(n --)
    {
        char op;cin>>op;
        if(op == 'I')
        {
            string a;cin>>a;
            insert(a);
        }
        else
        {
            string a;cin>>a;
            query(a);
        }
    }
}
```
