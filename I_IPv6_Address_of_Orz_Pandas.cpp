#include <bits/stdc++.h>
using namespace std;
__uint128_t geti(string s)
{
    __uint128_t ans = 0;
    for (auto i : s)
        ans = ans * 10 + i - '0';
    return ans;
}
int main()
{
    string str;
    while (cin >> str)
    {
        if (str == "0")
        {
            puts("::");
            continue;
        }
        __uint128_t now = geti(str);
        vector<int> s(8);
        for (int i = 7; i >= 0; --i)
        {
            s[i] = now & 65535;
            now >>= 16;
        }
        int l, r, len = 0, pass = 0;
        // while (s[pass] == 0)
        //     ++pass;
        for (int i = 0; i < 8; ++i)
        {
            if (!s[i])
            {
                int tmp = i;
                while (i + 1 < 8 && s[i + 1] == 0)
                    ++i;
                if (i - tmp + 1 >= len)
                {
                    len = i - tmp + 1;
                    r = i;
                    l = tmp;
                }
            }
        }
        if (len > 1)
        {
            if (l == 0)
                printf(":");
            for (int i = 0; i < l; ++i)
                printf("%x:", s[i]);
            printf(":");
            if (r == 7)
            {
                printf("\n");
            }
            else
            {
                for (int i = r + 1; i < 8; ++i)
                    printf("%x%c", s[i], (i == 7 ? '\n' : ':'));
            }
        }
        else
        {
            for (int i = 0; i < 8; ++i)
                printf("%x%c", s[i], (i == 7 ? '\n' : ':'));
        }
    }
}
