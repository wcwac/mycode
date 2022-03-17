#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, p = 1e9 + 7;
long long f[N][2];

// int f(int x)
// {
//     if (x == 1)
//         return 1;
//     if (x == 2)
//         return 2;
// }

int main()
{
    int n;
    cin >> n;
    f[0][0] = f[1][1] = 1;
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        f[i][0] = (f[i - 1][1] * 2 + f[i - 1][0] + f[i - 1][1]) % p;
        f[i][1] = f[i - 1][1] * 2 % p;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        cout << f[i][0] << " " << f[i][1] << endl;
        // ans=(ans+f[i][]
    }
    // cout << f(n);
    return 0;
}