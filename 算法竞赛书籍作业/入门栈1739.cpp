#include <iostream>
using namespace std;

const int N = 260;

char stk[N];
int tt;


int main()
{
    char n[256];cin >> n;
    for(int i = 0; n[i] != '@'; i ++)
    {   
        if(n[i] == ')')
        {
            while( tt && stk[tt] != '(') tt--;
            tt--;

        }
        else stk[++ tt] = n[i];
    }
    while(tt)
    {
        if(stk[tt--] == '(')
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}