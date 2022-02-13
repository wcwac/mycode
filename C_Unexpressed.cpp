#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> q;
int main()
{
    ll a;
    ll cnt = 0;
    cin >> a;
    for (ll i = 2; i * i <= a; ++i)
    {
        ll tmp = i * i;
        while (tmp <= a)
        {
            if (++q[tmp] == 1)
                ++cnt;
            tmp *= i;
        }
    }
    cout << a - cnt;

    return 0;
}