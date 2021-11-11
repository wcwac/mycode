#include <bits/stdc++.h>
using namespace std;
int s, l, n;

string sname[210];
unordered_map<string, int> id;

int tt[210][210];

int str[100010], last[210];

vector<int> eg[100010];
int sz[100010];
typedef pair<string, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;
int main()
{
    cin >> s >> l >> n;
    for (int i = 1; i <= s; ++i)
    {
        cin >> sname[i];
        id[sname[i]] = i;
    }
    for (int i = 1; i <= l; ++i)
    {
        string x, y;
        cin >> x >> y;
        tt[id[x]][id[y]] = tt[id[y]][id[x]] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        string tmp;
        cin >> tmp;
        str[i] = id[tmp];
        for (int j = 1; j <= s; ++j)
        {
            if (last[j] != i && last[j] != 0 && (!tt[j][str[i]]))
            {
                //cout << last[j] << " to " << i << endl;
                eg[last[j]].push_back(i);
                ++sz[i];
            }
        }
        last[str[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!sz[i])
            q.push({ sname[str[i]], i });
    }
    while (!q.empty())
    {
        int u = q.top().second;
        cout << q.top().first << " ";
        q.pop();
        for (auto i : eg[u])
        {
            if (--sz[i] == 0) {
                q.push({ sname[str[i]],i });
            }
        }
    }

    return 0;
}