#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 13331;//很重要

char str[N];
ULL h[N], p[N]; //p用于存储P的几次方

int main()
{
    int n, m;
    scanf("%d%d%s",&n, &m, str+1);
    p[0] = 1;
    for(int i = 1; i <= n; i ++)
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    while(m --)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        /* 下面这句话中的 h[l - 1] * p[r - l + 1] 很重要,因为h存储的是前缀和,如果直接相减那么
        位数是不一样的,例如如果是二进制 10110,想求3,4区间的11,不能直接1011-10,需要让h[3]乘上一
        量级让其变成 1011 - 1000才能得到11 */
        if(h[r1] - h[l1 - 1]*p[r1 - l1 + 1] == h[r2] - h[l2 - 1]*p[r2 - l2 + 1])
        printf("Yes\n");
        else printf("No\n");
    }
    
    
}