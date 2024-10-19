#include <bits/stdc++.h>
using namespace std;
vector<pair<long,long>>a,b;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int ca,cb;
        cin>>ca>>cb;
        a.push_back({ca,cb});
    }
    sort(a.begin(),a.end());
    if(a.empty()){
        cout << 0 ;
        return 0;
    }
    long st = a[0].first;
    long ed = a[0].second;
    for(auto item : a){
        if(ed >= item.first){
            ed = max(ed,item.second);
        }else{
            b.push_back({st,ed});
            st = item.first;
            ed = item.second;
        }
    }
    b.push_back({st,ed});
    int sum = 0;
    for(int i=0;i<b.size();i++){
        // cout << b[i].first << " " << b[i].second << endl;
        sum += b[i].second - b[i].first ;
    }
    cout << sum;
}