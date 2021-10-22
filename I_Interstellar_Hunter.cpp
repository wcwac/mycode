#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    for (ll cas = 1; cas <= T; ++cas)
    {
        ll ans = 0;
        ll fa = 0, fb = 0, k = 0;
        ll flag = 0, fx = 0, fy = 0;
        ll n;
        cin >> n;
        while (n--)
        {
            ll x;
            cin >> x;
            if (x == 1)
            {
                ll a, b;
                cin >> a >> b;
                if (a == 0 && b == 0)
                    continue;
                if (flag)
                {
                    fx = gcd<ll, ll>(fx, a);
                    fy = gcd<ll, ll>(fy, b);
                }
                else if (fa == 0 && fb == 0)
                {
                    fa = a;
                    fb = b;
                    k = a + b;
                }
                else
                {
                    if (fa * b == a * fb)
                    {
                        k = gcd<ll, ll>(k, a + b);
                    }
                    else
                    {
                        flag = 1;
                        fx = gcd<ll, ll>(fa, a);
                        fy = gcd<ll, ll>(fb, b);
                    }
                }
            }
            else
            {
                ll a, b, c;
                cin >> a >> b >> c;
                if (flag)
                {
                    if (gcd<ll, ll>(a, fx) == fx && gcd<ll, ll>(b, fy) == fy)
                        ans += c;
                }
                else
                {
                    if (fa != 0 || fb != 0)
                    {
                        if (a * fb == fa * b)
                        {
                            if ((a + b) % k == 0)
                            {
                                ans += c;
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%lld: %lld\n", cas, ans);
    }

    return 0;
}