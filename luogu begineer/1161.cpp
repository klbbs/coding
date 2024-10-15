#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int>hash;
    int n;cin >> n;
/*    vector<float>a(n); 妈的，就是这句要用双精度，害得我找半天原因，日了
*/
    vector<double>a(n) //再次重申：双精度!!!
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> t[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=t[i];j++){
            if(hash.count(a[i]*j)){
                hash.erase(a[i]*j);
            }else{
                hash.insert(a[i]*j);
            }
        }
    }
    auto it = hash.begin();
    cout << *it;
    return 0;
}