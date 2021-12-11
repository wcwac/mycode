#include <iostream>
using namespace std;
//行数代表几条线，列数代表交点数，当dp[i][j]==1时,代表存在

int dp[710][710 * 700] = {}; //N条线最多 n*(n-)/ 2个交点

int main()
{
    // freopen("1.out", "w", stdout);
    dp[0][0] = dp[1][0] = 1;      //n =0和n = 1的情况
    for (int n = 2; n <= 50; n++) //代表n条线
    {
        dp[n][0] = 1; //n条直线都平行时交点为0

        for (int i = 0; i < n; i++) //i表示n条直线有i条平行
        {

            for (int j = 0; j <= n * (n - 1) / 2; j++) //j表示交点数
            {
                int b = n - i - 1; //b为n条直线减去平行线
                if (dp[b][j] == 1)
                    dp[n][(n - b) * b + j] = 1; //m条直线的交点方案数 = （m-b）*b+b条之间本身的交点方案数（1<=r<=m）
            }
        }
        cerr << n << endl;
    }
    for (int N = 1; N <= 50; ++N)
    {
        int t = 0, last = 0, cnt = 1;
        printf("if (n==%d) \n", N);
        for (int j = 0; j <= N * (N - 1) / 2; j++)
        {
            if ((dp[N][j] == 1 || j == N * (N - 1) / 2))
            {
                cout << j
                     << ",";
                // if (j - last == t)
                // {
                //     ++cnt;
                // }
                // else
                // {
                //     cout << t << "," << cnt << ",";
                //     cnt = 1;
                //     t = j - last;
                // }
                // last = j;
            }
        }
        printf("\n");
        // cout << endl;
        //         cout << N * (N - 1) / 2 << endl;
    }
    return 0;
}
