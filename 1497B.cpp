#include <iostream>
#include <map>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        map<int, int> q, p;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            ++q[x % m];
        }
        int ans = 0;
        for (auto i : q)
        {
            int a = i.first, b = (m - i.first) % m;
            if (p[a])
                continue;
            p[a] = p[b] = 1;
            if (a == b)
            {
                ++ans;
                continue;
            }
            int qa = q[a], qb = q[b];
            if (qa > qb)
                swap(qa, qb);
            ans += 1;
            ans += max(0, qb - 1 - qa);
        }
        cout << ans << endl;
    }

    return 0;
}