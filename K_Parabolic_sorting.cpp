#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int s[N];
void add(int x, int d)
{
    for (; x < N; x += -x & x)
        s[x] += d;
}
int ask(int x)
{
    int ans = 0;
    for (; x; x -= -x & x)
        ans += s[x];
    return ans;
}

int main()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() + 1;
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        l[i] = ask(a[i] - 1);
        add(a[i], 1);
    }
    memset(s, 0, sizeof s);
    for (int i = n - 1; i >= 0; --i)
    {
        r[i] = ask(a[i] - 1);
        add(a[i], 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(l[i], r[i]);
    }
    cout << ans << endl;
    return 0;
}