# W 1 A:

## 对视频讲解的照猫画虎：

``````c++
#include <bits/stdc++.h>
const int N = 1000005;
using namespace std;
int w[N],d[N],l[N],r[N];
long b[N];
int n,m;
//整体思路为：用差分数组和二分统计看看一半的订单能不能处理完，然后一直二分，直到找到正好能处理完的那个订单
//b数组作为差分数组
bool check(int mid){//check函数是关键函数，它不仅仅给差分数组（b）赋值，而且进行能否处理订单的判断
    memset(b,0,sizeof(b));
    for(int i=1;i<=mid;i++){
        b[l[i]] += d[i];
        b[r[i]+1] -= d[i];//此处可以查看基础算法笔记的差分数组
    }
    for(int i=1;i<=n;i++){
        b[i] += b[i-1];//统计第i天的总订单量
        if(b[i] > w[i])return false;
    }
    return true;
}

int main(){
    //读入数据
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        cin>>d[i]>>l[i]>>r[i];
    }
    int left = 0,right = m;
    while(left<right){
        int mid = left + right +1 >> 1;//二分搜索中间值
        if(check(mid))left = mid;
        else right = mid-1;
    }
    if(right == m)cout << 0;//如果right正好为总订单数m，说明全部可以处理
    else cout << -1 << endl << right+1;//否则返回最后一个能处理订单的后一个订单
    return 0;
}
``````

