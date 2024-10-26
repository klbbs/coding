#include <iostream>
using namespace std;

int const N = 100005;

int A[N], B[N];

int n, m;

int main()
{
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ ) cin>>A[i];
    for(int i = 1; i <= m; i ++ ) cin>>B[i];
    int i = 1, j = 1;
    for(; j <= m; j ++ )
    {
        if(A[i] == B[j]) i++;
        if(i == n + 1)break;
    }
    if( i == n + 1)cout << "Yes";
    else cout << "No";
}
