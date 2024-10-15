#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int in0,in1,now=0;
    cin >> n;
    vector<vector<int>>nums(n,vector<int>(n,0));
    while(true){
        cin >> in0;   //这里要小心连续in0个0结尾就没了，导致程序退不出去
        if(now == n*n)break; //所以这里也要加上退出的命令
        now += in0;
        cin >> in1;
        for(int i=now;i<in1+now;i++){
            int h = i%n;
            int l = i/n;
            nums[h][l] = 1;
        }
        now += in1;
        if(now == n*n)break;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << nums[j][i];
        }
        cout << endl;
    }
    
    
    return 0;
}