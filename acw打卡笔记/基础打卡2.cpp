#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;
int q[N] , n , k;

int qs(int q[], int l, int r, int k)
{
    if ( l >= r)return q[l];
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while(q[i] < x);
        do j -- ; while(q[j] > x);
        if ( i < j) swap(q[i], q[j]);
    }
    int st = j - l + 1;
    if ( st >= k ) return qs(q, l, j, k);
    else return qs(q, j + 1, r, k - st);
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++ )cin>>q[i];//scanf("%d",&q[i]);
    printf("%d",qs( q, 0, n - 1, k));
    
    
    return 0;
}