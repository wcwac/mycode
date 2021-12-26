#include <bits/stdc++.h>
using namespace std;
vector<int> v;
const int N = 3e5 + 10;
int a[N], b[N];

int tol, root;     //节点个数
int val[32 * N];   //点的值
int ch[32 * N][2]; //边的值

void insert(int &x, int now, int dep)
{
    if (!x)
        x = ++tol;
    if (dep == 30)
        return void(++val[x]);
    insert(ch[x][now & 1], now >> 1, dep + 1);
}

typedef long long ll;
ll dfs(int x, int now, int dep, int cnt)
{
    if (!x)
        return 0;
    if (dep == 30)
        return cnt == 2 ? val[x] : 0;
    ll ans = 0;
    int v = now & 1;
    if (cnt < 2)
    {
        ans += ch[x][v ^ 1] ? dfs(ch[x][v ^ 1], now >> 1, dep + 1, cnt + 1) : 0;
    }
    ans += ch[x][v] ? dfs(ch[x][v], now >> 1, dep + 1, cnt) : 0;
    return ans;
}

inline int gint()
{
    int ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}

int main()
{
    int n, m;
    n = gint();
    m = gint();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = gint();
    }
    for (int i = 1; i <= m; ++i)
    {
        b[i] = gint();
    }
    for (int i = 1; i <= m; ++i)
    {
        insert(root, b[i], 0);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += dfs(root, a[i], 0, 0);
    }
    cout << ans << endl;
    return 0;
}