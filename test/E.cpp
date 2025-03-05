#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;


const int INF = 1e9;


void solve()
{
    string s;cin>>s;
    // N E S W
    char p[] = "NESW"; 
    map<char,int>mp;
    for(int i = 0; i < 4; i ++)
        mp[p[i]] = i;
    int now = mp[s[0]];
    int l = 0,r = 0;
    for(int i = 1; i < s.length(); i ++)
    {
        if(s[i] == p[(now + 1)%4])
            r ++;
        else if(s[i] == p[(now - 1 + 4)%4])
            l ++;
        now = mp[s[i]];
    }
    if(l > r)
        cout << "CCW" << endl;
    else cout << "CW" << endl;
    

}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T --)
    {
        solve();
    }
    return 0;
}