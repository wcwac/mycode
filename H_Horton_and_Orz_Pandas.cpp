#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
struct Edge
{
    int u, v, a, b, flag = 0;
};

bool cmp(Edge x, Edge y)
{
    return x.a * y.b > y.a * x.b;
}

int fa[N];

int ask(int x)
{
    return fa[x] == x ? x : fa[x] = ask(fa[x]);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        vector<Edge> eg(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> eg[i].u >> eg[i].v >> eg[i].b >> eg[i].a;
        }
        sort(eg.begin(), eg.end(), cmp);
        long long ansa = 0, ansb = 0;
        for (auto &i : eg)
        {
            int fu = ask(i.u), fv = ask(i.v);
            if (fu != fv || i.a * ansb > i.b * ansa)
            {
                fa[fu] = fv;
                ansa += i.a;
                ansb += i.b;
                i.flag = 1;
            }
        }
        // cout << ansa << " " << ansb << endl;
        // ;
        printf("%.15f\n", (double)(1.0l * ansa / ansb));
    }
    return 0;
}