#include <bits/stdc++.h>
using namespace std;


int main(){
    string str;cin >> str;
    int Bcnt=0,Gcnt=0;
    for(int i=0;i<str.length()-2;i++){
        if(str[i]=='b' || str[i+1] == 'o' || str[i+2] == 'y')Bcnt++;
    }
    for(int i=0;i<str.length()-3;i++){
        if(str[i] == 'g'|| str[i+1] == 'i' || str[i+2] == 'r' || str[i+3] == 'l')Gcnt++;
    }
    cout << Bcnt << endl << Gcnt;
    return 0;
}