#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y)
{
    if (x > y)
        return 0;
    if (x == y)
        return 1;
    for (int i = 1; i <= x; ++i)
    {
        if ((x | i) == x)
        {
            if (dfs(x + i, y))
                return 1;
        }
    }
    return 0;
}
int popcount(int x)
{
    int cnt = 0;
    while (x)
    {
        ++cnt;
        x -= (x & (-x));
    }
    return cnt;
}

int check(int x, int y)
{
    if (x > y)
        return 0;
    bitset<40> a(x), b(y);
    int cnt = 0;
    for (int i = 0; i < 35; ++i)
    {
        if (a[i] && !b[i])
        {
            ++cnt;
        }
        if (!a[i] && b[i])
        {
            --cnt;
            if (cnt < 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    // for (int i=1;i<=40;++i){
    //     for (int j=1;j<i;++j){
    //         if (!(check(j,i))==dfs(j,i)) printf("%d %d\n",j,i);
    //         // printf("%d to %d    %d\n",j,i,dfs(j,i));
    //     }
    // }
    int n;
    cin >> n;
    while (n--)
    {
        long long x, y;
        cin >> x >> y;
        cout << ((check(x, y)) ? "YES" : "NO") << endl;
    }

    return 0;
}