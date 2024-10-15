#include <bits/stdc++.h>
using namespace std;

int main(){
    string group;
    string plant;
    cin >> plant;
    cin >> group;
    int sumA=1,sumB=1;
    for(int i=0;i<plant.length();i++){
        char p = plant[i];
        sumA *= p-64;
    }
    for(int i=0;i<group.length();i++){
        char g = group[i];
        sumB *= g-64;
    }
    if(sumA%47 == sumB%47){
        cout << "GO";
    }else{
        cout << "STAY";
    }
    
    return 0;
}