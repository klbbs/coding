#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    double pay = 0;
    if(n<=150){
        pay = n*0.4463;
    }else if(n>150 && n<=400){
        pay = 150*0.4463;
        pay += (n-150)*0.4663;
    }else if(n>400){
        pay = 150*0.4463+250*0.4663;
        pay += (n-400)*0.5663;
    }
    cout << fixed << setprecision(1) << pay; //四舍五入保留一位小数
    
    return 0;
}