#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        string str;
        cin >> n >> m >> str;
        if (n % m)
        {
            puts("-1");
            continue;
        }
        int cnt[30],now=0;
        for (int i = 0; i < 30; ++i)
            cnt[i]  = 0;
        for (int i = 0; i < n; ++i)
        {
            if (cnt[str[i] - 'a'] == 0)
                cnt[str[i] - 'a'] = m,++now;
            --cnt[str[i] - 'a'];
            if (cnt[str[i] - 'a'] == 0) --now;
        }
        if (!now) {
            cout << str << endl;
            continue;
        }
        int flag = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int t = str[i] - 'a';
            ++cnt[t];
            if (cnt[t] == m)
            {
                cnt[t] = 0;
            }
            int aa = 0, bb = 0;
            for (int i = 0; i <= t; ++i)
                aa += cnt[i];
            for (int i = t+1; i < 26; ++i)
                bb += cnt[i];
            int j = n - 1 - i;
            if (j >= aa && j + 1 >= aa + bb)
            {
                flag = 1;
                ++str[i];
                if (cnt[t + 1] == 0) cnt[t + 1] = m;
                --cnt[t + 1];
                for (int _k = i + 1; _k < n; ++_k)
                {
                    str[_k] = 0;
                    for (int k = 0; k < 26; ++k)
                    {
                        if (cnt[k])
                        {
                            --cnt[k];
                            str[_k] = k + 'a';
                            break;
                        }
                    }
                    if (!str[_k]) {
                        str[_k] = 'a';
                        cnt[0] = m - 1;
                    }
                }
            }
            if (flag)
                break;
        }
        if (!flag)
        {
            puts("-1");
        }
        else
        {
            cout << str << endl;
        }
    }
}