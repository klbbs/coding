#include <iostream>
using namespace std;

const int N = 1e5+10;

int q[N], cnt;

void down(int x)
{
    int t = x;
    if(x*2 <= cnt && q[x*2] < q[t])t = 2 * x;//要注意这里的t和x,不能瞎调换
    if(x*2+1 <= cnt && q[x*2+1] < q[t])t = x*2 + 1;
    if(t != x)
    {
        swap(q[x], q[t]);
        down(t);
    }
}


int main()
{
    int n, m;cin>>n>>m;
    for(int i = 1; i <= n; i ++)scanf("%d", &q[i]);
    cnt = n;
    for(int i = n / 2; i; i --)down(i);
    while(m --)
    {
        printf("%d ", q[1]);
        q[1] = q[cnt--];
        down(1);
    }
}