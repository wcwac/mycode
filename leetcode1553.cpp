#include <bits/stdc++.h>
using namespace std;
int a[100010];
int check(int x)
{
    int cnt = 0;
    if (__builtin_popcount(x) == 1)
    {
        while (x)
            ++cnt, x /= 2;
        return cnt;
    }
    while (x)
    {
        if (x % 3 == 0)
            x /= 3;
        else if (x % 3 == 1)
        {
            --x;
        }
        else if ((x & 1) == 0)
        {
            x /= 2;
        }
        else
            --x;

        ++cnt;
    }
    return cnt;
}
int main()
{
    int n = 100;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = a[i - 1] + 1;
        if ((i & 1) == 0)
            a[i] = min(a[i], a[i >> 1] + 1);
        if ((i % 3) == 0)
            a[i] = min(a[i], a[i / 3] + 1);
        // if (a[i] != check(i))
        // {
        //     printf("%d: a[i]=%d  check(i)=%d\n", i, a[i], check(i));
        //     break;
        // }
        printf("%d: %d\n", i, a[i]);
    }

    return 0;
}