#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
double x[N], y[N], ans[N], speedmax[N], speedmin[N];
int main()
{
    int n;
    double m, mi, ma;
    cin >> n >> m >> mi >> ma;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        ans[i] = y[i];
    }
    x[0] = -1e9;
    for (int i = 1; i <= n; ++i)
    {
        double t = (x[i] - x[i - 1]) / m;
        ans[i] = speedmax[i - 1] * t + 0.5 * ma * t * t + ans[i - 1];
        if (ans[i] >= y[i])
        {
            ans[i] = y[i];
            double a = mi;
            double b = ma;
            double c = t;
            double d = 2 * (ans[i] - ans[i - 1] - speedmax[i - 1] * t);
            double x0 = (a * c + sqrt(-a * b * c * c + a * d + b * d)) / (a + b);
            double x1 = (b * c - sqrt(-a * b * c * c + a * d + b * d)) / (a + b);
            if (x0 >= 0 && x1 >= 0)
            {
                speedmax[i] = speedmax[i - 1] + a * x0 + b * x1;
            }
        }
        else
        {
            speedmax[i] = speedmax[i - 1] + t * ma;
        }
    }
    x[n + 1] = 2e9;
    swap(mi, ma);
    mi = -mi;
    ma = -ma;
    for (int i = n; i >= 1; --i)
    {
        double t = (x[i + 1] - x[i]) / m;
        ans[i] = min(ans[i], speedmax[i + 1] * t + 0.5 * ma * t * t + ans[i + 1]);
        if (ans[i] >= y[i])
        {
            ans[i] = y[i];
            double a = mi;
            double b = ma;
            double c = t;
            double d = 2 * (ans[i] - ans[i + 1] - speedmax[i + 1] * t);
            double x0 = (a * c + sqrt(-a * b * c * c + a * d + b * d)) / (a + b);
            double x1 = (b * c - sqrt(-a * b * c * c + a * d + b * d)) / (a + b);
            if (x0 >= 0 && x1 >= 0)
            {
                speedmax[i] = speedmax[i + 1] + a * x0 + b * x1;
            }
        }
        else
        {
            speedmax[i] = speedmax[i + 1] + t * ma;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}