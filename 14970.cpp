#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> q, p;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        sort(q.begin(), q.end());
        int now = 0;
        for (auto i : q)
        {
            if (i == now)
            {
                cout << now << " ";
                ++now;
            }
            else
            {
                p.push_back(i);
            }
        }
        for (auto i : p)
            cout << i << " ";
        puts("");
    }

    return 0;
}