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
        stack<int> p, q;
        vector<int> v, ans;
        map<int, int> flag;
        for (int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            p.push(x);
            v.push_back(x);
            ++flag[x];
        }
        sort(v.begin(), v.end(), greater<int>());
        for (auto i : v)
        {
            if (!flag[i])
                continue;
            while (p.top() != i)
            {
                --flag[p.top()];
                q.push(p.top());
                p.pop();
            }
            ans.push_back(p.top());
            p.pop();
            while (!q.empty())
            {
                ans.push_back(q.top());
                q.pop();
            }
            if (p.empty())
                break;
        }
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}