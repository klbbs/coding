#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<int>nums(n);
    vector<int>res(n,0);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int cnt = 0;
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i])cnt++;
        }
        res[i] = cnt;
        cnt = 0;
    }
    for(int i=0;i<n;i++)cout << res[i] << ' ';
    
    return 0;
}