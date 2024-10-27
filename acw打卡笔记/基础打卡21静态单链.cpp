#include <iostream>
//看了别人的题解，多练加理解才是真正掌握
using namespace std;

const int N = 100005;

int n[N], ne[N], idx = 1;

void add_k(int x, int k)
{
    n[idx] = x, ne[idx] = ne[k], ne[k] = idx++;//在k后面添加一个节点
}

void rm(int k)
{
    ne[k] = ne[ne[k]];
}


int main()
{
    int e;cin>>e;
    for(int i = 1; i <= e; i ++ )
    {
        char a;cin>>a;
        if(a == 'H')
        {
            int x;cin>>x;
            add_k(x, 0);
        }
        else if( a == 'I')
        {
            int k,x;cin>>k>>x;
            add_k(x, k);
        }
        else
        {
            int k; cin>>k;
            rm(k);
        }
    }
    for(int i = ne[0]; i; i = ne[i])
    {
        cout << n[i] << ' ';
    }

    return 0;
}

