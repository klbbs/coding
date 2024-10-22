#include <bits/stdc++.h>
using namespace std;

void sort(vector<int>&s,int l,int r){
    if(l>=r)return ;
    int i = l-1,j = r+1;
    while(i<j){
        do i++ ;while(s[i]<s[l]);
        do j-- ;while(s[j]>s[l]);
        if(i<j)swap(s[i],s[j]);
    }
    sort(s,l,j),sort(s,j+1,r);
}

int main(){
    //vector == 开挂
    vector<int>s;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        s.push_back(x);
    }
    sort(s,0,n-1);
    s.erase(unique(s.begin(),s.end()),s.end());
    cout << s.size() << endl;
    for(int i=0;i<s.size();i++)cout<<s[i]<<' ';
    return 0;
}