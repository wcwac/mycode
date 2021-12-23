#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int flag = 1, K;
        string ans;
        string s;
        cin >> s >> K;
        long long now = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
            {
                now = s[i] - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1]))
                {
                    ++i;
                    now = now * 10 + s[i] - '0';
                    if (now > K)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            else
            {
                if (now)
                {
                    while (now--)
                    {
                        ans += s[i];
                    }
                    now = 0;
                }
                else
                    ans += s[i];
            }
        }
        if (flag == 0 || ans.length() > K)
        {
            cout << "unfeasible" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}