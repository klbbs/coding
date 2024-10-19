#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int resA = 0, resB = 0;
    for(int i=1;i<=n;i++){
        int a = 0 , b = 0;
        int k = i;
        while(k!=0){
//          cout << bitset<10>(k) << ' ';
            if(k & 1 == 1)a++;
            else b++;
            k >>= 1;

        }
        if(a>b)resA++;
        else resB++;
    }
    cout << resA << " " << resB;
    return 0;
}