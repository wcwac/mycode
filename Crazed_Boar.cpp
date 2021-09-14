#include <bits/stdc++.h>
using namespace std;
int n;
double x_(double x, double y)
{

    return atan2(y, x) / (2 * acos(-1)) * 360;
}
double jiao(double a, double b, double c) //角ACB
{
    return acos((a * a + b * b - c * c) / 2 / a / b) / acos(-1) * 180;
}
struct node
{
    double x, y, r;
} a[20010];
double d, b, r;
const double eps = 1e-8;
struct kk
{
    double l, r;
    friend bool operator<(kk a, kk b)
    {
        return a.l < b.l;
        // return a.l + eps > b.l && a.l - eps < b.l ? a.r < b.r : a.l < b.l;
    }
} o[20010];
int tot;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    cin >> b >> d;
    //熊冲了d，熊半径为b
    for (int i = 1; i <= n; i++)
    {

        r = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
        if (b + d + a[i].r < r)
            continue;
        tot++;
        if (r * r - (a[i].r + b) * (a[i].r + b) < d * d)
        {
            o[tot].l = x_(a[i].x, a[i].y) - jiao(sqrt(r * r - (a[i].r + b) * (a[i].r + b)), r, a[i].r + b);
            o[tot].r = x_(a[i].x, a[i].y) + jiao(sqrt(r * r - (a[i].r + b) * (a[i].r + b)), r, a[i].r + b);
        }
        else
        {
            o[tot].l = x_(a[i].x, a[i].y) - jiao(d, r, a[i].r + b);
            o[tot].r = x_(a[i].x, a[i].y) + jiao(d, r, a[i].r + b);
        }
        if (o[tot].r > 180)
        {
            tot++;
            o[tot].r = o[tot - 1].r - 360;
            o[tot].l = -180;
            o[tot - 1].r = 180;
        }
        else if (o[tot].l < -180)
        {
            tot++;
            o[tot].l = o[tot - 1].l + 360;
            o[tot].r = 180;
            o[tot - 1].l = -180;
        }
    }
    sort(o + 1, o + 1 + tot);
    double sum = 0, now = -180;
    o[tot + 1].l = 180;
    for (int i = 1; i <= tot + 1; i++)
    {
        if (o[i].l >= now)
        {
            sum += o[i].l - now;
        }
        now = max(now, o[i].r);
    }
    printf("%.8lf", sum / 360);
}