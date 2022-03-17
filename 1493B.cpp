#include <bits/stdc++.h>
using namespace std;
int kk[20];

int main()
{
    kk[0] = 0;
    kk[1] = 1;
    kk[2] = 5;
    kk[5] = 2;
    kk[3] = -1;
    kk[4] = -1;
    kk[6] = -1;
    kk[7] = -1;
    kk[8] = 8;
    kk[9] = -1;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int hh, mm;
        scanf("%02d:%02d", &hh, &mm);
        while (1)
        {
            int flag = 1;
            char tmp[10];
            sprintf(tmp, "%02d%02d", hh, mm);
            for (int i = 0; i < 4; ++i)
            {
                if (isdigit(tmp[i]))
                {
                    if (kk[tmp[i] - '0'] < 0)
                    {
                        flag = 0;
                        break;
                    }
                    tmp[i] = kk[tmp[i] - '0'];
                }
            }
            if (flag)
            {
                int tmph = tmp[3] * 10 + tmp[2];
                int tmpm = tmp[1] * 10 + tmp[0];
                // printf("%02d:%02d\n", tmph, tmpm);
                if (tmph < n && tmpm < m)
                {
                    printf("%02d:%02d\n", hh, mm);
                    break;
                }
            }
            mm = mm + 1;
            if (mm == m)
            {
                mm = 0;
                hh = hh + 1;
            }
            if (hh == n)
            {
                hh = 0;
            }
        }
        // puts("-----");
    }

    return 0;
}