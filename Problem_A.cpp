#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int _, __;
    cin >> _;
    while (_--)
    {
        cout << "Case #" << ++__ << ":\n";
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> v;
        for (int i = 1; i <= n; ++i)
        {
            ll t;
            cin >> t;
            v.emplace_back(t);
        }
        sort(v.begin(), v.end());
        ll now = m;
        for (int i = 0; i < n; ++i)
        {
            if (now < v[i])
            {
                if (i == 0 || v[i - 1] + k < v[i])
                    break;
                now = v[i - 1] + k;
                k = max(k - 1, 0ll);
            }
        }
        if (now >= v[n - 1])
        {
            cout << "why am I so diao?" << endl;
        }
        else
        {
            cout << "madan!" << endl;
        }
    }
}