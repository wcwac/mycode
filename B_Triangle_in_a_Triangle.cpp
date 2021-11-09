#include <bits/stdc++.h>
using namespace std;

double s(double a, double b, double c)
{
    double t = (a + b + c) / 2;
    return sqrt(t * (t - a) * (t - b) * (t - c));
}

int main()
{
    double x[3], y[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    double ab = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
    double bc = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]));
    double ac = sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]));
    double cosa = (ab * ab + ac * ac - bc * bc) / 2 / ab / ac;
    double sina = sqrt(1 - cosa * cosa);
    double sinb = sina / bc * ac;
    double sinc = sina / bc * ab;
    double mi[3], ma[3];
    for (int i = 0; i < 3; ++i)
    {
        mi[i] = 1e9;
        ma[i] = 0;
        int n;
        cin >> n;
        while (n--)
        {
            double t;
            cin >> t;
            mi[i] = min(mi[i], t);
            ma[i] = max(ma[i], t);
        }
    }
    double ans = 0;

    //Case 1
    ans = max(ans, sina / 2 * (ma[0] - mi[0]) * (ac - mi[2]));
    ans = max(ans, sinb / 2 * (ma[0] - mi[0]) * ma[1]);

    ans = max(ans, sinb / 2 * (ma[1] - mi[1]) * (ab - mi[0]));
    ans = max(ans, sinc / 2 * (ma[1] - mi[1]) * ma[2]);

    ans = max(ans, sinc / 2 * (ma[2] - mi[2]) * (bc - mi[1]));
    ans = max(ans, sina / 2 * (ma[2] - mi[2]) * ma[0]);

    //Case 2
    double s1 = s(ab, bc, ac);
    ans = max(ans, s1 - sina / 2 * mi[0] * (ac - mi[2]) - sinb / 2 * mi[1] * (ab - mi[0]) - sinc / 2 * mi[2] * (bc - mi[1]));
    ans = max(ans, s1 - sina / 2 * ma[0] * (ac - ma[2]) - sinb / 2 * ma[1] * (ab - ma[0]) - sinc / 2 * ma[2] * (bc - ma[1]));

    printf("%.7f\n", ans);
}