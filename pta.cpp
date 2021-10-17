#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
typedef long long ll;
int n, m;
ll a[N][N];
ll sum[N][N];
ll ans = 0, now = 0;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    int ans = -1e9, aa, bb, cc, dd;
    for (int a = 1; a <= n; ++a)
    {
        for (int b = 1; b <= m; ++b)
        {
            for (int c = a; c <= n; ++c)
            {
                for (int d = b; d <= m; ++d)
                {
                    int now = sum[c][d] + sum[a - 1][b - 1] - sum[c][b - 1] - sum[a - 1][d];
                    if (now > ans)
                    {
                        ans = now;
                        aa = a;
                        bb = b;
                        cc = c;
                        dd = d;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    cout << aa << " " << bb << " " << cc << " " << dd;
    return 0;
}