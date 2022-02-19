#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int s[11][N];
int pos[11][N];
int vis[N];
long long ans = 0;
int main()
{
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> s[i][j];
            pos[i][s[i][j]] = j;
        }
    }
    for (int l = 1, r = 0; l <= n; l = r + 1)
    {
        int now[11];
        for (int i = 1; i <= m; ++i)
        {
            now[i] = pos[i][s[1][l]];
        }
        r = l;
        while (r + 1 <= n)
        {
            int flag = 1;
            int next = s[1][r + 1];
            for (int i = 1; i <= m; ++i)
            {
                if (pos[i][next] != now[i] + 1)
                {
                    // cout << i << " " << pos[i][next] << " " << now[i] + 1 << endl;
                    flag = 0;
                    break;
                }
                ++now[i];
            }
            if (flag)
            {
                ++r;
            }
            else
            {
                break;
            }
        }
        // cout << l << " " << r << endl;
        int j = r - l + 1;
        ans += 1ll * (j + 1) * j / 2;
    }
    cout << ans << endl;
    return 0;
}