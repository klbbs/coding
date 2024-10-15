#include <bits/stdc++.h>
using namespace std;

bool isT(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;cin >> n;
    for(int i=4;i<=n;i+=2){
        for(int j=2;j<n;j++){
            if(isT(j) && isT(i-j)){
                cout <<i<<'='<<j<<'+'<<i-j<<endl;
                break;
            }
        }
    }
    return 0;
}
