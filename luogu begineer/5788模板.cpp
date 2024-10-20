#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+10;
int stk[N],e[N],n,tt=0,res[N];//stk是单调栈，tt是栈顶，res是返回数组

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&e[i]);//读入
    for(int i=n;i>=1;i--){//从尾开始
        while(tt && e[stk[tt]]<=e[i])tt--;//如果栈不是空，新元素大于栈顶元素，弹出栈顶
        if(!tt)res[i]=0;//如果栈为空，返回数组在这个位置为0，这个数右边没有比它大的元素了
        else res[i]=stk[tt];//不是空的话，返回栈顶（前面while已经完成栈顶一定是大于这个数了）
        stk[++tt] = i;//加入新元素（下标）
    }
    for(int i=1;i<=n;i++)printf("%d ",res[i]);//倒序输出元素
    return 0;
}