#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[6], b[6];
    for (int i = 0; i < 6; ++i)
        cin >> a[i];
    for (int i = 0; i < 6; ++i)
        cin >> b[i];
    int cnt = 0;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (a[i] > b[j])
                ++cnt;
        }
    }
    if (!cnt)
    {
        cout << 0 << endl;
        return 0;
    }
    int t = __gcd(36, cnt);
    cout << cnt / t << "/" << 36 / t << endl;
}