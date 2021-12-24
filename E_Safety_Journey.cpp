#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long f[2][5010], sum[2], now = 0;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        v.emplace_back(pair<int, int>(x, y));
    }
    sum[1] = f[1][1] = 1;
    for (int _ = 0; _ < k; ++_, now ^= 1)
    {
        int last = now ^ 1;
        for (int i = 1; i <= n; ++i)
        {
            f[now][i] = (sum[last] - f[last][i] + P) % P;
        }
        for (const auto &i : v)
        {
            f[now][i.first] = (P + f[now][i.first] - f[last][i.second]) % P;
            f[now][i.second] = (P + f[now][i.second] - f[last][i.first]) % P;
        }

        sum[now] = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum[now] = (sum[now] + f[now][i]) % P;
        }
        // for (int i = 1; i <= n; ++i)
        // {
        //     cout << f[now][i] << " ";
        // }
        // cout << ";" << sum[now] << endl;
    }
    cout << f[now ^ 1][1];
    return 0;
}