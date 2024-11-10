#include <iostream>
#include <cstring>
using namespace std;

const int N  = 2e5 + 3, null = 0x3f3f3f3f;

int q[N];

int find(int x)
{
    int k = (x%N + N)%N;
    while(q[k] != null && q[k] != x)
    {
        k++;
        if(k == N) k = 0;//这里注意,不是N-1;当k等于k-1的时候,上面那条命令让k++,所以等于N的时候才是走到头了
    }
    return k;
}

int main()
{
    int n;cin>>n;
    memset(q, 0x3f, sizeof(q));//memset是按字节赋值,q数组是int类型的,每个字节都赋值3f,四字节就是0x3f3f3f3f,就是null
    while(n --)
    {
        char op[2];int x;
        scanf("%s%d",op, &x);
        if(*op == 'I')q[find(x)] = x;
        else
        {
            if(q[find(x)] == null)printf("No\n");
            else printf("Yes\n");
        }
    }
}