#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dist[N], visited[N];
vector<int> edge[N];
int n;
pair<int, int> dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        for (auto v : edge[u])
        {
            if (!visited[v] && dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    pair<int, int> ans(0, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (ans.first == dist[i])
        {
            if ((rand() & 4) == 1)
            {
                ans.second = i;
            }
        }
        else
        {
            ans = max(ans, pair<int, int>(dist[i], i));
        }
    }

    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int m;
    cin >> n >> m;
    srand(m);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= 200; ++i)
    {
        auto k = dijkstra(rand() % (n - 1) + 1);
        if (k.first > 1e9)
            return puts("-1"), 0;
        k = dijkstra(k.second);
        ans = max(ans, k.first);
    }

    int t = 0, tt = 1;
    while (ans > tt)
    {
        ++t;
        tt <<= 1;
    }
    cout << t << endl;
    return 0;
}