#include <bits/stdc++.h>
using namespace std;
int n;
bool isX(int x){
    if(x<2)return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x % i == 0)return false;
    }
    return true;
}

void backtrack(vector<int>&w,int k,int sum,int &res,int now,int start){
    if(now==k && isX(sum)){res++;return;}//这里之前调试忘记删输出信息了，搞半天没通过，记住教训
    else if(now == k)return;
    for(int i=start;i<=n;i++){
            backtrack(w,k,sum+w[i],res,now+1,i+1);
    }
}

int main(){
    vector<int>w;
    int k;cin>>n>>k;
    w.push_back(0);
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        w.push_back(a);
    }
    int res = 0;
    vector<int>status;
    int now = 0,sum = 0;
    backtrack(w,k,sum,res,now,1);
    cout << res;
}