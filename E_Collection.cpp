#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    map<int, int> q;
    while (n--)
    {
        int x;
        cin >> x;
        ans += (++q[x] != 1);
    }
    cout << ans << endl;
}