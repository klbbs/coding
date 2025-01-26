#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;

void solve()
{
    int n,m;cin>>n>>m;
    vector<pair<int,string>>s(n + 1);

    for(int i = 1; i <= n; i ++)
        cin>>s[i].second,s[i].first = 0;
    
    // 修改排序部分
    sort(s.begin() + 1,s.end(),[&](auto &a,auto &b){
        int compre = 0;
        int minLen = min(a.second.length(),b.second.length());
        while(compre < minLen && a.second[compre] == b.second[compre]) {
            compre++;
        }

        a.first = max(a.first,compre);
        b.first = max(b.first,compre);
        if(a.first == b.first)
            return a.second.length() < b.second.length();
        return a.first < b.first;
    });

    string now = s[1].second;
    LL ans = s[1].second.length();
    
    // 修改计算ans的部分
    for(int i = 2; i <= n; i ++)
    {
        int t = now.length();
        now += '?';
        int idx = 0;
        int minLen = min(t + 1,(int)s[i].second.length());
        
        while(idx < minLen && s[i].second[idx] == now[idx]) {
            idx++;
        }
        
        ans += max(now.length(),s[i].second.length()) - idx - 1 + 
               min(now.length(),s[i].second.length()) - idx; 
        now = s[i].second;
    }

    cout << ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    //cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}