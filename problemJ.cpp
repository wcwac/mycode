#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N][N];
char a[N], b[N];
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i)
        a[i + 1] = str[i];
    int n = str.length();
    getline(cin, str);
    int m = str.length();
    for (int i = 0; i < str.length(); ++i)
        b[i + 1] = str[i];

    if (n == 0 || m == 0)
    {
        puts(n == m ? "Yes" : "No");
        return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '*')
        {
            if (f[i - 2][0])
                f[i][0] = 1;
            for (int j = 1; j <= m; ++j)
            {
                if (f[i - 1][j])
                    f[i][j] = 1;
                if (a[i - 1] == b[j] && f[i - 1][j - 1])
                    f[i][j] = 1;
                if (a[i - 1] == b[j] && f[i][j - 1])
                    f[i][j] = 1;
                if (f[i - 2][j])
                    f[i][j] = 1;
            }
        }
        else if (a[i] == '+')
        {
            for (int j = 1; j <= m; ++j)
            {
                if (f[i - 1][j])
                    f[i][j] = 1;
                if (a[i - 1] == b[j] && f[i - 1][j - 1])
                    f[i][j] = 1;
                if (a[i - 1] == b[j] && f[i][j - 1])
                    f[i][j] = 1;
            }
        }
        else
        {
            for (int j = 1; j <= m; ++j)
            {
                if (a[i] == b[j] && f[i - 1][j - 1])
                    f[i][j] = 1;
            }
        }
    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= m; ++j)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (f[n][m] ? "Yes" : "No");
    return 0;
}