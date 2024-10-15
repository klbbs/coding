#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a,b,now,sum=0,res=0;
    for(int i=0;i<n;i++){
     cin >> a;
     cin >> b;
     now = sum+a+b-8;
     sum = now;
     res += now;
    }
    cout << res;
    return 0;
}