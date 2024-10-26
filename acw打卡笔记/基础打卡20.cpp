#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>q;
vector<pair<int,int>> res;

int main()
{
    int n; cin>>n;
    for(int i = 1; i <= n; i ++ )
    {
        int l, r; cin>>l>>r;
        q.push_back({l,r});
    }
    sort(q.begin(), q.end());
    int l = -1, r = -1;
    for(int i = 0; i < q.size(); i ++ )
    {
        if(r >= q[i].first) r = max(r, q[i].second);
        else res.push_back({l,r}), l = q[i].first, r = q[i].second;
    }
    if ( l == -1) res.push_back({l,r});
    cout << res.size();
}