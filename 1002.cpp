#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
inline int gint()
{
    int x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c))
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}

int check(const vector<double> &a, const vector<double> &b, double k)
{
    double l = -1e15, u = 1e15;
    for (int i = 0; i < a.size(); ++i)
    {
        l = max(l, b[i] - k * a[i] - 10);
        u = min(u, b[i] - k * a[i] + 10);
    }
    if (u - l >= 1.0 - eps || (long long)u >= l)
        return 1;
    return 0;
}

int main()
{
    int T = gint();
    while (T--)
    {
        int n = gint();
        vector<double> a, b, c;
        for (int i = 1; i <= n; ++i)
            a.push_back(gint());
        for (int i = 1; i <= n; ++i)
            c.push_back(gint());
        for (int i = 1; i <= n; ++i)
            b.push_back(gint());
        double sum = 0, sum1 = 0;
        int det = n / 2;
        for (int i = 0; i + det < n; ++i)
        {
            sum += a[i + det] - a[i];
            sum1 += b[i + det] - b[i];
        }
        sum /= sum1;
        int flag = 2;
        for (int i = sum - 50; i <= sum + 50; ++i)
        {
            // printf("check %d\n", i);
            if (check(a, b, i))
            {
                flag = 1;
                break;
            }
        }
        printf("%d\n", flag);
    }

    return 0;
}