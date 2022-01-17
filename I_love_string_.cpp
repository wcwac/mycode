#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i - 1])
            {
                ans = ans * 2 % p;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
}