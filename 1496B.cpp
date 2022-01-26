#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, ma = -1;
        cin >> n >> k;
        set<int> a;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            a.insert(x);
            ma = max(ma, x);
        }
        int mi = 0, cnt = 0;
        while (a.find(mi) != a.end())
        {
            ++mi;
            ++cnt;
        }
        if (k == 0)
        {
            cout << a.size() << "\n";
        }
        while (k--)
        {
            int t = (mi + ma + 1) / 2;
            a.insert(t);
            if (t == ma + 1)
            {
                cout << a.size() + k << "\n";
                break;
            }
            // cout << "ins" << t << endl;
            ma = max(t, ma);
            if (t != mi)
            {
                cout << a.size() << "\n";
                break;
            }
            ++mi;
            while (a.find(mi) != a.end())
            {
                ++mi;
            }
        }
    }

    return 0;
}