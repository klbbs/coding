#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a;cin >> n;
    vector<int>nums;
    vector<int>b;
    for(int i=0;i<n;i++){
        cin >> a;
        b.push_back(a);
    }
    for(int i=1;i<n;i++){
        nums.push_back(abs(b[i-1]-b[i]));
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    if(n>=2 && nums.size()==n-1){
        cout << "Jolly";
    }else{
        cout << "Not jolly";
    }
    return 0;
}