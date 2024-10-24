#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100005;
int s[N];

void sort(int s[],int l,int r)
{
    if(l>=r)return;
    int i = l-1, j = r+1;
    int x = s[l + r >> 1];
    while (i < j)
    {
        do i++ ; while(s[i] < x);
        do j-- ; while(s[j] > x);
        if (i < j)swap(s[i],s[j]);
    }
    sort(s,l,j),sort(s,j + 1,r);
}
int main()
{
    int n;cin>>n;
    for (int i = 0; i < n; i ++ )scanf("%d",&s[i]);
    sort(s,0,n-1);
    for (int i = 0; i < n; i ++ )printf("%d ",s[i]);
    
}