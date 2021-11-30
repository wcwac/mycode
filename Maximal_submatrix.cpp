#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;

int s[N][N];
int f[N][N];
int l[N], r[N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        long long ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cin >> s[i][j];
                f[i][j] = s[i][j] >= s[i - 1][j] ? f[i - 1][j] + 1 : 1;
                l[j] = r[j] = j;
            }
            for (int j = 1; j <= m; j++)
                while (l[j] > 1 && f[i][j] <= f[i][l[j] - 1])
                    l[j] = l[l[j] - 1];
            for (int j = m; j >= 1; j--)
                while (r[j] < m && f[i][j] <= f[i][r[j] + 1])
                    r[j] = r[r[j] + 1];
            for (int j = 1; j <= m; j++)
                ans = max(ans, (long long)(r[j] - l[j] + 1) * f[i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}