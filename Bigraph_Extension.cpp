#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;
        vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
        set<pii> q;
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            cnt1[x]++;
            cnt2[y]++;
            q.insert(pii(x, y));
        }
        vector<pii> ans;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n && cnt1[i] < 2; ++j)
            {
                if (cnt2[j] < 2 && q.find(pii(i, j)) == q.end())
                {
                    ++cnt1[i];
                    ++cnt2[j];
                    ans.push_back(pii(i, j));
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << n * 2 - m << "\n";
        for (const auto &i : ans)
        {
            cout << i.first << " " << i.second << "\n";
        }
    }
}