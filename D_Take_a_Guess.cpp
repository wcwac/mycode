#include <bits/stdc++.h>
using namespace std;

int ask_and(int x, int y)
{
    printf("and %d %d\n", x, y);
    fflush(stdout);
    int n;
    scanf("%d", &n);
    return n;
}
int ask_or(int x, int y)
{
    printf("or %d %d\n", x, y);
    fflush(stdout);
    int n;
    scanf("%d", &n);
    return n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ans(n, 0);
    a[0] = ask_and(1, n);
    b[0] = ask_or(1, n);
    for (int i = 1; i < n; ++i)
    {
        a[i] = ask_and(i, i + 1);
        b[i] = ask_or(i, i + 1);
    }
    for (int i = 0; i < 31; ++i)
    {
        int j = 1 << i;
        int flag = 1, now = j;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] & j)
            {
                if (now == 0)
                {
                    flag = 0;
                    break;
                }
            }
            else if (b[i] & j)
            {
                now ^= j;
            }
            else
            {
                if (now != 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if ((now & j) == (a[0] & j) && (now | j) == (b[0] & j))
        {
        }
        else
        {
            flag = 0;
        }
        if (flag)
        {
            ans[0] |= j;
        }
        now = flag ? j : 0;
        // printf("%d\n", flag != 0);
        for (int i = 1; i < n; ++i)
        {
            if (a[i] & j)
            {
            }
            else if (b[i] & j)
            {
                now ^= j;
            }
            else
            {
            }
            ans[i] |= now;
        }
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << ans[i] << ",";
    // }
    // cout << endl;
    // for (int i = 1; i < n; ++i)
    // {
    //     printf("%d ", ans[i - 1] & ans[i]);
    //     printf("%d \n", ans[i - 1] | ans[i]);
    // }
    // typedef pair<int, int> pii;
    // vector<pii> vvv;
    // for (int i = 0; i < n; ++i)
    // {
    //     vvv.push_back(pii(ans[i], i + 1));
    // }
    sort(ans.begin(), ans.end());
    cout << "finish " << ans[k - 1] << endl;
    return 0;
}