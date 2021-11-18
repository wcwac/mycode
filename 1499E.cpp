#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1010;
ll f[N][N][26], ans;
char a[N], b[N];

int dfs(int i, int j, int ch)
{
    if (!i || !j)
        return 0;
    if (f[i][j][ch - 'a'])
        return f[i][j][ch - 'a'];
    long long ret = a[i] == b[j] ? 2 : 4;
    if (a[i - 1] != ch)
        ret += dfs(i - 1, j,a[i-1]);
    if (b[j - 1] != ch)
        ret += dfs(i, j - 1,b[j-1]);
    return f[i][j][ch - 'a'] = ret;
}

int main()
{
    // string a, b;
    scanf("%s%s", a + 1, b + 1);
    int la = strlen(a + 1), lb = strlen(b + 1);
    // for (int i = 0; i <= la; ++i)
    // {
    //     for (int j = 0; j <= lb; ++j)
    //     {
    //         if (a[i] != b[j])
    //         {

    //             f[i][j][a[i] - 'a'] = f[i][j][b[j] - 'a'] = 1;
    //             if (i >= 2)
    //             {
    //                 int k = a[i - 1] - 'a';
    //                 if (a[i] - 'a' != k)
    //                     f[i][j][a[i] - 'a'] += f[i - 1][j][k];
    //             }
    //             if (j >= 2)
    //             {
    //                 int k = b[j - 1] - 'a';
    //                 if (b[j] - 'a' != k)
    //                     f[i][j][b[j] - 'a'] += f[i][j - 1][k];
    //             }
    //             if (i >= 2 && j >= 2)
    //             {
    //                 int k = b[j - 1] - 'a';
    //                 if (a[i] - 'a' != k)
    //                     f[i][j][a[i] - 'a'] += f[i][j - 1][k];
    //                 if (b[j] - 'a' != k)
    //                     f[i][j][b[j] - 'a'] += f[i - 1][j][k];
    //                 k = a[i - 1] - 'a';
    //                 if (a[i] - 'a' != k)
    //                     f[i][j][a[i] - 'a'] += f[i][j - 1][k];
    //                 if (b[j] - 'a' != k)
    //                     f[i][j][b[j] - 'a'] += f[i - 1][j][k];
    //             }
    //             // cout << i << " " << j << " " << f[i][j][a[i] - 'a'] << "  " << f[i][j][b[j] - 'a'] << endl;
    //             ans += f[i][j][a[i] - 'a'] + f[i][j][b[j] - 'a'];
    //         }
    //     }
    // }
    cout << dfs(la,lb,) << endl;
    return 0;
}