#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
long long a[N], sum = 0, mx = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    sum = sum * 2 + 1;
    cout << max(mx, sum / n + (sum % n != 0));
    return 0;
}