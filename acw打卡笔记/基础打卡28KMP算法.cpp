#include <iostream>
using namespace std;

const int N = 1000005;
int m, n, ne[N];
char s[N], p[N];

int main()
{
    cin>>n>>p+1>>m>>s+1;
    for(int i = 2, j = 0; i <= n; i ++)
    {
        while(j && p[j + 1] != p[i]) j = ne[j];//用到了已经创建部分的ne
        if(p[j + 1] == p[i]) j ++;//匹配成功的字数
        ne[i] = j;//创建 此下标的ne值
    }
    for(int i = 1, j = 0; i <= m; i ++)//for是i增加的唯一方法，同时每次遍历必定增加i
    {
        while(j && s[i] != p[j + 1]) j = ne[j];//不匹配直接回退
        if(p[j + 1] == s[i]) j ++;
        if(j == n)
        {
            cout << i - n << ' ';//输出 i（匹配到的数字）- n（模板串长） == 第几个字开始匹配成功
            j = ne[j]; //成功了就回退一步
        }
    }
    return 0;
}

