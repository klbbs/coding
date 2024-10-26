#include <iostream>
using namespace std;

int const N = 100005;

int A[N], B[N];

int main()
{
    int t, a, b;
    cin>>a>>b>>t;
    for(int i = 1; i <= a; i ++ )scanf("%d",&A[i]);
    for(int i = 1; i <= b; i ++ )scanf("%d",&B[i]);
    for(int i = 1, j = b; i <= a; i ++ )
    {
        while( j >= 1 && A[i] + B[j] > t) j --;
        if( j >= 1 && A[i] + B[j] == t) cout << i - 1 << ' ' << j - 1;
    }

}
