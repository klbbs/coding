#include <iostream>

using namespace std;


int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;cin>>x;
        int cnt = 0;  
        while( x > 0)
        {
            if(x & 1 == 1)cnt ++;
            x = x >> 1;
        }
        cout << cnt << ' ';
    }
        
    
}