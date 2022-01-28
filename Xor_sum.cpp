#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int tol, root;     //节点个数
int val[32 * N];   //点的值
int ch[32 * N][2]; //边的值

void insert(int *x, int now, int v)
{
    for (int i = 29; i >= 0; --i)
    {
        if (!*x)
        {
            *x = ++tol;
            val[*x] = ch[*x][0] = ch[*x][1] = 0;
        }
        val[*x] = v;
        x = &ch[*x][(now >> i) & 1];
    }
    if (!*x)
    {
        *x = ++tol;
        val[*x] = ch[*x][0] = ch[*x][1] = 0;
    }
    val[*x] = v;
}

int dfs(int x, int dep, int now, int k, int cut)
{
    int ans = -1;
    for (int i = 29; i >= 0; --i)
    {
        if (!x)
            return ans;
        if (val[x] < cut && ans < cut)
            return -1;
        if ((k >> i) & 1)
        {
            x = ch[x][((now >> i) & 1) ^ 1];
        }
        else
        {
            if (ch[x][((now >> i) & 1) ^ 1])
                ans = max(ans, val[ch[x][((now >> i) & 1) ^ 1]]);
            x = ch[x][(now >> i) & 1];
        }
    }
    return max(ans, val[x]);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, now = 0;
        cin >> n >> k;
        root = tol = 0;
        insert(&root, 0, 0);
        int ansl = -1, ansr = n + 1;
        for (int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            now ^= t;
            int l = dfs(root, 0, now, k, i - (ansr - ansl + 1));
            if (l != -1 && (i - l) < (ansr - ansl + 1))
            {
                ansr = i;
                ansl = l + 1;
            }
            insert(&root, now, i);
        }
        if (ansl == -1 && ansr == n + 1)
            cout << "-1" << endl;
        else
            cout << ansl << " " << ansr << endl;
    }
}