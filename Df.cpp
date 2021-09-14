#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const double pi = atan(1.) * 4.;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int M = 63;
const int N = 1e5 + 5;
struct fun
{
    bitset<270> bit;
} tree[N << 2], v[N << 2];

void sett(int l, int r, int rt)
{ // 建树
    if (l == r)
    {
        tree[rt].bit = 0;
        return;
    }
    int mid = l + r >> 1;
    sett(l, mid, rt << 1);
    sett(mid + 1, r, rt << 1 | 1);
    tree[rt].bit = (tree[rt << 1].bit | tree[rt << 1 | 1].bit);
}

void fun(int l, int r, int rt)
{ // 下推
    if (v[rt].bit.count())
    { // 统计 bit 中 1 的个数
        v[rt << 1].bit = v[rt].bit;
        v[rt << 1 | 1].bit = v[rt].bit;
        tree[rt << 1].bit = tree[rt].bit;
        tree[rt << 1 | 1].bit = tree[rt].bit;
        v[rt].bit = 0; // 记得清零
    }
}

void upset(int x, int y, int vel, int l, int r, int rt)
{
    if (x <= l && y >= r)
    {
        v[rt].bit.set(vel);
        tree[rt].bit = 0;
        tree[rt].bit.set(vel);
        return;
    }
    fun(l, r, rt);
    int mid = l + r >> 1;
    if (x <= mid)
        upset(x, y, vel, l, mid, rt << 1);
    if (y > mid)
        upset(x, y, vel, mid + 1, r, rt << 1 | 1);
    tree[rt].bit = (tree[rt << 1].bit | tree[rt << 1 | 1].bit);
}
bitset<270> bb(0);
void findd(int x, int y, int l, int r, int rt)
{
    if (x <= l && y >= r)
    {
        bb |= tree[rt].bit;
        return;
    }

    fun(l, r, rt);
    int mid = l + r >> 1;
    if (x <= mid)
        findd(x, y, l, mid, rt << 1);
    if (y > mid)
        findd(x, y, mid + 1, r, rt << 1 | 1);
}
int main()
{
    int n, m, k, a, b, c;
    scanf("%d %d %d", &n, &m, &k);
    sett(1, n, 1);
    char s[20];
    getchar();
    int leap = 0;
    while (m--)
    {
        scanf(" %s", s);
        if (s[0] == 'Q')
        {
            leap = 1;
            scanf("%d %d", &a, &b);
            bb = 0;
            findd(a, b, 1, n, 1);
            printf("%d\n", bb.count());
        }
        else
        {
            scanf("%d %d %d", &a, &b, &c);
            upset(a, b, c, 1, n, 1);
        }
    }
    if (!leap)
        printf("This is a boring game!\n");
    return 0;
}