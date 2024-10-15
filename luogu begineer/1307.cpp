#include <bits/stdc++.h>
using namespace std;

void myReverse(string &str,int i,int j){
    while(i<j){
        char tmp=str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int main(){
    int n;cin >> n;
    string str = to_string(n);
    if(str[0]=='-'){
        myReverse(str,1,str.length()-1);
    }else{
        myReverse(str,0,str.length()-1);
    }
    cout << stoi(str);
}