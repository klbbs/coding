#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;


void solve()
{
    int n;cin>>n;
    cout << "Yes" << endl;
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if(n == 2) 
    {
        cout << "1 3 6 5 2 4 5 3 2 1" << endl;
        return;
    }

    int all = (n + 1)*(n + 2)/2;
    int add = 1;
    for(int i = 1; i <= all; i += add)
    {
        cout << i << ' ';
        add ++;
    }
    for(int i = all - 1; i >= all - n; i --)
        cout << i << ' ';
    int sub = n;
    for(int i = all - n - sub; i >= 1; i -= sub)
    {
        cout << i << ' ';
        

        if(sub > 1)
            sub --;    
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}