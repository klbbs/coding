#include <iostream>
using namespace std;
const int N = 100005;

int q[N];
int n, m, x;


int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ )cin>>x,q[i] += x,q[i+1] -= x;
    // for(int i = 1; i <= m + n; i ++ )cout<<q[i]<<endl;
    for(int i = 1; i <= m; i ++ )
    {
        int l, r, c; cin>>l>>r>>c;
        q[l] += c;
        q[r + 1] -= c;
    }
    for(int i = 1; i <= n; i ++ )/*cout<<q[i]<<endl;*/q[i] += q[i - 1],cout<<q[i] << ' ';
    return 0;
}