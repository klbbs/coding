#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    double s; cin >> s;
    double now=0,start=2.0;
    while(now<s){
        now+=start;
        start *= 0.98;
        cnt++;
    }
    cout << cnt;
    
    return 0;
}