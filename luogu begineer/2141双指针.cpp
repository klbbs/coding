#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//一眼双指针
int main()
{
    int n;cin>>n;
    vector<int>q(n);
    int res = 0;
    for(int i = 0; i < n; i ++ )cin>>q[i];
    sort(q.begin(), q.end());
    //下面为调试时使用
    // for(int i = 0; i < n; i ++ )cout << q[i] << ' ' ;
    // cout << endl;
    for(int k = 0; k < n; k ++)
    {
        for(int i = 0, j = q.size() - 1; i < j ;)
        {
            if(i == k) i ++;
            if(j == k) j --;                            //下面为调试时使用
            if(q[i] + q[j] == q[k] && i != j){res++;/*cout << i << ' ' << j << ' ' << k <<endl*/;break;}
            if(q[i] + q[j] > q[k]) j --;
            else i ++;
        }
    }
    cout << res; 
    return 0;
}
