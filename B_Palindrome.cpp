#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int f[2][N];
int main()
{
    int n;
    string a, b;
    cin >> n;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; ++i)
    {
        int now = i & 1;
        int pre = now ^ 1;
        for (int j = 0; j < n; ++j)
        {
            if (a[j] == b[i])
            {
                f[now][j] = max(f[now][j], f[pre][j - 1] + 1);
            }else {
                f[now][j] = max(f[now][j], f[pre][j-1]);
            }
        }
    }
}