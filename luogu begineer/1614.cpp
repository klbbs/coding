//纯暴力，由于是入门题，时间放的比较大，正常来说用窗口
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int>ting(n);
    for(int i=0;i<n;i++){
        cin>>ting[i];
    }
    int min = INT_MAX;
    for(int i=0;i<n-m+1;i++){
        int tmp = 0;
        for(int j=i;j<i+m;j++){
            tmp += ting[j];
        }
        if(tmp<min)min=tmp;
    }
    cout << min;
    return 0;
}