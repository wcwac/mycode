#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    NODE *l, *r, *u, *d;
    int x, y;
} e[100010], *hd[510];
int tot, sz[510];
int n, m;
void build()
{
    for (tot = 1; tot <= m; ++tot)
    {
        e[tot].l = &e[tot - 1];
        e[tot].r = &e[tot + 1];
        e[tot].u = e[tot].d = &e[tot];
        e[tot].y = tot;
    }
    e[m].r = &e[0];
    e[0].l = &e[m];
    e[0].r = &e[1];
    e[0].u = e[0].d = &e[0];
}
void insert(int x, int y)
{
    ++sz[y];
    e[tot].x = x, e[tot].y = y;
    e[tot].d = e[y].d, e[tot].u = &e[y];
    e[y].d = e[y].d->u = &e[tot];
    if (hd[x])
    {
        e[tot].l = hd[x]->l, e[tot].r = hd[x];
        hd[x]->l = hd[x]->l->r = &e[tot];
    }
    else
        hd[x] = e[tot].l = e[tot].r = &e[tot];
    ++tot;
}
void del(int y)
{
    e[y].l->r = e[y].r;
    e[y].r->l = e[y].l;
    for (NODE *i = e[y].d; i != &e[y]; i = i->d)
        for (NODE *j = i->r; j != i; j = j->r)
            j->u->d = j->d, j->d->u = j->u, --sz[j->y];
}

void rec(int y)
{
    for (NODE *i = e[y].u; i != &e[y]; i = i->u)
        for (NODE *j = i->l; j != i; j = j->l)
            ++sz[j->y], j->u->d = j->d->u = j;
    e[y].l->r = e[y].r->l = &e[y];
}
int ans[510];
void dance(int dep)
{
    if (e[0].r == &e[0])
    {
        for (int i = 0; i < dep; ++i)
            printf("%d ", ans[i]);
        exit(0);
    }
    int c = e[0].r->y;
    for (NODE *i = e[0].r; i != &e[0]; i = i->r)
        if (sz[i->y] < sz[c])
            c = i->y;
    del(c);
    for (NODE *i = e[c].d; i != &e[c]; i = i->d)
    {
        for (NODE *j = i->r; j != i; j = j->r)
            del(j->y);
        ans[dep] = i->x;
        dance(dep + 1);
        for (NODE *j = i->l; j != i; j = j->l)
            rec(j->y);
    }
    rec(c);
}

int _n, _m;
map<int, vector<int>> q[250010];
int main()
{
    cin >> _n >> _m;
    for (int i = 1; i <= _n; ++i)
    {
        for (int j = 1; j <= _m; ++j)
        {
            int x;
            cin >> x;
            q[j][x].push_back(i);
        }
    }
    m = _n + 1;
    build()
    for 


    return 0;
}