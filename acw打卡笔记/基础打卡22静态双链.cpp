#include <iostream>
using namespace std;

const int N = 100005;

int e[N], ne[N], pe[N], idx;

void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], pe[idx] = k, pe[ne[k]] = idx, ne[k] = idx ++;
}

void rm(int k)
{
    pe[ne[k]] = pe[k], ne[pe[k]] = ne[k];
}

int main()
{
    ne[0] = 1, pe[1] = 0;
    //pe[0] = 1, ne[1] = 0;
    idx = 2;

    int n;cin>>n;
    while(n -- )
    {
        string a;cin>>a;
        if(a == "L")
        {
            int x;cin>>x;
            add(0, x);
        }
        if(a == "R")
        {
            int x;cin>>x;
            add(pe[1], x);
        }
        if(a == "IL")
        {
            int k,x;cin>>k>>x;
            add(pe[k + 1], x);
        }
        if(a == "IR")
        {
            int k,x;cin>>k>>x;
            add(k + 1, x);
        }
        if(a == "D")
        {
            int k;cin>>k;
            rm(k + 1);
        }
    }
    for(int i = ne[0]; i != 1; i = ne[i])cout << e[i] << ' ';
}