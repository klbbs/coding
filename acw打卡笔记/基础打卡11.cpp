#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int q[N];
int n, m;

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ )cin>>q[i];
    
    for(int i = 2; i <= n; i ++ )q[i] += q[i-1];
    
    for(int i = 0; i < m; i ++ )
    {
        int a,b;cin>>a>>b;
        cout<<q[b] - q[a-1] << endl;
    }
    return 0;
}