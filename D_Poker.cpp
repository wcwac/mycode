#include <bits/stdc++.h>
using namespace std;
int cnt[10], cnta[10], cntb[10];
int pw[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int calc()
{
    int a = 0, b = 0;
    for (int i = 1; i <= 9; ++i)
    {
        a += pw[cnta[i]] * i;
        b += pw[cntb[i]] * i;
    }
    return a > b;
}
int main()
{
    double ans = 0;
    int K;
    string S, T;
    cin >> K >> S >> T;
    for (int i = 1; i <= 9; ++i)
        cnt[i] = K;
    K = K * 9 - 8;
    for (int i = 0; i < 4; ++i)
    {
        cnt[S[i] - '0']--;
        cnt[T[i] - '0']--;
        cnta[S[i] - '0']++;
        cntb[T[i] - '0']++;
    }
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            --cnt[i];
            --cnt[j];
            if (cnt[i] >= 0 && cnt[j] >= 0)
            {
                ++cnta[i];
                ++cntb[j];
                if (calc())
                {
                    // cout<<i<<" "<<j<<"\n";
                    // cout<<K*K-1<<"\n";
                    if (i == j)
                        ans += 1.0l * (cnt[i] + 2) / K * (cnt[i] + 1) / (K - 1);
                    else
                        ans += 1.0l * (cnt[i] + 1) / K * (cnt[j] + 1) / (K - 1);
                }
                --cnta[i];
                --cntb[j];
            }
            ++cnt[i];
            ++cnt[j];
        }
    }
    cout << ans;
    return 0;
}