#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int sum[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        unordered_map<int, vector<int>> q;
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == '+')
            {
                sum[i] = sum[i - 1] + ((i & 1) ? 1 : -1);
            }
            else
            {
                sum[i] = sum[i - 1] - ((i & 1) ? 1 : -1);
            }
            q[sum[i]].push_back(i);
        }
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            int num = abs(sum[r] - sum[l - 1]);
            if (num == 0)
            {
                puts("0");
            }
            else if (num & 1)
            {
                puts("1");
                int t = sum[l - 1] + num;
            }
            else
            {
                puts("2");
            }
        }
    }

    return 0;
}