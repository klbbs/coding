#include <bits/stdc++.h>
using namespace std;

int gcd(int i,int j){
    int tmp;
    while(j!=0){
        tmp = i%j;
        i = j;
        j=tmp;
    }
    return i;
}

int main(){
    string a,b;
    cin >> a;cin >> b;
    int pointA=a.find('/',0);
    int pointB=b.find('/',0);
    int aUpper = stoi(a.substr(0,pointA)),aDown=stoi(a.substr(pointA+1,a.length()-1));
    int bUpper = stoi(b.substr(0,pointB)),bDown=stoi(b.substr(pointB+1,b.length()-1));
    int up = aUpper*bUpper,down=bDown*aDown;
    int i = gcd(up,down);
    down /= i;
    up /= i;
    cout << down << ' ' << up;
    return 0;
}