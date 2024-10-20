#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int q[N],a[N],tt=-1,hh;//队列存储下标

int main(){
    //窗口最小值
    int n,k;scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);//数据读入到数组
    for(int i=1;i<=n;i++){
        if(hh <= tt && i-k+1 > q[hh])hh++;//如果队头小于队尾：存在元素，如果队头下标小于当前窗口，弹出队头
        while(hh<=tt && a[i]<a[q[tt]])tt--;//如果新元素小于队尾，弹出队尾元素
        q[++tt] = i;//加入新元素（下标）
        if(i>=k)printf("%d ",a[q[hh]]);//当窗口满足k个元素时输出
    }
    printf("\n");
    //窗口最大值
    tt = -1,hh=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(hh <= tt && i-k+1 > q[hh])hh++;
        while(hh<=tt && a[i]>a[q[tt]])tt--;
        q[++tt] = i;
        if(i>=k)printf("%d ",a[q[hh]]);
    }
    return 0;
}