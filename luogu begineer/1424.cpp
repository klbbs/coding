#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;cin >> a;cin >> b;
    int sum=0;
    for(;b>0;b--){
        if(a>7)a%=7;
        if(a!=6 && a!=7){
            sum += 250;
        }
        a++;
    }
    cout << sum;
    return 0;
}