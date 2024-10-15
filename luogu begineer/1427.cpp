#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums;
    for(int n=-1;n!=0;){
        cin >> n;
        nums.push_back(n);
    }
    nums.pop_back();
    for(int i=nums.size()-1;i>=0;i--){
        cout << nums[i] << ' ';
    }
    
    return 0;
}