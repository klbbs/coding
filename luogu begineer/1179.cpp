#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin >> l;
    cin >> r;
    int cnt=0;
    for(int i=l;i<=r;i++){
        string j=to_string(i);
        for(int k=0;k<j.length();k++){ /*卧槽，string类的length和size方法居然不一样，为啥我把size换成length就成了，离谱啊哥 */
            if(j[k]=='2')cnt++;
        }
    }
    cout << cnt;
    
    
    
    return 0;
}