#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int q[N],n,x;


int main()
{
    cin>>n>>x;
    for(int i = 0; i < n; i ++)cin>>q[i];
    for(int i = 0; i < x; i ++)
    {
        int a;cin>>a;
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(q[mid] >= a)r = mid ;
            else l = mid + 1;
        }
        if(q[l] != a)cout << -1 << ' ' << -1 << endl;
        else {
            int lr = l, rr = n-1;
            while( lr < rr)
            {
                int midr = lr + rr + 1>> 1;
                if(q[midr] == q[l])lr = midr;
                else rr = midr - 1;
            }
            cout << l << " " << rr << endl;
        }
        
    }
}