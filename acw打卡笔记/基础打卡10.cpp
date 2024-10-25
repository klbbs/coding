#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int k;
vector<int> div(vector<int>&A, int b)
{
    long long t = 0;
    vector<int>C;
    for(int i = 0; i < A.size(); i ++)
    {
        t = t*10 + A[i];
        //cout << t << endl;
        C.push_back(t/b);
        t %= b;
    }
    reverse(C.begin(), C.end());
    while(C.back()==0 && C.size() > 1)C.pop_back();
    if(t)k = t;
    return C;
}

int main()
{
    string a;int b;
    cin>>a>>b;
    vector<int>A;
    for(int i = 0; i < a.length() ; i ++ )A.push_back(a[i] - '0');
    vector<int>C = div(A, b);
    for(int i = C.size() - 1; i >= 0; i --)cout<<C[i];
    cout << endl << k;
    
    return 0;
}