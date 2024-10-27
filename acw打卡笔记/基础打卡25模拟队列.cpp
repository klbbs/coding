#include <iostream>
#include <string>

using namespace std;

const int N = 100005;

int que[N], tt = 0, dd = 0;

int main()
{
    int n;cin>>n;
    while(n --)
    {
        string str;cin>>str;
        if(str == "push")
        {
            int x;cin>>x;
            que[dd ++] = x;
        }
        else if(str == "pop")tt ++;
        else if(str == "empty")
        {
            if(dd == tt)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << que[tt] << endl;
    }
}