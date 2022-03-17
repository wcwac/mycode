#include <bits/stdc++.h>
using namespace std;

long long ans;

int main()
{
    int n;
    cin >> n;
    ans += 1ll * (1 + n) * n / 2;
    ans += n;
    cout << ans;
    return 0;
}