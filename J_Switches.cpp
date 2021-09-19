#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 505;
int n;
int a[N][N << 1];

bool Gauss()
{
    for (int i = 1, r; i <= n; i++)
    {
        r = i;
        for (int j = i + 1; j <= n; j++)
            if (a[j][i] > a[r][i])
                r = j;
        if (r != i)
            swap(a[i], a[r]);
        if (!a[i][i])
            return false;
        for (int k = 1; k <= n; k++)
        {
            if (k == i || !a[k][i])
                continue;
            for (int j = i; j <= (n << 1); j++)
                a[k][j] = a[k][j] ^ a[i][j];
        }
    }
    return true;
}

int inv[N][N];
int ans[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i][i + n] = 1;
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    }
    if (Gauss())
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                inv[i - 1][j - 1] = a[i][j + n];
        for (int now = 0; now < n; now++)
        {
            for (int i = 0; i < n; ++i)
            {
                ans[i][0] = 0;
                for (int k = 0; k < n; ++k)
                    ans[i][0] = (ans[i][0] ^ (inv[i][k] & (k == now)));
            }
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                if (ans[j][0])
                    tmp.push_back(j + 1);
            for (int i = 0; i < tmp.size(); ++i)
                cout << tmp[i] << (i == tmp.size() - 1 ? "\n" : " ");
        }
    }
    else
        puts("-1");

    return 0;
}