#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = __gcd(a + b, c + d);
        if (c + d - x < c)
        {
            cout << "infinity" << endl;
        }
        else
        {
            cout<<(a+b)*(c+d)-a-b-c-d<<endl;
        }
    }

    return 0;
}