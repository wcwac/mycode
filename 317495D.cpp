#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll, int> pll;
tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> q;
const int N = 2e5 + 10;
ll t, sum, a[N], ans;
int main()
{
    int n;
    cin >> n >> t;
    q.insert(pll(0, 0));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        ans += q.size() - q.order_of_key(pll(sum - t + 1, 0));
        q.insert(pll(sum, i));
        //  cout << sum << " ";
    }
    cout << ans << endl;
    return 0;
}