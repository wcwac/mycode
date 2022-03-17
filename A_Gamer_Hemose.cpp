#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> q;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        sort(q.begin(), q.end(), greater<int>());
        int t = q[0] + q[1];
        int x = k / t, y = k % t;
        if (y == 0)
        {
            cout << 2 * x << endl;
        }
        else if (y <= q[0])
        {
            cout << 2 * x + 1 << endl;
        }
        else
        {
            cout << 2 * x + 2 << endl;
        }
    }
}