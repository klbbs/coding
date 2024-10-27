#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

stack<int>num;//存储数字
stack<char>op;//存储操作符
unordered_map<char,int> cmp{{'+',1},{'-',1},{'*',2},{'/',2}};//优先级设置

void res()//计算一个子树的值
{
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto p = op.top();
    op.pop();
    int t;    
    if(p == '+') t = a + b;
    else if (p == '-') t = a - b;
    else if (p == '*') t = a * b;
    else t = a / b;
    num.push(t);
}


int main()
{
    string a;cin>>a;//读入表达式
    for(int i = 0; i < a.length(); i ++ )//遍历存入（并计算）
    {
        auto x = a[i];
        if(isdigit(x))//是否为数字，如果是，要知道是几位数字，不能一个十位数存成俩个一位数
        {
            int j = i, k = 0;
            while(j < a.length() && isdigit(a[j]))
            {
                k = k*10 + a[j] - '0';
                j ++ ;
            }
            i = j - 1;
            num.push(k);
        }
        else if(x == '(')op.push(x);//左括号没啥特别的，直接存
        else if(x == ')')//右括号表示要优先计算的结束了
        {
            while(op.top() != '(')res();//疯狂计算直到遇到左括号
            op.pop();//括号内已经结束，弹出左括号
        }
        else
        {
            while(op.size() && op.top() != '(' && cmp[op.top()] >= cmp[x])res();//比较优先级，如果大于等于要进入操作栈的优先级，就直接计算一下
            op.push(x);//无论大于小于等于，都有把这个操作符存入
        }
    }
    while(op.size())res();//如果还有操作符，继续计算
    cout << num.top();//输出数栈顶，表示结果
}