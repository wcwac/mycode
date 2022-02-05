#include <bits/stdc++.h>
using namespace std;
int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        int n, m, mx = 0;
        cin >> n >> m;
        map<int, int> a;
        vector<int> b;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            ++a[x];
            mx = max(mx, x);
        }
        for (int i = 1; i <= m; ++i)
        {
            int x;
            cin >> x;
            b.emplace_back(x);
        }
        sort(b.begin(), b.end(), greater<int>());
        for (auto i : b)
        {
            // cout << i << ":";
            for (int j = mx; j >= 1; j >>= 1)
            {
                while ((i >= j) && a[j])
                {
                    i -= j;
                    --a[j];
                    // cout << j << " ";
                }
            }
            while (mx && !a[mx])
                mx >>= 1;
            // cout << endl;
        }
        int flag = 1;
        for (auto i : a)
        {
            if (i.second)
            {
                flag = 0;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
}