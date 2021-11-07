#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int f(int n, vector<pii> a, vector<pii> b)
{
    set<pii> q;
    for (auto i : b)
    {
        q.insert(pii(i.first, i.second));
        q.insert(pii(i.second, i.first));
    }
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;
    do
    {
        int flag = 1;
        for (auto i : a)
        {
            if (q.find(pii(v[i.first - 1], v[i.second - 1])) == q.end())
            {
                flag = 0;
                break;
            }
        }
        ans += flag;
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m1, m2;
    while (cin >> n >> m1 >> m2)
    {
        vector<pii> e1(m1), e2(m2);
        for (int i = 0; i < m1; ++i)
            cin >> e1[i].first >> e1[i].second;
        for (int i = 0; i < m2; ++i)
            cin >> e2[i].first >> e2[i].second;
        cout << f(n, e1, e2) / f(n, e1, e1) << "\n";
    }
    return 0;
}