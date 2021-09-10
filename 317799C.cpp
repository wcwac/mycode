#include <bits/stdc++.h>
using namespace std;
int ans[1010];
int main()
{
    string str;
    cin >> str;
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == 'a')
        {
            ans[i - 1] ^= 1;
            ans[i] ^= 1;
        }
    }
    for (int i = 0; i < str.size(); ++i)
    {
        cout << ans[i] << " ";
    }
}