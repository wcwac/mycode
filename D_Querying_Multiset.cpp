#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, now = 0;
    priority_queue<ll, vector<ll>, greater<ll>> a;
    cin >> n;
    while (n--)
    {
        ll x, y;
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            a.push(y - now);
        }
        else if (x == 2)
        {
            cin >> y;
            now += y;
        }
        else
        {
            cout << a.top() + now << endl;
            a.pop();
        }
    }

    return 0;
}