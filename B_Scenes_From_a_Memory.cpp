#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[N], prime[N], e;
void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime[++e] = i;
            // cout << i << endl;
        }
        for (int j = 1; j <= e && i < N / prime[j]; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        int len;
        string a;
        cin >> len >> a;
        int flag = 0;
        for (int i = 0; i < len; ++i)
        {
            int num = a[i] - '0';
            if (vis[num])
            {
                cout << 1 << endl
                     << num << endl;
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                int num = a[i] - '0';
                num = num * 10 + a[j] - '0';
                if (vis[num])
                {
                    cout << 2 << endl
                         << num << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            continue;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                for (int k = j + 1; k < len; ++k)
                {
                    int num = a[i] - '0';
                    num = num * 10 + a[j] - '0';
                    num = num * 10 + a[k] - '0';
                    if (vis[num])
                    {
                        cout << 3 << endl
                             << num << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
    }
    return 0;
}
