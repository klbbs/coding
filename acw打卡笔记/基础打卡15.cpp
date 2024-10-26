#include <iostream>

using namespace std;

const int N = 100005;

int q[N], s[N];
int n;

int main()
{
    int cnt = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++ ) scanf("%d",&q[i]);
    for(int i = 1, j = 1; i <= n; i ++ )
    {   
        s[q[i]]++;
        while( s[q[i]] > 1)s[q[j]]--,j++;
        cnt = max(i - j + 1, cnt);
    }
    cout << cnt;
}
