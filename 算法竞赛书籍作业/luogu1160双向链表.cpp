#include <iostream>
using namespace std;

const int N = 100005;

int pe[N], ne[N];


int main()
{
    int n;cin>>n;
    ne[0] = 2;
    pe[0] = 1;
    ne[2] = 1;
    pe[1] = 1;
    for(int i = 3; i <= n + 1; i ++)
    {
        int k, p;cin>>k>>p;
        k ++;
        if (p == 1)
        {
            pe[i] = k;
            ne[i] = ne[k];
            pe[ne[k]] = i;
            ne[k] = i;
        }
        else 
        {
            ne[i] = k;
            pe[i] = pe[k];
            ne[pe[k]] = i;
            pe[k] = i;
        }
    }
    int x;cin>>x;
    while( x --)
    {
        int t;cin>>t;
        t++;
        if(t == ne[0])
        {
            pe[ne[ne[0]]] = ne[0];
            ne[0] = ne[ne[0]];
        }
        else
        {
            ne[pe[t]] = ne[t];
            pe[ne[t]] = pe[t];
            pe[t] = -1;
            ne[t] = -1;
        }
    }
    for (int i = ne[0]; i != pe[0]; i = ne[i])
    cout << i - 1<< ' '; 
    return 0;
}