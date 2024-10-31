#include <iostream>
#include <deque>
using namespace std;

const int N = 2000005;
int s[N], q[N] , tt = -1, hh;

int find(int x)
{
    int l = hh, r = tt;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(s[q[mid]] >= x) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main()
{
    int n, m;scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++)scanf("%d",&s[i]);
    for(int i = 1; i <= n; i ++)
    {
        if(i - m >= q[hh]) hh ++;
        while(hh <= tt && s[q[tt]] <= s[i])tt--;
        q[++tt] = i;
        if( i >= m && q[hh])printf("%d\n",s[q[hh]]);
        
    }
    return 0;
}