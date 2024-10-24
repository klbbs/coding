#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sub(vector<int>&A, vector<int>&B)
{
    int t = 0;
    vector<int>C;
    for(int i = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;
        if(i < B.size())t -= B[i];
        C.push_back((t+10)%10);
        if(t < 0)t = 1;
        else t = 0;
    }
    for(int i = C.size() - 1; i >= 0; i ++){
        if(C.back() == 0 && C.size() > 1)C.pop_back();
        else break;
    }
    return C;
}


int main()
{
    string a,b;
    cin>>a>>b;
    int flag = 0;
    vector<int>A,B;
    vector<int>C;
    for(int i = a.length() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.length() - 1; i >= 0; i -- )B.push_back(b[i] - '0');
    if(A.size() > B.size()){C = sub(A, B);flag = 1;}
    else if(B.size() > A.size())flag = 0;
    else {
        for(int i = A.size() - 1; i >= 0; i -- )
        {
            if(A[i] > B[i]){flag = 1;break;}
            if(A[i] < B[i])break;
        }
    }
    if(flag)C = sub(A, B);
    else {C = sub(B, A);if(C.size()!=1 || C[0] != 0)cout<<'-';}
    for(int i = C.size() - 1; i >= 0; i--)cout << C[i];
}

