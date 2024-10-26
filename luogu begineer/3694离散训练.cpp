#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int k[N];
vector<int>w;
int find(vector<int>&w, int x)
{
    int l = 0, r = w.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(w[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main()
{
    int T;cin>>T;
    for(int i = 1; i <= T; i ++ )
    {
        int n;cin>>n;
        for(int i = 1; i <= n; i ++ )
        {
            int x; cin>>x;
            k[i] = x;
            w.push_back(x);
        }
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()), w.end());
        for(int i = 1; i <= n; i ++ )
        {
            cout << find(w, k[i]) << ' ';
        }
        cout << endl;
        w.clear();
    }
    return 0;
}