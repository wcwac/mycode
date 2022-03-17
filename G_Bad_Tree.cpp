#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<int> v;
int main()
{
    ll n, m;
    cin >> n >> m;
    if (pow(2.0l, n - 1) < m)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    --m;
    for (int i = 1; i <= n; ++i)
    {
        if (m >= pow(2.0l, n - i - 1))
        {
            m -= pow(2.0l, n - i - 1);
            cout << v.back() << " ";
            v.pop_back();
        }
        else
        {
            cout << v.front() << " ";
            v.pop_front();
        }
    }
}