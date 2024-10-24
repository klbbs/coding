
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;
int q[N], tmp[N], n;
long long res;
long long merge(int q[], int l, int r)
{
    if( l >= r)return 0;
    int mid = l + r >> 1;
    res = merge(q, l, mid) + merge(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;

    while( i <= mid && j <= r)
    {
		if( q[i] <= q[j])tmp[k ++] = q[i ++];
        else res += mid - i + 1,tmp[k ++] = q[j ++];
        
    }
    while( i <= mid)tmp[k ++] = q[i ++];
    while(j <= r)tmp[k ++] = q[j ++];
    for(i = l, j = 0; i <= r;)q[i ++] = tmp[j ++];
    return res;
}

int main()
{
	cin>>n;
	for(int i = 0; i < n; i ++ )cin>>q[i];
    merge(q, 0, n - 1);
    cout << res;
    //for(int i = 0; i < n; i ++)cout<<q[i]<<' ';
}



