#include <iostream>
using namespace std;
const int N = 100005;

int stk[N], tt;

int main()
{
    int n;cin>>n;
    while(n -- )
    {
        int x;cin>>x;
        //cout << stk[tt] << endl;
        while(tt >= 0 && stk[tt] >= x)tt --;
        //cout << tt << ' ';
        if(tt)cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++ tt] = x;
    }
}