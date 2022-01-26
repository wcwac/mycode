#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int read()
{
    int x;
    scanf("%d", &x);
    return x;
}
ll f[210][210], a[210][210], b[210][210], suma, sumb;
int n, m;
ll k;
char c;
void solve()
{
    n = read();
    m = read();
    k = read();
    memset(f, -0x3f, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
            cin >> c;
            b[i][j] = (c == 'Y');
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        suma = 0;
        sumb = 0;
        for (int l = 0; l <= k; l++)
        {
            f[i][l] = f[i - 1][l];
        }
        for (int j = n; j >= 1; j--)
        {
            sumb += 1 - b[i][j];
            suma += a[i][j];

            for (ll l = sumb; l <= k; l++)
                f[i][l] = max(f[i][l], f[i - 1][l - sumb] + suma);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, f[m][k]);
    cout << ans << endl;
}
int main()
{
    //	ios::sync_with_stdio(false);cin.tie(0);
    //	getlist(1e7);
    int t = 1;
    while (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
}
