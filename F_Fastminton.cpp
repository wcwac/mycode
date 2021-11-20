#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int now = 0, lg = 0, rg = 0, lm = 0, rm = 0;
    for (auto i : s)
    {
        if (i == 'Q')
        {
            if (lm + rm >= 3 || max(lm, rm) >= 2)
            {
                if (lm > rm)
                {
                    printf("%d (winner) - %d\n", lm, rm);
                }
                else
                {
                    printf("%d - %d (winner)\n", lm, rm);
                }
            }
            else if (now == 0)
            {
                printf("%d (%d*) - %d (%d)\n", lm, lg, rm, rg);
            }
            else
            {
                printf("%d (%d) - %d (%d*)\n", lm, lg, rm, rg);
            }
        }
        else if (i == 'S')
        {
            if (now == 0)
                ++lg;
            else
                ++rg;
        }
        else if (i == 'R')
        {
            if (now == 0)
                ++rg;
            else
                ++lg;
            now ^= 1;
        }
        if (max(lg, rg) >= 5)
        {
            if (lg - rg >= 2 || lg == 10)
            {
                ++lm;
                now = 0;
                lg = rg = 0;
            }
            else if (rg - lg >= 2 || rg == 10)
            {
                ++rm;
                now = 1;
                lg = rg = 0;
            }
        }
    }
}