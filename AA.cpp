#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;

signed main()
{
#ifdef Local
    freopen(R"(E:\CppProject\untitled\a.in)", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    int n{}, m{}, k{};
    ll v[10010];
    std::cin >> T;
    for (int tt = 1; tt <= T; ++tt)
    {
        cin >> n >> m >> k;
        ll t;
        for (int j = 0; j < n; ++j)
            cin >> v[j];
        sort(v, v + n);
        bool flag = true;
        if (m >= v[n - 1])
            flag = true;
        else if (m < v[0])
            flag = false;
        else
        {
            int pos = 0;
            while (pos + 1 < n && v[pos + 1] <= m)
                ++pos;
            ll zdl = v[pos];
            ll tmp;
            for (int i = pos + 1; i < n;)
            {
                tmp = zdl + k;
                if (tmp >= v[n - 1])
                {
                    flag = true;
                    break;
                }
                if (v[i] > tmp)
                {
                    flag = false;
                    break;
                }
                while (v[i] <= tmp)
                    ++i;
                zdl = v[i - 1];
                --k;
            }
        }
        cout << "Case #" << tt << ":\n";
        cout << (flag ? "why am I so diao?" : "madan!") << endl;
    }
    return 0;
}