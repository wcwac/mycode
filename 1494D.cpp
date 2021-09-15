#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int N = 510;
int n;
int a[N][N];
vector<int> b[N];
map<vector<int>, int> q;
int e1, e2, val[N * 50], fa[N * 50];
int dfs(vector<int> &x, int flag)
{
    if (x.empty())
        return 0;
    int &ret = q[x];
    if (ret)
        return ret;
    if (flag)
        ret = ++e1;
    else
        ret = ++e2;
    val[ret] = x.back();
    x.pop_back();
    fa[ret] = dfs(x, 0);
    return ret;
}
int main()
{
    cin >> n;
    e2 = n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;
            b[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(b[i].begin(), b[i].end(), greater<int>());
        b[i].erase(unique(b[i].begin(), b[i].end()), b[i].end());
        b[i][b[i].size() - 1] = (b[i][b[i].size() - 1] << 20) + i;
        dfs(b[i], 1);
    }
    cout << e2 << "\n";
    int mx = 0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            
        }
    }
    for (int i = 1; i <= e2; ++i)
    {
        if (i <= n)
            cout << (val[i] >> 20) << " ";
        else
        {
            cout << val[i] << " ";
            if (val[i] > val[mx])
                mx = i;
        }
    }
    cout << "\n"
         << mx << "\n";
    for (int i = 1; i <= e2; ++i)
    {
        if (fa[i])
        {
            cout << i << " " << fa[i] << "\n";
        }
    }
    return 0;
}