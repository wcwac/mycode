#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, u, d, l, r, flag = 0;
        cin >> n >> u >> r >> d >> l;
        for (int lu = 0; lu <= 1; ++lu)
        {
            for (int ld = 0; ld <= 1; ++ld)
            {
                for (int rd = 0; rd <= 1; ++rd)
                {
                    for (int ru = 0; ru <= 1; ++ru)
                    {
                        if (lu + ru > u || ld + rd > d || lu + ld > l || ru + rd > r)
                            continue;
                        if (u - lu - ru > n - 2)
                            continue;
                        if (d - ld - rd > n - 2)
                            continue;
                        if (l - lu - ld > n - 2)
                            continue;
                        if (r - ru - rd > n - 2)
                            continue;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }

    return 0;
}