#include <iostream>
#include <cstring>

using namespace std;

int const N = 1e5 + 5;
int t[N], cnt[N];
int find(int x)
{
    if(t[x] != x) t[x] = find(t[x]);
    return t[x];
}

int main()
{
    int n, m;cin>>n>>m;
    for(int i = 1; i <= n; i ++)t[i] = i,cnt[i] = 1;
    while(m --)
    {
        string op;cin>>op;
        if(op == "C")
        {
            int a,b;scanf("%d%d",&a,&b);
            if(find(a) != find(b))
            cnt[find(b)] += cnt[find(a)];
            t[find(a)] = find(b);
        }
        else if(op == "Q1")
        {
            int a,b;scanf("%d%d",&a,&b);
            if(find(a) == find(b))
            printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            int a;scanf("%d",&a);
            printf("%d\n", cnt[find(a)]);
        }
    }
}
