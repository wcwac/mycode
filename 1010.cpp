#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2010;
int fa[N];
int ask(int x)
{
    return fa[x] == x ? x : fa[x] = ask(fa[x]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        long long n, m;
        cin >> n >> m;
        for (int i = 1; i <= n + n; ++i)
            fa[i] = i;
        vector<int> cnt1(n + 1, 0), cnt2(n + 1, 0);
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            cnt1[x]++;
            cnt2[y]++;
            fa[ask(x)] = ask(y + n);
        }
        int cnt = n * 2 - m;
        vector<pii> ans;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n && cnt1[i] < 2; ++j)
            {
                if (cnt2[j] < 2)

                {
                    if (cnt == 1 || ask(i) != ask(j + n))
                    {
                        ++cnt1[i];
                        ++cnt2[j];
                        fa[ask(i)] = ask(j + n);
                        ans.push_back(pii(i, j));
                        --cnt;
                    }
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