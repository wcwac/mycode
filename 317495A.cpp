#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
ll a[N];
ll sum, ma;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        ma = max(ma, a[i]);
    }
    ll ans2 = ma + m;
    ll ans1 = (sum + m) / n + ((sum + m) % n != 0);
    if (ans1 < ma)
        ans1 = ma;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}