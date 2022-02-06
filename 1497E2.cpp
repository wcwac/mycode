#include <iostream>
#include <bitset>
#include <set>
#include <map>
#include <vector>
using namespace std;
map<int, int> _;
map<int, int> _h;
int cntt = 0;
int hsh(int x)
{
    return _h[x] ? _h[x] : _h[x] = cntt++;
}
int f(int _x)
{
    int x = _x;
    if (_[x])
        return hsh(_[x]);
    int r = 1;
    for (int i = 1; i * i <= x; ++i)
    {
        if (x % (i * i) == 0)
        {
            r = x / (i * i);
        }
    }

    return hsh(_[_x] = r);
}

typedef bitset<4096> bt;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        _.clear();
        _h.clear();
        int n, m, ans = 1;
        cin >> n >> m;
        bt q;
        vector<bt> v;
        for (int i = 1; i <= n; ++i)
        {
            int t;
            cin >> t;
            if (q[f(t)])
            {
                v.push_back(q);
                ++ans;
                q = 0;
            }
            q[f(t)] = 1;
        }
        v.push_back(q);
        while (v.size() > 1)
        {
            int now = 1e9, nowi = 0;
            for (int i = 1; i < v.size(); ++i)
            {
                int tmp = (v[i] & v[i - 1]).count();
                if (tmp < now)
                {
                    now = tmp;
                    nowi = i;
                }
            }
            v[nowi - 1] |= v[nowi];
            v.erase(v.begin() + nowi);
            if (m >= now)
            {
                m -= now;
                --ans;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}