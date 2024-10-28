# trie树

## 高效存储，查找字符串集合

## 	t r i e 树的基本结构如图

​	![trie](..\基础算法\photos\trie tree.png)

##### 从根节点开始，假如存储abcdef，如果没有节点a，那么就创建一个，以此类推，最后做个标记，表示到这里为止有一个字符串，（如果有一个字符串abc，那么从根节点开始可以找到abc，在c处打个标记，表示存储了abc）。

#### 如果要查找一个字符串，那么也是从根节点开始，直到找到了结束的字符，看是否被标记，如果被标记了，就说明这颗树存储了那个字符串，否则，没有标记或者找不到其中一些字符，那么这个字符串就没有存储（在这个trie树不存在）

#### 下面是tire树（静态）建立代码：

````c++
const int N = 100010;//顺便整一个较大的内存（表示树长）
int son[N][26];cnt[N],idx;// 下标作用和单调栈一样，cnt数组表示以当前节点结尾的字符串有多少个
char str[N];//采用str读入字符串
void insert(char str[])
{
	int p = 0;
    for (int i = 0; str[i];i ++ )//str[]最后一个是/0
    {
		int u = str[i] - 'a';//把26小写字母转换为数字存储（映射）
        if(!son[p][u]) son[p][u] = ++idx;//没有这个节点就创建
        p = son[p][u];//后移
    }
}
int query(char str[])
{
	int p = 0;
    for(int i = 0;str[i];i ++)
    {
		int u = str[i] - 'a';
        if(!son[p][u]) return 0;//不存在返回0
        p = son[p][u];//后移
    }
	return cnt[p];
}

````

#### 另外前辈的笔记---->[AcWing 835. Trie树图文详解 - AcWing](https://www.acwing.com/file_system/file/content/whole/index/content/1553895/)

## 因实践trie更加理解其静态结构 [trie模板题静态](../acw打卡笔记/基础算法29trie字典树.md)
