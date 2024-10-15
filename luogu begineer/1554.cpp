#include <bits/stdc++.h>
using namespace std;
//2b题浪费我这么多时间，原来是for处理str += 错了，int初值设置为大的了。。找了半天，以后注意
int main(){
    int M,N;cin >> M;cin >> N;
    string str;
    for(int i=M;i<=N;i++){
        str += to_string(i);
    }
    int nums[10]={0};
    for (int i = 0; i < str.length(); i++) {
        nums[str[i] - '0']++;
    }
    for(int i=0;i<10;i++)cout << nums[i] << ' ';
    return 0;
}