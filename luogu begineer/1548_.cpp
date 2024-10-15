#include <bits/stdc++.h>
using namespace std;
//算有多少个子矩形
void rect(int &sum,int N,int M){
    if(N==0)return;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sum += M-j+1;
        }
    }
    rect(sum,N-1,M);
}

int main(){
    int N,M;cin >> N;cin >> M;
    int MIN = min(M,N);
    int sum=0,zhen=0;
    rect(sum,N,M);
    for(int i=1;i<=MIN;i++){ //算有多少个正方形
        zhen += (M-i+1)*(N-i+1);
    }
    cout << zhen << ' ' << sum-zhen;
    return 0;
}