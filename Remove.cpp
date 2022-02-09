#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e6 + 10;
int f[N], n;
int p[N], cntp;

void dfs(int x, int now)
{
    for (int i = 0; i < cntp; ++i)
    {
        if (x + p[i] > n)
            return;
        if (f[x + p[i]] == -1)
            dfs(x + p[i], f[x + p[i]] = now + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        // cin >> n >> cntp;
        // for (int i = 0; i < cntp; ++i)
        // {
        //     cin >> p[i];
        // }
        // sort(p, p + cntp);
        // for (int i = 1; i <= n; ++i)
        // {
        //     f[i] = -1;
        // }
        // dfs(0, 0);
        int n, p;
        cin >> n >> p;
        vector<int> v;
        int flag = 1;
        for (int i = 0, x; i < p; ++i)
        {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<int>());
        unsigned long long now = 1;
        for (auto i : v)
        {
            now *= i;
            if (now > n)
                break;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == now)
                f[i] = 0;
            else if (i % v[0] == 0)
            {
                f[i] = i / v[0] + 2;
            }
            else
            {
                f[i] = i / v[0] + 1;
            }
        }

        unsigned long long ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            cout << i << ":" << f[i] << endl;
            ans *= 23333;
            if (f[i] != -1)
                ans += f[i];
        }
        cout << ans << endl;
    }
}