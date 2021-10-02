#include <bits/stdc++.h>
using namespace std;

struct node
{
    int cnt;
    node *child[2];
};

node *insert(node *x, int y)
{
    node *ret = new node(*x), *now = ret;
    for (int depth = 0; depth < 17; ++depth, y >>= 1)
    {
        ++now->cnt;
        now = now->child[y & 1] = new node(*(now->child[y & 1]));
    }
    return ret;
}
const int N = 1e5 + 10;
int a[N];
node *root[N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n;
    root[0] = new node;
    root[0]->child[0] = root[0]->child[1] = root[0];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        root[i] = insert(root[i - 1], a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        cout << query(root[l - 1], root[r], a, b);
    }
    return 0;
}