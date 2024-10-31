#include <iostream>
#include <algorithm>
using namespace std;
//想不到用trie
const int N = 4000005;

int t[N][2], idx;
int q[N];
void insert(int x)
{
    int p = 0;
    for(int i = 30; ~i; i --)
    {
        int u = x >> i & 1; 
        if(!t[p][u]) t[p][u] = ++ idx;
        p = t[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; ~i; i --)
    {
        int u = x >> i & 1; 
        if(t[p][!u]) p = t[p][!u], res += 1 << i;
        else
        {
            p = t[p][u];    
        }
    }
    return res;
}

int main()
{
    int n;scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        int x;scanf("%d", &x);
        insert(x);
        q[i] = x;
    }
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        res = max(res, query(q[i]));
    }
    cout << res;
}