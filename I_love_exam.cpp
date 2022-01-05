#include <bits/stdc++.h>
using namespace std;
string s[51];
map<string, int> q;
typedef pair<int, int> pii;
vector<pii> a[51];
int f1[51][510];
int f2[510][51][4];
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
    {
        memset(f1, 0, sizeof f1);
        memset(f2, -0x3f, sizeof f2);
        q.clear();
        int n, m, t, p;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> s[i];
            q[s[i]] = i;
            a[i].clear();
        }
        cin >> m;
        for (int i = 1; i <= m; ++i)
        {
            string tmp;
            int x, y;
            cin >> tmp >> x >> y;
            a[q[tmp]].emplace_back(x, y);
        }
        cin >> t >> p;
        for (int i = 1; i <= n; ++i)
        {
            for (auto j : a[i])
            {
                for (int k = t; k >= j.second; --k)
                {
                    f1[i][k] = min(100, max(f1[i][k], f1[i][k - j.second] + j.first));
                }
            }
        }
        f2[0][0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = t; j >= 0; --j)
            {
                for (int k = t; j <= k; --k)
                {
                    for (int g = 0; g <= p; ++g)
                    {
                        if (f1[i][j] >= 60)
                        {
                            f2[k][i][g] = max(f2[k][i][g], f2[k - j][i - 1][g] + f1[i][j]);
                        }
                        else if (g)
                        {
                            f2[k][i][g] = max(f2[k][i][g], f2[k - j][i - 1][g - 1] + f1[i][j]);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i <= p; ++i)
            ans = max(ans, f2[t][n][i]);
        cout << ans << endl;
    }
    return 0;
}