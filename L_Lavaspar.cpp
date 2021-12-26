#include <bits/stdc++.h>
using namespace std;
char s[50][50];

int flag1[50][50];
int flag2[50][50];
int flag3[50][50];
int flag4[50][50];
int main()
{
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        cin >> s[i];
    }
    int n;
    cin >> n;
    for (int _ = 1; _ <= n; ++_)
    {
        string t;
        cin >> t;
        vector<int> tmpa(26, 0);
        for (auto j : t)
        {
            ++tmpa[j - 'A'];
        }
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j + t.length() <= c; ++j)
            {
                vector<int> tmpb(26, 0);
                for (int k = 0; k < t.length(); ++k)
                {
                    ++tmpb[s[i][j + k] - 'A'];
                }
                if (tmpa == tmpb)
                {
                    for (int k = 0; k < t.length(); ++k)
                    {
                        flag1[i][j + k] |= (1 << _);
                    }
                }
            }
        }

        for (int i = 0; i < c; ++i)
        {

            for (int j = 0; j + t.length() <= r; ++j)
            {
                vector<int> tmpb(26, 0);
                for (int k = 0; k < t.length(); ++k)
                {
                    ++tmpb[s[j + k][i] - 'A'];
                }
                if (tmpa == tmpb)
                {
                    for (int k = 0; k < t.length(); ++k)
                    {
                        flag2[j + k][i] |= (1 << _);
                    }
                }
            }
        }

        for (int i = 0; i + t.length() <= r; ++i)
        {

            for (int j = 0; j + t.length() <= c; ++j)
            {
                vector<int> tmpb(26, 0);
                for (int k = 0; k < t.length(); ++k)
                {
                    ++tmpb[s[i + k][j + k] - 'A'];
                }
                if (tmpa == tmpb)
                {
                    for (int k = 0; k < t.length(); ++k)
                    {
                        flag3[i + k][j + k] |= (1 << _);
                    }
                }
            }
        }

        for (int i = 0; i + t.length() <= r; ++i)
        {

            for (int j = t.length() - 1; j < c; ++j)
            {
                vector<int> tmpb(26, 0);
                for (int k = 0; k < t.length(); ++k)
                {
                    ++tmpb[s[i + k][j - k] - 'A'];
                }
                if (tmpa == tmpb)
                {
                    for (int k = 0; k < t.length(); ++k)
                    {
                        flag4[i + k][j - k] |= (1 << _);
                    }
                }
            }
        }
    }

    // for (int i = 0; i < r; ++i)
    // {
    //     for (int j = 0; j < c; ++j)
    //     {
    //         cout << flag1[i][j] << ',';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < r; ++i)
    // {
    //     for (int j = 0; j < c; ++j)
    //     {
    //         cout << flag2[i][j] << ',';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < r; ++i)
    // {
    //     for (int j = 0; j < c; ++j)
    //     {
    //         cout << flag3[i][j] << ',';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < r; ++i)
    // {
    //     for (int j = 0; j < c; ++j)
    //     {
    //         cout << flag4[i][j] << ',';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            int t = flag1[i][j] | flag2[i][j] | flag3[i][j] | flag4[i][j];
            if (__builtin_popcount(t) >= 2)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}