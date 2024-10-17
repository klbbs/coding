#include <bits/stdc++.h>
using namespace std;
int w[2005],dp[2005];
int main(){
    int n,k;cin>>n>>k;
    for(int i=n;i>0;i--){
        cin>>w[i];
    }
    for(int i=1;i<=k;i++){
        dp[i] = w[i];
    }
    for(int i=k+1;i<=n;i++){
        dp[i] = max(dp[i-1],dp[i-k-1]+w[i]);
    }
    cout << dp[n];
    return 0;
}