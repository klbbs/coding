#include <bits/stdc++.h>
using namespace std;


void sort_(vector<int>&s,int l,int r,int k){
    if(l>=r)return ;
    int i=l,j=k;
    while(i<j){
        while(i<j && s[i]<s[l])i++;
        while(i<j && s[j]>s[l])j--;
        if(i<j)swap(s[i],s[j]);
    }
    swap(s[j],s[l]);
    int st = j - l + 1;
    if(k <= st)return sort_(s,l,j,k);
    else return sort_(s,l,j+1,st - k);
    
}

int main(){
    int n,k;cin>>n>>k;
    vector<int>s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    if(k>=(int)s.size())cout<<"NO RESULT";
    else cout << s[k-1];
    
}
