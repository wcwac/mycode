#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int check(int x)
{
    int ans = 0;
    typedef pair<int, int> pii;
    set<int> q, r;
    map<int, int> p;
    int t = 0;
    for (auto i : a)
    {
        if (q.find(i) != q.end())
        {
            int id = p[i];
            p[i] = t;
            r.erase(id);
            r.insert(t);
            ++ans;
        }
        else
        {
            if (q.size() >= x)
            {
                int id = *r.begin();
                r.erase(id);
                q.erase(a[id]);
            }
            q.insert(i);
            p[i] = t;
            r.insert(t);
        }
        ++t;
    }
    return ans;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int l = 1, r = n + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) >= k)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (l == n + 1)
    {
        puts("cbddl");
    }
    else
    {
        cout << l << endl;
    }
}