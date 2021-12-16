#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, s[N];
vector<int> a, b, c, d;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        if (s[i] > 0)
            a.push_back(i);
        if (s[i] == 0)
            b.push_back(i);
        if (s[i] < 0)
            c.push_back(i);
    }
    if (c.size() & 1)
    {
        int pos = -1;
        for (int i = 0; i < c.size(); ++i)
        {
            if (pos == -1 || s[c[i]] > s[c[pos]])
                pos = i;
        }
        // printf("%d %d\n", 2, c[pos]);
        b.push_back(c[pos]);
        c.erase(c.begin() + pos);
    }
    if (b.size())
    {
        for (int i = 0; i < (int)b.size() - 1; ++i)
        {
            printf("%d %d %d\n", 1, b[i], b[i + 1]);
        }
        if (b.size() != n)
            printf("%d %d\n", 2, b[b.size() - 1]);
    }
    for (int i = 0; i < (int)a.size() - 1; ++i)
    {
        printf("%d %d %d\n", 1, a[i], a[i + 1]);
    }
    for (int i = 0; i < (int)c.size() - 1; ++i)
    {
        printf("%d %d %d\n", 1, c[i], c[i + 1]);
    }
    if (a.size() && c.size())
    {
        printf("%d %d %d\n", 1, a[a.size() - 1], c[c.size() - 1]);
    }
    return 0;
}