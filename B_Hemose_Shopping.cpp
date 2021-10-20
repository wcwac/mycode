#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n), v1(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            v1[i] = v[i];
        }
        sort(v1.begin(), v1.end());
        int flag = 1;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != v1[i])
            {
                if (max(i, n - 1 - i) < x)
                    flag = 0;
            }
        }
        puts(flag ? "YES" : "NO");
    }
}