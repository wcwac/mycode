#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int s[N << 4];
void update(int x, int l, int r, int ll, int rr)
{
    // cout << x << "," << l << "," << r << endl;
    if (s[x])
        return;
    if (ll <= l && rr >= r)
    {
        s[x] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid)
        update(x << 1, l, mid, ll, rr);
    if (rr > mid)
        update((x << 1) | 1, mid + 1, r, ll, rr);
}
int query(int x, int l, int r)
{
    // cout << x << "," << l << "," << r << endl;
    if (s[x])
    {
        // cout << r << " " << l << "\n";
        return r - l + 1;
    }

    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;
    return query(x << 1, l, mid) + query((x << 1) | 1, mid + 1, r);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        update(1, 1, 100000, x1, x2 - 1);
    }
    cout << query(1, 1, 100000) << endl;
    return 0;
}
