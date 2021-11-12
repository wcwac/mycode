#include <iostream>
#include <map>
using namespace std;
map<int, int> _;
const int N = 1e4;
int flg[N], p[N], tot;

void getMu()
{
    for (int i = 2; i < N; i++)
    {
        if (!flg[i])
            p[++tot] = i;
        for (int j = 1; j <= tot && i * p[j] < N; j++)
        {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}

int f(int _x)
{
    int x = _x;
    if (_[x])
        return _[x];
    int r = 1;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % (i * i) == 0)
        {
            r = x / (i * i);
        }
    }

    return _[_x] = r;
}

int main()
{
    getMu();
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, ans = 1;
        cin >> n >> m;
        map<int, int> q;
        for (int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            if (q[f(t)])
            {
                ++ans;
                q.clear();
            }
            ++q[f(t)];
        }
        cout << ans << endl;
    }
    return 0;
}