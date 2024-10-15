#include <bits/stdc++.h>
using namespace std;
//这题特殊情况放到1317.cpp
int main(){
    int n;cin >> n;
    int cnt=0,last=0;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    if(nums.size()>2){
        for(int i=2;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                for(int j=i-2;j>last;j--){
                    if(nums[j]>nums[i-1]){
                        cnt++;
                        last = j;
                        break;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}