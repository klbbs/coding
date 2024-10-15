#include <bits/stdc++.h>
using namespace std;

int main(){
    int startH,startM;cin >> startH;cin >> startM;
    int endH,endM;cin >> endH;cin >> endM;
    int sumS = startH*60+startM,sumE= endH*60+endM;
    int spend = sumE-sumS;
    int outH=0;
    while(spend>=60){
        spend -= 60;
        outH++;
    }
    cout << outH << ' ' << spend;
    return 0;
}