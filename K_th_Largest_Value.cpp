#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main()
{
    int n, T, cnt = 0;
    cin >> n >> T;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], cnt += a[i];
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            if (a[y] == 1)
                --cnt;
            else
                ++cnt;
            a[y] ^= 1;
        }
        else
        {
            cout << (y <= cnt) << endl;
        }
    }
    return 0;
}