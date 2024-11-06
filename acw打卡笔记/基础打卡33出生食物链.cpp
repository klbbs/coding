#include <iostream>
using namespace std;

int const N = 5e4 + 10;
int p[N], d[N];
int n, k;
//卡了挺久的题
int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    cin>>n>>k;
    int res = 0;
    for(int i = 1; i <= n; i ++)p[i] = i;
    while(k --)
    {
        int op, x, y;scanf("%d%d%d", &op, &x, &y);
        if(x > n || y > n) res++;
        else
        {
            int px = find(x), py = find(y);
            if(op == 1)
            {
                if(px == py && (d[x] - d[y])%3)res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if(px == py && (d[x] - d[y] - 1)%3)res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    cout << res;
}