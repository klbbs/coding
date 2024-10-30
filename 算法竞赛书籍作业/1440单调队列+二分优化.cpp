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
/* 孩子们，一定不要用cin和cout，我这道题改了半天都没过，
    改成scanf和printf快了10倍，我估计二分都用不上 */
int main()
{
    int n, m;scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++)scanf("%d",&s[i]);
    for(int i = 1; i <= n; i ++)
    {
        if(i - m > q[hh]) hh ++;
        if(hh <= tt && s[q[tt]] >= s[i]) tt = find(s[i]) - 1;
        if( i >= 1 && q[hh])printf("%d\n",s[q[hh]]);
        else printf("0\n");
        q[++tt] = i;
    }
    return 0;    
}