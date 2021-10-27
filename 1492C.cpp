#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int l[N], r[N];
int main()
{
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int now = 0;
    for (int i = 0; i < m; ++i)
    {
        while (a[now] != b[i])
            ++now;
        l[i] = now;
        ++now;
    }

    now = n - 1;
    for (int i = m - 1; i >= 0; --i)
    {
        while (a[now] != b[i])
            --now;
        r[i] = now;
        --now;
    }
    // for (int i = 0; i < m; ++i)
    // {
    //     cout << l[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < m; ++i)
    // {
    //     cout << r[i] << " ";
    // }
    // cout << endl;
    int ans = 0;
    for (int i = 1; i < m; ++i)
    {
        ans = max(ans, r[i] - l[i - 1]);
    }
    cout << ans << endl;
    return 0;
}