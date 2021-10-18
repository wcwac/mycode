#include <iostream>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int flag1 = 0, flag2 = 0;
        for (int i = 0; i + 1 < s.length(); ++i)
        {
            if (s[i] == '1' && s[i + 1] == '1')
                flag1 = 1;
            if (flag1 && s[i] == '0' && s[i + 1] == '0')
                flag2 = 1;
        }
        puts(flag2 ? "NO" : "YES");
    }

    return 0;
}