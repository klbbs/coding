#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mul(vector<int>&A, int b)
{
    long long t = 0;
    vector<int>C;
    for(int i = 0; i < A.size(); i ++ )
    {
        t += A[i] * b;
        C.push_back(t%10);
        t /= 10;
    }
    while(t)C.push_back(t%10),t/=10;
    while(!C.back() && C.size() > 1)C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;cin>>a>>b;
    vector<int>A;
    for(int i = a.length() - 1; i >= 0; i -- )A.push_back(a[i] - '0');
    vector<int>C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i --)cout<<C[i];
}