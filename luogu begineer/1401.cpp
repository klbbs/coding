#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1,x2,y1,y2;
    cin >> x1;
    cin >> x2;
    cin >> y1;
    cin >> y2;
    string Mx=to_string(x2),My=to_string(y2);
    if(abs(x1)>abs(x2))Mx = to_string(x1);
    if(abs(y1)>abs(y2))My = to_string(y1);
    int length = Mx.length()+My.length();
    if(Mx[0]=='-' && My[0] == '-')length -= 2;
    else if(Mx[0] == '-' && My[0] != '-')length--;
    else if(Mx[0] != '-' && My[0] == '-')length--;
    if(length>10)cout << "long long int";
    else{
        long Max = stol(Mx)*stol(My);
        if(Max > INT_MAX || Max < INT_MIN)cout << "long long int";
        else{cout << "int";}
    }
    return 0;
}