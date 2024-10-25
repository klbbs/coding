#include <iostream>
using namespace std;

const int N = 1005;

int q[N][N];
int n, m, s, x;

int main()
{
    cin>>n>>m>>s;
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= m; j ++ ) cin>>x, q[i][j] += x, q[i + 1][j] -= x, q[i][j + 1] -= x, q[i + 1][j + 1] += x;
    for(int i = 1; i <= s; i ++ )
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        q[x1][y1] += c;
        q[x1][y2 + 1] -= c;
        q[x2 + 1][y1] -= c;
        q[x2 + 1][y2 + 1] += c;
    } 
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ )q[i][j] += q[i - 1][j] + q[i][j - 1] - q[i - 1][j - 1],cout << q[i][j]<< ' ';cout<<endl;}
}
