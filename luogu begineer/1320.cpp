#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    string tstr;
    cin >> tstr;
    str = tstr;
    int sum = str.length()*str.length();
    cout << str.length() << ' ';
    for(int i=0;i<tstr.length()-1;i++){
        cin >> tstr;
        str += tstr;
    }
    int ou0=0,ou1=0;
    for(int i=0;i<sum;){
        while(str[i]=='0'){
            ou0++;
            i++;
        }
        cout << ou0 << ' ';
        if(i==sum)break;
        ou0 = 0;
        while(str[i]=='1'){
            ou1++;
            i++;
        }
        cout << ou1 << ' ';
        ou1 = 0;
    }

    return 0;
}