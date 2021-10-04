#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        map<pii, int> q;
        pii now = pii(0, 0);
        q[now] = 1;
        long long ans = 0;
        for (auto i : s)
        {
            if (i == 'U')
            {
                now.second++;
            }
            else if (i == 'D')
            {
                now.second--;
            }
            else if (i == 'L')
            {
                now.first--;
            }
            else if (i == 'R')
            {
                now.first++;
            }
            ans += q[now]++;
        }
        cout << ans << endl;
    }
}