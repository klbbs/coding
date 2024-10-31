/************************
    感觉这个东西好聪明的感觉的感觉....的感觉
                hh
************************/


#include <iostream>
using namespace std;

const int N = 100005;

int q[N];

int find(int x)
{
    if(q[x] != x) q[x] = find(q[x]);
    return q[x];
}


int main()
{
    int n, m;cin>>n>>m;
    for(int i = 1; i <= n; i ++)q[i] = i;
    for(int i = 0; i < m; i ++ )
    {
        char op; scanf("%s", &op);
        int a,b; scanf("%d%d", &a, &b);

        if(op == 'M')
        {
            q[find(a)] = find(b);
        }
        else if(op == 'Q')
        {
            if( find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

}