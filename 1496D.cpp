#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], ans[N], f1[N], f2[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ans[1] = a[1];
    int len = 1, mx = 0;
    f1[1] = f2[1] = 1;
    map<int, int> q;
    for (int i = 2; i <= n; ++i)
    {
        f1[i] = f2[i] = 1;
        if (a[i] > a[i - 1])
        {
            f1[i] += f1[i - 1];
            mx = max(mx, f1[i]);
        }
        else
        {
            f2[i] += f2[i - 1];
            mx = max(mx, f2[i]);
        }
        ++q[f1[i]];
        ++q[f2[i]];
    }
    if (q[mx] != 2 || mx % 2 == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (f1[i] == mx && f2[i] == 1)
        {
            if (i + mx - 1 <= n && f2[i + mx - 1] == mx)
            {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}