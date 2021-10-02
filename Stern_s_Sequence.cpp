#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int f[20][2000];
typedef long long ll;
ll fpow(ll base, ll power)
{
    ll result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = result * base % P;
        }
        power >>= 1;
        base = (base * base) % P;
    }
    return result;
}

int main()
{
    int n = 10;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 1200; ++j)
        {
            if (j == 1)
                f[i][j] = 1;
            else if (j & 1)
                f[i][j] = f[i - 1][j / 2] + f[i - 1][j / 2 + 1];
            else
                f[i][j] = f[i - 1][j / 2];
        }
    }
    map<int, vector<int>> v;
    for (int i = 1; i <= 1024; ++i)
    {
        if (f[10][i] != f[9][i])
            break;
        v[f[10][i]].push_back(i);
        // v[f[10][i]].push_back(f[10][i - 1]);
    }
    for (int i = 1; i <= 10; ++i)
    {
        for (auto j : v[i])
        {
            printf("%d ", j);
        }

        puts("------");
    }
    ll p, q, nowa, nowb;
    cin >> p >> q;
    if (q == 1)
    {
        cout << fpow(2, p - 1);
        return 0;
    }
    nowa = fpow(2, q - 1) + 1;
    nowb = fpow(2, q) - 1;
    cout << nowa << " " << nowb << endl;
    for (ll i = 1; i <= p; ++i)
    {
        if (__gcd(i, q) != 1)
            continue;
        if (i == p)
        {
            if (i & 1)
            {
                cout << nowa << endl;
            }
            else
            {
                cout << nowb << endl;
            }
            return 0;
        }
        if (i & 1)
        {
            nowa = nowa * 2 % P;
        }
        else
        {
            nowb = nowb * 2 % P;
        }
        printf("%d: %lld,%lld\n", i, nowa, nowb);
        // q
    }
    return 0;
}