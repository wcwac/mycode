#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> eg[N];
typedef pair<int, int> pii;
// vector<pii> eg;

int depth[N], col[N];

pii find_max(int u, int fa, int nowcol)
{
    depth[u] = depth[fa] + 1;
    pii ans = pii(depth[u], u);
    for (auto v : eg[u])
    {
        if (col[v] == nowcol && v != fa)
        {
            ans = max(ans, find_max(v, u, nowcol));
        }
    }
    return ans;
}

pii find_mid(int u,int fa,int target,int nowcol){
    if (u==target) return pii(1,0);
    for (auto v:eg[u]){
        if (col[v] == nowcol && v != fa)
        {
            auto t=find_mid(v,u,target,nowcol);
            if (t.first==1){
                if (depth[u]==depth[target]/2)
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        eg[u].push_back(v);
        eg[v].push_back(u);
        // eg.push_back(pii(u, v));
    }
    cout << "? " << n;
    for (int i = 1; i <= n; ++i)
    {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();
    int ans = 0;
    cin >> ans;
    int a = 0;
    for (int i = 0; i < 10; ++i)
    {
        set<int> q;
        for (int j = 0; j < eg.size(); ++j)
        {
            if (j & (1 << i))
            {
                q.insert(eg[j].first);
                q.insert(eg[j].second);
            }
        }
        if (q.size() == 0)
            break;
        cout << "? " << q.size();
        for (auto j : q)
            cout << " " << j;
        cout << endl;
        cout.flush();
        int t;
        cin >> t;
        if (t == ans)
            a |= (1 << i);
    }
    cout << "! " << eg[a].first << " " << eg[a].second << endl;
    cout.flush();
}