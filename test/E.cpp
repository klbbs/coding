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
    int l,r;cin>>l>>r;
    sort(s.begin() + 1,s.end(),[&](auto &a,auto &b){
        int compre = 0;
        for(int i = 0; i < min(a.second.length(),b.second.length()); i ++)
            if(a.second[i] != b.second[i])
                break;
            else compre ++;

        a.first = max(a.first,compre);
        b.first = max(b.first,compre);
        if(a.first == b.first)
            return a.second.length() < b.second.length();
        return a.first < b.first;
    });
    // for(int i = 1; i <= n; i ++)
    //     cout << s[i].second  << endl;

    LL ans = s[1].second.length();
    for(int i = 2; i <= n; i ++)
    {
        ans += s[i].second.length() - s[i].first + s[i - 1].second.length() - s[i - 1].first;
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