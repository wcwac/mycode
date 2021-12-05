#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//freopen("1.in","r",stdin);
ll read()
{
    ll x;
    scanf("%lld", &x);
    return x;
}
int n, x, y, z;
void work(int &a, int &b, int &c, int &d)
{
    d = d + y;
    c = c + x + d / 1000;
    d = d % 1000;
    b = b + c / 60;
    c = c % 60;
    a = a + b / 60;
    b = b % 60;
}
int now, a, b, c, d;
string s;
int main()
{
    //freopen("1.in","r",stdin);
    scanf("%d %d.%d", &n, &x, &y);
    scanf("%d", &now);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", i);
        scanf("%d:%d:%d,%d", &a, &b, &c, &d);
        work(a, b, c, d);
        printf("%02d:%02d:%02d,%03d --> ", a, b, c, d);
        scanf(" --> %d:%d:%d,%d", &a, &b, &c, &d);
        work(a, b, c, d);
        printf("%02d:%02d:%02d,%03d", a, b, c, d);
        while (getline(cin, s))
        {
            if (s[0] == i + 1 + '0')
                break;
            else
                cout << s << endl;
        }
    }
}