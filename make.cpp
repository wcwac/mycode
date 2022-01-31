#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
typedef long long ll;
ll vis[N], prime[N], e;
void init()
{
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime[++e] = i;
            // cout << i << endl;
        }
        for (int j = 1; j <= e && i < N / prime[j]; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    freopen("p.in", "w", stdout);
    init();
}