#include <bits/stdc++.h>
using namespace std;
const int N = 510;
string str[N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> str[i];
        for (int i = 0, flag = 0; i < n; ++i)
        {
            if (i % 3 == 0)
                flag = 0;
            for (int j = 0; j < m; ++j)
            {
                if (i % 3 == 0)
                    str[i][j] = 'X';
                else if (flag == 0 && str[i][j] == 'X')
                {
                    flag = 1;
                    if (i % 3 == 1)
                        str[i + 1][j] = 'X';
                    if (i % 3 == 2)
                        str[i - 1][j] = 'X';
                }
            }
            if (i % 3 == 2 && i != n && flag == 0)
            {
                str[i - 1][0] = str[i][0] = 'X';
            }
        }
        if (n <= 2)
        {
            for (int i = 0; i < n; ++i)
                cout << str[i] << "\n";
            continue;
        }
        if ((n - 1) % 3 == 2)
        {
            for (int i = 0; i < m; ++i)
            {
                if (str[n - 1][i] == 'X')
                    str[n - 2][i] = 'X';
            }
        }
        for (int i = 0; i < n; ++i)
            cout << str[i] << "\n";
    }

    return 0;
}