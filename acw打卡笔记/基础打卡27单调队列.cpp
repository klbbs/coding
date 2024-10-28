#include <iostream>
using namespace std;
const int N = 1000005;

int q[N], a[N];

int main()
{
    int n, k;cin>>n>>k;
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i ++ )cin>>a[i];
    for(int i = 0; i < n; i ++ )
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh ++; //需要细想
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1 )cout<<a[q[hh]] << ' ';
    }
    hh = 0, tt = 0;
    cout << endl;
    for(int i = 0; i < n; i ++ )
    {
        if(hh <= tt && i - k + 1 > q[hh]) hh ++; 
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1)cout<<a[q[hh]] << ' ';
    }
}