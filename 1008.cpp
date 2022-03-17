#include <bits/stdc++.h>
using namespace std;

int f(int n, int m)
{
    int ans = 0;
    vector<int> a, b, s;
    for (int i = 1; i <= n; ++i)
        a.push_back(i);
    do
    {
        for (auto j : a)
            s.push_back(j);
    } while (next_permutation(a.begin(), a.end()));

    for (int i = 1; i <= m; ++i)
        b.push_back(i);
    do
    {
        for (int i = 0; i + m <= s.size(); ++i)
        {
            int flag = 1;
            for (int j = 0; j < m; ++j)
            {
                if (s[i + j] != b[j])
                {
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }
    } while (next_permutation(b.begin(), b.end()));
    return ans;
}
typedef long long ll;
const ll mod = 1e9+7;
ll fac[1000004];
int main()
{
    // int T;
    // cin >> T;
    // while (T--)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     cout << f(a, b) << endl;
    // }
    // cout<<f(3,3);

    fac[0] = 1;
    for (ll i = 1; i <= 10; i++)
        fac[i] = fac[i - 1] * i;
    for (int i = 1; i <= 7; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << f(i, j) - fac[i - j + 1] * fac[j] << " ";
        }
        puts("");
    }
    return 0;
}

