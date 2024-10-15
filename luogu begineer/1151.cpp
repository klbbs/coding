#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;cin >> k;
    vector<int>nums;
    for(int i=10000;i<=30000;i++){
        if(i%1000%k==0&&i/10%1000%k==0&&i/100%k==0){
            cout << i << endl;
            nums.push_back(i);
        }
    }
    if(nums.empty())cout << "No";
}