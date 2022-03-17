#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> s[i];
            if (s[i] & 1)
                ++cnt1;
            else
                ++cnt2;
        }
        if (abs(cnt1 - cnt2) >= 2)
        {
            puts("-1");
            continue;
        }
        long long ans1 = 1e18;
        if (cnt1 >= cnt2)
        {
            ans1 = 0;
            int now = 0;
            for (int i = 0; i < n; ++i)
            {
                if (s[i] & 1)
                {
                    ans1 += abs(i - now);
                    now += 2;
                }
            }
        }
        long long ans2 = 1e18;
        if (cnt1 <= cnt2)
        {
            ans2 = 0;
            int now = 0;
            for (int i = 0; i < n; ++i)
            {
                if (!(s[i] & 1))
                {
                    ans2 += abs(i - now);
                    now += 2;
                }
            }
        }
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}