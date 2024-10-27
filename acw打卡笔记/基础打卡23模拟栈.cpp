#include <iostream>
using namespace std;

int const N = 100005;

int q[N], idx = 0;

void push(int x)
{
    q[idx ++] = x;
}

void pop()
{
    idx --;
}

void check()
{
    if( !idx )cout << "YES" << endl;
    else cout << "NO" << endl;
}
void rear()
{
    cout << q[idx - 1] << endl;
}

int main()
{
    q[0] = -1;
    int n;cin>>n;
    while(n --)
    {
        string a;cin>>a;
        if(a == "push")
        {
            int x; cin>>x;
            push(x);
        }
        if(a == "pop")pop();
        if(a == "empty")check();
        if(a == "query")rear();
        
    }
}