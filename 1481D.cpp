#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N][N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> s[i] + 1;
        }
        if (m & 1 || (n == 2 && s[1][2] == s[2][1]))
        {
            puts("YES");
            for (int i = 1; i <= m + 1; ++i)
            {
                if (i & 1)
                    cout << "1 ";
                else
                    cout << "2 ";
            }
            puts("");
        }
        else
        {
            if (n == 2 && s[1][2] != s[2][1])
            {
                puts("NO");
            }
            else
            {
                puts("YES");
                int x = 1, y = 2, z = 3;
                if (s[y][z] == s[z][x])
                {
                    x = 2, y = 3, z = 1;
                }
                else if (s[z][x] == s[x][y])
                {
                    x = 3, y = 1, z = 2;
                }
                deque<int> q;
                q.push_back(x);
                q.push_back(y);
                q.push_back(z);
                m -= 2;
                int now = 1;
                while (m)
                {
                    if (now)
                    {
                        q.push_front(z);
                        q.push_back(x);
                        m -= 2;
                    }
                    else
                    {
                        q.push_front(x);
                        q.push_back(z);
                        m -= 2;
                    }
                    now ^= 1;
                }
                for (auto i : q)
                    cout << i << " ";
                puts("");
            }
        }
    }

    return 0;
}