#include <bits/stdc++.h>
using namespace std;
map<int, int> q;
int ans = 1e9;
void dfs(int now, int nowc)
{
    if (nowc > ans)
        return;
    if (now == 7)
    {
        ans = min(ans, nowc);
        return;
    }
    for (auto i : q)
    {
        if ((i.first | now) != now)
        {
            dfs((i.first | now), nowc + i.second);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y = 0;
        string str;
        cin >> x >> str;
        for (auto i : str)
        {
            if (i == 'A')
                y |= 1;
            if (i == 'B')
                y |= 2;
            if (i == 'C')
                y |= 4;
        }
        if (q[y])
            q[y] = min(q[y], x);
        else
            q[y] = x;
    }
    dfs(0, 0);
    if (ans == 1e9)
    {
        cout << "-1";
        return 0;
    }
    cout << ans;
}