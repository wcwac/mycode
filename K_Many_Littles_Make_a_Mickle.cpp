#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        long long ans = 0;
        for (long long i = 1; i <= n; ++i)
        {
            ans += i * i;
        }
        cout << ans * m << endl;
    }
}