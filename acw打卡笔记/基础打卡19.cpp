#include <iostream>
#include <vector>
#include <algorithm>
//本人认为此次代码较为混乱，虽然几乎是照抄，但是命名混乱而且对离散认知较为不清晰
using namespace std;

const int N = 3000005;//原题1<=n,m<=1e5,所以应该开1000005就行了，后来改成这个试了下还是过了
int s[N], q[N];//这两个数组用作存储值，一个是原值，一个是前缀和 
vector<pair<int,int>>k, query;//这里的k用作保留原位置和原值，query保存询问的区间，这两个在后面的离散化起到重要作用
vector<int>w;//最核心的东西，所有映射由它而来
int find(int x)//核心映射函数，把很大的坐标值映射为较小的下标值
{
    int l = 0, r = w.size() - 1;//在映射数组中搜索
    while( l < r)//找到w对应下标的值是x
    {
        int mid = l + r >> 1;
        if(w[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;//返回下标
}
int main()
{
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i ++ )
    {
        int x, c; cin>>x>>c;
        w.push_back(x), k.push_back({x,c}); //读入位置x和值c，放到w是因为这个位置需要被映射（用到了）
    }
    for(int i = 1; i <= m; i ++ )
    {
        int l, r; cin>>l>>r;
        query.push_back({l, r});
        w.push_back(l),w.push_back(r);//同理，l和r这两个位置被用到了
    }
    sort(w.begin(), w.end());//需要
    w.erase(unique(w.begin(), w.end()), w.end());//去重，不重要，是优化
    for(auto itme : k)//遍历k数组
    {
        int x = find(itme.first);//把位置映射到数组下标
        s[x] += itme.second;//数组下标加上值,此时记录的就是这个位置加上了这个值,+=是因为可以相同的坐标都在这里加上了值
    }
    for(int i = 1; i <= w.size(); i ++ ) q[i] =+ q[i - 1] + s[i];//处理前缀和,是+=还是=都无所谓，因为q数组是全0，更新到哪才存在值
    for(auto itme : query)//处理询问
    {
        int l = find(itme.first), r = find(itme.second);//映射把坐标到下标
        cout << q[r] - q[l - 1] << endl;//返回区间和
    }
}