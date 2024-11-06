//hp和ph是铁cs
#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;

int h[N], hp[N], ph[N], cnt;

void down(int x)
{
    int t = x;
    if(x*2 <= cnt && h[x*2] < h[t])t = x*2;
    if(x*2+1 <= cnt && h[x*2+1] < h[t])t = x*2+1;
    if(x != t)  
    {
        swap(ph[hp[x]], ph[hp[t]]);
        swap(hp[x], hp[t]);
        swap(h[x], h[t]);
        down(t);
    }
}

void up(int x)
{
    while(x/2 && h[x/2] > h[x])
    {
        swap(ph[hp[x]], ph[hp[x/2]]);
        swap(hp[x], hp[x/2]);
        swap(h[x], h[x/2]);
        x /= 2;
    }
}

int main()
{
    int n;cin>>n;
    int m = 0;
    while(n --)
    {
        string OP;cin>>OP;
        if(OP == "I")
        {
            int x;scanf("%d",&x);
            m++;
            cnt++;
            ph[m] = cnt;
            hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        if(OP == "PM")printf("%d\n",h[1]);
        if(OP == "DM")
        {
            swap(ph[hp[1]], ph[hp[cnt]]);
            swap(hp[1], hp[cnt]);
            swap(h[1], h[cnt]);
            cnt --;
            down(1);
        }
        if(OP == "D")
        {
            int x;scanf("%d",&x);
            x = ph[x];
            swap(ph[hp[x]], ph[hp[cnt]]);
            swap(hp[x], hp[cnt]);
            swap(h[x], h[cnt]);
            cnt --;
            down(x), up(x);
        }
        if(OP == "C")
        {
            int k,x;scanf("%d%d",&k,&x);
            h[ph[k]] = x;
            down(ph[k]), up(ph[k]);
        }
    }
}