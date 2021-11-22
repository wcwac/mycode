#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        // cout << s << endl;
        int flag = 0;
        for (int i = 1; i * 2 <= n; ++i)
        {
            if (s[i - 1] == '0')
            {
                printf("%d %d %d %d\n", i, n, i + 1, n);
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = n / 2; i <= n; ++i)
        {
            if (s[i - 1] == '0')
            {
                printf("%d %d %d %d\n", 1, i, 1, i - 1);
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        printf("%d %d %d %d\n", 1, n / 2, 2, n / 2 + 1);
    }

    return 0;
}