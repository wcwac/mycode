#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// ll f[110][5][5][5];

int main()
{
    // memset(f, 0x3f, sizeof f);
    int n;
    cin >> n;
    // f[0][0][0][0] = 0;
    pii ans = pii(1e9, 0);
    for (int i = 1; i <= n; ++i)
    {
        int v;
        string s;
        cin >> v >> s;
        vector<int> cnt(10, 0);
        for (auto j : s)
            ++cnt[j - '0'];
        if (cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 2)
            ans = min(ans, pii(v, i));
        // for (int j = 0; j <= 1; ++j)
        // {
        //     for (int k = 0; k <= 1; ++k)
        //     {
        //         for (int l = 0; l <= 2; ++l)
        //         {
        //             for (int j1 = 0; j1 <= cnt[0] && j + j1 <= 1; ++j1)
        //             {
        //                 for (int k1 = 0; k1 <= cnt[1] && k + k1 <= 1; ++k1)
        //                 {
        //                     for (int l1 = 0; l1 <= cnt[2] && l + l1 <= 2; ++l1)
        //                     {
        //                         f[i][j + j1][k + k1][l + l1] = min(f[i][j + j1][k + k1][l + l1], min(f[i - 1][j + j1][k + k1][l + l1], f[i - 1][j][k][l] + v));
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
    }
    cout << ans.second;
}
