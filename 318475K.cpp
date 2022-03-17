#include <bits/stdc++.h>
using namespace std;
int cnt[10], tmpcnt[10];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, N;
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d%d", &a, &b, &N);
        long long x = 1;
        while (x * x * a + x * b <= N)
        {
            // cout << x << endl;
            int mx = 0;
            int tmp = x * x * a + x * b;
            memset(tmpcnt, 0, sizeof tmpcnt);
            while (tmp)
            {
                mx = max(mx, ++tmpcnt[tmp % 10]);
                tmp /= 10;
            }
            for (int i = 0; i < 10; ++i)
            {
                if (tmpcnt[i] == mx)
                {
                    ++cnt[i];
                }
            }
            ++x;
        }
        int mx = 0;
        for (int i = 0; i <= 9; ++i)
        {
            mx = max(mx, cnt[i]);
        }
        if (!mx)
        {
            puts("-1");
            continue;
        }
        for (int i = 0; i <= 9; ++i)
        {
            if (cnt[i] == mx)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}