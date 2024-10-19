#include <bits/stdc++.h>
using namespace std;

int a[105],s[105];

int main(){
    int n;cin>>n;
    int res = 0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0,j=0;i<n;i++){
        if(a[i]!=a[j]){
            res = max(res,i-j);
            j = i;
        }
    }
    cout << res;
    
    
    return 0;
}
