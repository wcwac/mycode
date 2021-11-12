#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
set<int> eg[N];
int vis[N], sz[N];
int fibs[] = {2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229};
void dfs(int x, int fa)
{
    sz[x] = 1;
    for (auto i : eg[x])
    {
        if (i != fa)
        {
            dfs(i, x);
            sz[x] += sz[i];
        }
    }
}
int check(int fi)
{
    queue<int> q;
    vector<int> vec;
    vis[fi] = 1;
    vec.push_back(fi);
    q.push(fi);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : eg[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
                vec.push_back(v);
            }
        }
    }
    for (auto i : vec)
    {
        vis[i] = 0;
    }
    // cout << "\n";
    if (vec.size() <= 3)
        return 1;
    int little = 0, big = 0;
    for (int i = 2; i < 27; ++i)
    {
        if (vec.size() == fibs[i])
        {
            little = fibs[i - 2];
            big = fibs[i - 1];
            break;
        }
    }

    dfs(fi, 0);
    int failcnt = 0;
    for (auto i : vec)
    {
        if (sz[i] == big || sz[i] == little)
        {
            for (auto j : eg[i])
            {
                if (sz[j] > sz[i])
                {
                    eg[i].erase(j);
                    eg[j].erase(i);
                    int res=check(i) + check(fi);
                    eg[i].insert(j);
                    eg[j].insert(i);
                    if (res==2)
                        return 1;
                    // if (res==1)
                    //     return 0;
                    ++failcnt;
                    // if (failcnt == 3)
                    //     return 0;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        eg[x].insert(y);
        eg[y].insert(x);
    }
    int fi = 0;
    for (int i = 1; i < n; ++i)
    {
        if (eg[i].size() == 1)
        {
            fi = i;
        }
    }
    if (!fi)
    {
        puts("NO");
        return 0;
    }
    if (check(fi))
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }

    return 0;
}